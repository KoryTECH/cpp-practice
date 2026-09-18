#include <iostream>
using namespace std;

int add(int num1, int num2);
int subtract(int num1, int num2);
int multiply(int num1, int num2);
float divide(int num1, int num2);

int main(){
    int firstNum, secondNum;
    float answer;
    char operand;
    cout<<"This is a simple calculator"<< endl;
    cout<<"Enter First Number:"<< endl;
    cin>>firstNum;
    cout<<"Enter Second Number:"<< endl;
    cin>>secondNum;
    cout<<"Enter Operator (+ _ / *):"<< endl;
    cin>>operand;

    if(operand == '+'){
        answer = add(firstNum, secondNum);
    }
    else if(operand == '-'){
        answer = subtract(firstNum, secondNum);
    }
    else if(operand == '*'){
        answer = multiply(firstNum, secondNum);
    }
    else if(operand == '/'){
        answer = divide(firstNum, secondNum);
    }
    cout <<"Answer is: "<< answer << endl;
    return 0;
}

int add(int num1, int num2){
    return num1 + num2;
}
int subtract(int num1, int num2){
    return num1 - num2;
}
int multiply(int num1, int num2){
    return num1 * num2;
}
float divide(int num1, int num2){
    if(num2 ==0 ){
        cout<<"Error: Division by zero is not allowed."<< endl;
        return 0; // Return 0 or you can choose to handle it differently
    }
    else {
        return (float) num1 / num2;
    }
}