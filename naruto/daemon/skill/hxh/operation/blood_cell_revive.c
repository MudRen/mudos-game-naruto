/* �ާ@�N�G��y�A��(blood-cell revive) */
// �W�[���[��O by mouse 2007/7/25

#include <ansi.h>
#define SKILL_NAME   "blood-cell revive"
#define SKILL_NAME_C "��y�A��"
#define SKILL_CLASS  "operation"

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

// ���m�ޥ��v�T
int wittiness(object me, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/10;
}

// ���m�O�q�v�T
int defend(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)*3/40;
}

void do_perform(object me, object target)
{
    int sk;
    mapping cnd = ([]);
    
    sk = me->query_skill( SKILL_NAME, 1);
        
    if( sk < 20 || me->query_skill("operation", 1) < 40 ) {
        write("�A����O�����H�ϥγo�ӧޯ�C\n");
        return;
    }
    if( objectp(target) ) {
        if( sk < 60 ) {
            write("�A�ٵL�k��L�H�ϥγo�ӧޯ�C\n");
            return;
        }
    } else target = me;

    if( target->query_condition("blood_cell_revive_cond") != 0 ) {
        write(target->query("name")+"�w�g�Q�I�L��y�A�ͤF�C\n");
        return;
    }
    if( me->query_stat("mp") < sk*3/2 ) {
        write("�A�ثe�S������������O�ӨϥΦ�y�A�͡C\n");
        return;
    }
    me->damage_stat("mp", sk*3/2, me);

    message_vision("$N�N���O�@�x��i�h$n�������W�A�I�i�F"HIR"��y�A��"NOR"�I�I\n", me, target);

    cnd["name"] = HIR"��y�A��"NOR;
    cnd["duration"] = 60;
    cnd["heal"] = sk/10;

    target->set_condition("blood_cell_revive_cond", cnd);

    // �W�[�ޯ�g��
    me->improve_skill(SKILL_NAME, 1);
}

int perform_action(object me, string act, object target)
{
    if( !objectp(me) ) return 0;
    if( me->is_busy() ) return notify_fail("�A�{�b�S���ŨϥΦ�y�A�͡C\n");

    switch( act ) {
        case "revive": do_perform(me, target); break;
        default: return notify_fail("�ثe��y�A�ͦ� revive �o�ӥ\\��C\n"); break;
    }
    return 1;
}
