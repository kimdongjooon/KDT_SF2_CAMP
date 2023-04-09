#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;
int main(){
    cout<<"시작"<<endl;
    // 실습 1. 로또 추천 프로그램
    // 당첨 번호 벡터
    srand(time(NULL)); //for문안에 쓰면 이놈을 쓰면 같은값으로 고정됨. 초마다 바꾸기 때문에 1초안에 코드가 진행되서
    vector <int> lottonum;
    while(1){
        for (int i = 0; i<6;i++){
            
            lottonum.push_back(rand()%45+1);
            cout<<"1"<<endl;
        }

        for(int i = 0; i<lottonum.size();i++){
            for(int j = 0; j<lottonum.size();j++){
                if(i!=j && lottonum[i]==lottonum[j]){
                    lottonum.clear();
                    cout<<"22"<<endl;
                    break;
                }
            }
            if(lottonum.empty()){
                cout<<"333"<<endl;
                break;
            }
            
        }
        if(!lottonum.empty()){
            cout<<"4444"<<endl;
            break;
        }
    }
    cout<<"로또당첨 번호는 : ";
    for (int i =0;i<lottonum.size();i++){
        cout<<lottonum[i]<<" ";
    }
}