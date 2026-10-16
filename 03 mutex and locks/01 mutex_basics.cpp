#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

int counter = 0;

void increment(std::mutex* mtx){
    for(int i=0; i < 100000; i++){
        std::lock_guard<std::mutex> lock(*mtx);
        counter++;
    }
}


int main(){
    std::mutex mtx;

    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    std::thread t1(increment, &mtx);
    std::thread t2(increment, &mtx);

    t1.join();
    t2.join();
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Time taken: " << duration.count() << " μs" << std::endl;
    std::cout << "Counter: "<< counter;
    

}