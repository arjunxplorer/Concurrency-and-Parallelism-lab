#include <iostream>
#include <thread>
#include <mutex>

int counter =0;

void increment(std::mutex* mtx){
    for(int i=0; i < 100000; i++){
        std::unique_lock<std::mutex> lock(*mtx);
        counter++;
        lock.unlock();
    }
}

int main(){
    std::mutex mtx;

    std::thread t1(increment, &mtx);
    std::thread t2(increment, &mtx);

    t1.join();
    t2.join();

    std::cout << "Counter: "<< counter;
}