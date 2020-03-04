// forst_closed_ball.c �ܤƨt lv2 - �B�ʲy
// 2006/06/04 -Tmr
// �s�W�S��ޯ� by mouse 2007/7/25

#include <ansi.h>
#define SKILL_NAME   "frost closed ball"
#define SKILL_NAME_C "�B�ʲy"
#define SKILL_CLASS  "variation"

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

/*
|       �ޯ�v�T�G
|                �ޯ�G 0------50------100------150---175---200
|            �B��ɶ��G     1               2            3
|            �ˮ`�t�ơG 100% -----------------------------> 300%
|
*/

/*
|       �ק�᪺�ޯ�v�T 2007/7/25
|       ������P�whit�ơA�F������y�����A�ȡA���A��0�ɲ��Ͷˮ`
|
|       �ޯ�G0------------------100--------------150----------200
|       �ɶ��Gsk*2                sk/5             sk/20
*/       

// �ˬd�O�_��ϥΧޯ�
int isCast(object me, string act, object target, int sk)
{
    if( !objectp(me) || !objectp(target) ) return 0;

    if( act != "ball" ) {
        tell_object(me, SKILL_NAME_C + "�ثe�u�� ball �\\��C\n");
        return 0;
    }

    if( me->is_busy() ) {
        tell_object(me, "�A�����ۡA�S���Ũϥγo�ӧޯ�C\n");
        return 0;
    }

    if( target->is_busy() && target->query_condition("iceball") != 0 ) {
        tell_object(me, "���w�g����ʤF�A���ݭn�A�ΦB�ʲy�h�����ʡC\n");
        return 0;
    }

    if( !me->is_fighting(target) ) {
        tell_object(me, "�A�å��M���b�԰���...\n");
        return 0;
    }

    if( me->query_skill("variation", 1) < 50 ) {
        tell_object(me, "�A���ܤƨt�{���٨S�F�� 50 �šA�L�k�ϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    if( me->query_skill("ice variation", 1) < 80 ) {
        tell_object(me, "�A���B���O�ܤ��٨S�F�� 80 �šA�L�k�ϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    if( me->query_stat("mp") < 100 ) {
        tell_object(me, "�A������O���� 100 �I�C\n");
        return 0;
    }

    if( me->query_condition("iceball_cd") ) {
        tell_object(me, "�A�ثe�ٵL�k�ϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    return 1;
}

int get_times(int lv)
{
    if( lv <= 100 ) return 1;
    if( lv <= 150 ) return 2;
    return 3;
}

int get_bonus(int lv)
{
    if(lv < 1 ) return 100;
    return lv + 100;
}

int ice_time(int sk)
{
    if( sk < 100 ) return sk/2;
    else if( sk < 150 ) return sk/10;
    else return sk/20;
}

// ���o�ˮ`
int getDamage(object me, object target, int sk, int bonus)
{
    int raiseDamage, damage;
    object wp;

    raiseDamage = sk*3 + bonus*2 + me->query_skill("ice variation")*2;

    me->add_temp("apply/attack", raiseDamage);

    if( wp = me->query_temp("weapon/twohanded") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/righthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/lefthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else damage = COMBAT_D->isDamage(me, target, 0);

    me->add_temp("apply/attack", -raiseDamage);

    damage = damage/4;
    return damage;
}

void do_attack(object me, object target, int sk)
{
    int bonus, hit, times, icetime, damage;
    mapping cnd = ([]);

    times = get_times(sk);
    bonus = get_bonus(me->query_skill("variation"));
    icetime = ice_time(sk);

    // �R���v
    hit = COMBAT_D->isHit(me, target);

    // �ˮ`�p��
    damage = getDamage(me, target, sk, bonus);

    if( hit ) {
        // �ˮ`�ާl��
        damage = COMBAT_D->receive_damage(target, me, damage);

        target->receive_damage(damage, me);
        message_vision( sprintf(HIB"\t$n"HIB"�Q�B�ʲy���ӥ��ۡA�S�p�m���B���A$n"HIB"�����W�U���C�C�������B�F..."NOR"(%d) %s\n", damage, COMBAT_D->report_status(target) ), me, target);

        cnd["name"] = HIB+"�B�ʲy"+NOR;
        cnd["duration"] = icetime;
        cnd["from"] = me;
        cnd["damage"] = damage*4;

        // �w�g�B��N���B�F�A�קK buff �@���s�b
        if( target->query_condition("iceball") == 0 ) target->set_condition("iceball", cnd);

        // �w�H����
        target->start_busy(times);
    } else {
        // �ˮ`�A��z
        damage = damage/4;

        // �ˮ`�ާl��
        damage = COMBAT_D->receive_damage(target, me, damage);

        target->receive_damage(damage, me);
        message_vision( sprintf(HIB"\t$n"HIB"�Q�B�ʲy�X�����l�������A���l���F�ӧNŸ"NOR"(%d) %s\n", damage, COMBAT_D->report_status(target) ), me, target);
    }

    cnd["name"] = HIB+"(CD)�B�y"+NOR;
    cnd["duration"] = 10;

    // ���ެO�_���������Ӧ�cd
    me->set_condition("iceball_cd", cnd);
}

void do_shoot(object me, object target, int sk)
{
    message_vision(HIW"�@�ɥѵL�ƦB�@�զ���"HIC"�B�ʲy"HIW"�q$N�⤤�X�{�A���a�@�n�N��$n"HIW"�Y�h�I�I�I\n"NOR, me, target);
    do_attack(me, target, sk);
    me->damage_stat("mp", 50, me);
}

// �ϥε���
int perform_action(object me, string act, object target)
{
    int sk;

    sk = me->query_skill(SKILL_NAME, 1);

    if( !isCast(me, act, target, sk) ) return 1;

    do_shoot(me, target, sk);
    me->improve_skill( SKILL_NAME, 1);
    me->start_busy(2);

    return 1;
}
