#include <ansi.h>
#define SKILL_NAME "fire wall"
#define SKILL_NAME_C "����"
#define SKILL_CLASS "variation"

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

// �����ޥ��v�T
int intimidate(object me, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)*3/40;
}

// ��b�ˮ`�e�]�X�A�Ω�s�@�L�ĩάި��m
int receiveDamage(object me, object target, int damage)
{
    int raiseDamage, i;
    object wp;

    raiseDamage = me->query_skill(SKILL_NAME) + me->query_skill("variation")/2 + me->query_skill("fire variation")/2;

    if( me->query_condition("firewall", 1) != 0) {

        if( wp = me->query_temp("weapon/twohanded") ) i = COMBAT_D->isDamage(me, target, wp);
        else if( wp = me->query_temp("weapon/righthand") ) i = COMBAT_D->isDamage(me, target, wp);
        else if( wp = me->query_temp("weapon/lefthand") ) i = COMBAT_D->isDamage(me, target, wp);
        else i = COMBAT_D->isDamage(me, target, 0);

        i = (i*(100+(me->query_skill(SKILL_NAME)/4)))/(500-raiseDamage);

        target->receive_damage(i, me);
        message_vision("\n$n"RED"���F�ϧ����R��$N���V�Q���K�N�ˤF"HIR"("+i+")\n"NOR, me, target);
    }
    return damage;
}

// �ˬd�O�_��ϥΧޯ�
int isCast(object me, string act, object target, int sk)
{
    if( !objectp(me) ) return 0;

    if( me->is_busy() ) {
        tell_object(me, "�A�{�b�S���Ũϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    if( act != "fire" ) {
        tell_object(me, "�ثe" + SKILL_NAME_C + "�u�� fire �\\��C\n");
        return 0;
    }

    if( !me->is_fighting() ) {
        tell_object(me, "�����b�԰����~��I�i" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    if( me->query_skill("variation", 1) < 60 || sk < 60 ) {
        tell_object(me, "�A����O�����H�ϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    if( me->query_stat("mp") < 100 ) {
        tell_object(me, "�A���骬�p���ΡA����ϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    if( me->query_condition("firewall", 1) != 0) {
        tell_object(me, "�A�w�g��" + SKILL_NAME_C + "�]��|�P�F�C\n");
        return 0;
    }

    return 1;
}

void do_perform(object me, int sk)
{
    mapping cnd = ([]);

    message_vision("\n$N�B�_���O���¦a���@��A�u���j��"HIR"�����ĤѧΦ�"NOR+RED"�u����v"NOR"�N$N�]�Ш䤤�I\n\n"NOR, me);

    cnd["name"] = RED+"����"+NOR;
    cnd["duration"] = sk;
    cnd["from"] = me;

    me->set_condition("firewall", cnd);

    // �W�[�ޯ�g��
    me->damage_stat("mp", 100, me);
    me->start_busy(3);
    me->improve_skill(SKILL_NAME, 1);
    return;
}

int perform_action(object me, string act, object target)
{
    int sk;

    sk = me->query_skill(SKILL_NAME, 1);

    if( !isCast(me, act, target, sk) ) return 1;

    do_perform(me, sk);
    return 1;
}
