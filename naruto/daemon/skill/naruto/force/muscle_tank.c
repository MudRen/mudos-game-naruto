// ���s�}�� & �W�[��O���� by mouse 2007/8/14

#include <ansi.h>
#define SKILL_NAME "muscle tank"
#define SKILL_NAME_C "�׼u�Ԩ�"
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

// ���m�O�q�v�T
int defend(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/4;
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

    if( sk < 50 || me->query_skill("force") < 50 ) {
        tell_object(me, "�A����O�����H�ϥγo�@�ۡC\n");
        return 0;
    }

    if( me->query_stat("mp") < sk/10 ) {
        tell_object(me, "�A���骬�p���ΡA����ϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }
    return 1;
}

// �p��O�_�R��
int isHit(object me, object target)
{
    int i, j;

    i = COMBAT_D->wittiness(me, 1);
    j = COMBAT_D->intimidate(target, 1);

    if( COMBAT_D->SkillHit(me, target, i, j) ) return 1;
    else return 0;
}

// ���o�ˮ`
int getDamage(object me, object target, int sk)
{
    int raiseDamage, damage;
    object wp;

    if( me->query_attr("con") > 300 ) raiseDamage = 600 + sk*3 + me->query_skill("force")/2;
    else raiseDamage = me->query_attr("con")*2 + sk*3 + me->query_skill("force")/2;

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
    if( !hit ) {
        me->start_busy(5);
    } else {
        me->start_busy(2);
    }
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

    message_vision("\n$N��M���_�F�Τj�����X�e�t�V�e�u�ʡA�ϥX"HIW"�y"CYN+SKILL_NAME_C+HIW"�z"NOR"�µ�$n�ļ�...\n", me, target);
    if( hit ) {
        damage = getDamage(me, target, sk);
        target->receive_damage(damage, me);
        message_vision( sprintf("$n�Ӥ��ΰ{���A�K�Q�o���׼u���o���R�ۮQ...(%d) %s\n\n", damage, report_status(target) ), me, target);
    } else {
        message_vision("$N���������L�o�@��...\n\n", target);
    }
    setEffect(me, sk, hit);
    return 1;
}
