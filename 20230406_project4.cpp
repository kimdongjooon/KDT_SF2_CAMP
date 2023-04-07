#include <iostream>
#include <vector>

using namespace std;
 
int main(){
    // 사용자로 부터 홀수 n을 입력 받아 n*n 마방진 만들기
    // 마방진은 가로 세로 대각선의 합이 같아야 한다.

    vector <int> mabangjin;
    cout<<"마방진의 행 또는 열 수를 입력해주세요.(홀수만) : ";
    int num;
    cin >> num;

    for(int i = 1; i<num*num+1; i++){
        mabangjin.push_back(i);
    }
    for(int i = 0 ; i<mabangjin.size();i++){
        cout<<mabangjin[i]<<" ";
    }

    // 벡터 2차원 초기화
    vector < vector<int> > td_mabangjin(num,vector<int>(num,0));

    int row=0;
    int col=num/2;
    for (int i = 0; i<mabangjin.size();i++){
        // 첫행 중간열에 삽입.
        if(i==0){
            td_mabangjin.at(row).at(col)=mabangjin[i];
            continue; // i는 1부터 시작하도록 리셋.
        }
        // 첫행에 마지막 열일때 아래로 이동
        if(row==0 && col==num-1){
            row++;
            td_mabangjin.at(row).at(col)=mabangjin[i];
            continue;
        }

        // 첫행이 0 일때 우상단 이동 맨 아래행의 다음열
        if(row==0){
            row=num-1;
            col++;
            td_mabangjin.at(row).at(col)=mabangjin[i];
            continue;
        }

        // 마지막 열에서 우상단 이동일때 첫번째열에서 이전행
        if(col==num-1){
            row--;
            col=0;
            td_mabangjin.at(row).at(col)=mabangjin[i];
            continue;
        }

        // 만약 우상단으로 이동한 곳이 0이면 값 넣고 0이 아니면 밑으로 이동후 넣기
        if(td_mabangjin[row-1][col+1]==0){
            row--;
            col++;
            td_mabangjin.at(row).at(col)=mabangjin[i];
        }else{
            row++;
            td_mabangjin.at(row).at(col)=mabangjin[i];
        }

    }

    for(int i = 0; i<td_mabangjin.size();i++ ){
        for(int j = 0 ; j<td_mabangjin.at(i).size();j++){
            cout<<td_mabangjin.at(i).at(j) << " ";
        }
        cout<<endl;
    }


}