// harm_touch.c �S��t-�ˮ`��Ĳ
// 2005/10/22 -Tmr

/*
�� �ˮ`��Ĳ(harm touch)

�j�Ѭ۶Ƕˮ`��Ĳ�O�@�ثD�`�S���ˮ`��O�A�b�@������y���ĤH�����j�ˮ`�C

�ϥα���G�S��t(special) 30�ťH�W �� �ˮ`��Ĳ(harm touch) 25 �ťH�W�C
�ϥΤ�k�Gperform special.harming [�ﹳ]
�ˮ`�O  �G(�S��t����*5 + �ˮ`��Ĳ����*10)

�ˮ`��Ĳ:  25 �� | 50 �� | 75 �� | 100 �� | 125 �� | 150 �� | 175 �� | 200 �� |
���ήɶ�:  18 hr | 14 hr | 10 hr |   8 hr |   6 hr |   4 hr |   2 hr |   1 hr |
*/

#include <ansi.h>
#define SKILL_NAME   "harm touch"
#define SKILL_NAME_C "�ˮ`��Ĳ"
#define SKILL_CLASS  "special"
#define HOUR         1800

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

int getDuration(int lv) 
{
    switch( lv/25 ) {
        case 1: return 18*HOUR;
        case 2: return 14*HOUR;
        case 3: return 10*HOUR;
        case 4: return 8*HOUR;
        case 5: return 6*HOUR;
        case 6: return 4*HOUR;
        case 7: return 2*HOUR;
        case 8: return 1*HOUR;
    }
    return 20*HOUR;
}

// �ˬd�O�_��ϥΧޯ�
int isCast(object me, string act, object target, int sk, int ssk)
{
    mapping cnd = ([]);

    if( !objectp(me) || !objectp(target) ) {
        tell_object(me, "�ˮ`��Ĳ�ϥΤ�k�G perform harm touch.harming on [�ﹳ]\n");
        return 0;
    }

    if( !me->is_fighting(target) ) {
        tell_object(me, "�A�å��M���b�԰���...\n");
        return 0;
    }

    if( me->query_condition("harm_touch_cond" ) ) {
        tell_object(me, "�A���骺���A�٨S����_�A�ȮɵL�k�ϥζˮ`��Ĳ�C\n");
        return 0;
    }

    if( me->is_busy() ) {
        tell_object(me, "�A�����ۡC\n");
        return 0;
    }

    if( act != "harming" ) {
        tell_object(me, "" + SKILL_NAME_C + "�u�� harming ���\\��C\n");
        return 0;
    }

    if( sk < 25 || ssk < 30  ) {
        tell_object(me, "�A�ثe����O�٤����H�ϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    if( me->query_stat("mp") < 1 ) {
        tell_object(me, "�A�����O�ȧC�� 1�A�L�k�ϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    return 1;
}

// �ϥε���
int perform_action(object me, string act, object target)
{
    int sk, ssk, dmg, time;
    mapping cnd = ([]);

    sk = me->query_skill(SKILL_NAME, 1);
    ssk = me->query_skill("special", 1);

    if( !isCast(me, act, target, sk, ssk) ) return 1;

    dmg = sk*10 + ssk*5;
    message_vision( HIG"$N����������@�r���c�F�A�����aĲ�I�F$n�@�U...\n" NOR, me, target);

    target->receive_damage(dmg, me);
    message_vision( HIR "$n�o�X�@�}�Y�F���s�n�A����F " + dmg + " �I���i�ȶˮ`�I�I" + COMBAT_D->report_status(target) +"\n" NOR, me, target);

    me->damage_stat("mp", 1, me);
    me->improve_skill( SKILL_NAME, 1);

    time = getDuration(sk);

    cnd["name"] = HIK"(CD)�ˮ`"NOR;
    cnd["duration"] = time;
    cnd["no_clear"] = 1;
    me->set_condition("harm_touch_cond", cnd);
    me->start_busy(2);
    return 1;
}
