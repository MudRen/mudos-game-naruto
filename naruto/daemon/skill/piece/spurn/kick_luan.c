#include <ansi.h>
#define SKILL_NAME "kick luan"
#define SKILL_NAME_C "�P�}�E��"
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

int defend(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)*3/10;
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

    if( me->query_condition("luan_cd") ) {
        tell_object(me, "�A�~��I�i�L�áA�𮧤@�U�a�C\n");
        return 0;
    }

    if( me->query_skill("spurn", 1) < 180 || sk < 60 || me->query_skill("kick haze") < 120 ) {
        tell_object(me, "�A����O�����H�ϥγo�@�ۡC\n");
        return 0;
    }

    if( me->query_stat("mp") < sk/2 ) {
        tell_object(me, "�A���骬�p���ΡA����ϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    return 1;
}

// �p��H��
int check_number(object me, int sk)
{
    int number;

    if( sk < 100 ) {
        number = 0;
    } else {
        number = sk/100;
    }
    return number;
}

// �p��O�_�R��
int isHit(object me, object target)
{
    int hit, raiseHit;

    raiseHit = me->query_skill(SKILL_NAME, 1)/3;

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

    raiseDamage = sk*2 + me->query_skill("spurn") + me->query_skill("kick haze");

    if( wp = me->query_temp("weapon/twohanded") ) raiseDamage -= COMBAT_D->isDamage(me, target, wp)*2/3;
    else if( wp = me->query_temp("weapon/righthand") ) raiseDamage -= COMBAT_D->isDamage(me, target, wp)*2/3;
    else if( wp = me->query_temp("weapon/lefthand") ) raiseDamage -= COMBAT_D->isDamage(me, target, wp)*2/3;
    else raiseDamage -= COMBAT_D->isDamage(me, target, 0)*2/3;

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
    mapping cnd = ([]);

    cnd["name"] = HIB+"(CD)��"+NOR;
    cnd["duration"] = 6;

    // �Ŧ� msg
    message_vision("\n", me);
    me->set_condition("luan_cd", cnd);
    me->start_busy(2);
    me->damage_stat("mp", sk/2, me);
    me->improve_skill(SKILL_NAME, 1);
}

int perform_action(object me, string act, object target)
{
    int damage, sk, i, number;
    object *targets;

    sk = me->query_skill(SKILL_NAME, 1);
    targets = me->query_enemy();

    // �ˬd�O�_��ϥΧޯ�
    if( !isCast(me, act, target, sk) ) return 1;

    // �p��H��
    number = check_number(me, sk);

    message_vision("\n$N��⩹�a�W�@���A���L�s������X�h�D����"HIW"�y"HIB"�P�}�E��"HIW"�z"NOR"�����b�����ĤH�C\n", me, target);

    for(i=0;i<sizeof(targets);i++) {
        if( i > number ) break;       // �̦h�����T�H
        if( !isHit(me, targets[i]) ) {
            message_vision("�ý�y�������]���h�F���Y�A�s�@�U���S����$n�C\n", me, targets[i]);
        } else {
            damage = getDamage(me, targets[i], sk);

            // �ˮ`�ާl��
            damage = COMBAT_D->receive_damage(target, me, damage);

            targets[i]->receive_damage(damage, me);
            message_vision( sprintf("�u��v�a�@�n�A$n�Q�����A���A���l���y�S�Q�ƹD��������(%d) %s\n", damage, COMBAT_D->report_status(targets[i])), me, targets[i]);
        }
    }
    setEffect(me, sk);
    return 1;
}
