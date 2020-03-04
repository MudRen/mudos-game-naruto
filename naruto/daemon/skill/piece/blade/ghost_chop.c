#include <ansi.h>
#define SKILL_NAME "ghost chop"
#define SKILL_NAME_C "����"
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

int attack(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/2;
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

    if( me->query_condition("ghost_cd") ) {
        tell_object(me, "�������Ĩ�w�M�~��A���ϥΡC\n");
        return 0;
    }

    if( me->query_skill("blade", 1) < 30 || sk < 20 ) {
        tell_object(me, "�A����O�����H�ϥγo�@�ۡC\n");
        return 0;
    }

    if( me->query_stat("mp") < sk/10 ) {
        tell_object(me, "�A���骬�p���ΡA����ϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    return 1;
}

// ���o�ˮ`
int getDamage(object me, object target, int sk)
{
    int damage, raiseDamage;
    object wp;

    raiseDamage = sk + me->query_skill("blade")/2;

    if( me->query_attr("str") < 200 ) raiseDamage += me->query_attr("str");
    else raiseDamage += 200;

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
        me->damage_stat("mp", sk/20, me);
        me->start_busy(2);
    } else {
        me->damage_stat("mp", sk/10, me);
        me->start_busy(1);
    }
    cnd["name"] = HIK+"(CD)����"+NOR;
    cnd["duration"] = 3;

    me->set_condition("ghost_cd", cnd);
    me->improve_skill(SKILL_NAME, 1);
}

int perform_action(object me, string act, object target)
{
    int damage, sk, hit, i = 0;
    object *inv, item;

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

    message_vision("\n$N�N�T��M���O�q�E��@�I�A�ϥX"HIM"�y"HIK"����"HIM"�z"NOR"�ֳt�a�ĩ�$n���e�I\n", me, target);

    // �P�_�R��
    hit = COMBAT_D->isHit(me, target);

    if( !hit ) {
        message_vision("$N�ݷǤF�������_�ӡA���l�@�C�{�L�F�����C\n\n", target);
    } else {
        damage = getDamage(me, target, sk);
        target->receive_damage(damage, me);
        message_vision( sprintf("$n�Q�T�M�e��ӹL�A�����O�Ϩ��l���F�_�ӡA�b�Ť��Q�X�j�q�A��(%d) %s\n\n", damage, COMBAT_D->report_status(target) ), me, target);
    }
    setEffect(me, sk, hit);
    return 1;
}
