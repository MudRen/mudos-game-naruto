/* eaves family ��ò�U���@�a�H 
   ��{�t rank 1 sk
   -tmr 20051117
   update by Acme 2007.03.16
   �W�[���[��O by mouse 2007/7/25
   �ץ��a�H�������Ҧ� by mouse 2007/8/11
*/

#include <ansi.h>
#define SKILL_NAME   "eaves family"
#define SKILL_NAME_C "��ò�U���@�a�H"
#define SKILL_CLASS  "concrete"
#define SHADOW_NUM   4

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
    return ability + me->query_skill(SKILL_NAME)/40;
}

// �j�ׯ�O�v�T
int evade(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/10;
}

// �гy�����禡
void construct_shadow(object me)
{
    int i, count;
    object shadow;
    mapping map;

    if( me->query_skill("concrete", 1) < 20 ) {
        write("�A����O�����H�ϥγo�ӧޯ�C\n");
        return;
    }
    
    if( me->query_skill(SKILL_NAME, 1) < 50 ) {
        write("�A���ޯ൥�Ť����A�C�h���Q�ťi�h��{�@�Ӯa�H�C\n");
        return;
    }

    // �֦��̮����@�Ǭd�J��
    if( me->query_stat("mp") < 20 ) {
        write("�A�����O�����C\n");
        return;
    }

    map = me->query_temp("FAMILY");
    count = sizeof(map);
    
    // �M��i�νs�� count
    if( count ) {
        count = 0;
        for(i=0;i<SHADOW_NUM;i++)
            if( objectp(map["FAMILY"+i]) ) count++;
    }

    if( count >= me->query_skill(SKILL_NAME, 1)/50 ) {
        write("�A�ثe�L�k�A��{�h�l���a�H�C\n");
        return;
    }
    
    shadow = new(__DIR__"obj/family_obj.c");
    if( !objectp(shadow) ) {
        write("�A���G�L�k��{���\...\n");
        destruct(shadow);
        return;
    }

    message_vision("$N���W�����O�}�l�B��A�C�C�a�b���侮�E���@�ӤH�ΡI�I\n", me);
    me->damage_stat("mp", 20, me);
    me->start_busy(3);

    if( environment(me)->is_area() ) {
        if( !area_move(environment(me), shadow, me->query("area_info/x_axis"), me->query("area_info/y_axis")) ) {
            write("�A���a�H�X�ӫ�A�S���������F...\n");
            destruct(shadow);
            return;
        }
    } else {
        if( !shadow->move(environment(me)) ) {
            write("�A���a�H�X�ӫ�A�S���������F...\n");
            destruct(shadow);
            return;
        }
    }

    // �]�w�W��, ID
    switch( random(4) ) {
            case 0: shadow->set_name(me->query("name") + "���j�j", ({ me->query_id() + "'s family",  "family" })); break;
            case 1: shadow->set_name(me->query("name") + "���f�f", ({ me->query_id() + "'s family",  "family" })); break;
            case 2: shadow->set_name(me->query("name") + "������", ({ me->query_id() + "'s family",  "family" })); break;
            case 3: shadow->set_name(me->query("name") + "���̧�", ({ me->query_id() + "'s family",  "family" })); break;
    }

    // �ۦP����
    shadow->set("level", me->query_level());

    // �ۦP�ݩ�
    shadow->set_attr("str", me->query_attr("str"));
    shadow->set_attr("con", me->query_attr("con"));
    shadow->set_attr("int", me->query_attr("int"));
    shadow->set_attr("dex", me->query_attr("dex"));

    // �ۦP���A
    shadow->set_stat_current("ap", me->query_stat_maximum("ap"));
    shadow->set_stat_maximum("ap", me->query_stat_maximum("ap"));
    shadow->set_stat_current("hp", me->query_stat_maximum("hp"));
    shadow->set_stat_maximum("hp", me->query_stat_maximum("hp"));
    shadow->set_stat_current("mp", me->query_stat_maximum("mp"));
    shadow->set_stat_maximum("mp", me->query_stat_maximum("mp"));

    // �԰��]�w�A��{�Ƶ{�פp�� 100 �e�a�H���|����
    if( me->query_skill("concrete") < 100 ) shadow->set("no_combat", 1); // �������
    shadow->set("no_defend", 1); // ���ਾ�m
    shadow->set("no_evade", 1);  // ����j��

    shadow->set_leader(me);     //���Hleader
    shadow->set_owner(me);      //�]�wowner

    shadow->set("skill", SKILL_NAME);

    me->set_temp("FAMILY/FAMILY"+count, shadow);
    
    // �W�[�ޯ�g��
    me->improve_skill(SKILL_NAME, 1);

    shadow->guard_ob(me);       //�O�@leader
    return;
}

// �R�������禡
void destruct_shadow(object me)
{
    object shadow, *obs;


    if( !me->query_temp("FAMILY") ) {
        write("�A�ثe�S�����󪺮a�H�s�b�C\n");
        return;
    }
    if( sizeof(obs = values(me->query_temp("FAMILY"))) <= 0 ) {
        write("�A�ثe�S�����󪺮a�H�s�b�C\n");
        return;
    }
    foreach(shadow in obs)
    if( objectp(shadow) ) shadow->do_destruct();
    me->delete_temp("shadow");

    write("�A��{�X�Ӫ��Ҧ��a�H�������F�C\n");

    return;
}

// �ϥε���
int perform_action(object me, string act, object target)
{
    if( !objectp(me) ) return 0;
    if( me->is_busy() ) return notify_fail("�A�{�b�S���ŨϥΡC\n");

    switch( act ) {
        case "family": construct_shadow(me); break;
        case "destruct": destruct_shadow(me);  break;
        default: return notify_fail("�ثe��ò�U���@�a�H�� family, destruct ��إ\\��C\n"); break;
    }
    return 1;
}
