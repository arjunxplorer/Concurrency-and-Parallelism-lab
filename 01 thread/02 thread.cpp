#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>

void numbers(){
    for(int i=0; i< 100; i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        std::cout << i+1<< " ";
    }
}

void alphabet(){
    for(int i=0; i<100; i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        std::cout << "A"<< " ";
    }
}

int main(){
    std::thread n(numbers);
    std::thread a(alphabet);

    n.join();
    a.join();
    return 0;
}