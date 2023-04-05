#pragma once

#ifndef __CANDY_H__
#define __CANDY_H__

#include <iostream>
#include "snack.h"
using namespace std;
class Candy:public Snack{
    string flavor;
    public:
        Candy();
        
        Candy(string f,int p, string n, string c);
        

        // Candy(string name):Snack(name){}

        Candy(string flavor);

        void candy_print();

        void print_info();
    

};

#endif