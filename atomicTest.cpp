#include <iostream>
#include <vector>
#include <atomic>
#include <thread>
#include "atomic_op.h"

int cnt = 0;

void cnt1k() {
	for(int i = 0; i < 1000; i++)
		AtomicOps::Increment(&cnt);
}

void testIncrement() {
	std::vector<std::thread> threads;

	for(int i = 0; i <10; i ++) threads.push_back(std::thread(cnt1k));
	
	for(auto &th : threads) th.join();

	std::cout<<cnt<<"\n";

}

int ready = 0;
volatile int* pReady = &ready;

std::atomic_flag winner = ATOMIC_FLAG_INIT;


void cnt1m(int id) {
	while(!AtomicOps::AcquireLoad(pReady)) { std::this_thread::yield();}

	for(int i =0; i < 1000000;i++) {}

	if(!winner.test_and_set()) std::cout<<"Thread #"<<id<<" wins\n";
}

void testCAS() {
	std::vector<std::thread> threads;
	for(int i=0; i <10; i ++) threads.push_back(std::thread(cnt1m,i));
	
	AtomicOps::ReleaseStore(pReady,1);
	//AtomicOps::Increment(pReady);

	for(auto &th : threads) th.join();


}

int main() {

	//testIncrement();
	testCAS();
	return 0;
}
