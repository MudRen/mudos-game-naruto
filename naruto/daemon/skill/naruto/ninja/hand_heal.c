/* �x�P�N(hand heal) by mouse 2007/8/13 */

#include <ansi.h>
#define SKILL_NAME "hand heal"
#define SKILL_NAME_C "�x�P�N"
#define SKILL_CLASS "ninja"

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

int get_bonus(int lv)
{
    if(lv < 60 ) return 50;
    if(lv < 100 ) return 60;
    if(lv < 120 ) return 70;
    if(lv < 160 ) return 80;
    if(lv < 200 ) return 90;
    return 100;
}

// �ˬd�O�_��ϥΧޯ�
int isCast(object me, string act, int sk, string one, string two)
{
    if( !objectp(me) ) return 0;

    if( one == two ) {
        tell_object(me, "�o������O�P�@�ت��H�����h�ܦn���H\n");
        return 0;
    }

    if( one != "hp" && one != "ap" && one != "mp" ) {
        tell_object(me, "" + SKILL_NAME_C + "�u���ഫ��O(ap)�B��O(hp)�B�]�O(mp)�C\n");
        return 0;
    }

    if( two != "hp" && two != "ap" && two != "mp" ) {
        tell_object(me, "" + SKILL_NAME_C + "�u���ഫ��O(ap)�B��O(hp)�B�]�O(mp)�C\n");
        return 0;
    }

    if( me->query_skill("ninja", 1) < 100 || sk < 20 ) {
        tell_object(me, "�A�ثe���ԳN�y���٤����w�ϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    // �ɥδc�]���}�N�o�ɶ�
    if( me->query_condition("diabo_busy", 1) != 0) {
        tell_object(me, SKILL_NAME_C + "���b�N�o���A�йL�@�|�A�ϥΡC\n");
        return 0;
    }

    if( me->query_stat_maximum(two) <= me->query_stat(two) ) {
        tell_object(me, "�A�����骬�p�Q���}�n�A���ݨϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    return 1;
}

void do_perform(object me, string one, string two, int number, int sk)
{
    int heal, bonus, i;
    mapping cnd = ([]);

    heal = me->query_stat_maximum(two) - me->query_stat(two);
    bonus = get_bonus(sk);

    if( number >= 1 ) {
        if( me->query_stat(one) < number + 1 ) {
            write("�A�S������h�� "RED+one+NOR" �h�ɥR "RED+two+NOR"�C\n");
            return;
        }
    } else {
        if( me->query_stat(one) < heal + 1) {
            write("�A�S������h�� "RED+one+NOR" �h�ɥR "RED+two+NOR"�C\n");
            return;
        }
    }
    message_vision("$N�H�_�S���⦡�ֳt���L�A���۱N�⤤�X�{���Ŧ���y�u"HIC"�x�P��"NOR"�v���J�ۤv���ݤf...\n"NOR, me);
    if( number >= 1 ) {
        i = number*bonus/100;
        me->damage_stat(one, number, me);
        me->heal_stat(two, i);
        tell_object(me,HIC"�A��O�F "NOR+HIR+number+HIC" �I "NOR+one+HIC" �ɥR�F "HIY+i+HIC" �I "NOR+two+HIC"�C\n"NOR);
    } else {
        i = heal*bonus/100;
        me->damage_stat(one, heal, me);
        me->heal_stat(two, i);
        tell_object(me,HIC"�A��O�F "NOR+HIR+heal+HIC" �I "NOR+one+HIC" �ɥR�F "HIY+i+HIC" �I "NOR+two+HIC"�C\n"NOR);
    }
    me->improve_skill(SKILL_NAME, 1);

    cnd["name"] = HIC"(CD)�x�P"NOR;
    cnd["duration"] = 10;

    me->set_condition("diabo_busy", cnd);

    return;
}

int perform_action(object me, string act, object target)
{
    int sk, number;
    string one, two;

    sk = me->query_skill(SKILL_NAME, 1);

    if( !objectp(me) ) return 0;

    if( !act || sscanf(act, "%s to %s %d", one, two, number) != 3 ) {
        if( !act || sscanf(act, "%s to %s", one, two) != 2 ) return notify_fail("���O�榡�Rperform hand heal.<1> to <2> <�ഫ��>\n");
    }
    // �ˬd�O�_��ϥΧޯ�
    if( !isCast(me, act, sk, one, two) ) return 1;

    do_perform(me, one, two, number, sk);
    return 1;
}
