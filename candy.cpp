
#include "candy.h"


string flavor;
    
Candy::Candy(){}

Candy::Candy(string f,int p, string n, string c):Snack(p,n,c){
    this->flavor=f;
}

// Candy(string name):Snack(name){}

Candy::Candy(string flavor):Snack("캔디"){
    this->flavor=flavor;
    count++;
}

void Candy::candy_print(){
    cout << "캔디 다운캐스팅 완료"<<endl;
}

void Candy::print_info(){
    cout << this->flavor<<"맛 "<<this->name<<"입니다."<<endl;
}
    