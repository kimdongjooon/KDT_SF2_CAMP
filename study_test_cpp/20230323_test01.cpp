#include <iostream>

int main(){
    std::string name;
    int age;

    std::cout << "이름을 입력하세요. ";
    std::cin >> name;
    
    std::cout << "나이를 입력하세요. ";
    std::cin >> age;

    std::cout << "안녕하세요! " << name <<"님("<<age<<")세 "; 
}