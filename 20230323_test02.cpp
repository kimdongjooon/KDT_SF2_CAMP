
#include <iostream>

int main(){
    // 나이 판별기
    std::cout << "-------실습1-------\n";
    int age;
    std::cout << "나이를 입력하세요. ";
    std::cin >> age;

    if (age < 20){
        if (age >= 17){std::cout << "고등학생";}
        else if (age >=14){std::cout << "중학생";}
        else if (age >=8){std::cout << "초등학생";}
        else if (age >=1){std::cout << "유아";}
    }
    else if (age >= 200){std::cout << "나이가 너무 많습니다..!";}
    else if (age >=20){std::cout <<"성인";}
    else {std::cout << "나이를 다시 입력해주세요.";
    }


    // 성별 판별기
    std::cout << "\n-------실습2-------";
    std::string name;
    std::cout << "\n이름을 입력하세요. ";
    std::cin >> name;

    if (name == "홍길동"){std::cout << "남자";}
    else if (name == "성춘향"){std::cout << "여자";}
    else {std::cout << "모르겠어요.";}


    // 삼항 연산자
    std::cout << "\n-------실습3-------";
    int number ;
    std::cout << "\n숫자를 입력해주세요.";
    std::cin >> number;

    number%5 == 0 ? std::cout << number <<"는 5의 배수입니다.":std::cout << number<<"는 5의 배수가 아닙니다.";


    // 조건문 총합
    std::cout << "\n-------실습4-------";
    int num1, num2;
    std::cout << "\n연산할 정수 두 개를 입력해 주세요. ";
    std::cin >> num1;
    std::cin >> num2;
    std::string cal;
    std::cout << "연산자를 입력해주세요. (+ - * /) ";
    std::cin >> cal;

    if (cal=="/"){std::cout <<"**** 연산결과 ---> 몫 : "<<num1/num2<<" 나머지는 "<<num1%num2<<"입니다.";}
    else if (cal=="-"){std::cout <<"**** 연산결과 ---> "<<num1-num2;}
    else if (cal=="*"){std::cout <<"**** 연산결과 ---> "<<num1*num2;}
    else if (cal=="+"){std::cout <<"**** 연산결과 ---> "<<num1+num2;}
    else {std::cout <<"**** 연산결과 ---> 오류입니다 연사자를 다시 입력해주세요";}
}