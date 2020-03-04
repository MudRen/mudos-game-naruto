/* chamber fish �K�ǩ��� 
   ��{�t rank 2 sk
   -tmr 20060604
   update by Acme 2007.03.16
   �W�[���[��O by mouse 2007/7/25
*/

#include <ansi.h>
#define SKILL_NAME "chamber fish"
#define SKILL_NAME_C "�K�ǩ���"
#define SKILL_CLASS "concrete"

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

// �R����O�v�T
int exact(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/10;
}

// �гy�����禡
void construct_shadow(object me)
{
    int lv, sk;
    object shadow, armor;

    sk = me->query_skill("concrete", 1);

    if( sk < 50 ) {
        write("�A����O�����H�ϥγo�ӧޯ�C\n");
        return;
    }

    if( me->query_skill(SKILL_NAME, 1) < 10 ) {
        write("�A���K�ǩ������Ť����A�L�k�ϥγo�ӧޯ�C\n");
        return;
    }

    // �֦��̮����@�Ǭd�J��
    if( me->query_stat("mp") < 100 ) {
        write("�A�ݭn�ܤ�100�I�����O�A�~��l���K�ǩ����C\n");
        return;
    }

    if( objectp(me->query_temp("CHAMBER_FISH")) ) {
        write("�A�w�g�֦��@���K�ǩ����F�C\n");
        return;
    }

    shadow = new(__DIR__"obj/fish_obj.c");
    if( !objectp(shadow) ) {
        write("�A���G�L�k��{���\...\n");
        destruct(shadow);
        return;
    }

    message_vision("$N���W�����O�����a�b�|�g���E�����A�@���K�ǩ����Ө�o�ӥ@�ɤF�I�I\n", me);
    me->damage_stat("mp", 100, me);
    me->start_busy(3);

    if( environment(me)->is_area() ) {
        if( !area_move(environment(me), shadow, me->query("area_info/x_axis"), me->query("area_info/y_axis")) ) {
            write("�A���K�ǩ����X�ӫ�A�S���������F...\n");
            destruct(shadow);
            return;
        }
    } else {
        if( !shadow->move(environment(me)) ) {
            write("�A���K�ǩ����X�ӫ�A�S���������F...\n");
            destruct(shadow);
            return;
        }
    }

    shadow->set_name(me->query("name") + "���K�ǩ���", ({ me->query_id() + "'s chamber fish",  "fish" }));

    // �ޯ�v�T�������j��
    // �C5�Ť@�ӵ��šA�̺��O60��
    lv = (me->query_skill(SKILL_NAME)/10)*3;

    // �̵��Ŵ��ɯ�O
    // �H�U��Ԥ��@��
    shadow->set_level(lv);
    shadow->set_attr("str", lv*150/100);
    shadow->set_attr("con", lv*150/100);
    shadow->set_attr("dex", lv*150/100);
    shadow->set_attr("int", lv*150/100);
    shadow->set_stat_maximum("ap", lv*50);
    shadow->set_stat_maximum("hp", lv*50);
    shadow->set_stat_maximum("mp", lv*50);
    shadow->set_stat_current("ap", lv*50);
    shadow->set_stat_current("hp", lv*50);
    shadow->set_stat_current("mp", lv*50);
    shadow->set_skill("combat", lv*3);
    shadow->set_skill("parry", lv*3);
    shadow->set_skill("dodge", lv*3);
    shadow->set_skill("heavy hit", lv*3);
    shadow->set_skill("savage hit", lv*3);
    shadow->set_skill("continual hit", lv*3);

    // ���� armor
    if( sk > 100 ) {
        armor = new(__DIR__"obj/armor.c");

        armor->set("apply_armor/armor", ([
                   "armor": sk/2,
                   "hp": sk*5,
               ]));

        armor->move(shadow);
        armor->wear();
    }
    shadow->do_heal();

    shadow->set_leader(me);     //���Hleader
    shadow->set_owner(me);      //�]�wowner

    me->set_temp("CHAMBER_FISH", shadow);

    // �W�[�ޯ�g��
    me->improve_skill(SKILL_NAME, 1);

    shadow->guard_ob(me);       //�O�@leader
    return;
}

// �R�������禡
void destruct_shadow(object me)
{
    object shadow, *obs;
    
    if( !me->query_temp("CHAMBER_FISH") ) {
        write("�A�ثe�S�����󪺱K�ǩ����C\n");
        return;
    }
    write("�A��{�X�Ӫ��K�ǩ����^��e�쥻���@�ɤF�C\n");
    me->query_temp("CHAMBER_FISH")->do_destruct();
    me->delete_temp("CHAMBER_FISH");
    return;
}

// �}�i�����A���e���X�r��
void feed_fish(object me)
{
    int lv, atk;
    object fish, wp;

    lv = me->query_skill(SKILL_NAME)/5;

    if( !objectp(fish=me->query_temp("CHAMBER_FISH")) ) {
        write("�A�ثe�S�����󪺱K�ǩ����C\n");
        return;
    }
    if( me->query_stat("mp") < 100 ) {
        write("�A�ܤֻݭn100�I�����O�ȡA�~��}�i�K�ǩ����C\n");
        return;
    }

    if( me->query_skill(SKILL_NAME) < 100 ) {
        write("�A���ޯ൥���٤������C\n");
        return;
    }
    if( fish->query("feed") > 1000 ) {
        write("�A���K�ǩ����w�g���ݭn�A�}�i�F�C\n");
        return;
    }
    // �W�[�ޯ�g��
    me->improve_skill(SKILL_NAME, 1);

    message_vision(CYN"$N���_�Ǻ��S�X�j�L�A$n�@�f�r��$N���j�L�A�}�l�l�m$N�����O...\n"NOR, me, fish);
    me->damage_stat("mp", 20 + random(10), me);
    me->start_busy(1);
    
    fish->add("feed", me->query_attr("con") + random(me->query_level()) );
    fish->add_temp("fish_armor", 1);

    if( fish->query("feed") < 1000 ) return;

    // �r���������O�|�������v�T
    atk = 140 - ( fish->query_temp("fish_armor") * 10 );
    if( atk < 40 ) atk = 40;
    wp = new(__DIR__"obj/tooth.c");

    wp->setup_weapon(atk, atk+20, 100, 1);
    wp->move(fish);
    wp->wield("righthand");
    message_vision(HIG"���M$n�@�P�a�ݰʡA�L�̳��M���X�@�Ʋ`��⪺�y��...\n"NOR, me, fish);
    if( me->query_skill(SKILL_NAME) > 150 && random(me->query_skill(SKILL_NAME)) > me->query_skill(SKILL_NAME)*3/10 ) {
        wp = new(__DIR__"obj/tooth.c");
        wp->setup_weapon(atk, atk+20, 100, 1);
        wp->move(fish);
        wp->wield("lefthand");
        message_vision(HIG"�֪��y���|�������A$n�o�X�@�}�C��A�L�̤S���X�F�t�@�ƺ��y��...\n"NOR, me, fish);
    }
    fish->set("name", me->query("name") + "��"GRN"�K�ǩ���"NOR);
}

// �d�ߩ���
void show_state(object me)
{
    object fish, armor, tooth;
    string *msg, cnd, show = "";
    int i, cnd_data;
    
    if( !objectp(fish = me->query_temp("CHAMBER_FISH")) ) {
        write("�A�ڥ��N�S����{�����C\n");
        return;
    }
    armor = present("scale armor", fish);
    tooth = present("fish tooth", fish);

    printf("[%s] �믫�G%d/%d, ��O�G%d/%d, �]�O�G%d/%d\n"NOR,
        fish->query("name"),
        fish->query_stat_current("ap"),
        fish->query_stat_maximum("ap"),
        fish->query_stat_current("hp"),
        fish->query_stat_maximum("hp"),
        fish->query_stat_current("mp"),
        fish->query_stat_maximum("mp"), );

    write("�ססססססססססססססססססססססססססססססססס�\n");

    if( armor ) {
        msg = armor->query("apply_armor/armor");
        foreach(cnd, cnd_data in msg) {
            show += cnd+":"+cnd_data+"  ";
        }
        printf("[%s]�Z�ұj�סG%s\n"NOR, armor->query("name"), show);
    }
    if( tooth ) printf("[%s]�Z���j�סG%d - %d\n"NOR, tooth->query("name"), tooth->query("damage/righthand/lower"), tooth->query("damage/righthand/upper") );
    return;
}

// �ϥε���
int perform_action(object me, string act, object target)
{
    if( !objectp(me) ) return 0;
    if( me->is_busy() ) return notify_fail("�A�{�b�S���ŨϥΡC\n");

    switch( act ) {
        case "feed": feed_fish(me); break;
        case "fish": construct_shadow(me); break;
        case "destruct": destruct_shadow(me);  break;
        case "state": show_state(me); break;
        default: return notify_fail("�ثe�K�ǩ����� fish, feed, destruct, state �|�إ\\��C\n"); break;
    }
    
    return 1;
}