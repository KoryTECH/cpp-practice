#include <iostream>

int main(){
    int int_value{45};
    double double_value{33.65};

    int& reference_to_int_value{int_value};    
    // int& refernce_to_int_value1 = int value;
    double& reference_to_double_value {double_value};

    std::cout<< "int_value: "<< int_value<< std::endl;
    std::cout<< "double_value: "<< double_value<< std::endl;
    reference_to_int_value = 97;
    reference_to_double_value = 96.53;
    std::cout<< "int_value: "<< int_value<< std::endl;
    std::cout<< "double_value: "<< double_value<< std::endl;
    // std::cout<< "refrence to int_value: "<< reference_to_int_value<< std::endl;
    // std::cout<< "refernece_to_double_value: "<< reference_to_double_value<< std::endl;
    // std::cout<< "memory address of int_value: "<< &int_value<< std::endl;
    // std::cout<< "memory address of double_value: "<< &double_value<< std::endl;
    // std::cout<< "memory address of refrence to int_value: "<< &reference_to_int_value<< std::endl;
    // std::cout<< "memory address of refernece_to_double_value: "<< &reference_to_double_value<< std::endl;

}