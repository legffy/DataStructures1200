#include <iostream>
#include <string>
#include <cctype>
int myAtoi(std::string s){
    int i = s.size()-1;
    long int currdig = 1;
    long int num = 0;
    char*  sCStyle []= s.c_str();
    while(i>=0){
        if(!::isdigit()){
            std::cout << "not a digit";
        }
        num = num; 
        i--;
    }
    return num;
}
int main(int argc, char*  argv[]){
    std::cout << "hello world" << std::endl;
    std::cout << myAtoi("   1234");
}