#include <iostream>

// 함수
// 무조건 함수 선언할때 메인 함수보다 앞에서 선언하여야 한다.
// 만약 메인 함수보다 밑에서 선언하고 싶을때 원형 함수를 선언하여 주면 된다.
// void test_1(){}함수를 선언하고 메인함수 위헤 void test_1();
// 매개변수가 있을때는 () 안에 매개변수까지 넣어주면됨. 
// void test_2(int num1, int num2, std::string str1);

// 1. 매개변수 O return X;
// 2. 매개변수 O return O;
// 3. 매개변수 X return O;
// 4. 매개변수 X return x;

// 매개변수 여부, return 여부

// 1. 매개변수 X return X
void test_1() {
    std::cout <<"매개변수 X return X 테스트 함수"<< std::endl;
}

// 2. 매개변수 O return X
void test_2(int num1, int num2, std::string str1) {
    std::cout<<"매개변수 O return X 테스트 함수"<< std::endl;
}     

// 3. 매개변수 O return O
std::string test_3(int num1, std::string str1){
    // 함수 본문
    return "str_type";
}

// 4. 매개변수 X return O
int test_4(){
    // 함수 본문
    return 20230324;
}

int main(){
    // 함수 선언 후 적용해보기.
    test_1();
    test_2(3, 2,"123");
    std::cout << test_3(3, "123") << std::endl;
    std::cout << test_4() << std::endl;

    // for문 예제
    for (int i = 0; i < 5; i++){
        std::cout << "안녕하세요1" << std::endl; 
    }

    // while문 예제
    int i = 0;
    while(i<5){
        std::cout << "안녕하세요2"<< std::endl; 
        i++;
    }

    // do while 문 예제
    int k = 0;
    do {
        std::cout << "안녕하세요3" << std::endl;
        k++;
    } while (k<5);
    std::cout << "end" << std::endl;


    
}

