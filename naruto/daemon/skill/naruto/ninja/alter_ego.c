/* alter_ego.c �ԳN�G�����N 
   �W�[�v�����N���� by mouse 2007/8/12
   �ק�g����o���� by mouse 2008/4/26
*/

#include <ansi.h>
#define SKILL_NAME "alter ego"
#define SKILL_NAME_C "�����N"
#define SKILL_CLASS "ninja"
#define SHADOW_NUM 5

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

// �����ޥ��v�T
int intimidate(object me, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)*3/40;
}

// �j�ׯ�O�v�T
int evade(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/20;
}

// �гy�����禡
void construct_shadow(object me)
{
    int i, count, sk, sha;
    object shadow;
    mapping map;

    sk = me->query_skill(SKILL_NAME, 1);
    sha = me->query_skill("shadow", 1);

    if( sk < 40 || me->query_skill("ninja") < 20 ) {
        write("�A����O�����A����ϥ�"+SKILL_NAME_C+"�C\n");
        return;
    }

    if( me->query_stat("mp") < 20 ) {
        write("�A�ثe�S���������d�J�ԨӨϥ�" + SKILL_NAME_C + "�C\n");
        return;
    }
    map = me->query_temp("shadow");
    count = sizeof(map);

    // �M��i�νs�� count
    if( count ) {
        count = 0;
        for(i=0;i<SHADOW_NUM;i++)
            if( objectp(map["shadow"+i]) ) count++;
    }

    if( count >= SHADOW_NUM || count >= sk/40 ) {
        write("�A�������ƶq�w�g���h�F�A�L�k�A�гy�h�l�������C\n");
        return;
    }
    
    shadow = new(__DIR__"obj/shadow.c");
    if( !objectp(shadow) ) {
        write("�A���G�L�k�гy����...\n");
        destruct(shadow);
        return;
    }
    shadow->set("number", "shadow/shadow"+count);

    if( sha > 39 && sk > 99 && count < sha/60 ) {

        // �v�������d�J�ԭ���b�o�̧P�_
        if( me->query_stat("mp") < 50 ) {
            write("�A�S���������d�J�Ԩϥμv�����N�C\n");
            return;
        }
        message_vision("$N���⭸�֦a���L�A�N�d�J�Ԥ�����|�P�A�I�i�F"HIB"�v����"HIW"���N"NOR"�I�I\n", me);
        me->damage_stat("mp", 50, me);
        me->start_busy(3);
    } else {
        message_vision("$N����ֳt�����L�A�I�i�F"HIW+ SKILL_NAME_C +NOR"�I�I\n", me);
        me->damage_stat("mp", 20, me);
        me->start_busy(3);
    }
    if( environment(me)->is_area() ) {
        if( !area_move(environment(me), shadow, me->query("area_info/x_axis"), me->query("area_info/y_axis")) ) {
            write("�A�������X�ӫ�A�S���������F...\n");
            destruct(shadow);
            return;
        }
    } else {
        if( !shadow->move(environment(me)) ) {
            write("�A�������X�ӫ�A�S���������F...\n");
            destruct(shadow);
            return;
        }
    }
    // �]�w�W��, ID
    if( sha > 39 && sk > 99 && count < sha/60 ) shadow->set_name(HIB"[�v]"NOR+me->query("name"), ({ me->query_id() + "'s shadow",  "shadow" }));
    else shadow->set_name(HIW"[��]"NOR+me->query("name"), ({ me->query_id() + "'s alter ego",  "ego" }));
    shadow->set("nickname", me->query("nickname"));
    shadow->set("title", me->query("title"));

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

    // ����q�P�_�A�����i�H�@�δN���Φh�g�F
    if( sha > 39 && sk > 99 && count < sha/60 ) {
        // �P�_���a�]�w���v�����O����������
        switch( me->query_temp("SHADOW_TEMP") ) {
            // ������
            case 0: shadow->set("no_evade", 1);

                    shadow->set("apply/attack", me->query_ability("attack")/2);
                    shadow->set("apply/armor", me->query_ability("defend")/2);

                    shadow->set_skill("parry", me->query_skill("parry"));
                    shadow->set_skill("combat", me->query_skill("combat"));
                    break;
            // ���m��
            case 1: shadow->set("no_combat", 1);

                    shadow->set("apply/armor", me->query_ability("defend")/2);
                    shadow->set("apply/evade", me->query_ability("evade")/2);

                    shadow->set_skill("parry", me->query_skill("parry"));
                    shadow->set_skill("dodge", me->query_skill("dodge"));
                    break;
            // ������
            case 2: shadow->set("no_defend", 1);
                    shadow->set("no_evade", 1);

                    // �������������԰��ʧ@�A�԰����O�g�b������
                    shadow->set("chat_chance_combat", 10);
                    shadow->set("apply/attack", me->query_ability("attack"));
                    shadow->set("apply/exact", me->query_ability("exact"));

                    // sk �]�n�]�w
                    shadow->set_skill("combat", me->query_skill("combat"));
                    shadow->set_skill("continual hit", me->query_skill("continual hit"));
                    shadow->set_skill("savage hit", me->query_skill("savage hit"));
                    shadow->set_skill("heavy hit", me->query_skill("heavy hit"));
                    if( me->query_skill("thousand year kill") > 49 ) {
                        shadow->set_skill("thousand year kill", me->query_skill("thousand year kill"));
                        shadow->set_skill("force", me->query_skill("force"));
                    }
                    break;
        }
        shadow->set_skill("heavy hit", me->query_skill("heavy hit"));
        if( sha >= 200 ) {
            shadow->set_skill("substitute", me->query_skill("substitute")/2);
            shadow->map_skill("dodge", "substitute");
        }
        // �ϥμv�����W�[�v�������g��
        me->improve_skill("shadow", 1);
    } else {
        // �԰��]�w
        shadow->set("no_combat", 1);      // �������
        shadow->set("no_defend", 1);      // ���ਾ�m
        shadow->set("no_evade", 1);       // ����j��
        me->improve_skill(SKILL_NAME, 1); // �W�[�ޯ�g��
    }
    shadow->set("skill", SKILL_NAME);  // shadow�O��alter ego�ޯ�s�X
    me->set_temp("shadow/shadow"+count, shadow);

    shadow->guard_ob(me);       //�O�@leader
    shadow->set_leader(me);     //���Hleader
    shadow->set_owner(me);      //�]�wowner
    return;
}

// �R�������禡
void destruct_shadow(object me)
{
    object shadow, *obs;
    
    if( !me->query_temp("shadow") ) {
        write("�A�ثe�S�����󪺤����s�b�C\n");
        return;
    }
    
    if( sizeof(obs = values(me->query_temp("shadow"))) <= 0 ) {
        write("�A�ثe�S�����󪺤����s�b�C\n");
        return;
    }
    foreach(shadow in obs) {
        if( objectp(shadow) ) shadow->do_destruct();
        me->delete_temp("shadow");
    }
    write("�A���Ҧ������������F�C\n");

    return;
}

// �ϥε���
int perform_action(object me, string act, object target)
{
    if( !objectp(me) ) return 0;
    if( me->is_busy() ) return notify_fail("�A�{�b�S���ŨϥΤ����N�C\n");

    switch( act ) {
        case "shadow": construct_shadow(me); break;
        case "destruct": destruct_shadow(me);  break;
        default: return notify_fail("�ثe������ shadow, destruct ��إ\\��C\n"); break;
    }
    return 1;
}
