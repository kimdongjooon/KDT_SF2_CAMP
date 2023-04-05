#include <iostream>
#include <vector>

using namespace std;

// //실습 1,2 :  클래스 사용해보기
// class Rectangle {
//     // 필드
//     double width;
//     double height;

//     public: // 접근 제어자
//         // 생성자
//         Rectangle(){}

//         Rectangle(double width, double height){
//             this->width = width;
//             this->height = height;
//         }
        
//         // 메소드
//         void area(){
//             cout <<"넓이는 : "<<this->width*this->height<<endl;
//         }

//         // getter 함수
//         double getWidth(){
//             return this->width;
//         }

//         double getHeight(){
//             return this->height;
//         }

//         // setter 함수
//         void setWidth(double w){
//             this->width = w;
//         }

//         void setHeight(double h){
//             this->height = h;
//         }

// };

// 실습 3. 게임 캐릭터 생성하기
class Character {
    int hp = 100;
    int level = 0;

    public:
        string name;    
        int item_num = 0;
        
        int attack_damage=0;

        Character (string name){
            this->name = name;
            cout<<name<<" 캐릭터가 생성 되었습니다."<<endl; 
        }

        void C_name(){
            string name;
            cout<<"새 이름을 입력해주세요: ";
            cin >> name;
            this->name = name;
            cout<<"new name : "<<this->name<< endl;
        }

        void level_up(){
            cout<<"level up!!"<<endl;
            this->level++;
            cout<<"현재 레벨 : "<<this->level<<endl;
        }

        void get_item(){
            cout<<"아이템을 얻었습니다!"<<endl;
            this->item_num++;
            cout<<"현재 아이템 개수 : "<<this->item_num<<endl;
        }

        void use_item(){
            if (this->item_num<=0){
                cout <<"사용가능한 아이템이 없습니다!!"<<endl;
            }else{
                cout<<"아이템을 사용했습니다!"<<endl;
            this->item_num--;
            cout<<"현재 아이템 개수 : "<<this->item_num<<endl;
            }
            
        }

        void status(){
            cout<<"이름 : "<<this->name<<endl;
            cout<<"레벨 : "<<this->level<<endl;
            cout<<"현재 아이템 개수 : "<<this->item_num<<endl;
            cout<<"현재 체력 : " <<this->hp<<endl;

        }

        int attack(Character C){
            if (this->item_num<=0){
                cout <<"사용가능한 아이템이 없어 공격을 못합니다!"<<endl;
            }else{
                int damage = 10;
                cout<<"아이템을 사용하여 "<<damage<<"의 데미지를 주었습니다."<<endl;
                this->item_num--;
                cout<<"현재 아이템 개수 : "<<this->item_num<<endl;
                int tmp = C.hp - damage;
                C.hp=tmp;
                cout<<"공격당한 "<<C.name<<"의 현재 hp는 "<<C.hp<<"입니다."<<endl;
                return C.hp;
            }
            
        }

        string getName(){
            return this->name;
        }

        int setHp(int h){
            this->hp = h;
        }
    
};

int main(){
    // // 실습 1. 클래스 사용해보기
    // cout<<"사각형의 가로와 세로 길이를 입력해주세요. (띄어쓰기로 구분) ";
    // double w,h;
    // cin >> w >> h;
    
    // //실습 1
    // Rectangle Rec(w,h); 
    // Rec.area();

    // // 실습 2
    // Rectangle Rec1;
    // Rec1.setWidth(w);
    // Rec1.setHeight(h);
    // Rec1.area();


    // 실습 3
    cout<<"두개의 유저 이름을 입력해주세요 : ";
    string name1,name2;
    cin >> name1 >> name2;
    Character C1(name1);
    Character C2(name2);

    vector <Character> cv;
    vector <Character> cv_tmp;
    cv.push_back(C1);
    cv.push_back(C2);
    cv_tmp.push_back(C1);
    cv_tmp.push_back(C2);

    

    // C1.game_start();
    
    // C1.attack(C2);

    
    cout << "게임을 실행할 유저의 이름을 입력해주세요. "<<endl;
    string start_user_name;
    cin >> start_user_name;
    for(int i = 0;i<cv.size();i++){
        if (cv[i].getName() == start_user_name){ // 클래스안 변수 자체를 가져올수없음 getname함수 쓰기
            while(1){
                int num;
                cout << "어떤 동작을 실행하시겠습니까? (0 : 종료) ";
                cin >> num;
                cin.ignore();
                if(num == 0){
                    cout<<"게임을 종료합니다. "<<endl;
                    for (int k = 0 ; k<cv.size(); k++){
                    cv_tmp[k].status();
                    }
                    break;
                }

                switch (num){
                    case 1 : // 이름 변경
                        cv_tmp[i].C_name();
                        break;
                    case 2 : // 레벨업
                        cv_tmp[i].level_up();
                        break;
                    case 3 : // 아이템 줍기
                        cv_tmp[i].get_item();
                        break;
                    case 4 : // 아이템 사용
                        cv_tmp[i].use_item();
                        break;
                    case 5 : // 사용자 상태
                        cv_tmp[i].status();
                        break;
                    case 6 : {// 사용자 공격하기
                        cout<<"공격할 유저 이름을 입력하세요. : ";
                        string ak_name;
                        cin >> ak_name;
                        int count=0;
                        for(int j = 0; j<cv.size();j++){                            
                            if(cv_tmp[j].getName()==ak_name){
                                cv_tmp[j].setHp(cv_tmp[i].attack(cv_tmp[j]));
                                count++;
                            }
                        }
                        if (count==0){
                            cout << "해당 유저가 없습니다."<<endl;
                        }
                        break;
                    }
                    default:
                        continue;

                }

            }
        }
    }

    

    


    
    

}