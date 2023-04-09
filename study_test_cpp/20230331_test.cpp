#include <iostream>

using namespace std;
// // 실습 1. 상속 사용해보기
// class Shape {
//     protected:
//         int edge_num;
//         double under_edge_length;

//     public:
//         Shape(int en, double uel){
//             this->edge_num=en;
//             this->under_edge_length=uel;
//         }

//         void printInfo(){
//             cout <<"변의 개수는 : "<<this->edge_num<<endl;
//             cout <<"밑변의 길이는 : "<<this->under_edge_length<<endl;
//         }
// };

// class Rectangle : public Shape{
//     double vertical_length;

//     public:
//         Rectangle(double vl, int en, double uel):Shape(en,uel){
//             this->vertical_length=vl;
//         }

//         void area(){
//             cout << "사각형의 넓이는 : "<<this->under_edge_length*this->vertical_length<<endl;
//         }
// };

// class Triangle : public Shape{
//     double height;

//     public:
//         Triangle(double h, int en, double uel):Shape(en,uel){
//             this->height=h;
//         }

//         void area(){
//             cout <<"삼각형의 넓이는 : "<<this->under_edge_length*this->height*0.5<<endl;
//         }
// };

// 실습 2. 동물의 왕국.
// 추상화 할 부분 필드: 동물의 1.종이름 2.다리의개수 3.동물의 키.  , 메소드 : 정보출력.
// 각 동물들의 울음소리

// 실습 3. 오버라이딩 이해하기.
class Student{
    protected:
        string name;
        string school_name;
        int age;
        int school_num;

    public:
        Student(){}
        Student(string n1, string n2, int n3, int n4){
            this->name=n1;
            this->school_name=n2;
            this->age=n3;
            this->school_num=n4;
        }

        void lunch(){cout<<"점심은 학식"<<endl;}

};

class Kim : public Student {
    double height;

    public:
        Kim(double h,string n,string scname, int a, int scnum):Student(n,scname,a,scnum){
            this->height=h;
        }

        void lunch(){cout<<"점심은 김가네 김밥"<<endl;}
};

class Baek : public Student {
    string grade;

    public:
        Baek(string g, string n,string scname, int a, int scnum):Student(n,scname,a,scnum){
            this->grade=g;
        }

        void lunch(){cout<<"점심은 백종원 피자"<<endl;}
};



int main (){

    // cout << "삼각형의 높이, 변의 개수, 밑변의 길이를 입력해주세요 : ";
    // double v1,v3;
    // int v2;
    // cin >> v1>>v2>>v3;
    // Triangle T = Triangle(v1,v2,v3); // 높이가 10, 변개수가 3, 밑변길이가 5 인 삼각형
    // cout << "사각형의 세로, 변의 개수, 가로의 길이를 입력해주세요 : ";
    // double v4,v6;
    // int v5;
    // cin >> v4>>v5>>v6;
    // Rectangle R = Rectangle(v4,v5,v6); // 세로가 20, 변개수가 4, 가로가 15 인사각형

    // T.printInfo();
    // T.area();
    // R.printInfo();
    // R.area();
    Student S = Student();
    cout << "기존 lunch 메소드 : ";
    S.lunch();

    cout << "키, 이름, 학교, 나이, 학번을 입력하세요. :  ";
    double v1;
    string v2,v3;
    int v4,v5;
    cin >> v1>> v2>>v3>>v4>>v5;
    Kim K = Kim(v1,v2,v3,v4,v5);
    K.lunch();

    cout << "성적, 이름, 학교, 나이, 학번을 입력하세요. : ";
    string v6,v7,v8;
    int v9,v10;
    cin >> v6>>v7>>v8>>v9>>v10;
    Baek B = Baek(v6,v7,v8,v9,v10);
    B.lunch();
}