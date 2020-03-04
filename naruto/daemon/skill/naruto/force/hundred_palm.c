/* ���s�}�� & �ק�ˮ`���� by mouse 2007/8/14 */

#include <ansi.h>
#define SKILL_NAME "hundred palm"
#define SKILL_NAME_C "�ʯP�x"
#define SKILL_CLASS "force"

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

// �����O�q�v�T
int attack(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/5;
}

// �ˬd�O�_��ϥΧޯ�
int isCast(object me, string act, object target, int sk)
{
    if( !objectp(me) || !objectp(target) ) return 0;

    if( me->is_busy() ) {
        tell_object(me, "�A�{�b�S���Ũϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    if( act != "attack" ) {
        tell_object(me, "�ثe" + SKILL_NAME_C + "�u�� attack �\\��C\n");
        return 0;
    }

    if( !me->is_fighting(target) ) {
        tell_object(me, "�A�å��M���b�԰���...\n");
        return 0;
    }

    if( me->query_condition("hundred_cd") ) {
        tell_object(me, "�A���G�ٵL�k�F���a���`�ϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    if( sk < 30 || me->query_skill("force") < 20 ) {
        tell_object(me, "�A����O�����H�ϥγo�@�ۡC\n");
        return 0;
    }

    if( me->query_stat("mp") < sk/4 ) {
        tell_object(me, "�A���骬�p���ΡA����ϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    return 1;
}

// �p��O�_�R��
int isHit(object me, object target)
{
    int i, j;

    i = COMBAT_D->intimidate(me, 1)*2;
    j = COMBAT_D->wittiness(target, 1) + COMBAT_D->evade(target, me, 1)/2;

    if( COMBAT_D->SkillHit(me, target, i, j) ) return 1;
    else return 0;
}

// ���o�ˮ`
int getDamage(object me, object target, int sk)
{
    object wp;
    int damage, raiseDamage, white, str;

    white = me->query_skill("white eyes", 1);

    if( me->query_condition("white_eyes") && white > 70 ) {
        if( me->query_attr("str") > 300 ) str = 600;
        else str = me->query_attr("str")*2;
    } else {
        if( me->query_attr("str") > 300 ) str = 300;
        else str = me->query_attr("str");
    }
    raiseDamage = str + sk*3 + me->query_skill("force");

    me->add_temp("apply/attack", raiseDamage);

    if( wp = me->query_temp("weapon/twohanded") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/righthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/lefthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else damage = COMBAT_D->isDamage(me, target, 0);

    me->add_temp("apply/attack", -raiseDamage);

    return damage;
}

// �ޯ�ϥΫ� 
void setEffect(object me, int sk)
{
    mapping cnd = ([]);

    cnd["name"] = HIW+"(CD)�ʯP"+NOR;
    cnd["duration"] = 5;

    me->set_condition("hundred_cd", cnd);
    me->damage_stat("mp", sk/6, me);
    me->improve_skill(SKILL_NAME, 1);
}

// ��ʧ���
int perform_action(object me, string act, object target)
{
    int damage, sk, hit;

    sk = me->query_skill(SKILL_NAME, 1);

    // �ˬd�O�_��ϥΧޯ�
    if( !isCast(me, act, target, sk) ) return 1;

    // �O�_�R��
    hit = isHit(me, target);

    message_vision("\n$N�N�d�J�ԹλE��k�x���A�@��"HIW"�y"HIC + SKILL_NAME_C + HIW"�z"NOR"���$n��������...\n", me, target);
    if( hit ) {
        damage = getDamage(me, target, sk);

        // �ˮ`�ާl��
        damage = COMBAT_D->receive_damage(target, me, damage);

        target->receive_damage(damage, me);
        message_vision( sprintf("$n�{�פ��ΡA�w�ͥͤ��F�o�ۭ��^�F�Ƥ�...(%d) %s\n\n", damage, report_status(target) ), me, target);
        me->start_busy(1);
    } else {
        message_vision("$N���I�L�媺�{�L�F�o�@��...\n\n", target);
        me->start_busy(3);
    }
    setEffect(me, sk);
    return 1;
}
