#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>


void task1(std::mutex* mtx1, std::mutex* mtx2){
    std::lock_guard<std::mutex> lock1(*mtx1);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::lock_guard<std::mutex> lock2(*mtx2);
}

void task2(std::mutex* mtx1, std::mutex* mtx2){
    std::lock_guard<std::mutex> lock1(*mtx2);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::lock_guard<std::mutex> lock2(*mtx1);
}

int main() {
    std::mutex mtx1, mtx2;

    std::thread t1(task1, &mtx1, &mtx2);
    std::thread t2(task2, &mtx1, &mtx2);

    t1.join();
    t2.join();

    return 0;


}