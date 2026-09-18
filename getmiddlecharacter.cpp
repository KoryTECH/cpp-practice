#include <iostream>
#include <string>

std::string get_middle(std::string input);

int main(){
  get_middle("test");
  get_middle("testing");
}

std::string get_middle(std::string input) {
    int len = input.length(); 
    
    if (len % 2 == 0) {
        // return input.substr((len / 2) - 1, 2);
        std::cout << input.substr((len / 2) - 1, 2) << std::endl;
    } 
    else {
        // return input.substr(len / 2, 1);
        std::cout << input.substr(len / 2, 1) << std::endl;
    }
}