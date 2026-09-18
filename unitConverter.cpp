#include <iostream>
#include <string>

int choice;
double value;


int main(){
    std::cout<<"This is a unit converter" << std::endl;
    std::cout<<"Select which unit you want to convert"<< std::endl;
    std::cout<<"1. Temperature"<< std::endl;
    std::cout<<"2. Weight"<< std::endl;
    std::cout<<"3. Length"<< std::endl;
    std::cout<<"4. Find Age"<< std::endl;
    std::cin>>choice;
    if(choice == 1){
        std::cout<<"You have selected Temperature"<< std::endl;
        std::cout<<"Enter what you are converting to"<< std::endl;
        std::cout<<"\n 1. From celcius to faranheit"<< std::endl;
        std::cout<<"\n 2. From faranheit to celcius"<< std::endl;
        std::cin>>choice;
        if(choice == 1){
            std::cout<<"Enter the value to convert to faranheit: "<< std::endl;
            std::cin>>value;
            value = (value * 9/5) + 32;
            std::cout<<"The converted value is: "<< value <<" faranheit"<< std::endl;
        }
        else{
            std::cout<<"Enter value to convert to celcius: "<< std::endl;
            std::cin>>value;
            value = (value / 9/5) - 32;
            std::cout<<"The converted value is: " << value << "celcius"<< std::endl;
        }
    }
    else if(choice == 2){
        std::cout<<"You have selected Weight"<< std::endl;
        std::cout<<"Enter what you are converting to "<< std::endl;
        std::cout<<"\n 1. From pounds to kilograms"<< std::endl;
        std::cout<<"\n 2. From kilograms to pounds"<< std::endl;
        std::cin>>choice;
        if(choice == 1){
            std::cout<<"Enter the value of pounds to convert to kilograms: "<< std::endl;
            std::cin>>value;
            value = (value * 0.45359237);
            std::cout<<"The converted the value from pounds to kilogram is: "<<value<<"kilogram(s)"<< std::endl;
        }
        else{
            std::cout<<"Enter the value of kilograms to convert to pounds"<< std::endl;
            std::cin>>value;
            value = (value *2.20462);
            std::cout<<"The converted value from kilograms to pounds is: "<<value<<"pound(s)"<< std::endl;
        }
    }
    else if(choice == 3){
        std::cout<<"You have selected Length"<< std::endl;
        std::cout<<"Enter what you are converting to "<< std::endl;
        std::cout<<"\n 1. From miles to kilometers"<< std::endl;
        std::cout<<"\n 2. From kilometers to miles"<< std::endl;
        std::cin>>choice;
        if(choice == 1){
            std::cout<<"Enter the value of miles to convert to kilometers: "<< std::endl;
            std::cin>>value;
            value = (value * 1.60934);
            std::cout<<"The converted value from miles to kilometers is: "<<value<<"kilometer(s)"<< std::endl;
        }
        else{
            std::cout<<"Enter the value of kilometers to convert to miles: "<< std::endl;
            std::cin>>value;
            value = (value * 0.621371);
            std::cout<<"The converted value from kilometers to miles is: "<<value<<"mile(s)"<< std::endl;
        }
    }
   else if(choice == 4){
	    std::cout<< "Enter the age you are trying to get" << std::endl;
	    std::cin>>value;
	    value = 2026 - value;
	    std::cout<<"The age is: "<<value<<std::endl;
   }

    return 0;
}
