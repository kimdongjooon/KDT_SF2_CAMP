#pragma once

#ifndef __CHOCOLATE_H__
#define __CHOCOLATE_H__

#include <iostream>
using namespace std;
#include "snack.h"
class Chocolate:public Snack{
    string shape;
    public:
        Chocolate();

        Chocolate(string s,int p, string n, string c);
        
        // Chocolate(string name):Snack(name){}

        Chocolate(string shape);

        void Chocolate_print();

        void print_info();
};
#endif