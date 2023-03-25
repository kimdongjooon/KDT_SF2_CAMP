#include <iostream>

int main(){
    // 자료형 변수 
    int a = 1;
    std::cout << "a 변수의 값은 " << a << std::endl;
    
    bool b = true;
    std::cout << "b 변수의 값은 "<<b << std::endl;
    
    char c = 'z';
    std::cout << "c 변수의 값은 "<< c << '\n';

    float d = 3.14;
    std::cout << "d 변수의 값은 "<< d << '\n';
    
    // 문자열 변수 단따옴표는 안됨.
    std::string str1$ = "안녕하세요" ;
    std::string str2 = " KDJ입니다." ;
    str2 = " 김동준입니다.";
    std::cout << str1$ + str2 << std::endl;

    // 변수 입력 받기
    int input_a;
    std::string input_b;

    std::cout << "입력받을 정수형 변수와 문자열 변수를 입력해주세요. ";
    std::cin >> input_a;
    std::cin >> input_b;

    std::cout << "입력받은 정수형 변수의 출력 값은 "<< input_a << std::endl;
    std::cout << "입력받은 문자열 변수의 출력 값은 "<< input_b << std::endl;

    
   int ab = 5;
   if (ab > 10){
    std::cout << "\n a는 10보다 큽니다.";
   } 
   else if (ab == 5){
    std::cout << "\n a는 5입니다.";
   }
   else {
    std::cout << "\n a는 10보다 작거나 5가 아닙니다.";
   }
}