#include <ansi.h>
#define SKILL_NAME "age agonize"
#define SKILL_NAME_C "�T�Q���дo��"
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

    if( me->query_condition("age_cd") ) {
        tell_object(me, "�A����O�ثe�ٵL�k�o�X�����C\n");
        return 0;
    }

    if( !me->query_temp("weapon/righthand") && !me->query_temp("weapon/lefthand") && !me->query_temp("weapon/twohanded")) {
        tell_object(me, "�o�O�@�M�y�ޯ�A�������@��Z���~��ϥΡC\n");
        return 0;
    }

    if( me->query_skill("blade", 1) < 160 || sk < 40 || me->query_skill("chivy tiger") < 70 ) {
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
    int i, j;

    i = COMBAT_D->intimidate(me, 1)*2;
    j = COMBAT_D->evade(target, me, 1);

    if( COMBAT_D->SkillHit(me, target, i, j) ) return 1;
    else return 0;
}

// ���o�ˮ`
int getDamage(object me, object target, int sk)
{
    int damage;

    // �ˮ`�����ͩR�̤j��
    if( sk < 81 ) {
        damage = target->query_stat_maximum("hp")/100;    // 1%
        if( damage > 500 ) damage = 500;
    } else if( sk < 121 ) {
        damage = target->query_stat_maximum("hp")/50;     // 2%
        if( damage > 1000 ) damage = 1000;
    } else if( sk < 161 ) {
        damage = target->query_stat_maximum("hp")/25;     // 4%
        if( damage > 2000 ) damage = 2000;
    } else if( sk < 200 ) {
        damage = target->query_stat_maximum("hp")*2/25;   // 8%
        if( damage > 4000 ) damage = 4000;
    } else {
        damage = target->query_stat_maximum("hp")/10;     // 10%
        if( damage > 5000 ) damage = 5000;
    }
    return damage;
}

// �ޯ�ϥΫ� 
void setEffect(object me, int sk, int hit)
{
    mapping cnd = ([]);

    if( !hit ) {
        me->start_busy(3);
        me->damage_stat("mp", sk/4, me);
    } else {
        me->start_busy(2);
        me->damage_stat("mp", sk/2, me);
    }
    cnd["name"] = HIW+"(CD)�дo"+NOR;
    cnd["duration"] = 100;

    me->set_condition("age_cd", cnd);
    me->improve_skill(SKILL_NAME, 1);
}

int perform_action(object me, string act, object target)
{
    int damage, sk, hit;

    sk = me->query_skill(SKILL_NAME, 1);

    // �ˬd�O�_��ϥΧޯ�
    if( !isCast(me, act, target, sk) ) return 1;

    message_vision("\n$N�C�n��ۡu�T�Q��...�v���M�⤤���M�@��"HIY"�y"HIW"�дo��"HIY"�z"NOR"�I�M�𪽽�$n���e�I\n"NOR, me, target);

    // �O�_�R��
    hit = isHit(me, target);

    if( !hit ) {
        message_vision("$N�ݷǤF�M�𪺧�աA�@��½�u�׶}�F�����C\n\n", target);
    } else {
        damage = getDamage(me, target, sk);
        target->receive_damage(damage, me);
        message_vision( sprintf("�M��q$n���W�e���ӹL�A�@�f�A��q$n�L���Q�F�X��(%d) %s\n\n", damage, COMBAT_D->report_status(target) ), me, target);
    }
    setEffect(me, sk, hit);
    return 1;
}
