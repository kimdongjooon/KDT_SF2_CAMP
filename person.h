#pragma once // 한번이라도 읽혔으면 안읽겠다.

#ifndef __PERSON_H__ // 정의가 안되어있다면.
#define __PERSON_H__ // 정의하겠다.
#include <iostream>
using namespace std;

class Person{ // 선언부만 남기기
    
    public:
        static int cnt;
        Person();
        Person(string name);
        static int ver;
        string name;
        int id;
        void sleep();
        static void static_method();

};
#endif