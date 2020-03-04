#include <ansi.h>
#define SKILL_NAME "kick thunder"
#define SKILL_NAME_C "�P�}�E�չp"
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
    return ability + me->query_skill(SKILL_NAME)/20;
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

    if( me->query_condition("white_cd") ) {
        tell_object(me, "�A�ٵL�k��X�p���R�Q�������C\n");
        return 0;
    }

    if( me->query_skill("spurn", 1) < 200 || sk < 50 || me->query_skill("kick haze") < 50 ) {
        tell_object(me, "�A����O�����H�ϥγo�@�ۡC\n");
        return 0;
    }

    if( me->query_stat("mp") < sk/2 ) {
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
    targetHit = target->query_ability("wittiness");

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
    int damage;

    if( sk < 100 ) {
        damage = target->query_stat_maximum("hp")/100;    // 1%
        if( damage > 500 ) damage = 500;
    } else if( sk < 140 ) {
        damage = target->query_stat_maximum("hp")/50;     // 2%
        if( damage > 1000 ) damage = 1000;
    } else if( sk < 170 ) {
        damage = target->query_stat_maximum("hp")*3/100;  // 3%
        if( damage > 1500 ) damage = 1500;
    } else if( sk < 200 ) {
        damage = target->query_stat_maximum("hp")/20;     // 5%
        if( damage > 2500 ) damage = 2500;
    } else {
        damage = target->query_stat_maximum("hp")*2/25;   // 8%
        if( damage > 4000 ) damage = 4000;
    }
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
    cnd["name"] = HIW+"(CD)�չp"+NOR;
    cnd["duration"] = 80;

    me->set_condition("white_cd", cnd);
    me->damage_stat("mp", sk/2, me);
    me->improve_skill(SKILL_NAME, 1);
}

int perform_action(object me, string act, object target)
{
    int damage, sk, hit;

    sk = me->query_skill(SKILL_NAME, 1);

    // �ˬd�O�_��ϥΧޯ�
    if( !isCast(me, act, target, sk) ) return 1;

    message_vision("\n$N���W�Ť��A�˪Ť@�O"HIW"�y�P�}�E�չp�z"NOR"�{�p�{�q�����V$n\n", me, target);

    // �R��
    hit = isHit(me, target);

    if( !hit ) {
        message_vision("�����b�a�W���X�@�D�ʤf�A�ݾl����l�٦b�|�P�y«...\n\n", target);
    } else {
        damage = getDamage(me, target, sk);
        target->receive_damage(damage, me);
        message_vision( sprintf("���G��������$n���ݤf�A�@�}�����ϱo$n�R�X�@�j�f�A��(%d) %s\n\n", damage, COMBAT_D->report_status(target) ), me, target);
    }
    setEffect(me, sk, hit);
    return 1;
}
