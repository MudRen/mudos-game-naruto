#include <ansi.h>
#define SKILL_NAME "dirge lion"
#define SKILL_NAME_C "��l���q"
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

    if( !me->query_temp("weapon/righthand") && !me->query_temp("weapon/lefthand") && !me->query_temp("weapon/twohanded")) {
        tell_object(me, "�o�O�@�M�y�ޯ�A�������@��Z���~��ϥΡC\n");
        return 0;
    }

    if( me->query_condition("lion_cd") ) {
        tell_object(me, "�ثe�߯��L�k�M�`�C\n");
        return 0;
    }

    if( me->query_skill("blade", 1) < 200 || sk < 60 ) {
        tell_object(me, "�A����O�����H�ϥγo�@�ۡC\n");
        return 0;
    }

    if( me->query_stat("mp") < sk/3 ) {
        tell_object(me, "�A���骬�p���ΡA����ϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    return 1;
}

// �p��O�_�R��
int isHit(object me, object target)
{
    int i, j;

    i = COMBAT_D->intimidate(me, 1)*1.5;
    j = COMBAT_D->wittiness(target, 1);

    if( COMBAT_D->SkillHit(me, target, i, j) ) return 1;
    else return 0;
}

// ���o�ˮ`
int getDamage(object me, object target, int sk)
{
    int damage, raiseDamage;
    object wp;

    raiseDamage = sk*5 + me->query_skill("savage hit")*2 + me->query_skill("blade");

    if( me->query_attr("str") < 300 ) raiseDamage += me->query_attr("str")*5;
    else raiseDamage += 1500;

    me->add_temp("apply/attack", raiseDamage);

    if( wp = me->query_temp("weapon/twohanded") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/righthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/lefthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else damage = COMBAT_D->isDamage(me, target, 0);

    me->add_temp("apply/attack", -raiseDamage);

    return damage;
}

// �ޯ�ϥΫ� 
void setEffect(object me, int sk, int hit)
{
    mapping cnd = ([]);

    if( !hit ) {
        me->start_busy(3);
    } else {
        me->start_busy(1);
    }
    cnd["name"] = YEL+"(CD)��l"+NOR;
    cnd["duration"] = 10;

    me->set_condition("lion_cd", cnd);
    me->damage_stat("mp", sk/3, me);
    me->improve_skill(SKILL_NAME, 1);
}

int perform_action(object me, string act, object target)
{
    int damage, sk, hit;

    sk = me->query_skill(SKILL_NAME, 1);

    // �ˬd�O�_��ϥΧޯ�
    if( !isCast(me, act, target, sk) ) return 1;

    message_vision("\n$N"HIW"�`�`�l�F�@�f��A���رN�M�٤J�T���u"HIM"�@�M�y�E�~�X"HIW"�v�߯�������`�b�M�N�����I\n"NOR, me, target);

    // �P�_�R��
    hit = isHit(me, target);

    if( !hit ) {
        message_vision(HIK"$n"HIK"�ݯ}�F�ۦ����¤O�A�ߨ�X�۱N$N"HIK"�������d�F�U�ӡC\n\n"NOR, me, target);
    } else {
        damage = getDamage(me, target, sk);
        target->receive_damage(damage, me);
        message_vision( sprintf(HIR"$N�����@�G�A�����ޤM��L$n"HIR"�n�`"NOR+YEL"�y��l���q�z"HIR"$n"HIR"�Q�X�j�q�A��I�I"NOR"(%d) %s\n\n", damage, COMBAT_D->report_status(target) ), me, target);
    }
    setEffect(me, sk, hit);
    return 1;
}
