/* ���q��(double fang) by mouse 2007/8/13 */

#include <ansi.h>
#define SKILL_NAME "double fang"
#define SKILL_NAME_C "���q��"
#define SKILL_CLASS "ninja"

inherit SKILL;

object pet;

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

// �R����O�v�T
int exact(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/20;
}

// �j�ׯ�O�v�T
int evade(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)*3/100;
}

// �ˬd�O�_��ϥΧޯ�
int isCast(object me, string act, object target, int sk)
{
    if( !objectp(me) || !objectp(target) ) return 0;

    if( me->is_busy() ) {
        tell_object(me, "�A�{�b�S���Ũϥγq���C\n");
        return 0;
    }

    if( act != "atwirl" ) {
        tell_object(me, "�ثe�q���u�� atwirl �\\��C\n");
        return 0;
    }

    if( !me->is_fighting(target) ) {
        tell_object(me, "�A�å��M���b�԰���...\n");
        return 0;
    }

    if( me->query_skill("ninja") < 100 || sk < 60 ) {
        tell_object(me, "�A����O�����H�ϥγo�@�ۡC\n");
        return 0;
    }

    if( me->query_stat("mp") < sk/5 ) {
        tell_object(me, "�A���骬�p���ΡA����ϥγq���C\n");
        return 0;
    }

    if( me->query_condition("four_foot", 1) == 0) {
        tell_object(me, "�A�����n�b�|�}�N�����A�U�~��ϥγq���C\n");
        return 0;
    }

    if( me->query_condition("fang_cd") ) {
        tell_object(me, SKILL_NAME_C + "�e�m�ǳƩ|�������C\n");
        return 0;
    }

    return 1;
}

// �P�_�d����
int check_pet(object me, object target)
{
    // �d�����b���ǩάO�w�ˡA�ήڥ��S�d�������ϥ�
    // �԰��}�l�~�l�d�A���d�����F�~���ޡA���O���檺
    if( !objectp(pet = me->query_temp("pet")) || !present("_MY_PET_", environment(me)) ) return 0;
    else if( !living(pet) ) return 0;
    else if( !pet->is_fighting(target) ) return 0;
    else return 1;
}

// ���o�R��
int getHit(object me, object target, int dog)
{
    int hit, meHit, targetHit;

    meHit = COMBAT_D->exact(me, target, 1)*1.5;
    targetHit = COMBAT_D->evade(target, me, 1)*1.2;

    // ���L�d�����P�_���P
    if( !dog ) {
        target->add_temp("apply/evade", targetHit);
        hit = COMBAT_D->isHit(me, target);
        target->add_temp("apply/evade", -targetHit);
    } else {
        me->add_temp("apply/exact", meHit);
        target->add_temp("apply/evade", targetHit);
        hit = COMBAT_D->isHit(me, target);
        me->add_temp("apply/exact", -meHit);
        target->add_temp("apply/evade", -targetHit);
    }
    return hit;
}

// ���o�ˮ`
int getDamage(object me, object target, int sk, int dog)
{
    int damage, raiseDamage;
    object wp;

    raiseDamage = sk*2 + me->query_skill("ninja") + me->query_skill("four foot");

    if( dog ) {
        if( pet->query("level") < 50 ) raiseDamage += pet->query("level")*8;
        else raiseDamage += 400;
    }
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
    cnd["name"] = HIW+"(CD)�q��"+NOR;
    cnd["duration"] = 6;

    // ���S���t��������cd�A�ɶ��]�@��
    me->set_condition("fang_cd", cnd);

    me->damage_stat("mp", sk/5, me);
    me->improve_skill(SKILL_NAME, 1);
}

void do_perform(object me, object target, int sk)
{
    int hit, damage, dog;

    dog = check_pet(me, target);
    hit = getHit(me, target, dog);
    damage = getDamage(me, target, sk, dog);

    // �S�d����
    if( !dog ) {
        message_vision("\n$N�j�q�@�n�A���M���D�ܪŤ��A�@��"HIC"�u�q���v"NOR"���l���p�s��������༲�V$n�I\n", me, target);
        if( hit ) {
            target->receive_damage(damage, me);
            message_vision(sprintf("�u�I�v�a�@�n�A$n�Q�s���������F�X�h�A����@�Ƕˮ`(%d) %s\n\n", damage, report_status(target) ), me, target);
        } else {
            message_vision("���O�|�P��y�ܤƤӤj�A�s���������F$N���d��C\n\n", target);
        }
    } else {
        message_vision("\n$N�۹D�G"HIG"�W���I"+pet->query("name")+"�I"NOR"\n\n�u��"+pet->query("name")+"���D�ܪŤ��A�P$N�P�ɧΦ�"HIC"��D�s�����y"HIB+BLINK"���q��"NOR+HIC"�z"NOR"�ֳt���V$n�I\n", me, target);
        if( hit ) {
            target->receive_damage(damage, me);
            message_vision(sprintf("��D�s�������۽����A�N$n���F�W�h�A�b���_�������U�L���a���A�ܦ��@�Φתd(%d) %s\n\n", damage, report_status(target) ), me, target);
        } else {
            damage = damage/10;
            target->receive_damage(damage, me);
            message_vision(sprintf("$n�Q�����ƪ��k�L�@�T�S�Q���J�s�������A���٬O����@�Ƕˮ`(%d) %s\n\n", damage, report_status(target) ), me, target);
        }
    }
    // �ϥγo�����Ӧ��Ԥ��������q�P�]�O�A����L����ϥ�
    if( dog ) {
        pet->do_check_food();
        pet->damage_stat("mp", sk/5, pet);

        // �d�����A�Ӯt�N�������a
        if( pet->query_food() < 10 || pet->query_stat("mp") < sk/5 || pet->query_stat("hp") < 100 || pet->query_stat("ap") < 100 ) {
            message_vision(HIR"\n$n�b���餣�Ϊ����p�U�w�t�X$N�����A����Ө����F�ө����L�h�C\n"NOR, me, pet);
            pet->die();
        }
    }
    // �ϥΫᦩ��
    setEffect(me, sk, hit);
}

// ��ʧ���
int perform_action(object me, string act, object target)
{
    int sk;

    sk = me->query_skill(SKILL_NAME, 1);

    // �ˬd�O�_��ϥΧޯ�
    if( !isCast(me, act, target, sk) ) return 1;

    // �ϥΧޯ�
    do_perform(me, target, sk);

    return 1;
}
