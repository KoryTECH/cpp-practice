#include <iostream>
#include <string>
#include <vector>

struct contact {
    std::string name;
    std::string phoneNumber;
};

int main(){
    std::vector<contact> contacts = {{"Korede", "7010145485"}, {"Kory", "7075844893"}};
    int newName;
    int newPhoneNumber;
    int length = (sizeof(contacts) / sizeof(contacts[0]));
    std::cout << contacts[0].name << '\t' ;  
    std::cout << contacts[0].phoneNumber<< std::endl;  
    std::cout << contacts[1].name << '\t' ;  
    std::cout << contacts[1].phoneNumber<< std::endl;
    // std::cin >> newName; 
    // std::cin >> newPhoneNumber;
    // contacts.emplace_back(newName,newPhoneNumber);
    // for(int i = 0; i <= length; i++){
    //     std::cout << contacts[i].name << '\t' ;  
    //     std::cout << contacts[i].phoneNumber<< std::endl; 
    // }
    return 0;
}