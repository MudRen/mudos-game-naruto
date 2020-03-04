#include <ansi.h>
#define SKILL_NAME "body skill"
#define SKILL_NAME_C "�K�����k"
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

// ���o�ˮ`
int getDamage(object me, object target, int sk, int i)
{
    int damage, raiseDamage;
    object wp;

    raiseDamage = sk*8 + me->query_skill("body iron")*3;

    if( i == 1 ) raiseDamage += me->query_skill("gun finger")*3;
    else if( i == 2 ) raiseDamage += me->query_skill("kick haze wolf")*3;
    else if( i == 3 ) raiseDamage += me->query_skill("heavy hit")*2 + me->query("savage hit");

    me->add_temp("apply/attack", raiseDamage); 

    if( wp = me->query_temp("weapon/twohanded") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/righthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/lefthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else damage = COMBAT_D->isDamage(me, target, 0);

    me->add_temp("apply/attack", -raiseDamage);

    return damage;
}

int autoCasting(object me, object target, object weapon)
{
    string msgin, msgout;
    int damage, sk, i;

    sk = me->query_skill(SKILL_NAME, 1);

    // �P�_�O�_�Ұ�
    if( me->query_stat("mp") < sk/5 ) return 1;
    if( me->query_skill("body iron", 1) < 200 ) return 1;
    if( sk < 40 ) return 1;

    if( sk < 80 ) {                          
        if( random(sk) < sk*9/10 ) return 1;  // 20~80 �� 10%
    } else if( sk < 150 ) {                  
        if( random(sk) < sk*17/20 ) return 1; // 81~150 �� 15%
    } else {                                 
        if( random(sk) < sk*8/10 ) return 1;  // 151~200 �� 20%
    }
    i = random(3) + 1;

    switch( i ) {
        case 1:
            msgin = "$N�k�⭹�����M��$n�@�u�A�S�X�y�U������"RED"�y"HIC"�K�����k�E�T����"NOR+RED"�z"NOR"�I\n";
            msgout = "�u�ԡv�a�@�n�A$n�Q�����Ҽu���A��ӤH���F�X�h(%d)%s\n";
            break;
        case 2:
            msgin = "$N�T�q�@�n�o��"RED"�y"HIY"�K�����k�E�T��"NOR+RED"�z"NOR"�H���֪��t�׹G��$n�ǳƶi�欼�y�I\n";
            msgout = "$n�|�������L�ӡA$N���W�X�ۡu�|���K�褧��v�������ˤF$n(%d)%s\n";
            break;
        case 3:
            msgin = "$N��X�h�D�����A���l�ϰ_"RED"�y"HIM"�K�����k�E���B�T"NOR+RED"�z"NOR"�é���������b$n�I\n";
            msgout = "$n���U�۩�m�����A�֪�$N��M�X�{�H����$n�P�R�@��(%d)%s\n";
            break;
        default:
            msgin = "���������...�֧�Ův�ӭײz�a�C\n";
            msgout = "�o�өۦ��S���ˮ`�A�]����������F�C\n";
            break;
    }
    message_vision(msgin, me, target);
    if( !COMBAT_D->isHit(me, target) ) {
        message_vision("$N�n���Q�T���P�ƤF�A������@�b���M�ۦb��a�ȶ�ȶ㪺�s...\n", me, target);
        me->start_busy(2);
    } else {
        damage = getDamage(me, target, sk, i);
        target->receive_damage(damage, me);
        message_vision( sprintf(msgout, damage, COMBAT_D->report_status(target) ), me, target);
    }
    me->damage_stat("mp", sk/2, me);
    me->improve_skill(SKILL_NAME, 1);
    return 1;
}