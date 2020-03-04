#include <ansi.h>
#define SKILL_NAME "kick lotus"
#define SKILL_NAME_C "�P�}�E����"
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

int exact(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/10;
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

    if( me->query_condition("lotus_cd") ) {
        tell_object(me, "�A�Pı�ַN�����@�p�A���Q�X�ۡC\n");
        return 0;
    }

    if( me->query_skill("spurn", 1) < 50 || sk < 60 ) {
        tell_object(me, "�A����O�����H�ϥγo�@�ۡC\n");
        return 0;
    }

    if( me->query_stat("mp") < 50 ) {
        tell_object(me, "�A���骬�p���ΡA����ϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    return 1;
}

// �R������(1)
int attackHit(object me, object target)
{
    int i, j;

    i = COMBAT_D->intimidate(me, 1)*1.8;
    j = COMBAT_D->wittiness(target, 1)*1.5;

    if( COMBAT_D->SkillHit(me, target, i, j) ) return 1;
    else return 0;
}

// �R������(2)
int buffHit(object me, object target)
{
    int i, j;

    i = COMBAT_D->intimidate(me, 1)*2 + COMBAT_D->exact(me, target, 1)/2;
    j = COMBAT_D->wittiness(target, 1) + COMBAT_D->evade(target, me, 1);

    if( COMBAT_D->SkillHit(me, target, i, j) ) return 1;
    else return 0;
}

// ���o�ˮ`
int getDamage(object me, object target, int sk)
{
    int damage, raiseDamage;
    object wp;

    raiseDamage = sk;

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
        me->damage_stat("mp", 15, me);
    } else {
        me->damage_stat("mp", 30, me);
    }
    cnd["name"] = HIM+"(CD)����"+NOR;
    cnd["duration"] = 6;

    me->set_condition("lotus_cd", cnd);
    me->start_busy(1);
    me->improve_skill(SKILL_NAME, 1);
}

int perform_action(object me, string act, object target)
{
    int damage, sk, hit;
    mapping cnd = ([]);

    sk = me->query_skill(SKILL_NAME, 1);

    // �ˬd�O�_��ϥΧޯ�
    if( !isCast(me, act, target, sk) ) return 1;

    message_vision("\n$N���}���X�@�Ǳ����A�k�}���M��X�P�}�N�������_�A�����@��"HIW"�y"HIM"�P�}�E����"HIW"�z"NOR"���V$n�C\n", me, target);

    hit = attackHit(me, target);

    if( !hit ) {
        message_vision("$N�Ͻ�@�}�����N����𦨯}�H��ä�|��...\n\n", target);
    } else {
        damage = getDamage(me, target, sk);
        target->receive_damage(damage, me);
        message_vision( sprintf("������������F$n�A�Ĵ�����ä�b�Ť��Φ��@�M����(%d) %s\n\n", damage, COMBAT_D->report_status(target) ), me, target);
        if( sk > 70 && target->query_condition("firelotus", 1) == 0) {
            message_vision("$N���M�j��"HIM"�u�K�E���E�u�v"NOR"��W�Z���@���ϥX"HIR"�y��l�쿾�z"NOR"�@���j���y�{�V$n�I\n", me, target);
            if( !buffHit(me, target) ) {
                message_vision("���O���y����V�����F�A�u�b�a�W�z�X�@�}����C\n\n", target);
            } else {
                message_vision("���y�����Ť�����ä�A�s������N$n���|�P�N���@�������C\n\n", me, target);

                cnd["name"] = HIM+"�������"+NOR;
                cnd["duration"] = sk/20;
                cnd["from"] = me;

                target->set_condition("firelotus", cnd);
            }
        }
    }
    setEffect(me, sk, hit);
    return 1;
}
