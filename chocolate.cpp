
#include "chocolate.h"


string shape;
    
Chocolate::Chocolate(){}

Chocolate::Chocolate(string s,int p, string n, string c):Snack(p,n,c){
    this->shape=s;
}
// Chocolate(string name):Snack(name){}

Chocolate::Chocolate(string shape):Snack("초콜릿"){
    this->shape=shape;
    count++;
}

void Chocolate::Chocolate_print(){
    cout<<"초콜릿 다운캐스팅 완료"<<endl;
}

void Chocolate::print_info(){
    cout << this->shape<<"모양 "<<this->name<<"입니다."<<endl;;
}
