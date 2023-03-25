#include <iostream>
#include <array>

// main 함수는 return 0; 을 적지 않아도 자동으로 실행하여 주기때문에 안적어도 됨.
int main(){

    // // 배열 : 여러값들을 하나의 변수에 저장가능함.
    // std::string fruit[3] = {"apple","banana","mango"};
    // std::string fruit1[] = {"apple","banana","mango"}; // 크기 지정안하고 값으로 선언을 해주어도됨.
    

    // std::cout << fruit << '\n'; // 이렇게 쓰면 배열의 주소값을 출력한다.
    // std::cout << fruit[0] << std::endl ; // 한개씩만 출력가능. std::endl은 엔터를 의미 '\n'과 같은 의미.

    // // 배열의 길이 sizeof()를 사용, 변수의 저장공간을 byte단위로 반환해줌.
    // // 전체 배열의 저장공간을 한개의 저장공간으로 나누면 배열의 개수가 된다.
    // // 길이는 sizeof(std::string)과 sizeof(fruit[0])으로 나누어도됨.
    // // *fruit은 fruit의 첫 메모리 주소를 의미.
    // std::cout << sizeof(fruit)/sizeof(*fruit) << std::endl;

    // for (int i = 0 ; i<sizeof(fruit)/sizeof(*fruit) ; i++){
    //     std::cout << fruit[i] << std::endl;
    // }

    // // 2차원 배열
    // // 1 2 3
    // // 4 5 6
    // int num_arr[2][3] = {
    //     {2,2,2},
    //     {1,23,3}
    // };

    // // 출력하기
    // int size1 = sizeof(num_arr)/sizeof(num_arr[0]); // 2차원 배열의 행의 개수
    // int size2 = sizeof(num_arr[0])/sizeof(num_arr[0][0]); // 2차원 배열의 열의 개수
    // for (int i = 0 ; i<size1 ; i++){
    //     for (int j = 0 ; j<size2 ; j++){
    //         std::cout << num_arr[i][j]<<" ";
    //     }
    //     std::cout << std::endl;
    // }

    // std::cout << sizeof(*num_arr)<< std::endl;

    // // 문자열 2차원 배열
    // std::string str_arr[2][4]={
    //     {"a","b","c","d"},
    //     {"e","f","g","h"}
    // };
    // std::cout << sizeof(str_arr)/sizeof(*str_arr[0])<<std::endl;
    // std::cout << sizeof(str_arr)/sizeof(str_arr[0][0])<<std::endl;
    // std::cout << sizeof("a")<<std::endl;

    
    // // 배열의 for-each문 1차원 배열에만 적용가능. 인덱싱 필요없이 배열 값자체를 순서적으로 뽑아낸다.
    // // 
    // for (std::string str : str_arr[0]){
    //     std::cout << str << " ";
    // }
    // // auto 를 써주면 해당 배열의 자료형타입을 자동으로 인식하여 실행되도록 함.
    // for (auto str : str_arr[1]){
    //     std::cout << str << " ";
    // }
    // // for-each문에서는 배열값들을 초기화하고 싶을때 &를 써주면 해당 주소를 가져오는것이므로 그 해당주소에 대한 값을 넣을 수 있다.
    // // for (auto &str : str_arr[0]){
    // //     std::cin >> str;
    // // }

    // // for-each문 2차원
    // for (auto &arr : str_arr){
    //     for (auto str : arr){
    //         std::cout << str << "-";
    //     }
    // }

    // // 동적 배열과 포인터
    // // 사용자한테 입력받은 수로 배열의 크기를 지정해야할때
    // // &n 이것은 n의 주소의 값임.
    // // *p 은 n의 주소값임.
    // int n =3;
    // int n2 = 99;
    // int *p = &n; // 포인터 변수
    // std::cout << p << std::endl; // 포인터 변수만 입력하면 p의 주소값을 나타냄. 즉 n의 주소값.
    // std::cout << *p << std::endl; // p가 가리키고 있는 주소에 담긴 값을 출력.

    // *p = 100;

    // n = 10;
    // std::cout << p << std::endl; // 포인터 변수만 입력하면 p의 주소값을 나타냄. 즉 n의 주소값.
    // std::cout << *p << n<< std::endl; // p가 가리키고 있는 주소에 담긴 값을 출력.
    // // 값만 초기화 시킬때는 주소값은 그대로이고 주소의 값은 변경된다.

    // std::string str="aaa";
    // std::string *str_p = &str;
    // std::cout << str_p << std::endl; // 포인터 변수만 입력하면 str_p의 주소값을 나타냄. 즉 str의 주소값.
    // std::cout << *str_p << std::endl; // str_p가 가리키고 있는 주소에 담긴 값을 출력.
    
    // // 선언할때 &값을 쓰면 초기화시킨 변수와 동일한 주소를 가짐 즉 동일한 변수로 사용가능.
    // int &num = n; // 참조 변수.
    // std::cout << n <<std::endl;
    // std::cout << &n <<std::endl;
    // std::cout << num <<std::endl;
    // std::cout << &num <<std::endl;
    // // std::cout << *num <<std::endl;

    // num = 11;
    // std::cout << n <<std::endl;
    // std::cout << &n <<std::endl;
    // std::cout << num <<std::endl;
    // std::cout << &num <<std::endl;

    // 포인터를 이용하여 동적 메모리 할당.
    // 포인터를 이용하면, 동적 메모리를 생성 가능함.
    // 이때까지 사용한 것은 정적 메모리임. ex) int n; , int arr[3]; 등
    // 힙영역 : 동적메모리 > 할당과 해제를 직접 관리하여 주어야함.
    // 스택영역 : 정적 메모리. > 빌드(디버깅) 할때 배열의 크기가 지정되어 있어야함 그렇기에 사용자가 입력한 변수로 배열의 크기를 지정할 수 없음.
    // 포인터가 무조건 동적 메모리로 사용되는 것이 아님.
    // 동적 메모리 사용 방법.
    int *p = new int; // new 라는 명령어를 사용하여 선언한다. - 할당
    // 코드 본문 작성.
    delete p; // 해제 , 안해도 에러는 안뜨지만 메모리를 계속 잡아먹음.
    // 동적 배열 만들기.

    int num;
    std::cout << "배열의 크기를 입력하세요. ";
    std::cin >> num;
    // int arr[num];
    int *arr = new int[num];
    delete[] arr;
    // 대괄호 있고 없고의 차이는?

    for (int i = 0; i<num; i++){
        arr[i]=i+1;
        std::cout << arr[i] << std::endl;
    }

    std::string *str = new std::string[num];
    delete[] str;
    
    for(int i = 0; i < num ; i++){
        str[i]=65+i;
        std::cout << str[i] << std::endl;
    }

    // 일차원 동적배열 > int *arr1 = new int[num]; > {int, int, int} 형
    // 이차원 동적배열 > { {int,int}, {int,int}, {int,int} }
    int **arr2 = new int *[num]; // num은 1차원 배열 개수 지정

    for (int i = 0; i < num; i++){
        arr2[i] = new int[num];
        // { { , , , ,}, { , , , , }, ...}
    }

    for (int i =0 ; i < num; i ++){
        for (int j = 0 ; j < num ; j++){
            arr2[i][j]=1;
            std::cout << arr2[i][j]<< " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0 ; i <num; i++){
        delete[] arr2[i];
    }

    delete[] arr2;
    

}