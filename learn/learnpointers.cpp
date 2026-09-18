#include <iostream>

int main(){
    int* ptr {new int(38)};
    std::cout<<"Value: "<<*ptr<< std::endl;
    std::cout<<"Adress: "<<ptr<< std::endl;
    delete ptr;
    ptr = nullptr;
    if(ptr != nullptr){
        std::cout<< ptr << std::endl;
    }
    else {
        std::cout<< "Empty pointer" << std::endl; 
    }
}