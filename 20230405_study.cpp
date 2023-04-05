# include <iostream>
# include <cstdlib>
# include <ctime>


using namespace std;
int main(){
    // 난수 생성 하기. std::rand() 함수 사용.(0~32767) 값.
    // std::srand(1); // 시드값 지정 방법.
    // 현재 시간기준으로 시드값 지정하려고 함.
    std::srand(time(NULL));
    int randomnum = std::rand();
    cout << randomnum <<endl;

    // 랜덤 숫자는 크기 때문에 나머지 기능으로 원하는 숫자 랜덤하게 출력가능. 밑은 0~24까지 랜덤함 숫자를 반환됨.
    cout << randomnum % 25<<endl;


}