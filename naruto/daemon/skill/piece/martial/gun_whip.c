#include <ansi.h>
#define SKILL_NAME "gun whip"
#define SKILL_NAME_C "���j�E�@"
#define SKILL_CLASS "martial"

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

int intimidate(object me, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/10;
}

// ���o�ˮ`
int getDamage(object me, object target, int sk)
{
    int damage;
    object wp;

    if( wp = me->query_temp("weapon/twohanded") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/righthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/lefthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else damage = COMBAT_D->isDamage(me, target, 0);

    if( sk < 100 ) return damage/4;          // 25%
    else if( sk < 120 ) return damage*7/25;  // 28%
    else if( sk < 150 ) return damage/3;     // 33%
    else if( sk < 180 ) return damage*13/50; // 36%
    else if( sk < 199 ) return damage*2/5;   // 40%
    else return damage*50/100;               // 50%

    return damage;
}

// �ޯ�ϥΫ� 
void setEffect(object me, int sk, int hit)
{
    if( !hit ) {
        me->damage_stat("mp", sk/30, me);
    } else {
        me->damage_stat("mp", sk/15, me);
    }
    me->improve_skill(SKILL_NAME, 1);
}

int autoCasting(object me, object target, object weapon)
{
    string *name = ({ "�ӻH", "�k�j�L", "�{�l", "�k�u", "�I��", "�k�p�L", "�ݤf", 
                      "���j�L", "���u", "���p�L", "�k��", "����", "�߷F", "����",
                      "���\\", "����", "�@�B", "��m", "����", "���U", "���",
                      "�{��", "�Ǥl", "�@����", "����", });

    string msg = name[random(sizeof(name))];
    int damage, sk, hit;

    sk = me->query_skill(SKILL_NAME, 1);

    // �P�_�O�_�Ұ�
    if( me->query_stat("mp") < sk/15 ) return 1;
    if( me->query_skill("martial", 1) < 40 ) return 1;
    if( sk < 20 ) return 1;

    if( sk < 80 ) {                          
        if( random(sk) < sk*9/10 ) return 1;  // 20~80 �� 10%
    } else if( sk < 150 ) {                  
        if( random(sk) < sk*19/20 ) return 1; // 81~150 �� 15%
    } else {                                 
        if( random(sk) < sk*4/5 ) return 1;   // 151~200 �� 20%
    }

    message_vision("$N��$n�ĤF�L�h�A"HIW"�y"HIB"���j�E�@"HIW"�z"NOR"�b�����e�k�⩿�M���@�@�˥ϰʩ�V$n"+msg+"�I\n", me, target);

    hit = COMBAT_D->isHit(me, target);

    if( !hit ) {
        message_vision("���O$N��������V���G�S����ǡA���_�F�a�W�@�����ǹ�...\n", me, target);

    } else {
        damage = getDamage(me, target, sk);
        target->receive_damage(damage, me);
        message_vision( sprintf("�u�ԡv�a�@�n����$n"+msg+"�A$n�]"+msg+"���Цӵh�W����(%d) %s\n", damage, COMBAT_D->report_status(target) ), me, target);
        if( me->query_skill("martial", 1) >= 60 && !target->is_busy() ) {
            target->start_busy((sk-20)/60);
        }
    }
    setEffect(me, sk, hit);
    return 1;
}