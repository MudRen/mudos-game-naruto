/* �X���k-�K�����Q�|�x(soft fist) 
   by mouse 2007/8/12
*/

#include <ansi.h>
#define SKILL_NAME "soft fist"
#define SKILL_NAME_C "�K�����Q�|�x"
#define SKILL_CLASS "force"

inherit SKILL;

int number;

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
    return ability + me->query_skill(SKILL_NAME)*13/200;
}

// �����O�q�v�T
int attack(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)*3/20;
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

    if( sk < 50 || me->query_skill("force", 1) < 60 ) {
        tell_object(me, "�A����O�����H�ϥγo�@�ۡC\n");
        return 0;
    }

    if( me->query_stat("mp") < sk/5 ) {
        tell_object(me, "�A���骬�p���ΡA����ϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    if( me->query_condition("soft_cd") ) {
        tell_object(me, SKILL_NAME_C + "��������������~��A���ϥΡC\n");
        return 0;
    }

    return 1;
}

// �p��O�_�R��
int isHit(object me, object target)
{
    int hit, meHit, targetHit;

    meHit = COMBAT_D->intimidate(me, 1);
    targetHit = COMBAT_D->wittiness(target, 1);

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

    // �����o�K���x���x��
    switch( sk ) {
        case 0..100: number = random(16); break;
        case 101..140: number = random(32); break;
        case 141..160: number = random(32) + 16; break;
        case 161..180: number = random(32) + 32; break;
        case 181..199: number = random(16) + 48; break;
        case 200: number = 64; break;
    }
    raiseDamage = number*10 + sk + me->query_skill("force");

    me->add_temp("apply/attack", raiseDamage);

    if( wp = me->query_temp("weapon/twohanded") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/righthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/lefthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else damage = COMBAT_D->isDamage(me, target, 0);

    me->add_temp("apply/attack", -raiseDamage);

    return damage;
}

// �ղ�������ˮ`�t�~��
int apDamage(object me, object target, int sk)
{
    int ap;

    if( me->query_skill("white eyes") < 140 ) ap = sk;
    else if( me->query_skill("white eyes") < 160 ) ap = sk*2;
    else ap = sk*3;

    return ap;
}

// �ޯ�ϥΫ� 
void setEffect(object me, int sk, int hit)
{
    mapping cnd = ([]);

    // �S�����B�ղ����A���P�����A�p��
    if( !hit ) {
        me->damage_stat("mp", sk/10, me);
    } else {
        if( me->query_condition("white_eyes") ) {
            me->improve_skill(SKILL_NAME, 1);
        } else {
            me->damage_stat("mp", sk/5, me);
        }
    }
    cnd["name"] = HIW+"(CD)�K��"+NOR;
    cnd["duration"] = 4;

    // ���ެO�_���������Ӧ�cd
    me->set_condition("soft_cd", cnd);
    me->improve_skill(SKILL_NAME, 1);
    me->start_busy(1);
}

// ��ʧ���
int perform_action(object me, string act, object target)
{
    int sk, damage, hit, white, ap;

    sk = me->query_skill(SKILL_NAME, 1);
    white = me->query_skill("white eyes", 1);

    // �ˬd�O�_��ϥΧޯ�
    if( !isCast(me, act, target, sk) ) return 1;

    // �ˬd�R��
    hit = isHit(me, target);

    // ���o�ˮ`�A�K���x�����ƭn����X��
    damage = getDamage(me, target, sk);

    message_vision("\n$N���񥭡A�\\�X��V�a�ڶǩӤ����k"HIW"�y�X���z"NOR"���_�⦡...�u"HIW"�X���k"NOR"�E"HIR"�K��"+chinese_number(number)+"�x"NOR"�v\n", me, target);
    if( hit ) {
        if( me->query_condition("white_eyes") && white > 99 ) {
            ap = apDamage(me, target, sk);

            target->receive_damage(damage, me);

            // ���� ap �񥴺���٤֪��ɭԴN�����]���� 1
            if( target->query_stat("ap") < ap ) target->set_stat_current("ap", 1);
            else target->damage_stat("ap", ap, me);

            message_vision(sprintf("$N�t�X�ղ��ݬ�$n������߬��ʡA�s�_�ƴx�N$n���l���þɭP���f�y(%d) %s\n\n", damage, report_status(target) ), me, target);
        } else {
            target->receive_damage(damage, me);
            message_vision(sprintf("$N�s�X�ƴx���V$n���骺�U�j�g���A����$n�f�R�A�����L�ܷ�(%d) %s\n\n", damage, report_status(target) ), me, target);
        }
    } else {
        message_vision("���O$N�oı$n���w���ߨ��Ʀ��ۡA�]���ߨ覬�ۤF�C\n\n", me, target);
    }
    setEffect(me, sk, hit);
    return 1;
}
