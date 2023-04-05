#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main(){

    // //실습 1. 거꾸로 일기
    // ifstream file1;

    // file1.open("hello.txt");

    
    // vector <string> txt_line;
    // if(file1.is_open()){
    //     while(1){
    //         string line;
    //         getline(file1, line);
    //         if(line.empty()){
    //             break;
    //         }
    //         txt_line.push_back(line);
    //     }
    // }
    // file1.close();

    // ofstream file2;
    // file2.open("output.txt");

    // for (int i = txt_line.size()-1; 0 <= i ;i--){
    //     file2 << txt_line[i]<<endl;
    //     cout<<txt_line[i]<<endl;
    // }
    // file2.close();
        
    // // 실습 2. 회원 명부작성
    // // (1) 사용자에게 3명의 회원에 대한 이름 비밀번호 입력 받기
    
    // cout << "입력할 회원이 몇명입니까? : ";
    // int num ;
    // cin >>num ; 
    // cin.ignore(); // \n가 남아있어 getline 첫번째 받을때 영향을 끼치므로 이명령으로 사용하여 입력 버퍼에 \n을 삭제하여 준다.
    // cout << num<<"명의 회원에 대한 이름 비밀번호를 순차적으로 입력하세요. "<<endl;
    // ofstream file3("member.txt");
    // for (int i = 0; i<num; i++){
    //     string input_id_password;

    //     cout<<i+1<<"번째 회원 : ";
    //     getline(cin,input_id_password);
        
    //     file3 << input_id_password<<endl;
    // }
    // file3.close();

    // // 명부 읽어오기

    // ifstream file4("member.txt");
    // cout<< "------------- 회원 명부 읽기 -------------"<<endl;
    // while(1){
    //     string output_id_password;
    //     getline(file4,output_id_password);
    //     if(output_id_password.empty()){
    //         break;
    //     }
    //     cout<<output_id_password<<endl;
    // }
    // file4.close();

    // // 실습 3. 명부 기반 로그인 성공 여부
    // // 사용자에게 이름, 비밀번호 입력 받기
    // cout << "이름을 입력하세요. ";
    // string name;
    // cin >> name;
    // cout << "비밀번호를 입력하세요. ";
    // string password;
    // cin >> password;

    // ifstream file5("member.txt");
    // while(1){
    //     string user;
    //     string f_name;
    //     string f_password;
    //     getline(file5,user);
    //     if(user.empty()){
    //         cout << "로그인 실패";
    //         break;
    //     }
    //     stringstream ss (user);
    //     ss >>f_name >> f_password;
    //     if(f_name == name && f_password == password){
    //         cout << "로그인 성공";
    //         break;
    //     }
    // }
    // file5.close();

    // 실습 4 로그인 성공시 전화전호 저장하기
    cout << "이름을 입력하세요. ";
    string name;
    cin >> name;
    cout << "비밀번호를 입력하세요. ";
    string password;
    cin >> password;

    ifstream file5("member.txt");
    while(1){
        string user;
        string f_name;
        string f_password;
        getline(file5,user);
        if(user.empty()){
            cout << "로그인 실패";
            break;
        }
        stringstream ss (user);
        ss >>f_name >> f_password;

        // 로그인 성공.
        if(f_name == name && f_password == password){
            cout << "로그인 성공"<<endl;
            string tel_num;
            cout << "전화번호를 입력해 주세요: ";
            cin >> tel_num;
            // 전화 번호 명부에 중복 확인. 중복되면 전체 수정. 중복되면 count증가
            int count=0;

            vector<string> v_id_tel;
            ifstream file7("member_tel.txt");
            string tel_user_name;
            string tel_user_tel;
            while(file7 >>tel_user_name>>tel_user_tel ){ // 전화 번호 명부 하나하나씩 뽑아서 중복 검사 중복이 한개라도 있으면 count 변수 증가.
                // 와일문 안에 위와같은 조건문을 써주면 입력받을때 문자열이 없으면 false를 반환해준다.
                // string tel_user;
                // string tel_user_name;
                // string tel_user_tel;
                // getline(file7,tel_user);
                
            
                // cout << " tel_user : " << tel_user<< "입니다." << endl;
                // if(tel_user.empty()){
                //     break;
                // }
                // stringstream ss1(tel_user);
                // ss1 >> tel_user_name >> tel_user_tel;
                v_id_tel.push_back(tel_user_name);
                
                
                if(name == tel_user_name){ // 중복이 될때 전화번호갱신
                    v_id_tel.push_back(tel_num);       
                    count++;
                }
                else{
                    v_id_tel.push_back(tel_user_tel);
                }
            }
            file7.close();

            // ofstream file8("member_tel.txt"); //전화 번호 명부를 열어서 중복되는 이름이 있는지 확인 후 수정.
            // if(name == tel_user_name){ // 중복이 될때 전화번호갱신
            //         file8 << tel_user_name << " " << tel_num<<endl;
            //         count++;
            //     }
            //     else{ // 로그인은 성공했지만 중복이 안될때는 그대로 나두기.
            //         file8 << tel_user_name << " " << tel_user_tel<<endl;
            //     }
            // file8.close();


            // cout << "카운트 숫자는" <<count << endl;;
            

            // 중복이 안되었다면 기존 전화번호 명부에 추가
            if(count==0){ 
                ofstream file6("member_tel.txt",ios::app); 
                file6 << f_name <<" "<<tel_num<<endl;
                file6.close();
                cout << name <<"님은 신규고객입니다. 전화번호 명부에 등록되었습니다."<<endl;
                break;
            }
            else{ // 중복이 되었다면 수정한 정보 갱신.
                ofstream file8("member_tel.txt");
                for(int i = 0 ; i<v_id_tel.size();i=i+2){
                    file8 << v_id_tel[i] << " "<<v_id_tel[i+1]<<endl;
                }
                file8.close();
                cout << name <<"님은 기존고객입니다. 전화번호를 새롭게 갱신하였습니다."<<endl;
                break;
                 
            }
            
        }
    }
    file5.close();
}