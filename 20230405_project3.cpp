#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int main(){
    // 랜덤 숫자 맞추기
    // 컴퓨터 랜덤 숫자 생성(1~25) 중복x
    vector <int> com_lst;
    srand(time(NULL));
    for (int i =0;i<6;i++){
        int num = rand()%25+1;
        cout<<num<<" ";
        com_lst.push_back(num);
    }


    // 사용자 원하는 숫자(1~25) 입력 중복x
}