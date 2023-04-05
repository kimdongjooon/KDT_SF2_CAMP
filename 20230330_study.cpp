#include <iostream>

using namespace std;

// 클래스 
class Cat{
    string name;
    int age;
    string kind;

    public: // 접근 제어자
        Cat(string name, int age, string kind){ // 생성자
            this->name = name;
            this->age = age;
            this->kind = kind;
            cout<< this->name<<"의 클래스를 생성하였습니다."<<endl;
        }

        void mew(){
            cout<<this->name<<"(이)가 야옹하고 웁니다."<<endl;
        }

        void eat(){
            cout <<this->name<<"가 먹이를 먹습니다."<<endl;
        }

        void info(){
            cout <<"고양이 이름은 "<<this->name<<" 나이는 "<<this->age<<"살이고 종은 "<<this->kind<<"입니다."<<endl;
        }
};

int main(){
    Cat cat_1("나비", 3, "페르시안");
    cat_1.info();
    cat_1.mew();
    cat_1.eat();    
}