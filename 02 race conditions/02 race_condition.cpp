#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

int counter =0;
void increment(std::mutex* mtx){
    std::lock_guard<std::mutex> lock(*mtx);
    for(int i=0; i < 100000; i++){
        counter++;
    }
}

int main() {
    std::mutex mtx;
    std::thread i(increment, &mtx);
    std::thread j(increment, &mtx);

    i.join();
    j.join();

    std::cout << "Counter: "<< counter;
}