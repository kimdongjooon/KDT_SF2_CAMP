# include <iostream>
# include <fstream> // 파일 입출력 헤더
# include <string> // getline 메소드 사용하기 위함.

using std::cout, std::cin, std::endl, std::ifstream, std::string , std::ofstream;


// 구조체
// 여러가지 변수를 메인함수 외부에 선언 후 사용.
struct Position{
    int x = 0;
    int y = 0;
};

int main(){

    Position p;
    p.x = 3;
    p.y = 5;
    cout << "x좌표 : "<<p.x<< " y좌표 : "<<p.y<<endl;

    // 파일 입출력.
    // 1. 입력받을 파일 변수 선언
    ifstream file;

    // 2. open 메소드 사용해서 텍스트 파일 불러오기
    file.open("text_file.txt");

    // 3. 파일이 잘열렸는지 확인방법.
    // 띄어쓰기 기준으로 문자열에 저장 가능하다. 그렇다면 다 읽기 위한 방법은? 
    string word1;
    string word2;
    if (file.is_open()){
        file >> word1 >> word2;
        cout << "성공 "<< word1<<word2 <<endl;
    }else{
        cout << "실패"<<endl;
    }

    // 5번 항목 실행. 엔터 기준으로 문자열 입력 받기 가능.
    string f_line1;
    string f_line2;
    getline(file, f_line1);
    getline(file, f_line2);
    cout << f_line1 << " -- " <<f_line2;

    // 4. 파일 닫기
    file.close();

    // 5. 텍스트 파일 모두 읽기 - getline 메소드 : 띄어쓰기 구분없이 엔터 나올때 까지 모두 읽기가능.

    string line;
    getline(cin , line);
    cout << line;

    string file_line;
    getline(file, file_line);
    cout << file_line;

    // ofstream 파일 입력
    ofstream file2("text_file2.txt");

    if(!file2.fail()){
        file2 << "hello word!!\n" << "안녕하세요1212~";
    }
    else {
        cout << "파일이 있습니다.";
    }

    
    

}