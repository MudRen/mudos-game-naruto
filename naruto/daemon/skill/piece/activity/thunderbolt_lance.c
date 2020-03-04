#include <ansi.h>
#define SKILL_NAME "thunderbolt lance"
#define SKILL_NAME_C "�p���j"
#define SKILL_CLASS "activity"

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
    if( !objectp(me) || !objectp(target) ) {
        tell_object(me, "�ثe" + SKILL_NAME_C + "�� compo �M back ��إ\\��C\n");
        return 0;
    }

    if( act != "back" ) {
        tell_object(me, "�ثe" + SKILL_NAME_C + "�� compo �M back ��إ\\��C\n");
        return 0;
    }

    if( me->is_busy() ) {
        tell_object(me, "�A�{�b�S���Ũϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    if( me->query_skill("activity", 1) < 180 || sk < 60 || me->query_skill("anemometer") < 80 ) {
        tell_object(me, "�A����O�����H�ϥγo�@�ۡC\n");
        return 0;
    }

    if( !me->is_fighting(target) ) {
        tell_object(me, "�԰�������F�ٷQ������C\n");
        return 0;
    }

    if( !me->query_condition("thunderbolt", 1) ) {
        tell_object(me, "�S���¶�����p�q�C\n");
        return 0;
    }

    if( me->query_stat("mp") < sk/2 ) {
        tell_object(me, "�A�����A�L�k�ϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    return 1;
}

// �p��O�_�R��
int isHit(object me, object target)
{
    int i, j;

    i = COMBAT_D->intimidate(me, 1)*1.5;
    j = COMBAT_D->evade(target, me, 1);

    if( COMBAT_D->SkillHit(me, target, i, j) ) return 1;
    else return 0;
}

// ���o�ˮ`
int getDamage(object me, object target, int sk, object staff)
{
    int damage, raiseDamage;
    object wp;

    raiseDamage = sk*10 + me->query_skill("anemometer")*2 + me->query_skill("activity")*2;
    raiseDamage += staff->query("damage/twohanded/upper");

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
    if( !hit ) {
        me->damage_stat("mp", sk/10, me);
    } else {
        me->damage_stat("mp", sk/2, me);
    }
    me->start_busy(2);
    me->improve_skill(SKILL_NAME, 1);
    me->delete_condition("thunderbolt");
}

void do_perform(object me)
{
    int sk;
    object staff;

    mapping cnd = ([]);

    sk = me->query_skill(SKILL_NAME, 1);

    if( me->query_stat("mp") < sk/30 ) {
        write("�A�����A�L�k�ϥ�" + SKILL_NAME_C + "�C\n");
        return;
    }

    if( me->is_busy() ) {
        tell_object(me, "�A�ȮɵL�k�s�y�¶��C\n");
        return 0;
    }

    if( sk < 10 ) {
        write("�S�Ƿ|" + SKILL_NAME_C + "���|�s�y�¶��C\n");
        return;
    }

    if( me->query_condition("thunderbolt", 1) != 0) {
        write("���w�g���ͤF�A�A���o�ʧ������i��|�����C\n");
        return;
    }

    if( !me->is_fighting() ) {
        write("�S�ƻs�y����¶��C\n");
        return;
    }

    // ���������W���S���ѭԴ�
    if( !objectp(staff = present("_WEATHER_", me)) ) {
        write("�A���W�S���ѭԴΫ��Χޯ�C\n");
        return;
    }
    message_vision("$N"HIB"�N"+staff->query("name")+NOR+HIB"��e�}�l���E�_�@�ζ¦⪺�Q��...\n"NOR, me);

    cnd["name"] = HIK"���E�¶�"NOR;
    cnd["duration"] = 10;

    me->start_busy(2);
    me->damage_stat("mp", sk/30, me);
    me->set_condition("thunderbolt", cnd);
    return;
}

int perform_action(object me, string act, object target)
{
    object staff;
    int damage, sk, hit;

    sk = me->query_skill(SKILL_NAME, 1);

    if( !objectp(me) ) return 0;

    if( act == "compo") {
        do_perform(me);
        return 1;
    }
    // �ˬd�O�_��ϥΧޯ�
    if( !isCast(me, act, target, sk) ) return 1;

    if( !objectp(staff = present("_WEATHER_", me)) )
        return notify_fail("�S���ѭԴεL�k�޾ɹp���C\n");

    hit = isHit(me, target);

    message_vision("\n$N�]��$n������A�C�C���E��"HIY"�q��"NOR"�b"+staff->query("name")+"�W�A$n�ߨ��ਭ���m...\n"NOR, me, target);

    if( !hit ) {
        message_vision(HIK"�¶��o�X�԰Ԫ��n�T�A�M��C�C�������F...\n\n"NOR, me, target);
    } else {
        damage = getDamage(me, target, sk, staff);
        target->receive_damage(damage, me);
        message_vision("\n$N���ݶ¶��v�������A�j�ۤ@�n"HIR"�y"HIY+BLINK"�p���j"NOR+HIR"�z"NOR"�I$n�~���ۤv�w�g�W��F�I\n"NOR, me, target);
        message_vision( sprintf("���M�p�q�q�¶�����V�g�X�A��L$n���ݤf���b$N�⤤��"+staff->query("name")+"�I(%d) %s\n\n", damage, COMBAT_D->report_status(target)), me, target);
    }
    setEffect(me, sk, hit);
    return 1;
}
