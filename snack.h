# pragma once

#ifndef __SNACK_H__
#define __SNACK_H__

#include <iostream>
using namespace std;

class Snack{
    protected:
        int price;
        string name;
        string company;
    
    public:
        static int count;
        // virtual ~Snack() {}
        Snack();

        Snack(int p, string n, string c);

        Snack(string name);

        void printName();
        virtual void print_info();// 가상은미리선언.
};
#endif

