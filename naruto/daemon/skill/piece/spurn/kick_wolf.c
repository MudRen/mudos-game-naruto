#include <ansi.h>
#define SKILL_NAME "kick wolf"
#define SKILL_NAME_C "�P�}�E�t�T"
#define SKILL_CLASS "spurn"

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

int evade(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)*2/5;
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

    if( act != "kick" ) {
        tell_object(me, "�ثe" + SKILL_NAME_C + "�u�� kick �\\��C\n");
        return 0;
    }

    if( !me->is_fighting(target) ) {
        tell_object(me, "�A�å��M���b�԰���...\n");
        return 0;
    }

    if( me->query_condition("wolf_cd") ) {
        tell_object(me, "��������l�R���u�ʤ~��ϥΩt�T�C\n");
        return 0;
    }

    if( me->query_skill("spurn", 1) < 60 || sk < 60 ) {
        tell_object(me, "�A����O�����H�ϥγo�@�ۡC\n");
        return 0;
    }

    if( me->query_stat("mp") < sk/8 ) {
        tell_object(me, "�A���骬�p���ΡA����ϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    return 1;
}

// �p��O�_�X�{�P�R�@��
int isSock(object me, object target)
{
    // ��� 80 �H�W�W�[�P�R�v�T
    if( me->query_skill("spurn", 1) < 80 ) return 0;

    // �[�P�R�@�����v
    return (COMBAT_D->sock(me, target, 1) > random(100));
}

// �p��O�_�R��
int isHit(object me, object target)
{
    int hit, raiseHit;

    raiseHit = me->query_skill(SKILL_NAME, 1)/2;

    me->add_temp("apply/exact", raiseHit);
    hit = COMBAT_D->isHit(me, target);
    me->add_temp("apply/exact", -raiseHit);

    return hit;
}

// ���o�ˮ`
int getDamage(object me, object target, int sk)
{
    int damage, raiseDamage;
    object wp;

    raiseDamage = sk + me->query_skill("spurn");

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
    cnd["name"] = HIY+"(CD)�t�T"+NOR;
    cnd["duration"] = 5;

    me->set_condition("wolf_cd", cnd);
    me->damage_stat("mp", sk/8, me);
    me->improve_skill(SKILL_NAME, 1);
}

int perform_action(object me, string act, object target)
{
    string msg, msgin, msgout;
    int damage, sk, sock, hit;

    sk = me->query_skill(SKILL_NAME, 1);

    // �ˬd�O�_��ϥΧޯ�
    if( !isCast(me, act, target, sk) ) return 1;

    // �O�_�P�R�@��
    sock = isSock(me, target);

    // �R���P�_
    hit = isHit(me, target);

    // �ˮ`
    damage = getDamage(me, target, sk);

    if( sock ) {
        msg = HIR"\n(�P�R�@��)"NOR" $N�@�s��X���D�u��"HIW"�y"NOR+YEL"�P�}�E�s�T�s�P"HIW"�z"NOR"�̷ӳt�פ��P����u�V$n�I\n"NOR;
        msgin = "$n�Q�s�T�r��A�������_��������������A�X�G�֯�����F(%d) %s\n\n";
        msgout = "$N�{�L�F�@�D�S�@�D�������A�ש��׶}�Ҧ��������C\n\n";
        damage = (damage * COMBAT_D->sockPower(me, target, 1))/100;
    } else {
        msg = "\n$N���e�@�B�A��X"HIW"�y"HIY"�P�}�E�t�T"HIW"�z"NOR"�����̵�$N���ʪ��t�v�u�V$n�C\n"NOR;
        msgin = "$n�{������Q�t�T�r���A�æ]���V����F�Ƥ�(%d) %s\n\n";
        msgout = "�t�T���ʤӹL�w�C�A$N���N�]��Ϥ�V�h�F�C\n\n";
    }
    message_vision(msg, me, target);
    if( !hit ) {
        message_vision(msgout, me, target);
    } else {
        target->receive_damage(damage, me);
        message_vision( sprintf(msgin, damage, COMBAT_D->report_status(target) ), me, target);
    }
    setEffect(me, sk, hit);
    return 1;
}
