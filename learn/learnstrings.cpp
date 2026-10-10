#include <iostream>
#include <string>

int main(){
    std::string planet{"Earth. Where the sky is blue"};
    std::cout<<planet<<std::endl;
    std::string preferedPlanet{planet};
    std::cout<<preferedPlanet<<std::endl;
    std::string message{"Hello there",5};
    std::cout<<message<<std::endl;
    std::string weird_message{4,'e'};
    std::cout<<weird_message<<std::endl;
    std::string greeting {"Hello world"};
    std::cout<<greeting<<std::endl;
    std::string sayingHello{greeting, 5,6};
    std::cout<<sayingHello<<std::endl;
}
