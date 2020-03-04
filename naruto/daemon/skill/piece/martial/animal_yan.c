#include <ansi.h>
#define SKILL_NAME "animal yan"
#define SKILL_NAME_C "�~�Y"
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

int wittiness(object me, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/10;
}

// �p��O�_�R��
int isHit(object me, object target)
{
    int i, j;

    i = COMBAT_D->intimidate(me, 1)*2;
    j = COMBAT_D->wittiness(target, 1) + COMBAT_D->intimidate(target, 1);

    if( COMBAT_D->SkillHit(me, target, i, j) ) return 1;
    else return 0;
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

    if( sk < 100 ) return damage;              // 100%
    else if( sk < 120 ) return damage*11/10;   // 110%
    else if( sk < 150 ) return damage*6/5;     // 120%
    else if( sk < 180 ) return damage*13/10;   // 130%
    else if( sk < 199 ) return damage*3/2;     // 150%
    else return damage*7/4;                    // 175%
}

// �ޯ�ϥΫ� 
void setEffect(object me, int sk, int hit)
{
    if( !hit ) {
        me->damage_stat("mp", sk/12, me);
    } else {
        me->damage_stat("mp", sk/6, me);
    }
    me->improve_skill(SKILL_NAME, 1);
}

int autoCasting(object me, object target, object weapon)
{
    string *name = ({ "�ӻH", "�k�j�L", "�{�l", "�k�u", "�I��", "�k�p�L", "�ݤf", 
                      "���j�L", "���u", "���p�L", "�k��", "����", "�߷F", "����",
                      "���\\", "����", "�n�`", "����", "��l", });

    string msg = name[random(sizeof(name))];
    int damage, sk, hit;

    sk = me->query_skill(SKILL_NAME, 1);

    // �P�_�O�_�Ұ�
    if( me->query_stat("mp") < sk/6 ) return 1;
    if( me->query_skill("martial", 1) < 80 ) return 1;
    if( sk < 40 ) return 1;

    if( sk < 80 ) {
        if( random(sk) < sk*9/10 ) return 1; // 20~80 �� 10%
    } else if( sk < 150 ) {
        if( random(sk) < sk*8/10 ) return 1; // 81~150 �� 20%
    } else {
        if( random(sk) < sk*7/10 ) return 1; // 151~200 �� 30%
    }
    message_vision("$N�k�ⴤ���A�H���j���t�״��X�ֳt��"HIR"�y"HIY"�~�Y"HIR"�z"NOR"�@�����V$n��"+msg+"�I\n", me, target);

    hit = COMBAT_D->isHit(me, target);

    if( !hit ) {
        message_vision("�u�ԡv�a�@�n�A$N�n�z�L�O�����Y���b$n"+msg+"�A$n�@�I�Ƥ]�S���C\n", me, target);
        me->damage_stat("mp", sk/12, me);
    } else {
        damage = getDamage(me, target, sk);
        target->receive_damage(damage, me);
        message_vision( sprintf("�u�I�v�a�@�n$n��ӤH���F�X�h�A���Ъ�"+msg+"�����O�h�W���@(%d) %s\n", damage, COMBAT_D->report_status(target) ), me, target);
        if( random(sk) > sk*7/10 ) {
            damage = damage/2 + random(30);
            message_vision("$N�X�Ӱl���A���զV�e�ϥX�u"HIW"���j"NOR"�v�W�V$n��"+msg+"����C\n", me, target);
            target->receive_damage(damage, me);
            message_vision( sprintf("�u�P�v�a�@�n$n"+msg+"�A������G���ж�(%d) %s\n", damage, COMBAT_D->report_status(target) ), me, target);
            me->improve_skill(SKILL_NAME, 1);
        }
    }
    setEffect(me, sk, hit);
    return 1;
}