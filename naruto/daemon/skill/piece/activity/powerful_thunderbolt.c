#include <ansi.h>
#define SKILL_NAME "powerful thunderbolt"
#define SKILL_NAME_C "�p�^�U�v"
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

int wittiness(object me, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/10;
}

int defend(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/10;
}

// �ˬd�O�_��ϥΧޯ�
int isCast(object me, string act, object target, int sk)
{
    if( !objectp(me) || !objectp(target) ) {
        tell_object(me, "�ثe" + SKILL_NAME_C + "�� compo �M jet ��إ\\��C\n");
        return 0;
    }

    if( act != "jet" ) {
        tell_object(me, "�ثe" + SKILL_NAME_C + "�� compo �M jet ��إ\\��C\n");
        return 0;
    }

    if( me->is_busy() ) {
        tell_object(me, "�A�{�b�S���Ũϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    if( !me->is_fighting() ) {
        tell_object(me, "�԰�������F�ٷQ������C\n");
        return 0;
    }

    if( !me->query_condition("thunderbolt", 1) ) {
        tell_object(me, "�S���¶�����p�q�C\n");
        return 0;
    }

    if( me->query_skill("activity", 1) < 160 || sk < 40 ) {
        tell_object(me, "�A��O�٤������ϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    if( me->query_stat("mp") < sk/5 ) {
        tell_object(me, "�A�����A�L�k�ϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    return 1;
}

// �p��O�_�R��
int isHit(object me, object target)
{
    int i, j;

    i = COMBAT_D->exact(me, target, 1) + COMBAT_D->intimidate(me, 1);
    j = COMBAT_D->evade(target, me, 1)*2;

    if( COMBAT_D->SkillHit(me, target, i, j) ) return 1;
    else return 0;
}

// ���o�ˮ`
int getDamage(object me, object target, int sk, object staff)
{
    int damage, raiseDamage;
    object wp;

    raiseDamage = sk*2 + me->query_skill("activity") + me->query_skill("anemometer");

    if( wp = me->query_temp("weapon/twohanded") ) raiseDamage -= COMBAT_D->isDamage(me, target, wp)*3/4;
    else if( wp = me->query_temp("weapon/righthand") ) raiseDamage -= COMBAT_D->isDamage(me, target, wp)*3/4;
    else if( wp = me->query_temp("weapon/lefthand") ) raiseDamage -= COMBAT_D->isDamage(me, target, wp)*3/4;
    else raiseDamage -= COMBAT_D->isDamage(me, target, 0)*3/4;

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
void setEffect(object me, int sk)
{
    // �Ŧ� msg
    message_vision("\n", me);
    me->start_busy(2);
    me->damage_stat("mp", sk/5, me);
    me->improve_skill(SKILL_NAME, 1);
    me->delete_condition("thunderbolt");
}

void do_perform(object me)
{
    int sk;
    object staff;

    mapping cnd = ([]);

    sk = me->query_skill(SKILL_NAME, 1);

    if( me->query_stat("mp") < sk/40 ) {
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

    message_vision("$N"HIK"���k����O���"+staff->query("name")+NOR+HIK"�A�b�Ť��s�y�X�@�K���¶�...\n"NOR, me);

    cnd["name"] = HIK"�Q���K�G"NOR;
    cnd["duration"] = 10;

    me->start_busy(3);
    me->damage_stat("mp", sk/40, me);
    me->set_condition("thunderbolt", cnd);
    return;
}

int perform_action(object me, string act, object target)
{
    object staff, *targets;
    int damage, sk, i, number;

    sk = me->query_skill(SKILL_NAME, 1);
    targets = me->query_enemy();

    if( !objectp(me) ) return 0;

    if( act == "compo") {
        do_perform(me);
        return 1;
    }
    // �ˬd�O�_��ϥΧޯ�
    if( !isCast(me, act, target, sk) ) return 1;

    if( !objectp(staff = present("_WEATHER_", me)) ) return notify_fail("�S���ѭԴΫ���p�q�C\n");

    message_vision("\n$N�N"HIY"�q��w"NOR"��V�Ť��¶�"HIK"�y"HIY"�p�^�U�v"HIK"�z"NOR"�p�q�ƨg�����b�|�P�a�W�I\n"NOR, me);

    number = (sk/50) - 1;
    if( number <= 0 ) number = 0;

    if( me->query_skill("activity", 1) >= 70 ) {
        for(i=0;i<sizeof(targets);i++) {
            if( i > number ) break;   // �̦h�����|�H
            if( !isHit(me, targets[i]) ) {
                message_vision("$n�B����G�����A�{�q�X�G�N�a���N�ɡA�o�S������$n�C\n", me, targets[i]);
            } else {
                damage = getDamage(me, targets[i], sk, staff);
                targets[i]->receive_damage(damage, me);
                message_vision( sprintf(HIY"$n"HIY"�Q�q���z�z�j�s�A�ϩ���ݨ�$n"HIY"�����f�b�{�{(%d) %s\n", damage, COMBAT_D->report_status(targets[i])), me, targets[i]);
            }
        }
    } else {
        if( !isHit(me, target) ) {
            message_vision("$n�B����G�����A�{�q�X�G�N�a���N�ɡA�o�S������$n�C\n", me, target);
        } else {
            damage = getDamage(me, target, sk, staff);
            target->receive_damage(damage, me);
            message_vision( sprintf(HIY"$n"HIY"�Q�q���z�z�j�s�A�ϩ���ݨ�$n"HIY"�����f�b�{�{(%d) %s\n", damage, COMBAT_D->report_status(target)), me, target);
        }
    }
    setEffect(me, sk);
    return 1;
}
