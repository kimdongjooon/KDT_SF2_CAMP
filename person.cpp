#include "person.h"

Person::Person(){
    cnt++;
}

Person::Person(string name){
    this->name=name;
}
// 사람 카운트세기
int Person::cnt=0;
int Person::ver=0;

void Person::sleep(){
    name="aa";
    ver=3;
    cout<<"sleep method"<<endl;
}

void Person::static_method(){
    ver = 4;
    // name = "12"; 에러뜸 static 메소드는 static변수로만 접근가능 (일반 멤버 접근 불가)
    cout <<"static method"<<endl;
}