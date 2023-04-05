#include <iostream>
#include <vector> //STL안에 있음.

// using namespace std; 전체다 쓰게 됨 나중에 익숙해 지면 쓰기.
using std::cout, std::cin, std::endl, std::vector;

namespace test {
    int num = 1;
    int sum(int n, int n1){
        return n+n1;
    }
}

namespace wooriBank{
    int balance = 0;

    double deposit(double money){
        return money + 0.03*money;
    }
}

int main(){
    int num = 0;

    // vector > 동적배열을 사용하지 않고 vector를 많이 이용함.
    // vector 는 내장 함수가 아니라서 전처리하여 불러와서 사용해야 함.
    std::string str = "aa";
    std::vector<int> v; // int 형 배열을 만듦.
    // std::vector<std::string> v2 // string 형 배열을 만듦.

    std::vector<int> v_test1 = {1,2,3}; // 바로 초기화 시켜줘도 됨.
    // {1,2,3} 생성

    std::vector<int> v_test2(4); // int 형 백터를 생성 후 크기를 4로 할당하고 백터 요소를 0으로 초기화한다는 의미.
    // {0,0,0,0} 생성

    std::vector<int> v_test3(7,1); // int 형 백터를 생성 후 크기를 5로 할당하고 백터 요소를 1으로 초기화한다는 의미.
    // {1,1,1,1,1,1,1} 생성


    // 백터에서 제공되는 함수 1. assign : 선언된 벡터 변수에 값들을 할당 및 초기화하는 함수.
    // 기존 할당되고 초기화된 벡터 크기 및 값 바꾸기. 위의 선언된 벡터 변수 v_test3 이용.
    v_test3.assign(3,2); // 0~2 번째 까지 벡터 요소를 2로 변경.
    // {1,1,1,1,1,1,1} > {2,2,2} 로 변경됨.


    // 백터에서 제공되는 함수 2. size : 벡터의 크기를 계산해주는 함수.
    v_test3.size();
    // {2,2,2} 형태의 크기는 3이므로 3를 반환함.

    for (int i = 0; i<v_test3.size();i++){
        std::cout << i+1<<"번째 벡터 요소의 값은 "<<v_test3[i]<<" 입니다."<< std::endl;
    }
    
    // 벡터크기이상의 for문을 돌릴때도 설정한 조건문까지 range 에러가 뜨지않는다.??ㄷㄷㄷ
    // 그리고 기존에 초기화한 크기보다 낮게 할당했을때 초기화되었던 데이터는 남아있다.


    // 벡터에서 제공되는 함수 3. push_back() : 벡터의 마지막 원소를 push 함
    v_test3.push_back(4);
    //{2,2,2} > {2,2,2,4} 로 바뀜


    // 벡터에서 제공되는 함수 4. pop_back() : 벡터의 마지막 원소를 꺼낸다.
    v_test3.pop_back();
    // {2,2,2,4} > {2,2,2} 로 바뀐다. 마지막 원소를 변수에 저장이 가능한가?


    // 벡터에서 제공되는 함수 5. begin() : 벡터의 시작 주소를 반환함. 인데스 0
    v_test3.begin();
    // 시작 주소인 0을 반환함.

    
    // 벡터에서 제공되는 함수 6. insert(인덱스 위치, 넣을 값) : 벡터의 인덱스를 지정하여 값을 넣어주는 함수.
    v_test3.insert(v_test3.begin(),10);
    // {2,2,2} > {10,2,2,2} 로 변경. 주의할 점 인덱스를 직접 숫자로 지정하면 에러남. 왜?

    
    // 이중 벡터 선언
    std::vector<std::vector<int>> v_test4 = {{1,2}, {3,4}};
    for(int i = 0; i<v_test4.size();i++){
        for(int j = 0; j < v_test4.at(i).size();j++){
            std::cout << v_test4.at(i).at(j) << " ";
        }
        std::cout << std::endl;
    }

    
    // 식별자 : 변수, 함수 이용.
    // namespace를 사용할때 충돌안나게 조심. 예를 들어, 
    // 메인 함수에서 선언된 변수가 1순위로 선택됨. 하지만 두개의 namespace를 사용하여 같은이름의 변수를 선언하였을때 충돌이 나면서 에러가 뜹니다.
    // 그래서 using namespace를 가급적으로 사용하는 것만 등록하는게 좋음.
    cout << num <<endl; 
    cout << test::num<< endl; 
    cout << test::sum(1,2)<<endl;

    



}
