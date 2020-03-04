#include <ansi.h>
#define SKILL_NAME "chop two"
#define SKILL_NAME_C "�G��"
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
    return ability + me->query_skill(SKILL_NAME)/10;
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

    if( !me->query_temp("weapon/righthand") || !me->query_temp("weapon/lefthand") ) {
        tell_object(me, "�o�O�G�M�y�ޯ�A�������G��Z���~��ϥΡC\n");
        return 0;
    }

    if( me->query_skill("blade", 1) < 60 || sk < 50 ) {
        tell_object(me, "�A����O�����H�ϥγo�@�ۡC\n");
        return 0;
    }

    if( me->query_stat("mp") < 120 ) {
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

    raiseDamage = sk + me->query_skill("blade")/2;

    if( wp = me->query_temp("weapon/twohanded") ) raiseDamage -= COMBAT_D->isDamage(me, target, wp)*3/4;
    else if( wp = me->query_temp("weapon/righthand") ) raiseDamage -= COMBAT_D->isDamage(me, target, wp)*3/4;
    else if( wp = me->query_temp("weapon/lefthand") ) raiseDamage -= COMBAT_D->isDamage(me, target, wp)*3/4;
    else raiseDamage -= COMBAT_D->isDamage(me, target, 0)*3/4;

    me->add_temp("apply/attack", raiseDamage);

    if( wp = me->query_temp("weapon/twohanded") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/righthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/lefthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else damage = COMBAT_D->isDamage(me, target, 0);

    me->add_temp("apply/attack", -raiseDamage);

    return damage;
}

// �ޯ�ϥΫ� 
void setEffect(object me, int sk, int number)
{
    // �Ŧ�msg
    message_vision("\n", me);

    // �P�_�e���������O�_�R���y���۩w, �W�L�T�ۨS���h�w2�^
    if( me->query_temp("busy_temp") > 2 ) {
        me->start_busy(6);
        me->delete_temp("busy_temp");
    } else {
        me->start_busy(3);
        me->delete_temp("busy_temp");
    }
    me->damage_stat("mp", 20*number, me);
    me->improve_skill(SKILL_NAME, 1);
}

int perform_action(object me, string act, object target)
{
    string msgin, msgout;
    int number, damage, hit, sk, i;
    object wp;

    sk = me->query_skill(SKILL_NAME, 1);

    // �ˬd�O�_��ϥΧޯ�
    if( !isCast(me, act, target, sk) ) return 1;

    message_vision("\n$N�N�⤤���M���|�A�\\�X�u�G�v���r��...�y"HIC"�G��"NOR"�z\n", me, target);

    // �M�N�v�T�P�s���P�_
    if( me->query_skill("blade", 1) < 100 ) number = 0;
    else number = sk/50;

    for(i=0;i<number;i++) {

        // �R���B�ˮ`�C�����n�P�_�@��
        hit = isHit(me, target); 
        damage = getDamage(me, target, sk);

        switch( i ) {
            case 0: 
                msgin = "$N�Ϥ⮳���M�ªŤ��@���ϥX�y"HIM"�n��"NOR"�z$n�S���{�}����F�ˮ`(%d) %s\n";
                msgout = "$N�Ϥ⮳���M�ªŤ��@�A�ϥX�y"HIM"�n��"NOR"�z���O�Q$n�{�L�F...\n";
                break;
            case 1:
                msgin = "$N�b�Ť����^���⮳�M�¤U�o�X�y"HIC"���n��"NOR"�z�����A��ˤF$n(%d) %s\n";
                msgout = "$N�b�Ť����^���⮳�M�¤U�o�X�y"HIC"���n��"NOR"�z�����A���O�Q$n�{�L�F...\n";
                break;
            case 2:
                msgin = "$N���ձN���M��V$n�y"HIG"�{"NOR"�z�j�j��������ˤF$n(%d) %s\n";
                msgout = "$N���ձN���M��V$n�y"HIG"�{"NOR"�z�A���O�Q$n�{�L�F...\n";
                break;
            case 3:
                msgin = "$N���l�@��A�S������$n�@�A�y"HIY"�F��"NOR"�z$n�L�k�{���w�O�Y�F�o��(%d) %s\n";
                msgout = "$N���l�@��A�S������$n�@�A�y"HIY"�F��"NOR"�z�A���O�Q$n�{�L�F...\n";
                break;
            default: return notify_fail("�P�_�����D��C\n"); break;
        }
        if( hit ) {
            target->receive_damage(damage, me);
            message_vision(sprintf(msgin, damage, COMBAT_D->report_status(target) ), me, target);
        } else {
            message_vision(msgout, me, target);
            me->add_temp("busy_temp",1);
        }
    }
    setEffect(me, sk, number);
    return 1;
}