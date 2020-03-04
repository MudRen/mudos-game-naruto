#include <ansi.h>
#define SKILL_NAME "chimera fay"
#define SKILL_NAME_C "�۷Q����"
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
    return ability + me->query_skill(SKILL_NAME)/100;
}

int defend(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)*7/20;
}

// �ˬd�O�_��ϥΧޯ�
int isCast(object me, string act, int sk)
{
    if( !objectp(me) ) return 0;

    if( me->is_busy() ) {
        tell_object(me, "�A�{�b�S���Ũϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    if( act != "assoil" ) {
        tell_object(me, "�ثe" + SKILL_NAME_C + "�� assoil �o�ӥ\\��C\n");
        return 0;
    }

    if( me->query_skill("activity", 1) < 60 || sk < 50 ) {
        tell_object(me, "�A����O�����H�ϥγo�@�ۡC\n");
        return 0;
    }

    if( me->query_stat("mp") < sk/2 ) {
        tell_object(me, "�A�����A�L�k�ϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    if( me->query_condition("elf", 1) ) {
        tell_object(me, "�A�w�g�b�ϥ�" + SKILL_NAME_C + "�ޥ��F�C\n");
        return 0;
    }

    if( !me->is_fighting() ) {
        tell_object(me, "�S�b�԰�������n�����C\n");
        return 0;
    }

    return 1;
}

void do_perform(object me, int sk)
{
    object *team, member, staff;
    mapping cnd = ([]);

    team = me->query_team();

    // ���������W���S���ѭԴ�
    if( !objectp(staff = present("_WEATHER_", me)) ) {
        write("�A���W�S���ѭԴΫ��Χޯ�C\n");
        return;
    }
    message_vision("$N���X"+staff->query("name")+"�ô��@�q�M�ỡ�D�G"HIW"�����¼�"NOR"�E"HIC"�۷Q����"NOR"�I\n"NOR, me);

    // ���A�@��
    cnd["name"] = HIC+SKILL_NAME_C+NOR;
    cnd["duration"] = sk/4;
    cnd["evade"] = sk/2;

    if( !pointerp(team = me->query_team() ) ) {
        message_vision(HIW"$N�����v���������b�o��...\n"NOR, me);
        me->set_condition("elf", cnd);
    } else {
        foreach(member in team) {
            // �ն��H����m���P�]�S���\��
            if( environment(me)->is_area() && !area_environment(me, member)) continue;
            message_vision(HIW"$N�����v���������b�o��...\n"NOR, member);
            member->set_condition("elf", cnd);
        }
    }
    me->damage_stat("mp", sk/2, me);
    me->improve_skill(SKILL_NAME, 1);
    return;
}
int perform_action(object me, string act)
{
    int sk;
    sk = me->query_skill(SKILL_NAME, 1);

    // �ˬd�O�_��ϥΧޯ�
    if( !isCast(me, act, sk) ) return 1;

    do_perform(me, sk);
    return 1;
}
