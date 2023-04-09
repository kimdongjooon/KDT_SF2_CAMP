#include <iostream>


using namespace std;
// 프로젝트 6. 계산기 만들기.
// 클래스 상속, 정적 멤버, 업 캐스팅, 가상 함수를 사용하여 사칙연산을 수행하는 계산기 만들기.
// 구현 예정 기능 1. 도출된 결과 후속 계산하는 기능, 정적 멤버 사용.
// 구현 예정 기능 2. 도출된 결과를 초기화 하고 새로 시작하는 기능.
// 구현 예정 기능 3. 계산기를 종료하는 기능.

// 가상함수를 선언하고 각 사칙연산의 클래스 선언 및 계산하는 함수 구현

class Calculator{
    
    public:
        static double result;
        virtual void cal(){};

};

class Add: public Calculator{
    int a;
    int b;
    public:
        Add(int a, int b):Calculator(){
            this->a=a;
            this->b=b;
        }

        void cal(){
            this->result= a + b;
            cout<<"--------------------------------------------------"<<endl;
            cout<<"결과 : "<< this->result<<endl;
            cout<<"--------------------------------------------------"<<endl;
        }

};

class Minus: public Calculator{
    public:
        Minus(int a, int b):Calculator(){
            cal(a,b);
        }

        void cal(int a, int b){
            this->result= a - b;
            cout<<"--------------------------------------------------"<<endl;
            cout<<"결과 : "<< this->result<<endl;
            cout<<"--------------------------------------------------"<<endl;
        }
};
class Divide: public Calculator{
    public:
        Divide(int a, int b):Calculator(){
            cal(a,b);
        }

        void cal(int a, int b){
            this->result= (double)a / (double)b;
            cout<<"--------------------------------------------------"<<endl;
            cout<<"결과 : "<< this->result<<endl;
            cout<<"--------------------------------------------------"<<endl;
        }

};
class Multi: public Calculator{
    public:
        Multi(int a, int b):Calculator(){
            cal(a,b);
        }

        void cal(int a, int b){
            this->result= (double)a * (double)b;
            cout<<"--------------------------------------------------"<<endl;
            cout<<"결과 : "<< this->result<<endl;
            cout<<"--------------------------------------------------"<<endl;
        }

};

void Operator_func(char o, int n1, int n2){
    switch (o){
        case '+':{
            Calculator* cal = new Add(n1,n2);
            cal->cal();
            delete cal;
            break;
        }
        case '-':{
            Calculator* cal = new Minus(n1,n2);
            delete cal;
            break;
        }
        case '/':{
            Calculator* cal = new Divide(n1,n2);
            delete cal;
            break;
        }
        case '*':{
            Calculator* cal = new Multi(n1,n2);
            delete cal;
            break;
        }
        default:
            cout<<"+ , - , / , * 연산자를 입력해주세요."<<endl;
            break;
    }
}

double Calculator::result=0;

int main(){
    // 숫자 하나를 먼저입력 받고 연산자와 추가로 연산할 숫자 입력받기
    int num1, num2;
    char Operator;
    cout<<"숫자를 입력해주세요 : ";
    cin >> num1;
    cout<<"연산자를 입력해주세요 : ";
    cin >> Operator;
    cout<<"숫자를 입력해주세요 : ";
    cin >> num2;
    Operator_func(Operator,num1,num2);
    
    while(1){
        cout<<"연산을 게속 진행하겠습니까? (Y: 계속, AC: 초기화, EXIT: 종료) ";
        string c;
        cin >> c;
        if(c=="Y"){
            cout<<"연산자를 입력해주세요 : ";
            cin >> Operator;
            cout<<"숫자를 입력해주세요 : ";
            cin >> num2;
            Operator_func(Operator,Calculator::result,num2);
        }else if(c=="AC"){
            Calculator::result=0;
            int num1, num2;
            char Operator;
            cout<<"숫자를 입력해주세요 : ";
            cin >> num1;
            cout<<"연산자를 입력해주세요 : ";
            cin >> Operator;
            cout<<"숫자를 입력해주세요 : ";
            cin >> num2;
            Operator_func(Operator,num1,num2);
        }else if(c=="EXIT"){
            break;
        }else{
            cout<<"올바른 입력어가 아닙니다. 다시 입력해주세요. "<<endl;
        }
    }
    




}