#include <iostream>

using namespace std;

struct Rectangle{
    double width;
    double height;
};


int main(){
    Rectangle R;
    cout << "가로, 세로 길이를 입력하세요. ";
    cin >> R.width >>R.height;

    cout << "넓이는 : "<<R.width*R.height<<endl;
    
}