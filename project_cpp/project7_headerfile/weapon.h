# pragma once

#ifndef __WEAPON_H__
#define __WEAPON_H__

#include <iostream>
#include <vector>
using namespace std;

class Weapon{
    
    public:
        string grade;
        int weapon_damage;
        int weapon_critical_hit;
        int weapon_critical_damage;

        Weapon(string g, int wd, int wch, int wcd);
    
};
#endif

