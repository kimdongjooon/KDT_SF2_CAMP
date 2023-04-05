#include <iostream>
#include <vector>
#include <sstream>

using namespace std;


// 이름쌓기 프로그램.
class stackname{
public:
    static int stack_num;
    
};

int stackname::stack_num=0;

int main(){
    
    vector <string> stack_name;
    while(1){
        
        vector <string> stack_name_tmp;
        int break_count=0;
        string line;
        string name;
        std::cout<<"이름 쌓기 ~ 이름 쌓기 ~ : ";
        getline(cin,line);
        stringstream ss(line);

        while(ss>>name){ // 문자열 입력 받기.
            // cout<<"0 : "<<name<<endl;
            // 빈 벡터일때 한번만 실행하고 입력 종료. 
            
            // if(stack_name.empty()){
                
            //     // stack_name.push_back(name);
            //     std::cout<<"1 : "<<stack_name.size() <<endl;
                
            // }
            // 임시 비교 벡터 생성 및 삽입.
            stack_name_tmp.push_back(name);
            // std::cout<<"1 : "<<stack_name.size()<<endl;
            // std::cout<<"2 : "<<stack_name_tmp.size()<<endl;

        }   

            // 기존 쌓인 이름과 입력한 이름 일치 비교. 
            // 한문자열씩 비교하여 입력한 문자열들이 기존 문자열들이랑 모두 일치하면, 
            // 기존 스택배열 사이즈+1 값이 가리키는 입력배열의 값을 pushback해서 기존 스택에 저장.
            int count=0;
            
            for (int i = 0; i<stack_name.size();i++){
                // std::cout<<stack_name[i] <<" : "<<stack_name_tmp[i]<<endl;
                if(stack_name[i]==stack_name_tmp[i]){
                    // std::cout<<"3"<<endl;
                    count++; // 일치할때마다 +1 씩 다맞으면 벡터 사이즈랑 똑같아짐
                    // stack_name.insert(stack_name.begin()+i,stack_name_tmp[i]);
                    
                }else{// 한개라도 일치하지않는다면 중지 후 카운트 출력.
                    // std::cout<<"4"<<endl;
                    stackname::stack_num=stack_name.size();
                    break_count++;
                    break;
                }
            }
        // 만약 일치한 개수와 벡터 사이즈가 같으면. 추가 후 계속 진행 아니면 끝
        if(count==stack_name.size()){
            // std::cout<<"5"<<endl;
            if (stack_name.empty()){
                stack_name.push_back(stack_name_tmp[0]);
            }else{
                stack_name.push_back(stack_name_tmp[stack_name.size()]);
            }
        }else{
            // std::cout<<"6"<<endl;
            break;
        }

        // std::cout<<"7 : break_count : "<<break_count<<endl;
        if(break_count!=0){
            break;
        }

    }
    
    std::cout<<"게임 종료! "<<stackname::stack_num<<"까지 성공했습니다!"<<endl;

}