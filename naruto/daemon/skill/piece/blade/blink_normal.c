#include <ansi.h>
#define SKILL_NAME "blink normal"
#define SKILL_NAME_C "�����{��"
#define SKILL_CLASS "blade"

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

int exact(object me, object target, int ability, int type)
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
int getDamage(object me, object target, int sk)
{
    int damage, raiseSK;
    object wp;

    raiseSK = sk + me->query_skill("blade");

    if( wp = me->query_temp("weapon/twohanded") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/righthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/lefthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else damage = COMBAT_D->isDamage(me, target, 0);

    if( raiseSK < 150 ) return damage*2/5;        // 40%
    else if( raiseSK < 200 ) return damage*3/5;   // 60%
    else if( raiseSK < 250 ) return damage*4/5;   // 80%
    else if( raiseSK < 300 ) return damage;       // 100%
    else if( raiseSK < 360 ) return damage*11/10; // 110%
    else return damage*125/100;              // 125%
}

// �ޯ�ϥΫ� 
void setEffect(object me, int sk, int hit)
{
    if( !hit ) {
        me->damage_stat("mp", sk/40, me);
    } else {
        me->damage_stat("mp", sk/20, me);
    }
    me->improve_skill(SKILL_NAME, 1);
}

int autoCasting(object me, object target, object weapon)
{
    int damage, sk, hit;

    sk = me->query_skill(SKILL_NAME, 1);

    // �P�_�O�_�Ұ�
    if( !me->query_temp("weapon/righthand") && !me->query_temp("weapon/lefthand") && !me->query_temp("weapon/twohanded")) return 1;
    if( me->query_stat("mp") < sk/20 ) return 1;
    if( me->query_skill("blade", 1) < 20 ) return 1;
    if( sk < 20 ) return 1;

    if( sk < 80 ) {                          
        if( random(sk) < sk*9/10 ) return 1; // 20~80 �� 10%
    } else if( sk < 150 ) {                  
        if( random(sk) < sk*8/10 ) return 1; // 81~150 �� 20%
    } else {                                 
        if( random(sk) < sk*7/10 ) return 1; // 151~200 �� 30%
    }
    // �R��
    hit = isHit(me, target);

    message_vision("\n$N���D�R"HIG"�ګD�`�Q�������g���M�k�I�ݧڪ��u"+me->query("name")+HIG"�ųΡv�I\n\n"NOR, me, target);
    message_vision("$N�|�_�Z���µ�$n�o�X�@�D�E�Q�ת����M��"HIC"�y"HIW"�����{��"HIC"�z"NOR"���V$n�I\n", me, target);

    if( !hit ) {
        message_vision("$N�y�L������]�}�@�ǡA�����K���u�����F...\n", target);
    } else {
        damage = getDamage(me, target, sk);

        // �ˮ`�ާl��
        damage = COMBAT_D->receive_damage(target, me, damage);

        target->receive_damage(damage, me);
        message_vision( sprintf("�u��v$n�Q���������A�u�����a�����Q�M����}(%d) %s\n", damage, COMBAT_D->report_status(target) ), me, target);
    }
    setEffect(me, sk, hit);
    return 1;
}