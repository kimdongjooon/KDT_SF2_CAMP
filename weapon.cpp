#include "weapon.h"

string grade;
int weapon_damage;
int weapon_critical_hit;
int weapon_critical_damage;

Weapon::Weapon(string g, int wd, int wch, int wcd){
    this->grade=g;
    this->weapon_damage=wd;
    this->weapon_critical_hit=wch;
    this->weapon_critical_damage=wcd;
}
