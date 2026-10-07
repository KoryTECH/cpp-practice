#include<iostream>
#include<string>
#include<sstream>
#include<vector>


void pig_it(std::string str){
    std::istringstream stream(str);
    std::vector<std::string> words;
    std::string word;
    while (stream>>word){
        words.push_back(word);
    }
    int length = words.size();
    for (int i = 0; i < length; i++){
        char suffix = words[i][0];
        words[i].erase(0,1);
        words[i].push_back(suffix);
        std::cout<<words[i]<<"ay ";
    }
}

int main(){
    pig_it("Pig Latin is cool");

}