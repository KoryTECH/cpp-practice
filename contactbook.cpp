#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void showMenu();
void add();
void remove();
void displayAll();

int choice;

struct Contact{
    std::string name;
    std::string phoneNumber;
    std::string email;
};

std::vector<Contact>phoneBook;

int main(){
    std::cout<< "Welcome to contact book" << std::endl;
    showMenu();
    return 0;
}

void showMenu(){
    std::cout<< ""<< std::endl;
    std::cout<< "1. Add to contact book" << std::endl;
    std::cout<< "2. Delete from contact book" << std::endl;
    std::cout<< "3. Display All contact" << std::endl;
    std::cout<< "4. Exit contact book" << std::endl;
    std::cin>> choice;

    if(choice == 1){
        add();
    }
    else if(choice == 2){
        remove();
    }
    else if(choice == 3){
        displayAll();
    }
    else if(choice == 4){
        std::cout<< "Exiting contact book" << std::endl;
    }
    else{
        std::cout<< "Invalid choice" << std::endl;
    }

}

void add(){
        while(true){
            Contact c;
            std::cout<< "Enter name or done: " << std::endl;
            std::cin.ignore();
            std::getline(std::cin, c.name);
            if(c.name == "done") break;

            std::cout<< "Enter Phone number: " <<std::endl;
            std::cin.ignore();
            std::getline(std::cin, c.phoneNumber);
            std::cout<< "Enter email: " << std::endl;
            std::cin.ignore();
            std::getline(std::cin, c.email);
            phoneBook.push_back(c);
        }
        showMenu();
}

void remove(){
    std::string name;
    std::cout<< "Enter name to remove: " << std::endl;
    std::cin.ignore();
    std::getline(std::cin, name);
    phoneBook.erase(std::remove_if(phoneBook.begin(), phoneBook.end(), [&](const Contact& c) {
        return c.name == name;
    }), phoneBook.end());

    showMenu();
}
void displayAll(){
    std::cout<< "Displaying all contacts...." << std::endl;
    for(int i = 0; i < phoneBook.size(); i++){
        std::cout<< "Name: " << phoneBook[i].name << std::endl;
        std::cout<< "Phone number: " << phoneBook[i].phoneNumber << std::endl;
        std::cout<< "Email: " << phoneBook[i].email << std::endl;
    }
    showMenu();
}