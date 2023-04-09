#include "character.h"

// 캐릭터 처음 생성
Character::Character(string name){
    this->Character_name=name;
    hp = 100;
    level = 1;
    base_attack_damage = 10;
    critical_hit = 5;
    critical_damage = 100;
    weapon_grade="미장착";   
    cout<<name<<" 캐릭터가 생성되었습니다. "<<endl;
    cout<<endl;
}

// 캐릭터 불러 오기 캐릭터 이름과 소지했던 무기만 불러움. 그외다 초기화.
Character::Character(string CN, int N, int R, int U, int L, int M){
    this->Character_name=CN;
    hp = 100;
    level = 1;
    base_attack_damage = 10;
    critical_hit = 5;
    critical_damage = 100;
    weapon_grade="미장착";   
    get_weapon.clear();
    get_weapon.push_back(N);
    get_weapon.push_back(R);
    get_weapon.push_back(U);
    get_weapon.push_back(L);
    get_weapon.push_back(M);
    cout<<CN<<" 캐릭터 불러오기 완료!"<<endl;
}


// 상태창 보기
void Character::status(){
    cout<<"==== "<<Character_name<<"의 상태창 ===="<<endl;
    cout<<"현재 체력 : "<<hp<<endl;
    cout<<"현재 레벨 : "<<level<<endl;
    cout<<"기본 공격력 : "<<base_attack_damage<<endl;
    if(weapon_grade=="미장착"){
        cout<<"무기 공격력 : 0 - "<<weapon_grade<<endl;
    }else if (!weapon_info.empty()){
        cout<<"무기 공격력 : "<<weapon_info[0]<<" ("<<weapon_grade<<" 무기) - 착용중"<<endl;
    }
    cout<<"총 공격력 : "<<getDamage()<<endl;
    cout<<"치명타 확률 : "<<getCritical_hit()<<"%"<<endl;
    cout<<"치명타 데미지 : "<<getCritical_damage_p()<<"%"<<endl;
}
int Character::getDamage(){
    return base_attack_damage+weapon_info[0];
}

double Character::getCritical_damage(){   
    return getDamage()*(100+critical_damage+weapon_info[2])/100;
}

double Character::getCritical_hit(){
    return critical_hit+(double)weapon_info[1];
}

double Character::getCritical_damage_p(){   
    return critical_damage+weapon_info[2];
}

void Character::weapon_swaping(Weapon W){
    weapon_info.clear();
    weapon_grade = W.grade;
    weapon_info.push_back(W.weapon_damage);
    weapon_info.push_back(W.weapon_critical_hit);
    weapon_info.push_back(W.weapon_critical_damage);
}

void Character::weapon_equip(){
    cout<<"현재 무기 현황 - 노말:"<<get_weapon[0]<<" 레어:"<<get_weapon[1]<<" 유니크:"<<get_weapon[2]<<" 레전더리:"<<get_weapon[3]<<" 신화:"<<get_weapon[4] <<endl;
    cout<<"어떤 무기를 착용하시겠습니까? (0: 미착용, 1:노말, 2:레어, 3:유니크, 4:레전더리, 5:신화 ) ";
    int weapon_num;
    std::cin >> weapon_num;
    if(weapon_grade=="미장착" && weapon_num==0){
        cout<<"착용중인 무기가 없습니다."<<endl;
    }else if(weapon_num==0){
        cout<<"무기를 장착해제하였습니다."<<endl;
        weapon_grade="미장착";
        weapon_info.assign(4,0);
    }else if(get_weapon[0]>=1 && weapon_num==1){
        Normal N = Normal();
        weapon_swaping(N);
    }else if(get_weapon[1]>=1 && weapon_num==2){
        Rare R = Rare();
        weapon_swaping(R);
    }else if(get_weapon[2]>=1 && weapon_num==3){
        Unique U = Unique();
        weapon_swaping(U);
    }else if(get_weapon[3]>=1 && weapon_num==4){
        Legendary L = Legendary();
        weapon_swaping(L);                
    }else if(get_weapon[4]>=1 && weapon_num==5){
        Mythic M = Mythic();
        weapon_swaping(M);
    }
    else{
        cout<<"선택하신 무기가 없습니다."<<endl;
    }
}

// 몬스터 공격
int Character::monster_attack(int monster_damage, int player_hp){
    cout<<"야생 몬스터가 반격하여 "<<monster_damage<<"만큼의 데미지를 입힙니다."<<endl;
    return player_hp - monster_damage;
}

// 몬스터 공격하기
int Character::player_attack(int critical_point, int monster_hp){
    if(critical_point>=1 && critical_point<=getCritical_hit()){
        cout<<"**** 크리티컬!! ****"<<endl;
        cout<<"야생의 몬스터에게 "<<getCritical_damage()<<"의 데미지를 입혔습니다!!"<<endl;
        return monster_hp - getCritical_damage();
    }else if(getCritical_hit()<critical_point && critical_point<=100){
        cout<<"야생의 몬스터에게 "<<getDamage()<<"의 데미지를 입혔습니다!!"<<endl;
        return monster_hp - getDamage();
    }else{
        cout<<"오류1"<<endl;
        return 0;
    }
}

// 보스 어택.
int Character::boss_attack(int critical_point){
    if(critical_point>=1 && critical_point<=getCritical_hit()){
        cout<<"**** 크리티컬!! ****"<<endl;
        cout<<"월드 보스 몬스터에게 "<<getCritical_damage()<<"의 데미지를 입혔습니다!!"<<endl;
        return getCritical_damage();
    }else if(getCritical_hit()<critical_point && critical_point<=100){
        cout<<"월드 보스 몬스터에게 "<<getDamage()<<"의 데미지를 입혔습니다!!"<<endl;
        return getDamage();
    }else{
        cout<<"오류1"<<endl;
        return 0;
    }
}


// 사냥하기
static int monster_hp;
void Character::hunting(){
    srand(time(NULL));
    cout<<"(무기 확률 - 노말:56%, 레어:30%, 유니크:10%, 레전더리:3%, 신화:1%)"<<endl;
    cout<<" 야생의 몬스터 등장!! "<<endl;
    cout<<"체력 : "<<monster_hp<<endl;
    int weapon_point = rand()%100+1; // 1~100까지 랜덤으로 저장해서 지정된 구간에 해당시에 무기 획득.
    int tmp_monster_hp = monster_hp;
    while(1){
        cout<<"무엇을 하시겠습니까? (1: 공격, 0: 도망) : ";
        int action;
        std::cin >> action;
        if(action==1){
            int critical_point = rand()%100+1; // 1~100까지 랜덤으로 저장.
            tmp_monster_hp = player_attack(critical_point,tmp_monster_hp);
            if(tmp_monster_hp<=0){
                cout<<"야생의 몬스터 처지!"<<endl;
                cout<<"=== 레벨업!!! ==="<<endl;
                this->level++;
                this->hp = this->hp+10;
                this->base_attack_damage = this->base_attack_damage+5;
                this->critical_hit = (double)this->critical_hit + 0.1;
                this->critical_damage = this->critical_damage + 10;
                if(weapon_point>=1 && weapon_point<=56){
                    cout<<"노말 무기를 획득하였습니다!!"<<endl;
                    get_weapon[0]++;
                }
                else if(weapon_point>56 && weapon_point<=86){
                    cout<<"레어 무기를 획득하였습니다!!"<<endl;
                    get_weapon[1]++;
                }
                else if(weapon_point>86 && weapon_point<=96){
                    cout<<"유니크 무기 획득하였습니다!!"<<endl;
                    get_weapon[2]++;
                }
                else if(weapon_point>97 && weapon_point<=99){
                    cout<<"레전더리 무기 획득하였습니다!!"<<endl;
                    get_weapon[3]++;
                }
                else if(weapon_point>99 && weapon_point<=100){
                    cout<<"신화 무기 획득하였습니다!!"<<endl;
                    get_weapon[4]++;
                }
                else{
                    cout<<"오류2"<<endl;
                }
                monster_hp = monster_hp + rand()%250+50; // 몬스터 잡을때 마다 50~300 만큼의 체력 증가
                break;

            }else{
                cout<<"야생 몬스터 현재 채력 : "<<tmp_monster_hp<<endl;
            }
            
        } // 종료
        else if (action==0){
            cout<<"도망 성공"<<endl;
            break;
        }else{
            cout<<"공격(1) 또는 도망(0)을 선택해주세요."<<endl;
        }
        
    }
}

// 월드 보스 딜미터기 
void Character::world_boss_dps(){
    srand(time(NULL));
    int total_damage=0;
    cout<<"10번의 공격을 진행합니다."<<endl;
    for(int i = 1 ; i<=10 ; i++){
        int critical_point = rand()%100+1;
        total_damage=total_damage+boss_attack(critical_point);
        
    }
    cout<<"월드 보스에게 가한 총 데미지는 "<<total_damage<<"입니다."<<endl;   
}


int Character::monster_hp=100;