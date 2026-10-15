#include <iostream>
#include <thread>
#include <vector>
#include <string>

void numbers(){
    for(int i=0; i< 5; i++){
        std::cout << i+1<< " ";
    }
}

void alphabet(){
    std::vector<std::string> a ={"A", "B", "C", "D", "E"};

    for(std::string n : a){
        std::cout << n << " ";
    }
}

int main() {
    std::thread n(numbers);
    std::thread a(alphabet);

    n.join();
    a.join();

    return 0;

}