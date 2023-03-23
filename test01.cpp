#include <iostream>

int main(){

    // std::cout << "Hello world!" ;

    // 자료형 변수 
    int a = 1;
    std::cout << "숫자는 " ;
    std::cout << a ;

    bool b = true;
    std::cout << '\n';
    std::cout << b ;

    char c = 'z';
    std::cout << '\n';
    std::cout << c ;
    std::cout << '\n';
    

    // 문자열 변수 단따옴표는 안됨.
    std::string str1$ = "안녕하세요" ;
    std::string str2 = " KDJ입니다." ;
    str2 = " 김동준입니다.";
    std::cout << str1$ + str2 ;

    // 변수 입력 받기
    /*int input_a;
    std::string input_b;

    std::cin >> input_a;
    std::cin >> input_b;

    std::cout << input_a << input_b;
    */
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