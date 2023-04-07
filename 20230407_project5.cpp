#include <iostream>
#include <cstdlib>
#include <vector>
#include <sstream>


using namespace std;

// 야구 게임 만들기
// 사용자는 1~9까지 숫자를 3개 뽑고 컴퓨터가 1~9사이 랜덤으로 뽑은 숫자의 순서와 숫자를 맞추는 게임
// 규칙 1. 사용자가 맞출때 까지 게임을 진행하도록 while문을 사용한다.
// 규칙 2. 순서와 숫자가 맞으면 strike, 숫자만 맞으면 ball, 아무것도 못맞추면 노카운트


int main(){
    // 몇개의 숫자로 게임을 할지 입력받기
    int n;
    while(1){   
        cout<<"몇개의 숫자로 게임을 진행하시겠습니까? ( 1 ~ 9 ) : ";
        cin >> n;
        if(n >=1 && n <=9){
            cout<<"컴퓨터 무작위 숫자 입력 완료!"<<endl;
            break;
        }else{
            cout<<"1 ~ 9 사이 숫자를 입력해주세요! "<<endl;
        }
    }

    // 컴퓨터가 뽑은 무작위 숫자를 저장할 벡터 선언.
    vector <int> com_num_v;

    // 컴퓨터가 무작위로 숫자를 뽑아야하기때문에 <cstdlib> 헤더를 가져와서 rand()메소드 사용.
    srand(time(NULL)); // 시드 값을 주고 실행할때마다 무작위 값 다르게 출력 하도록 설정.
    // 중복 제거.
    while(1){
        int dul_count=0;
        int random_num = rand()%9+1;
        for (int i = 0 ; i < com_num_v.size() ;i++){
            if(com_num_v[i]==random_num){
                dul_count=1;
            }
        }
        if(dul_count==0){
            com_num_v.push_back(rand()%9+1); // 입력한 숫자의 개수만큼 무작위 숫자 벡터에 저장.
        }
        if(com_num_v.size()==n){
            break;
        }
    }
    
    // 정답 숫자
    // for(int answer : com_num_v){
    //     cout << answer << ' ';
    // }
    // cout<<endl;
    
    // 진행한 게임 횟수 카운트
    int game_count=0;
    // 규칙 1. 진행
    while(1){
        int game_break=0;
        cin.ignore();
        while(1){
            // 사용자가 입력한 숫자를 저장할 벡터 선언
            vector <int> user_num_v;

            cout << endl<< "1 ~ 9 사이의 "<<n<<"개의 숫자를 입력해주세요. (종료 : q) : ";
            
            string user_num;
            getline(cin, user_num);
            if(user_num == "q"){
                cout<<"게임종료"<<endl;
                game_break=1;
                break;
            }

            // 입력된 숫자 분할.
            int tmp_num;
            stringstream ss;
            ss.str(user_num);
            while(ss>>tmp_num){
                user_num_v.push_back(tmp_num);
            }
            cout <<"입력하신 숫자는 ";
            for (int num:user_num_v){
                cout << num << " ";
            }
            cout<<endl;

            //사용자가 입력한 개수가 설정한 숫자의 개수보다 적거나 많으면 다시실행.
            if(user_num_v.size()!=n){
                cout<<"입력하신 숫자의 개수가 "<<n<<"개가 아닙니다. 다시입력해주세요."<<endl;
                break;
            }
            //  중복이면 다시실행.
            int break_num2=0;
            for(int i = 0 ; i < user_num_v.size();i++){
                for(int j = 0 ; j < user_num_v.size(); j++){
                    if( i!=j && user_num_v[i]==user_num_v[j]){
                        break_num2=1;
                        break;
                    }
                }
                if(break_num2==1){
                    break;
                }
            }
            if(break_num2==1){
                cout<<"중복된 숫자가 있습니다. 다시입력해주세요. "<<endl;
                break;
            }

            //  입력된 숫자가 1~9사이가아니면 다시실행, 
            for (int num : user_num_v){
                if(num==1 || num==2 || num==3 || num==4 || num==5 || num==6 || num==7 || num==8 || num==9){}
                else{ 
                    cout<<"입력하신 숫자 중 1~9사이의 숫자가 아닌 숫자가 있습니다. 다시입력해주세요."<<endl;
                    break;
                }
            }

            // 정상입력 완료.
            // 규칙 2. 순서와 숫자가 맞으면 strike, 숫자만 맞으면 ball, 아무것도 못맞추면 노카운트 구현.
            
            int strike = 0;
            int ball = 0;
            for(int i = 0;i<com_num_v.size();i++){
                // 스트라이크 카운트 기능 구현
                if(com_num_v[i]==user_num_v[i]){
                    strike++;
                }
                // ball 기능 구현
                for(int j = 0 ; j <user_num_v.size();j++){
                    if(i!=j && com_num_v[i]==user_num_v[j]){
                        ball++;
                    }
                }
            }
            // 여기까지 왔으면 게임한번 진행한 상태이므로 카운팅
            cout<<"Strike : "<<strike<<"     Ball : "<<ball<<endl; 
            game_count++;

            // 다맞췄으면 종료
            if(strike == n){
                cout<< "게임승리!! "<<endl<<"게임진행 횟수는"<<game_count<<"입니다."<<endl;
                game_break=1;
                break;
            } 
        }
        if (game_break ==1){
            break;
        }
    }
}