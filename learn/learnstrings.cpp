#include <iostream>
#include <string>

int main(){
    std::string name {};
    std::getline(std::cin>> std::ws , name );
    std::cout<<name<<" has "<<std::size(name)<<" letters in it"<<std::endl;  
    size_t size{10};
    double* p_salaries {new double[size]};
    int* p_students {new int[size]{} };
    double* p_scores {new double[size]{1,2,3,4,5}};
    std::cout<<*p_salaries<< std::endl;
    std::cout<<*p_students<< std::endl;
    std::cout<<*p_scores<< std::endl;
}