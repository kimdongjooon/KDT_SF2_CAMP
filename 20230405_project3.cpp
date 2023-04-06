#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;


int main(){
    // 랜덤 숫자 맞추기
    // 컴퓨터 랜덤 숫자 생성(1~25) 중복x
    vector <int> com_lst;
    srand(time(NULL));
    while(1){
        int break_fun=0;
        for (int i =0;i<6;i++){
            int num = rand()%25+1;
            com_lst.push_back(num);
        }
        //중복 검사
        for(int i =0; i<com_lst.size();i++){
           for(int j = 0; j<com_lst.size();j++){
                if(i!=j && com_lst[i]==com_lst[j]){
                    break_fun=1;
                }
           } 
        }
        if(break_fun==1){
            com_lst.clear();
        }else{
            break;
        }
    }

    
    // 사용자 원하는 숫자(1~25) 입력 중복x
    vector <int> user_lst;
    int rank_num = 1;
    while(1){
        cout<<rank_num<<"번째 숫자를 입력하세요. : ";
        int num;
        cin>>num;
        if(user_lst.empty()){
            // cout<<"1"<<endl;
            user_lst.push_back(num);
            rank_num++;
        }else{
            // 중복성 검사, 중복되면 다시 입력 아니면 추가.
            int dup_count=0;
            for(int j = 0 ; j<user_lst.size();j++){
                // cout<<"2 : j = "<<j<<endl;
                if(user_lst[j]==num){
                    cout<<j <<" -- "<<user_lst[j] <<" - "<<num; 
                    cout<<"이미 입력된 숫자입니다. 다시 입력해주세요. "<<endl;
                    dup_count=1;
                    break;
                }
            }
            // 중복이 안되면 추가
            if(dup_count==0){
                user_lst.push_back(num);
                rank_num++;
            }

            // 6개가 다 추가되면 종료
            if(rank_num==7){
                break;
            }
        }
        
    }
    // 사용자가 입력한 숫자
    cout<<"사용자 번호 : ";
    for (int i = 0 ; i < user_lst.size();i++){
        cout<<user_lst[i]<<" ";
    }
    cout<<endl;

    // 맞춘개수 결과!
    int correct_num=0;
    for (int i =0; i<com_lst.size();i++){
        if(com_lst[i]==user_lst[i]){
            correct_num++;
        }
    }

    cout<<"----------------------------"<<endl;
    cout<<"당첨번호 공개"<<endl;
    // 컴퓨터가 생성한 숫자
    for(int i =0; i<com_lst.size();i++){
        cout<<com_lst[i]<<" ";
    }
    cout<<endl;
    cout<<"결과는 1~7등까지 나옵니다."<<endl;
    cout<<"결과 : "<<7-correct_num<<"등 입니다 !"<<endl;

}