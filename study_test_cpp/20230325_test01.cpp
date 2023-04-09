#include <iostream>
// using namespace std;

int main(){
    // // 실습 1 city라는 배열 변수를 만들고, 5개의 나라 이름을 값으로 지정
    // // 배열 전체 출력
    // std::string city[5]={"korea","japan","USA","china","indo"};
    // int size1 = sizeof(city)/sizeof(city[0]);
    // for(int i = 0; i<size1; i++){
    //     std::cout << city[i]<<" ";
    // }
    // std::cout << std::endl;

    // // 실습 2. city2라는 배열 변수를 선언하고, 5개의 나라 이름을 사용자가 콘솔에 입력한 값으로 지정
    // // 출력

    // std::string city2[5];
    // int size2 = sizeof(city2)/sizeof(city2[0]);
    // std::cout << "나라 5개를 입력해주세요. ";
    // for (int j = 0; j<size2; j++){
    //     std::cin >> city2[j];
    // }
    // for(int k = 0; k<size2; k++){
    //     std::cout << city2[k]<<" ";
    // }
    // std::cout << std::endl;
    // // 실습 3. grade 라는 배열 변수를 선언하고, 학생 5인의 성적 입력 받기
    // // 성적 평균 출력

    // int grade[5];
    // int size3 = sizeof(grade)/sizeof(grade[0]);
    // for (int n = 0; n<size3 ; n++){
    //     std::cout << n+1<<"번 학생의 성적을 입력하세요. :";
    //     std::cin >> grade[n];
    // }
    // double score=0;
    // for (int m = 0; m<size3 ; m++){
    //     score+=grade[m];
    // }
    // std::cout <<"성적 평균 : "<<score/size3<<std::endl;
    
    // 실습 4 학생 3명의 국어 성적과 수학 성적을 사용자로 부터 입력받아서 배열에 저장
    // 학생들의 국어 성적과 수학 성적의 평균을 산출하는 프로그램작성
    // int stu_grade[3][2];
    // int size4 = sizeof(stu_grade)/sizeof(stu_grade[0]); // 국어 와 수학
    // int size5 = sizeof(stu_grade[0])/sizeof(stu_grade[0][0]); // 3명의 학생
    
    // for (int i = 0; i<size4 ;i++){
    //     std::cout <<i+1<<"번 학생의 국어 성적과 수학 성적을 입력하세요. : ";
    //     for (int j = 0; j<size5 ; j++){
    //         std::cin >>stu_grade[i][j];
    //     }
    // }
    // double ko_score=0;
    // double math_score=0;
    // for (int i = 0; i<size4 ;i++){
    //     for (int j = 0; j<size5 ; j++){
    //         if (j==0){
    //             ko_score+=stu_grade[i][j];
    //         }
    //         else if(j==1){
    //             math_score+=stu_grade[i][j];
    //         }
    //         else {
    //             std::cout << "오류";
    //             break;
    //         }
    //     }
    // }
    // std::cout << std::endl << "국어 평균 점수 : "<<ko_score/size4<<std::endl;
    // std::cout << "수학 평균 점수 : "<<math_score/size4<<std::endl;

    //실습 5 숫자 맞추기 게임.
    // int correct[3]= {1,8,5};
    // int user[3];
    // int user_size = sizeof(user)/sizeof(user[0]);
    // int correct_size = sizeof(correct)/sizeof(correct[0]);
    // std::cout << "1~9사이의 숫자 3개를 입력하세요 : ";
    // for (int i = 0; i<user_size; i++){
    //     std::cin >> user[i];
    // }

    // int correct_count=0;
    // for (int j = 0; j<correct_size;j++){
    //     for (int k = 0; k<user_size;k++){
    //         if(correct[j]==user[k]){
    //             correct_count+=1;
    //         }
    //     }
    // }

    // std::cout <<correct_count<<"개 맞춤."<<std::endl;

    // 실습 6 동적 배열 사용해보기
    // (1) 사용자로부터 x,y 2개의 자연수를 입력 받기
    int x;
    int y;
    while(1){
        std::cout << "x를 입력하세요 : ";
        std::cin >> x; 
        std::cout << "y를 입력하세요 : ";
        std::cin >> y;
        if(x<=0 or y<=0){
            std::cout << "x와 y모두 양수로 입력해주세요."<< std::endl;
        }else{
            break;
        }
        
    }
    // x * y 크기를 갖는 이차원 동적 배열 arr을 선언
    int **arr = new int *[x];

    for (int i = 0; i<x; i++){
        arr[i] = new int[x];
    }
    int count=1;
    for (int i = 0; i<x; i++){
        for (int j = 0; j<y;j++){
            arr[i][j]=count;
            count++;
        }
    }

    for (int i = 0; i<x; i++){
        for (int j = 0; j<y;j++){
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0 ; i <y; i++){
        delete[] arr[i];
        // { {}, {}, {}, {}, {} } 으로 해제
    }

    delete[] arr;
    // {} 으로 해제

    // 실습 배열 실습 응용
    // 몇명 학생 성적 평균을 구할지 입력 받기
    int stu_num;
    std::cout << "몇 명의 학생수를 입력하세요. : ";
    std::cin >> stu_num;
    int *score = new int[stu_num];

    for (int i = 0; i < stu_num; i++){
        int stu_score;
        std::cout << i+1<<"번 학생의 성적을 입력하세요. ";
        std::cin >> stu_score;
        score[i]=stu_score;
    }
    double total_score=0;
    for (int i = 0; i<stu_num;i++){
        total_score +=score[i];
    }

    delete[] score;
    std::cout << "성적 평균은 : "<< total_score/stu_num << std::endl;

    
    // 입력받은 학생 수 만큼 성적을 입력 받기

    // 학생들의 성적 평균 산출하기

}