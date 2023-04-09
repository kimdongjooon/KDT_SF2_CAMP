# include <iostream>

using namespace std;
// 1. 상속 
class Person{
    // 필드
    // 일반적으로 private이다. 이것은 클래스 안에서만 사용가능 상속받아서 사용하려면 public사용.
    int age;
    protected : 
        string name;

    // 생성자
    public:
        string public_example = "접근제어자 public일때 호출완료!";
        // Person() {} // 기본 생성자. 생성자를 지정안하면 디폴트로 자동으로 설정 하지만 설정하면 없어짐.
        Person(string name, int age) {
            this->name=name;
            this->age=age;
        }
        Person(int age) {}

        void eat(){ cout << "밥먹기" <<endl; }

        void sleep(){ cout <<"잠자기" <<endl; }

        int override_test(int num){
            return num;
        }

        int getAge(){
            return age;
        }

        string getName(){
            return this->name;
        }

    // 메서드
};

// protected 자기 자신의 자식 클래스에서 접근가능.
// private 자기 자신클래스에서만 접근 가능.
// public 모든 곳에서 접근 가능.
// 자식클래스는 부모클래스의 생성자를 자동으로 호출함. 부모에서 작성안했으면 기본 생성자를 호출. 
class Student : public Person{ // Person의 클래스를 상속받는다. > 접근제어자인 public의미는 부모클래스에서 상속받은 멤버들의 한계를 지정. 
    string stu_id;             // 부모의 public 을 받을때 protected접근제어자를 사용하면 public 메소드가 protected로 재지정되서 메인함수에 사용할 수 없음.
    
    public:
        // student 생성자를 작성하지 않은 경우 or 기본 생성자인경우 - 매개변수가 없는 경우.
        // Student(){ person();} // 다음과 같이 실행됨. 부모클래스 생성자가 기본이면 편함.
        Student(string name, int age) : Person(name,age){ //부모 클래스의 생성자를 선택하는 방법.
            this->stu_id="1234";            
        } 
        Student() : Person(1) { }

        void study(){cout<<"공부하기"<<endl;}

        void sleep(){cout<<"10시에 잠자기"<<endl;}

        int override_test(int num){
            return num + getAge();
        }
};



int main(){
    // Person p = Person();
    Student s = Student ("홍길동", 28);
    cout<<"이름 : "<<s.getName()<<endl;
    cout<<"나이 : "<<s.getAge()<<endl;
    cout<<"public 접근제어자 테스트 : "<< s.public_example <<endl<<endl;
    
    cout<<"메소드 상속 확인 결과"<<endl;
    cout<<"Person 클래스에서 상속된 메서드 : ";
    s.eat();
    cout<<"Student 클래스에서 정의된 메서드 : "; 
    s.study();
    cout<<endl;

    cout<<"오버라이딩 확인 결과"<<endl;
    cout<<"기존 : 잠자기 > 오버라이딩 후 : 10시에 잠자기 -> 결과확인 : ";
    s.sleep();
    cout <<"기존 : 28 > 오버라이딩 후 28+5 -> 결과확인 : " <<s.override_test(5)<<endl;
    
}