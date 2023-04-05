#include "snack.h"

int price;
string name;
string company;


int Snack::count=0;
// virtual ~Snack() {}
Snack::Snack(){}

Snack::Snack(int p, string n, string c){
    this->price=p;
    this->name=n;
    this->company=c;
}

Snack::Snack(string name){
    this->name=name;
}

void Snack::printName(){
    cout<<"상품 이름 : "<<this->name<<endl;
}
void Snack::print_info(){
    cout<<"출력 잘못됨."<<endl;
}
