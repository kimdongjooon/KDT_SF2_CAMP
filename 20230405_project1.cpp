#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

static int game_num = 0;

int main(){
    // 베스킨라빈스 31게임.
    // 규칙 1. 각자턴마다 상대방이 부른 숫자와 내가부른 숫자 개수가 같으며 안됨.
    while(1){
        // 사용자가 숫자 입력하는 기능
        int user_num;
        while(1){
            cout<<"숫자 개수를 입력해주세요. : ";
            cin >> user_num;
            if(0<=user_num&& user_num<=3){
                break;
            }else{
                cout<<"0~3사이의 숫자를 입력해주세요!"<<endl;
            }
        }
        
        cout<<"사용자가 부른 숫자!"<<endl;
        for(int i =0 ; i <user_num; i++){
            game_num++;
            cout<< game_num <<endl;
            if(game_num==31){
                break;
            }
        }
        if(game_num==31){
            cout<<"사용자 패배!"<<endl;
            break;
        }
        // 사용자가 부른숫자 - 랜덤하게 생성.
        srand(time(NULL));
        int computer_num;
        // 사용자와 컴퓨터가 부른 숫자 중복제외 규칙.
        while(1){
            computer_num = rand()%3+1;
            if(user_num!=computer_num){
                break;
            }
        }
        
        cout<<"컴퓨터가 입력한 숫자 개수: "<<computer_num<<endl;
        cout<<"컴퓨터가 부른 숫자! "<<endl;
        for(int j = 0 ; j < computer_num ; j++){
            game_num++;
            cout<<game_num<<endl;
            if(game_num==31){
                break;
            }
        }
        if(game_num==31){
            cout<<"사용자 승리!"<<endl;
            break;
        }


        
    }


}
