# include <iostream>

using namespace std;


// 추상 메소드 (순수 가상 함수)
// 추상 클래스 : 한개 이상의 추상 메소드를 가지고 있는 클래스
class Person{
public:
    // Person(){
    //     cout<<"생성자입니다."<<endl;
    // }
    
    // ~Person(){
    //     cout<<"소멸자입니다."<<endl;

    // }

    virtual ~Person(){
        cout <<"가상함수 소멸자입니다."<<endl;
    } // 자식의 소멸자가 있다고 기대한다 없으면 자동 생성 시켜줌.

    virtual void test() = 0; // 추상 메소드 문법. 순수 가상함수

    // 가상함수
    // 부모클래스에서 정의 될 예정, 자식 클래스가 재정의 될것이라고 기대하는 함수.
    virtual void sleep(){ // > 동적 바인딩을 위해. > 포인터를 사용해서 이용해야함.
        cout<<"잠자기"<<endl;
    }


};

// class Person1{
//     public:
//         Person1(){
//         cout<<"생성자입니다."<<endl;
//         }
//         ~Person1(){
//         cout<<"소멸자입니다."<<endl;
//         }
// };

// 추상 클래스를 상속 받는 자식 클래스는 추상 메소드를 구현해야한다. 오버라이딩하면됨.
class Student : public Person {
public:
    void test(){
        cout <<"테스트 함수입니다."<<endl;
    }
    void test_stu(){
        cout <<"학생 클래스 테스트 함수입니다."<<endl;
    }
    void sleep(){ // 가상함수 재정의(오버라이딩)
        cout <<"10시에 잠자기"<<endl;
    }
    ~Student(){
        cout << "student 소멸자입니다."<<endl;
    }

};

class RemoteControl{
    public:
        virtual void turnOn()=0;
        virtual void turnOff()=0;
};

class TV : public RemoteControl{
    public:
        void turnOn(){cout<<" 티비 킴"<<endl;}
        void turnOff(){cout<<" 티비 킴"<<endl;}
};

class Shape1{
    int num = 99;
    public:
        Shape1(int n){
            this->num = n;
        }

        void getLinenum(){
            cout<<num;
        }
};

class Rect: public Shape1{
    int height;
    public:
        Rect(int h) : Shape1(4){
            this->height=h;
        }
        
};


int main(){
    // 추상클래스이기 때문에 오류가 남. 인스턴스를 생성못함. 상속받는 자식 클래스도 포함 단 오버라이딩하면 정상 자식클래스는 정상.
    // Person  p = Person(); >> 에러
    Student s1 = Student(); 
    s1.test();
    
    // // Shape 클래스의 변수 메소드에만 접근가능, Rect클래스의 변수 및 메소드는사용 불가능. 
    // Shape1 s2 = Rect(5);
    
    // //배열로도 선언가능. 한꺼번에 묶기 가능. 부모배열로 자식 요소르 채울수있음.
    // Shape1 sa[1]= {Rect(4)};

    // 캐스팅 
    Student s3;
    Person* p1 = &s3; // 업캐스팅.
    // p1->test();
    // p1->test_stu(); 업캐스팅은 자식클래스의 추상메소드만 불러와서 쓸수있음.

    Person* p2 = new Student(); // 업캐스팅
    // p2->test();

    // delete p2; // 딜리트는 추상클래스의 추상 메소드 때문에 에러가 일어남 왜? 

    // 다운캐스팅.
    // int a = 3;
    // double b = (double)a; // 강제 형변환 느낌.

    // Student* stu = (Student*)p2; // 다운캐스팅. >> 여기서 p2를 사용하고 있어서 에러가 뜸. > 여기서 생성자 안뜸.
    // stu->test(); // 포인터를 쓰면 . 을 안쓰고 -> 를 무조건 써야된다.
    // stu->test_stu(); // 다운캐스팅하면 쓸수있음.
    //stu는 해지될떄 스레기값을 가리킴.
    delete p2;
    
    
    // Person p3 =Student(); //p3가 업캐스팅이 안되어있어서 다운캐스팅이 안됨.
    // Student stu = (Student)p3; // 에러. 이렇게 쓰면안됨.
    cout << "------"<<endl;
    // 가상함수 동적 바인딩 virtul 붙어있는 함수(가상함수) 부모꺼 읽기전에 자식꺼 읽으러감.
    Person* s10 = new Student(); // 업캐스팅 가정하에.
    s10->sleep();
    delete s10;
    

    // Person1 p;
    //정적메모리
    //스택영역에 저장됨. 해제를 명시적으로 할 필요 없음,

    return 0; // p의 소멸자
}