#include <ansi.h>
#define SKILL_NAME "change ability"
#define SKILL_NAME_C "�����ഫ"
#define SKILL_CLASS "special"

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

void do_perform_up(object me, string msg, string two)
{
    write("�A�Pı���\\���N�z�ഫ��"+msg+NOR"�F�I\n");
    me->set("ghost_change/"+two, 1);
    me->damage_stat("mp", 50, me);
    me->start_busy(3);
    me->improve_skill(SKILL_NAME, 1);
    return;
}

void do_perform_down(object me, string msg, string two)
{
    mapping cnd = ([]);
    int sk;

    sk = me->query_skill(SKILL_NAME, 1);

    write(HIK"�A�Pı�����@�}�w�t�A���G�O�z�o���ഫ���ѡI\n"NOR);
    me->delete_condition("ghost_change1");
    me->delete_condition("ghost_change2");
    me->delete_condition("ghost_change3");
    me->delete_condition("ghost_change4");
    me->delete("ghost_change");
    cnd["name"] = HIK"(���त)"NOR;
    cnd["duration"] = sk*18;
    cnd["str"] = sk/2;
    cnd["dex"] = sk/2;
    cnd["con"] = sk/2;
    cnd["int"] = sk/2;
    me->damage_stat("mp", 100, me);
    me->set_condition("ghost_change_down", cnd);
    me->start_busy(3);
    return;
}

void do_perform(object me, string two)
{
    mapping cnd = ([]);
    string msg;
    int sk, i;

    sk = me->query_skill(SKILL_NAME, 1);

    if( me->is_fighting() ) {
        write("�԰����ಾ��z�H�A�Ʊ��F��X¬�ܡH\n");
        return;
    }
    if( me->query_skill("special", 1) < 50 || sk < 50 ) {
        write("�A�ٵL�k�ϥγo�˧ޯ�C\n");
        return;
    }
    if( me->query_stat("mp") < 100 ) {
        write("�A���骬�p���ΡA����ϥ�" + SKILL_NAME_C + "�C\n");
        return;
    }
    if( me->query_condition("ghost_change_down") != 0 ) {
        write("�A�ثe��z�@���V�áA�y�L�𮧤@�q�ɶ��A�Χa�C\n");
        return;
    }
    if( two == "str" && me->query("ghost_change/str") ) {
        write("�A�w�g����z�b���ɤO�q�F�C\n");
        return;
    }
    if( two == "dex" && me->query("ghost_change/dex") ) {
        write("�A�w�g����z�b���ɱӱ��F�C\n");
        return;
    }
    if( two == "con" && me->query("ghost_change/con") ) {
        write("�A�w�g����z�b�������F�C\n");
        return;
    }
    if( two == "int" && me->query("ghost_change/int") ) {
        write("�A�w�g����z�b���ɴ��z�F�C\n");
        return;
    }
    switch( two ) {
        case "str": msg = ""HIR"�O�q";
                    cnd["name"] = HIR"�O�q����"NOR;
                    cnd["duration"] = sk/2;
                    cnd["str"] = sk/10;
                    cnd["ability"] = "str";
                    break;
        case "dex": msg = ""HIG"�ӱ�";
                    cnd["name"] = HIG"�ӱ�����"NOR;
                    cnd["duration"] = sk/2;
                    cnd["str"] = sk/10;
                    cnd["ability"] = "dex";
                    break;
        case "con": msg = ""HIY"���";
                    cnd["name"] = HIY"��责��"NOR;
                    cnd["duration"] = sk/2;
                    cnd["str"] = sk/10;
                    cnd["ability"] = "con";
                    break;
        case "int": msg = ""HIC"���z";
                    cnd["name"] = HIC"���z����"NOR;
                    cnd["duration"] = sk/2;
                    cnd["str"] = sk/10;
                    cnd["ability"] = "int";
                    break;
        default: write("�i�H���w�����ج� str, dex, con, int�C\n");
                 return;
                 break;
    }

    // �����ഫ�Ĥ@���@�w���\�A�G�T�����v�ѧޯ൥�żv�T�A�ĥ|���h�T�w 200 �� +15
    // �ഫ���\�̰���[ 20 �I�ݩʡA�ഫ���ѷ|���� 40 �I
    // ���Ѯɵ���N�o�ɶ��A�����n 1 �Ӥp�ɥH�W�A�S���ѴN���ΧN�o

    i = 100;

    message_vision(HIW"\n$N"HIW"�R���߫�A�N�餺���C�z�ǥѩ��O���N�ഫ...\n"NOR, me);
    if( !me->query_condition("ghost_change1") ) {
        me->set_condition("ghost_change1", cnd);
        do_perform_up(me, msg, two);
        return;
    } else if( !me->query_condition("ghost_change2") ) {
        if( sk > 100 ) i += sk - 100;
        if( random(i) >= 50 ) {
            me->set_condition("ghost_change2", cnd);
            do_perform_up(me, msg, two);
            return;
        }
        do_perform_down(me, msg, two);
        return;
    } else if( !me->query_condition("ghost_change3") ) {
        if( sk >= 150 ) i += sk - 150;
        if( random(i) > 75 ) {
            me->set_condition("ghost_change3", cnd);
            do_perform_up(me, msg, two);
            return;
        }
        do_perform_down(me, msg, two);
        return;
    } else if( !me->query_condition("ghost_change4") ) {
        if( sk >= 200 ) i += 15;
        if( random(i) > 95 ) {
            me->set_condition("ghost_change4", cnd);
            do_perform_up(me, msg, two);
            return;
        }
        do_perform_down(me, msg, two);
        return;
    } else {
        write("�A�w�g��F�@�b�H�W���z���ɯ�O�A�A�Υi��|�����J�]�C\n");
        return;
    }
    message_vision("���G�o�ͤF�@�ǲ��`..�Ь��Ův�B�z�C\n"NOR, me);
    return;
}

int perform_action(object me, string act, object target)
{
    string one, two;
    if( !objectp(me) ) return 0;

    if( me->is_busy() )
        return notify_fail("�A�{�b�S���Ũϥ�" + SKILL_NAME_C + "�C\n");

    if( !act || sscanf(act, "%s %s", one, two) != 2 )
        return notify_fail("���O�榡�Rperform change ability.change <�ݩ�>\n");

    if( one != "change" ) return notify_fail("�ثe" + SKILL_NAME_C + "�u�� change �\\��C\n");

    do_perform(me, two);
    return 1;
}
