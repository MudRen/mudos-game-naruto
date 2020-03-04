#include <ansi.h>
#define SKILL_NAME "chivy tiger"
#define SKILL_NAME_C "��E���y"
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

int intimidate(object me, int ability, int type)
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

    if( me->query_condition("tiger_cd") ) {
        tell_object(me, "���O�q�����n��A���y�a�C\n");
        return 0;
    }

    if( me->query_skill("blade", 1) < 20 || sk < 20 ) {
        tell_object(me, "�A����O�����H�ϥγo�@�ۡC\n");
        return 0;
    }

    if( me->query_stat("mp") < sk/15 ) {
        tell_object(me, "�A���骬�p���ΡA����ϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    return 1;
}

// �p��O�_�R��
int isHit(object me, object target)
{
    int hit, meHit, targetHit;

    meHit = me->query_ability("intimidate");
    targetHit = target->query_ability("intimidate");

    me->add_temp("apply/exact", meHit);
    target->add_temp("apply/evade", targetHit);
    hit = COMBAT_D->isHit(me, target);
    me->add_temp("apply/exact", -meHit);
    target->add_temp("apply/evade", -targetHit);

    return hit;
}

// ���o�ˮ`
int getDamage(object me, object target, int sk)
{
    int damage, raiseDamage;
    object wp;

    if( sk > 40 ) raiseDamage = sk + me->query_skill("blade");
    else raiseDamage = 0;

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
        me->start_busy(2);
    } else {
        me->start_busy(1);
    }
    cnd["name"] = HIM+"(CD)���y"+NOR;
    cnd["duration"] = 3;

    me->set_condition("tiger_cd", cnd);
    me->damage_stat("mp", sk/15, me);
    me->improve_skill(SKILL_NAME, 1);
}

int perform_action(object me, string act, object target)
{
    int damage, sk, hit, i = 0;
    object *inv, item, wp;

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

    message_vision("\n$N�p�r����C���l�W�իݵo�A���M�z���Ӱ_�ĦV$n"HIG"�y"HIM"���y"HIG"�z"NOR"�I\n", me, target);

    // �P�_�R��
    hit = isHit(me, target);

    if( !hit ) {
        message_vision("$N�ݬ�F��աA�ߨ�q����{�F�}�ӡC\n\n", target);
    } else {
        damage = getDamage(me, target, sk);

        // ���Z���ˮ`�A�[�Ӭި�
        damage = COMBAT_D->receive_damage(target, me, damage);

        target->receive_damage(damage, me);
        message_vision( sprintf("$n���פ���Q���X��D�`�`���ˤf�A����F���p���жˡC(%d) %s\n\n", damage, COMBAT_D->report_status(target) ), me, target);
    }
    setEffect(me, sk, hit);
    return 1;
}
