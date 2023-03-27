#include <iostream>

using namespace std;

namespace seoul {
    int local_number;
    string landmark;

}

namespace busan {
    int local_number;
    string landmark;
}

using namespace busan;

int main(){
    // 실습1 namespace 사용해보기
    cout << "서울의 지역번호와 랜드마크를 입력해주세요. ";
    cin >> seoul::local_number>>seoul::landmark;

    cout << "부산의 지역번호와 랜드마크를 입력해주세요. ";
    cin >> local_number>> landmark;

    cout << "서울의 지역번호는 0"<<seoul::local_number<<"이고 랜드마크는 "<<seoul::landmark<<"입니다."<<endl;
    cout << "부산의 지역번호는 0"<<local_number<<"이고 랜드마크는 "<<landmark<<"입니다. "<<endl;

}