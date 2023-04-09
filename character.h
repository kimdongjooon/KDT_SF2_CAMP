#pragma once

#ifndef __CHARACTER_H_
#define __CHARACTER_H_

#include <iostream>
#include <vector>
#include "normal.h"
#include "rare.h"
#include "unique.h"
#include "legendary.h"
#include "mythic.h"

using namespace std;


class Character{
    // 필드
    int hp;
    int level;
    int base_attack_damage;
    double critical_hit;
    int critical_damage;
    string weapon_grade;

    // 기능
    public:
        string Character_name; // 플레이어 이름.
        vector <int> weapon_info; // 무기데미지, 무기 치명타확률, 무기 치명타 데미지
        vector <int> get_weapon; // 인덱스순 노말 레어 유니크 레전더리 신화
        // 캐릭터 처음 생성
        Character(string name);

        // 캐릭터 불러 오기 캐릭터 이름과 소지했던 무기만 불러움. 그외다 초기화.
        Character(string CN, int N, int R, int U, int L, int M);


        // 상태창 보기
        void status();
        int getDamage();

        double getCritical_damage();

        double getCritical_hit();

        double getCritical_damage_p();

        void weapon_swaping(Weapon W);

        void weapon_equip();

        // 몬스터 공격하기
        int monster_attack(int critical_point, int monster_hp);
        
        // 보스 어택.
        int boss_attack(int critical_point);


        // 사냥하기
        static int monster_hp;
        void hunting();

        // 월드 보스 딜미터기 
        void world_boss_dps();

};


#endif