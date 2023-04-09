//추상클래스 예시

#include <iostream>

#include "weapon.h"
#include "normal.h"
#include "rare.h"
#include "unique.h"

#include "character.h"
using namespace std;

int main(){
    // cout<<"완료"<<endl;

    // Weapon W = Weapon("1",1,2,3);
    // cout<<"웨폰 헤더 "<<W.grade<<endl;

    // Normal N = Normal();
    // cout<<"노말 헤더 "<<N.grade<<endl;

    // Rare R = Rare();
    // cout<<"레어 헤더 "<<R.grade<<endl;

    // Unique U = Unique();
    // cout<<"유니크 헤더 "<<U.grade<<endl;

    struct s{
        int s;
    };
    vector <s> weapon_info={{10},{11},{22},{33}}; // 첫번째 인덱스:0일때 미착용, 1일때 노말, 2일때 레어, 3일때 유니크

    cout<<(weapon_info[0].s==10)<<weapon_info[1].s<<endl;
    weapon_info = {{111},{222},{333},{444}};
    cout<<weapon_info[0].s<<weapon_info[1].s<<endl;
}