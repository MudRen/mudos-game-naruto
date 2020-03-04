#include <ansi.h>
#define SKILL_NAME "gun finger"
#define SKILL_NAME_C "���j"
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

int attack(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)*3/5;
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

    if( sk < 100 ) return damage*3/4;          // 75%
    else if( sk < 120 ) return damage*9/10;    // 90%
    else if( sk < 150 ) return damage*11/10;   // 110%
    else if( sk < 180 ) return damage*5/4;     // 125%
    else if( sk < 199 ) return damage*7/5;     // 140%
    else return damage*3/2;                    // 150%
}

// �ޯ�ϥΫ� 
void setEffect(object me, int sk)
{
    me->damage_stat("mp", sk/20, me);
    me->improve_skill(SKILL_NAME, 1);
}

int autoCasting(object me, object target, object weapon)
{
    string *name = ({ "�ӻH", "�k�j�L", "�{�l", "�k�u", "�I��", "�k�p�L", "�ݤf", 
                      "���j�L", "���u", "���p�L", "�k��", "����", "�߷F", "����",
                      "���\\", "����", "�@�B", "��m", "����", "���U", "���",
                      "�{��", "�Ǥl", "�@����", "����", });

    int damage, sk, hit;

    sk = me->query_skill(SKILL_NAME, 1);

    // �P�_�O�_�Ұ�
    if( me->query_stat("mp") < sk/20 ) return 1;
    if( me->query_skill("martial", 1) < 20 ) return 1;
    if( sk < 20 ) return 1;

    if( sk < 80 ) {
        if( random(sk) < sk*9/10 ) return 1; // 20~80 �� 10%
    } else if( sk < 150 ) {
        if( random(sk) < sk*8/10 ) return 1; // 81~150 �� 20%
    } else {
        if( random(sk) < sk*7/10 ) return 1; // 151~200 �� 30%
    }
    hit = COMBAT_D->isHit(me, target);

    message_vision("$N�ϥX"HIY"�y"HIW"���j"HIY"�z"NOR"�k����X�����ֳt�W�V$n��"+name[random(sizeof(name))]+"�I\n", me, target);
    if( !hit ) {
        message_vision("$n���X���u���V$N����b�A��}�F�����C\n", me, target);
    } else {
        damage = getDamage(me, target, sk);
        target->receive_damage(damage, me);
        message_vision( sprintf("�u�P�v�a�@�n$N������b$n���W�W�X�@�Ӷˤf...(%d) %s\n", damage, COMBAT_D->report_status(target) ), me, target);
    }
    setEffect(me, sk);
    return 1;
}