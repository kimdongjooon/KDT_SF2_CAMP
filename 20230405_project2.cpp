#include <iostream>
#include <ctime>
#include <vector>


using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;


int main(){
    // 30초 동안 끝말잇기 게임.
    // 1. 30초 동안 진행되도록 기능 구현.
    time_t startTime = time(NULL);
    // time_t ST = time(NULL);
    // struct tm* st = localtime(&ST);
    vector <string> name_lst;
    // cout<<"시작 초"<<st->tm_sec<<endl;
    while(1){
        // 단어를 입력하는 기능
        // 시작 단어 지정.
        if(name_lst.empty()){
            cout<<"시작 단어를 입력해주세요. : ";
            string startname;
            cin >> startname;
            name_lst.push_back(startname);
        }

        // 다음 단어 지정.
        int time_limit=0;

        cout<<"다음 단어를 입력해주세요. : ";
        string nextname;
        cin >> nextname;

        // 입력 시간 기준 30 초 지났으면 타임 오버출력 및 종료
        time_t endTime = time(NULL);
        
        // 만약 30초 초과 했으면 break; 
        cout << CLOCKS_PER_SEC << " "<<endTime << " " << startTime<<endl;
        cout<< "현재 시간 : "<<(double)(endTime-startTime)<<endl;
        if((double)(endTime-startTime)>30){
            time_limit=1;
            break;
        }

        while(1){

            // // 입력 시간 기준 30 초 지났으면 타임 오버출력 및 종료
            // time_t endTime = clock();
            
            // // 만약 30초 초과 했으면 break; 
            // cout << CLOCKS_PER_SEC << " "<<endTime << " " << startTime<<endl;
            // cout<< "현재 시간 : "<<(double)(endTime-startTime)/100<<endl;
            // if((double)(endTime-startTime)/100>30){
            //     time_limit=1;
            //     break;
            // }

            // 중복성 검사
            int dup_test=0;
            for (int i = 0;i<name_lst.size();i++){
                if(name_lst[i]==nextname){
                    
                    dup_test=1;
                    break;
                }
            }
            if(dup_test==1){
                cout<<"중복된 단어가 있습니다. 다시 입력해주세요. "<<endl;
                break;
            }

            
        
            // 맨 앞글자 와 맨 뒷글자 같으면 벡터 저장 후 종료. 아니면 그냥 종료 
            //                       벡터 제일 끝 문자열지정  문자열에서 제일 마지막 문자 출력.
            if(nextname[0]==name_lst[name_lst.size()-1][name_lst[name_lst.size()-1].size()-1]){
                name_lst.push_back(nextname);
                break;
            }else{
                cout<<"일치하지 않습니다. 다시 입력해주세요."<<endl;
                break;
            }

                    

        }

        // 끝말잇기 현재 상황.
            cout<<name_lst[0];
            for(int i = 1;i<name_lst.size();i++){
                cout<<"->"<<name_lst[i];
            }
            cout<<endl;

        if(time_limit==1){
            cout<< "타임오버 : 입력한 단어의 총개수는 : "<<name_lst.size()<<"개입니다."<< endl;
            break;
        }


        
    }




}