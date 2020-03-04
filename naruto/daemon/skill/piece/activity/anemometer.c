#include <ansi.h>
#define SKILL_NAME "anemometer"
#define SKILL_NAME_C "���t�p"
#define SKILL_CLASS "activity"

inherit SKILL;

void create()
{
    seteuid(getuid());
    DAEMON_D->register_skill_daemon(SKILL_NAME);
}

string query_class() { return SKILL_CLASS; }

void skill_advanced(object me, string skill)
{
    int lv = me->query_skill(skill, 1);
    switch( lv ) {
        case 189: me->set_skill_require(skill, 1500000); break; // ���d3 : 189��190
        case 149: me->set_skill_require(skill, 1000000); break; // ���d2 : 149��150
        case  99: me->set_skill_require(skill, 500000);  break; // ���d1 :  99��100
        default:  me->set_skill_require(skill, lv*lv*5); break;
    }
}

int wittiness(object me, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/5;
}

// �p��O�_�R��
int isHit(object me, object target)
{
    int hit, raiseHit;

    raiseHit = me->query_skill(SKILL_NAME, 1);

    me->add_temp("apply/exact", raiseHit); 
    hit = COMBAT_D->isHit(me, target);
    me->add_temp("apply/exact", -raiseHit);

    return hit;
}

// ���o�ˮ`
int getDamage(object me, object target, int sk, object staff)
{
    int damage;
    object wp;

    if( wp = me->query_temp("weapon/twohanded") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/righthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/lefthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else damage = COMBAT_D->isDamage(me, target, 0);

    damage += staff->query("damage/twohanded/upper");

    if( sk < 100 ) return damage*3/4;          // 75%
    else if( sk < 120 ) return damage*9/10;    // 90%
    else if( sk < 150 ) return damage*11/10;   // 110%
    else if( sk < 180 ) return damage*5/4;     // 125%
    else if( sk < 199 ) return damage*7/5;     // 140%
    else return damage*3/2;                    // 150%
}

int autoCasting(object me, object target, object weapon)
{
    int damage, sk;
    object staff;

    sk = me->query_skill(SKILL_NAME, 1);

    // ���������W���S���ѭԴΡA�S�ѭԴδN���κ���v�F
    if( !objectp(staff = present("_WEATHER_", me)) ) return 1;

    // �P�_�O�_�Ұ�
    if( me->query_stat("mp") < sk/15 ) return 1;
    if( me->query_skill("activity", 1) < 20 ) return 1;
    if( sk < 20 ) return 1;

    if( sk < 80 ) {                          
        if( random(sk) < sk*9/10 ) return 1; // 20~80 �� 10%
    } else if( sk < 150 ) {                  
        if( random(sk) < sk*17/20 )return 1;  // 81~150 �� 15%
    } else {                                
        if( random(sk) < sk*3/4 ) return 1; // 151~200 �� 25%
    }
    message_vision("$N�N�ѭԴζi��R�q�ʧ@�A���ֳۧt�]�V$n�ϥX"+staff->query("name")+HIC"�y"HIW"���t�p"HIC"�z"NOR"�I\n", me, target);
    
    if( !isHit(me, target) ) {
        message_vision("���t�p���X���p�q�����F��V�A�S������$N...\n", target);
    } else {
        damage = getDamage(me, target, sk, staff);

        target->receive_damage(damage, me);
        message_vision( sprintf("�u�Դ��v�@�n�A$n�Q�p�q�������A�o�X�}�}�N�׭�(%d) %s\n", damage, COMBAT_D->report_status(target) ), me, target);
    }
    me->damage_stat("mp", sk/15, me);
    me->improve_skill(SKILL_NAME, 1);
}