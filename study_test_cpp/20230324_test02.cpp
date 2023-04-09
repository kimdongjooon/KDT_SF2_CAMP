#include <iostream>
#include <cmath>

//실습1 사칙연산 함수 만들기
// 두 개의 정수를 매개 변수로 받아 그 합을 리턴하는 add 함수
int add(int num1, int num2){
    return num1+num2;
}

// 두 개의 정수를 매개 변수로 받아 그 차을 리턴하는 minus 함수
int minus(int num1, int num2){
    return abs(num1-num2);
}

// 두 개의 정수를 매개 변수로 받아 그 곱을 리턴하는 multiple함수를 만드세요.
int multiple(int num1, int num2){
    return num1*num2;
}

// 두 개의 정수를 매개 변수로 받아 그 나눗셈을 리턴하는 divide 함수
float divide(int num1, int num2){
    return static_cast<float>(num1)/static_cast<float>(num2);
}

// main함수에서 위의 4개의 함수를 한번씩 호출하여 리턴된 값을 출력하세요.

// 두 개의 정수를 매개 변수로 받아 그 곱을 출력하는 multiple_cout함수를 만드세요.
void multiple_cout(int num1, int num2){
    std::cout << "입력한 두 수의 곱은 "<<num1*num2<<"입니다.";
}

// 하나의 정수를 매개변수로 받아서 그 수가 짝수 이면 "짝수", 홀수 이면"홀수"라고 출력하는 함수
void odd_even(int num){
    if (num/2 ==0){
        std::cout << "짝수";
    }
    else{
        std::cout << "홀수";
    }
}

// 세 개의 수를 매개변수로 받아서 그중 가장 큰 수를 반환하는 함수 작성
int max_int(int num1, int num2, int num3){
    if(num1>=num2){
        if(num1>=num3){
            return num1;
        }
        else{
            return num3;
        }
    }
    else{
        if(num2>=num3){
            return num2;
        }
        else{
            return num3;
        }
    }
}

int main(){
    //multiple 함수 
    int num1, num2;
    std::cout << "두 개의 정수를 입력하시오. ";
    std::cin >> num1 >> num2;
    std::cout <<"입력한 수의 합은 "<< add(num1,num2)<<std::endl;
    std::cout <<"입력한 수의 차은 "<< minus(num1,num2)<<std::endl;
    std::cout <<"입력한 수의 곱은 "<< multiple(num1,num2)<<std::endl;
    std::cout <<"입력한 수의 나눗셈은 "<< divide(num1,num2)<<std::endl;
    
    int num3;
    std::cout << "한 개의 정수를 입력하시오.";
    std::cin >> num3;
    odd_even(num3); 


    int num4, num5, num6;
    std::cout <<'\n'<< "세개의 변수를 입력하시오.";
    std::cin >> num4 >> num5 >> num6;
    std::cout << "가장 큰 수는 "<<max_int(num4,num5,num6)<<"입니다.";
}