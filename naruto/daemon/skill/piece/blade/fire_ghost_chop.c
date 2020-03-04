#include <ansi.h>
#define SKILL_NAME "fire ghost chop"
#define SKILL_NAME_C "�N����"
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

int sock(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/40;
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

    if( me->query_skill("blade", 1) < 40 || sk < 60 ) {
        tell_object(me, "�A����O�����H�ϥγo�@�ۡC\n");
        return 0;
    }

    if( me->query_stat("mp") < sk/8 ) {
        tell_object(me, "�A���骬�p���ΡA����ϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    return 1;
}

// �p��O�_�R��
int isHit(object me, object target)
{
    int i, j;

    i = COMBAT_D->intimidate(me, 1);
    j = COMBAT_D->wittiness(target, 1);

    if( COMBAT_D->SkillHit(me, target, i, j) ) return 1;
    else return 0;
}

// ���o�ˮ`
int getDamage(object me, object target, int sk)
{
    int damage, raiseDamage;
    object wp;

    if( me->query_attr("str") < 300 ) raiseDamage = me->query_attr("str")/3 + sk*2;
    else raiseDamage = 100 + sk*2;

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
    me->damage_stat("mp", sk/8, me);
    me->start_busy(3);
    me->improve_skill(SKILL_NAME, 1);
}

int perform_action(object me, string act, object target)
{
    int damage, sk, i = 0;
    object *inv, item;
    mapping cnd = ([]);

    sk = me->query_skill(SKILL_NAME, 1);
    inv = all_inventory(me);

    // �ˬd�O�_��ϥΧޯ�
    if( !isCast(me, act, target, sk) ) return 1;

    foreach(item in inv) {
        if( item->is_weapon() ) {
            i++;
        }
    }
    if( !me->query_temp("weapon/righthand") || !me->query_temp("weapon/lefthand") || i < 3 ) 
        return notify_fail("�T�M�y�����˳ƨ��Z������a�ĤT��Z���~��ϥΡC\n");

    message_vision("\n$N�ϥX"HIR"�y"RED"�N����"HIR"�z"NOR"����Q�X�����P���A�N�T��M�O�q�E��@�I�ĦV$n�I\n", me, target);

    // �ˮ`�p��
    damage = getDamage(me, target, sk);

    cnd["name"] = HIR+"�ۤ����A"+NOR;
    cnd["duration"] = sk/20;
    cnd["from"] = me;

    if( !isHit(me, target) ) {
        message_vision("���G���V�u�b�a�W�N�X�@�����u...\n\n", target);
    } else {
        // �P�_���S���ۤ��A�w�g�ۤ��N���A���S���A
        if( target->query_condition("firedamage") ) {
            target->receive_damage(damage, me);
            message_vision( sprintf("$n�Q�T�M�e��ӹL�A�����O�Ϩ��l���F�_�ӡA�b�Ť��Q�X�j�q�A��(%d) %s\n\n", damage, COMBAT_D->report_status(target) ), me, target);
        } else {
            target->receive_damage(damage, me);
            message_vision( sprintf("���V����$n�����l���X�@�D���������u�A�Q�X���A�妭�w�Q���N��(%d) %s\n\n", damage, COMBAT_D->report_status(target) ), me, target);
            target->set_condition("firedamage", cnd);
        }
    }
    setEffect(me, sk);
    return 1;
}