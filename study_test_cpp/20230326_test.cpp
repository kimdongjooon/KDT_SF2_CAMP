#include <iostream>
#include <vector>

int main(){
    // // 실습 1 벡터 실습.
    // int x,y;
    // while(1){
    //     std::cout << "x를 입력하세요. ";
    //     std::cin >> x;
    //     std::cout << "y를 입력하세요. ";
    //     std::cin >> y;
    //     if(x>0 && y>0){
    //         break;
    //     }
    //     std::cout << "x, y가 양수가 아닙니다 다시 입력해주세요 "<<std::endl;
    // }
    
    // std::vector<std::vector<int>> v_test1(x, std::vector<int>(y, 0));
    // int count=1;
    // for (int i = 0; i<x;i++){
    //     for (int j = 0; j<y ; j++){
    //         v_test1.at(i).at(j) = count;
    //         count++;
    //     }
        
    // }
    
    // for (int i = 0; i<v_test1.size();i++){
    //     for (int j = 0; j<v_test1.at(i).size() ; j++){
    //         std::cout << v_test1.at(i).at(j) << " ";
    //     }
    //     std::cout << std::endl;
    // }
    
    
    // // 실습 2. 벡터 실습 2
    // // 사용자가 입력한 숫자들을 배열에 담고 그 수 합구하기
    
    // std::vector<int> score;
    // int total_score=0;
    // while(1){
    //     int num;
    //     std::cout <<"숫자를 입력하세요 (0 : exit) : ";
    //     std::cin >>num;

    //     if(num == 0){
    //         break;
    //     }
        
    //     score.push_back(num);
    // }
    
    // for (int i = 0; i<score.size(); i++){
    //     total_score += score[i];
    // }

    // std::cout << "사용자가 입력한 총합은 "<<total_score<<"입니다."<<std::endl;


    // 실습 3. 벡터 실습 무조건 오늘 해결하고 자기.
    // 영어로 된 문자열 모두 소문자로 입력 받아서 문자열에 사용된 문자의 개수를 구하시오

    std::vector<char> v_test2;
    std::vector<char> v_result;
    std::string senten ;
    
    // std::cin.getline(v_test2,'\n');
    std::getline(std::cin,senten);
    

    for (int i = 0; i<senten.length(); i++){
        v_test2.push_back((char)senten[i]);
    }

    v_test2.erase(std::remove(v_test2.begin(), v_test2.end(), ' '), v_test2.end());
    // for (int i = 0;i<v_test2.size();i++){
    //     std::cout << v_test2[i]<< "-"<< std::endl;
    // }

    

    v_result.push_back(v_test2[0]);
    for (int i = 0;i<v_test2.size();i++){
        int count = 0;
        for (int j = 0; j < v_result.size();j++){
            if(v_result[j] == v_test2[i]){
                count++;
                continue;
            }
        }
        if (count==0){
            v_result.push_back(v_test2[i]);
        }
                
    }
    
    std::cout <<v_result.size()<<"개 ("<<v_result[0];
    for (int i = 1; i<v_result.size();i++){
        std::cout <<","<<v_result[i] ;
    }
    std::cout <<")"<<std::endl;

    

}