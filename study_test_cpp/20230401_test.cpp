#include <iostream>
#include <vector>

using namespace std;

// class Shape2{
// public:
//     // 가상 함수 소멸자
//     virtual ~Shape2() {} //warning: delete called on 'Shape2' that is abstract but has non-virtual destructor [-Wdelete-abstract-non-virtual-dtor]에러코드 해결
//     // 추상 메소드 
//     virtual void draw() = 0;
// };

// class Circle : public Shape2{
// public:
//     void draw(){cout <<"원 입니다."<<endl;}
// };

// class Rect1 : public Shape2{
// public:
//     void draw(){cout <<"사각형 입니다."<<endl;}
// };

// class Tria : public Shape2{
// public:
//     void draw(){cout <<"삼각형 입니다."<<endl;}
// };

/*class Snack{
    protected:
        int price;
        string name;
        string company;
    
    public:
        static int count;
        // virtual ~Snack() {}
        Snack(){}

        Snack(int p, string n, string c){
            this->price=p;
            this->name=n;
            this->company=c;
        }

        Snack(string name){
            this->name=name;
        }

        void printName(){
            cout<<"상품 이름 : "<<this->name<<endl;
        }
        virtual void print_info(){
            cout<<"출력 잘못됨."<<endl;
        }
        

};

class Candy:public Snack{
    string flavor;
    public:
        Candy(){}
        
        Candy(string f,int p, string n, string c):Snack(p,n,c){
            this->flavor=f;
        }

        // Candy(string name):Snack(name){}

        Candy(string flavor):Snack("캔디"){
            this->flavor=flavor;
            count++;
        }

        void candy_print(){
            cout << "캔디 다운캐스팅 완료"<<endl;
        }

        void print_info(){
            cout << this->flavor<<"맛 "<<this->name<<"입니다."<<endl;
        }
    

};

class Chocolate:public Snack{
    string shape;
    public:
        Chocolate(){}

        Chocolate(string s,int p, string n, string c):Snack(p,n,c){
            this->shape=s;
        }
        // Chocolate(string name):Snack(name){}

        Chocolate(string shape):Snack("초콜릿"){
            this->shape=shape;
            count++;
        }

        void Chocolate_print(){
            cout<<"초콜릿 다운캐스팅 완료"<<endl;
        }

        void print_info(){
            cout << this->shape<<"모양 "<<this->name<<"입니다."<<endl;;
        }
};
*/
#include "snack.h"
#include "candy.h"
#include "chocolate.h"


int main(){
    // Circle C= Circle();
    // Rect R= Rect();
    // Tria T= Tria();
    // C.draw();
    // R.draw();
    // T.draw();

    // // 업캐스팅
    // Shape2 *C1 = new Circle();
    // Shape2 *R1 = new Rect1();
    // Shape2 *T1 = new Tria();
    // // Shape2 *snackarr = {new Circle(), new Rect1(), new Tria()};
    // C1->draw();
    // delete C1;
    // R1->draw();
    // delete R1;
    // T1->draw();
    // delete T1;


    

    // Snack snackBasket[4]={Candy("청포도캔디"),Candy("텐텐"),Chocolate("허쉬"),Chocolate("빼레로쉐")};
    // Snack* snackBasket1[4]={new Candy("청포도맛",1200,"캔디","A사"),new Candy("딸기맛",1200,"캔디","C사"),new Chocolate("둥근",1500 ,"빼레로쉐","B사"), new Chocolate("네모",1500 ,"가나 초콜릿","D사")};
    // for (int i =0;i<sizeof(snackBasket1)/sizeof(snackBasket1[i]);i++){
    //     snackBasket1[i]->print_info();
         
    // }



    // // 업캐스팅
    // Candy c1("사탕1"),c2("사탕2");
    // Chocolate ch1("초콜릿1"),ch2("초콜릿2");
    // Snack *snakbasketarr[] = {&c1, &c2, &ch1, &ch2};
    // Snack *dynamic_test_snack = new Chocolate(); // 다이나믹캐스트를 이용시에 가상함수 소멸자가 무조건 필요함 없으면 에러뜸.

    // for (int i = 0; i < sizeof(snakbasketarr)/sizeof(snakbasketarr[i]);i++){
    //     snakbasketarr[i]->printName();
    // }

    // // 다운캐스팅
    // Candy* d_candy =(Candy*)snakbasketarr[0];
    // Chocolate* d_cho = dynamic_cast<Chocolate*>(dynamic_test_snack);
    // d_candy->candy_print();
    // d_cho->Chocolate_print();
    // delete dynamic_test_snack;

    //20230402 static 실습
    vector <Snack*> basketarr;
    while(1){
        cout<<"과자 바구니에 추가할 간식을 고르시오. (1: 사탕, 2: 초콜릿, 0: 종료) : ";
        int select;
        int exit = 0;
        
        cin >> select;
        switch (select){
            case 1:{
                cout<<"맛을 입력하세요 : ";
                string flavr;
                cin >> flavr;
                Candy* can =new Candy(flavr);
                basketarr.push_back(can);
                
                break;
            }
                
            case 2:{
                cout<<"모양을 입력하세요 : ";
                string shape;
                cin >> shape;
                Chocolate* cho = new Chocolate(shape);
                basketarr.push_back(cho);
                
                break;
            }
                
            case 0:{
                exit=1;
                cout<<"과자 바구니에 담긴 간식의 개수는 "<<Snack::count<<"개 입니다."<<endl;
                cout<<"과자 바구니에 담긴 간식 확인하기!"<<endl;
                for(int i =0;i<basketarr.size();i++){
                    basketarr[i]->print_info();
                    
                }
                break;
            }
            default:{
                cout<<"0~2 사이의 숫자를 입력하세요."<<endl;
            }

        
                

        }
        if(exit==1){
            break;
        }
        
        
    }

    

}