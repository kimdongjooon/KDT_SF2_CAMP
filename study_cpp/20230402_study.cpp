#include <iostream>

using namespace std;

#include "person.h"
//  

#include "student.h"




// class Person{
// public:
//     Person(){
//         cnt++;
//     }
//     // 사람 카운트세기
//     static int cnt;
//     static int ver;
//     string name;    
//     int id;
//     void sleep(){
//         name="aa";
//         ver=3;
//         cout<<"sleep method"<<endl;
//     }
    
//     static void static_method(){
//         ver = 4;
//         // name = "12"; 에러뜸 static 메소드는 static변수로만 접근가능 (일반 멤버 접근 불가)
//         cout <<"static method"<<endl;
//     }
// };

// static변수는 무조건 초기화 시켜줘야됨.!!
// int Person::ver = 0;
// int Person::cnt = 0;

int main(){
    // // static 멤버로 초기화시킨 변수 및 메소드는 클래스 변수로 직접 사용가능함.
    // Person::ver=5;
    // Person::static_method();
    // // Person::name="알파"; name이 static변수가 아니면 에러.

    Person p = Person();
    p.name="aaa";
    p.ver=5;
    Person p1 = Person();
    p1.name="bbb";
    p1.ver=7;
    p1.sleep();
    p1.static_method();
    cout <<p.name<<" "<<p1.name<<endl;
    cout <<p.ver<<" "<<p1.ver<<endl;
    cout <<"인원 총합은"<<Person::cnt<<endl;

    Student s = Student("가나다");
}