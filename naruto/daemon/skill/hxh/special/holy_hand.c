// holy_hand.c �S��t-�t������
// 2005/10/22 -Tmr
// �g�L�Q�׫�קאּ cd 10����
// �]���\��S��A�[�W�i��|�񥢱Ѫ��P�_

#include <ansi.h>
#define SKILL_NAME   "holy hand"
#define SKILL_NAME_C "�t������"
#define SKILL_CLASS  "special"

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
    if( !objectp(me) ) return 0;

    // �S���ؼдN���w���ۤv
    if( !objectp(target) ) target = me;

    if( me->query_condition("holy_hand_cond" ) ) {
        tell_object(me, "�A���骺���A�٨S����_�A�ȮɵL�k�ϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }
    if( me->is_busy() ) {
        tell_object(me, "�A�����ۡC\n");
        return 0;
    }
    if( act != "healing" ) {
        tell_object(me, "" + SKILL_NAME_C + "�u�� healing ���\\��C\n");
        return 0;
    }
    if( sk < 25 || me->query_skill("special", 1) < 30  ) {
        tell_object(me, "�A�ثe����O�٤����H�ϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }
    if( me->query_stat("mp") < 50 ) {
        tell_object(me, "�A�����O�ȧC�� 50�A�L�k�ϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }
    return 1;
}

// �ϥε���
int perform_action(object me, string act, object target)
{
    int sk;
    mapping cnd = ([]);

    sk = me->query_skill(SKILL_NAME, 1);

    if( !isCast(me, act, target, sk) ) return 1;

    message_vision("\n$N���X�Q��D�G"HIG"���R�@�H...�ڷR�A��...\n"NOR, me, target);
    message_vision(HIW"$N����G�����䪺�����A�����aĲ�I�F$n�@�U...\n\n"NOR, me, target);

    if( sk + me->query_skill("special", 1)/2 < random(250) ) {
        tell_object(target, HIG"�W�Ҥ��h�a���F�A���k�y�U�@�ڴx�A�N�A�����F�I\n\n");
    } else {
        tell_object(target, HIG"�A���M�P����W�Ҫ����d�A�����W�U�R���F���O�I�I\n\n");
        target->heal_stat("ap", 9999);
        target->heal_stat("hp", 9999);
        target->heal_stat("mp", 9999);
    }

    cnd["name"] = HIW"(CD)�t��"NOR;
    cnd["duration"] = 300;

    me->set_condition("holy_hand_cond", cnd);
    me->damage_stat("mp", 50, me);
    me->improve_skill(SKILL_NAME, 1);
    me->start_busy(2);
    return 1;
}
