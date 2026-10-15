#include <iostream>
#include <thread>


int counter = 0;
void increment(){
    for(int i=1; i <= 100000; i++){
        counter++;
    }
}

int main() {
    std::thread i(increment);
    std::thread j(increment);
    i.join();
    j.join();

    std::cout << "Counter: "<< counter;
    return 0;
}