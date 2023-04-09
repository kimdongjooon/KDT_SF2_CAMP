#include <iostream>

int main(){
    // 실습 1. 구구단 만들기
        // 5단만 출력
    int num;
    std::cout << "출력한 단을 하나 입력하세요.(1~9) : ";
    std::cin >> num;
    std::cout << num<<"단 출력\n";
    for (int i = 1;i < 10; i++){
        std::cout << num <<" * "<< i <<" = "<<num*i<<"\n";
    }
        // 1~9단 모두출력
    std::cout << "1~9단 출력\n";
    for (int a = 1; a<10; a++){
        std::cout << "---- "<<a<<"단 ----\n";
        for (int b = 1; b<10; b++){
            std::cout <<a<<" * "<<b<<" = "<<a*b<<"\n";
        }
    }

    // 실습2 1부터 n까지의 합 구하기
    std::cout << "1부터 n까지 합 구하기\n";
    std::cout << "숫자(양의 정수)를 입력하세요. : ";
    int num1;
    int num_sum=0;
    std::cin >> num1;
    for (int c =1; c<=num1;c++){
        num_sum += c;
    }
    std::cout << "1부터 "<<num1<<"까지의 합은 : "<<num_sum<<"\n";

    // 실습3 while문 사용해보기
    // 앞에서 진행한 실습 1,2를 while 문으로 작성해보기
        // 실습 1 while 문
    int num2;
    std::cout << "출력한 단을 하나 입력하세요.(1~9) : ";
    std::cin >> num2;
    std::cout << num2<<"단 출력\n";
    int d=1;
    while(1){
        std::cout << num2 <<" * "<< d <<" = "<<num2*d<<"\n";
        d++;
        if(d == 9){break;}
    }
    
        // 1~9단 모두출력
    std::cout << "1~9단 출력\n";
    int e=1;
    int f=1;
    while(1){
        if (e==10){break;}
        std::cout << "---- "<<e<<"단 ----\n";
        while(1){
            if (f==10){
                f = 1;
                break;
            }
            std::cout <<e<<" * "<<f<<" = "<<e*f<<"\n";
            f++;
            
        }
        e++;
        
    }

    // 실습4 사용자가 입력한 숫자 더하기
    // 사용자가 입력한 숫자들을 계속 더하는 프로그램 만들기
    //      사용자는 더하고 싶은 숫자를 횟수 제한 없이 입력가능
    //      단, 0을 입력하면 종료
    std::cout << "사용자가 입력한 숫자 더하기\n\n";
    int num_sum1=0;
    while(1){
        std::cout << "숫자를 입력하세요. (0 : exit) : ";
        int input_num;
        std::cin >>input_num;
        num_sum1+=input_num;
        if(input_num == 0){
            std::cout << "사용자가 입력한 수의 합은 : "<<num_sum1<<'\n';
            break;
            }

    }

    // 실습(번외) 입력한 숫자 만큼 별 찍기
    std::cout << "input : ";
    int star_num;
    std::cin >> star_num;
    std::cout << "output : \n";
    for (int g=1;g<=star_num;g++){
        for (int h=1; h<=g;h++){
            std::cout <<"*";
        }
        std::cout <<'\n';
    }
}   