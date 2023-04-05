#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;
static int game_num = 0;

class User{
    int user_num;

    public:
        User(int n){
            this->user_num=n;
        }
        void input_num(){
            std::cout<<"사용자가 부른 숫자!"<<endl;
            for(int i =0 ; i <user_num; i++){
                game_num++;
                std::cout<< game_num <<endl;
                if(game_num==31){
                    break;
                }
            }
        }
        
};

class Computer{
    int computer_num;
    public:
        Computer(int n){
            this->computer_num=n;
        }

        void input_num(){
            std::cout<<"컴퓨터가 입력한 숫자 개수: "<<computer_num<<endl;
            std::cout<<"컴퓨터가 부른 숫자! "<<endl;
            for(int j = 0 ; j < computer_num ; j++){
                game_num++;
                std::cout<<game_num<<endl;
                if(game_num==31){
                    break;
                }
            }
        }
        
};

//



int main(){
    // 베스킨라빈스 31게임.
    // 규칙 1. 각자턴마다 상대방이 부른 숫자와 내가부른 숫자 개수가 같으며 안됨.
    
    std::cout <<"게임 선 지정 ( 0 : 사용자, 1 : 컴퓨터 )";
    int start_num;
    cin >> start_num;
    while(1){
        // 사용자와 컴퓨터 우선 순위 지정
        

        // 사용자가 숫자 입력하는 기능
        int user_num;
        while(1){
            std::cout<<"숫자 개수를 입력해주세요. : ";
            cin >> user_num;
            if(0<user_num && user_num<=3){
                break;
            }else{
                std::cout<<"1~3사이의 숫자를 입력해주세요!"<<endl;
            }
        }
        // 사용자 입력 결과
        User user(user_num);
        user.input_num();

        if(game_num==31){
            std::cout<<"사용자 패배!"<<endl;
            break;
        }

        // 컴퓨터가 부른숫자 - 랜덤하게 생성.
        srand(time(NULL));
        int computer_num;
        // 사용자와 컴퓨터가 부른 숫자 중복제외 규칙.
        while(1){
            computer_num = rand()%3+1;
            if(user_num!=computer_num){
                break;
            }
        }
        
        // 컴퓨터 입력 결과
        Computer computer(computer_num);
        computer.input_num();
        if(game_num==31){
            std::cout<<"사용자 승리!"<<endl;
            break;
        }


        
    }


}
