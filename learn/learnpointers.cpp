#include <iostream>
int main(){
    // int* ptr {new int(38)};
    // std::cout<<"Value: "<<*ptr<< std::endl;
    // std::cout<<"Adress: "<<ptr<< std::endl;
    // delete ptr;
    // ptr = nullptr;
    // if(ptr != nullptr){
    //     std::cout<< ptr << std::endl;
    // }
    // else {
    //     std::cout<< "Empty pointer" << std::endl; 
    // }
    // int *ptr4 {nullptr};
    // ptr4 = new int;
    // *ptr4 = 77;
    // std::cout<<"value that ptr4 holds = "<<*ptr4<<std::endl;
    // delete ptr4;
    // ptr4 = nullptr;
    // ptr4 = new int(81);
    // // std::cout<<"value that ptr4 holds = "<<*ptr4<<std::endl;
    // int age = 14;
    // int* Page = &age;
    // int** Ptr = &Page;
    // int*** Ptr3 = &Ptr;
    // std::cout<<"expected 14 got: "<<*Page<< std::endl;
    // std::cout<<"expected the memory address of the variable holding 14, got: "<<Page<< std::endl;
    // std::cout<<"This is Ptr after **: " <<**Ptr<< std::endl;
    // std::cout<<"This is Ptr after *: " <<*Ptr<< std::endl;
    // std::cout<<"This is the pointer holding the page pointer, expected to get the memory address, got : " <<Ptr<< std::endl;
    // std::cout<<"This is Ptr3 after ***: " <<***Ptr3<< std::endl;
    // std::cout<<"This is Ptr3 after **: " <<**Ptr3<< std::endl;
    // std::cout<<"This is Ptr3 after *: " <<*Ptr3<< std::endl;
    // std::cout<<"This is address in Ptr3 : " <<Ptr3<< std::endl;
    // std::cout<<"This is address of Ptr3 : " <<&Ptr3<< std::endl;

    int* data = new int[100000000000];
    std::cout<< "Program ending well"<<std::endl;
    return 0;
}