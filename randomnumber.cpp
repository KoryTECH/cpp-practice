#include <iostream>
#include <random> // Required header


double randomNumber();
int choice; 
int computerNumber;
void mainGame();


int main() {
    computerNumber = (int) randomNumber();
    mainGame();
    return 0;
}

void mainGame(){
    std::cout<<"Welcome to the challenge of guessing a random number against me"<< std::endl;
    std::cout<<"\t\t Choose a number between 1 -10"<< std::endl;
    
    std::cin >> choice;
    if(choice < 1 || choice > 10){
        std::cout<<"The number must be between 1-10. Please try again"<< std::endl;
        mainGame();
    }
    else if(choice != computerNumber ){
       std::cout<<"Wrong you've have failed againt me" <<std::endl;
        mainGame();
    }
    else{
        std::cout<<"You have won against me. You have earned my respect"<< std::endl;
    }
}

double randomNumber(){
    // 1. Obtain a random seed from the hardware
    std::random_device rd;
    
    // 2. Initialize the standard Mersenne Twister engine with the seed
    std::mt19937 gen(rd());
    
    // 3. Define the distribution range [0.0, 1.0)
    std::uniform_real_distribution<double> dis(1.0, 10.0);
    
    // 4. Generate the random number
    double randomValue = dis(gen);
    
    return randomValue;
}