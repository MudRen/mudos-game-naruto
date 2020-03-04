/* ��N�w�K���x�^�� */

#include <ansi.h>
#define SKILL_NAME "sky palm"
#define SKILL_NAME_C "�K���^��"
#define SKILL_CLASS "force"

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

// ��b�ˮ`�e�]�X�A�Ω�s�@�L�ĩάި��m
int receiveDamage(object me, object target, int damage)
{
    int i, raiseDamage, exact, evade;
    object wp;

    if( !me->query_condition("sky_palm") ) return damage;

    exact = random(me->query_ability("exact") + me->query_ability("intimidate"));
    evade = random(target->query_ability("evade"));

    me->damage_stat("mp", 20, me);
    message_vision(HIG"\n$N�ݷǤF��աA�ߨ�ϥΥղ��d�X"NOR"$n"HIG"���z�I�P�������ҬI�i�y"HIW"�K���x�^��"HIG"�z�I\n"NOR, me, target);
    if( exact < evade ) {
        message_vision(HIY"���O"NOR"$n"HIY"�~�M�ݯ}�F�^�Ѵx�k�A�����q$N�������I�����I\n\n"NOR, me, target);
    } else {
        if( exact - evade < 100 ) {
            message_vision(YEL"���G$n"YEL"�������~�M�Q�^�Ѵx�k���ƤƸѡA�u���f�M�׶}$N�������I\n\n"NOR, me, target);
        } else {
            raiseDamage = me->query_skill(SKILL_NAME) + me->query_skill("force")/2 + me->query_skill("soft fist") + me->query_skill("white eyes");

            me->add_temp("apply/attack", raiseDamage);

            if( wp = me->query_temp("weapon/twohanded") ) i = COMBAT_D->isDamage(me, target, wp);
            else if( wp = me->query_temp("weapon/righthand") ) i = COMBAT_D->isDamage(me, target, wp);
            else if( wp = me->query_temp("weapon/lefthand") ) i = COMBAT_D->isDamage(me, target, wp);
            else i = COMBAT_D->isDamage(me, target, 0);

            me->add_temp("apply/attack", -raiseDamage);

            target->receive_damage(i, me);
            message_vision( sprintf(HIR"$N�����N���������ƸѡA��ϥΦ^�Ѵx�k����$n"HIR"�������`�B�A���ФF$n(%d) %s\n\n", i, report_status(target) ), me, target);
        }
        return 0;
    }
    return damage;
}

// �ˬd�O�_��ϥΧޯ�
int isCast(object me, string act, object target, int sk)
{
    if( !objectp(me) ) return 0;

    if( me->is_busy() ) {
        write("�A�{�b�S���Ũϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    if( act != "attack" ) {
        write("�ثe" + SKILL_NAME_C + "�u�� attack �\\��C\n");
        return 0;
    }

    if( !me->is_fighting() ) {
        write("�����b�԰����~��I�i" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    if( me->query_condition("sky_palm_cd", 1) ) {
        write("�A�ثe�`�N�O���ΡA�L�k�ϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    if( me->query_condition("sky_palm", 1) ) {
        write("�A�ثe�w�g�b�ϥ�" + SKILL_NAME_C + "���C\n");
        return 0;
    }

    if( !me->query_condition("white_eyes") ) {
        write("�u���b�ղ������A���~��ϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    if( me->query_skill("force", 1) < 160 || sk < 60 || me->query_skill("soft fist", 1) < 80 ) {
        write("�A����O�����H�ϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    if( me->query_stat("mp") < 50 ) {
        write("�A���骬�p���ΡA����ϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    return 1;
}

void do_perform(object me, int sk)
{
    mapping cnd = ([]);

    message_vision(HIG"\n$N�t�X�ղ��}�l�I�i�y"HIW"�K���^�Ѵx"HIG"�z�����褤�a�X�A�X���a�l�A�u�ձK���z���I\n\n"NOR, me);

    cnd["name"] = HIG+"�^��"+NOR;
    cnd["duration"] = sk;
    cnd["from"] = me;

    me->set_condition("sky_palm", cnd);

    cnd["name"] = HIG+"(CD)�^��"+NOR;
    cnd["duration"] = sk*3/2;

    me->set_condition("sky_palm_cd", cnd);

    // �W�[�ޯ�g��
    me->damage_stat("mp", 50, me);
    me->start_busy(2);
    me->improve_skill(SKILL_NAME, 1);
    return;
}

int perform_action(object me, string act, object target)
{
    int sk;

    sk = me->query_skill(SKILL_NAME, 1);

    if( !isCast(me, act, target, sk) ) return 1;

    do_perform(me, sk);
    return 1;
}
