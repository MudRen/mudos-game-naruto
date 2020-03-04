#include <ansi.h>

inherit AREA;

void create()
{
    set("name", "�������𢹼h");
    set("x_axis_size", 30);            // ��V�j�p
    set("y_axis_size", 30);            // �a�V�j�p
    setup();
    set("no_recall", 1);
    set("no_drop", 1);
}

void init()
{
    add_action("do_up", "up");
    add_action("do_out", "exit");
    add_action("do_move", "move");
    add_action("do_move", "sfly");
}

int do_move(string arg)
{
    message_vision("$N�������}���a�A���O�@���䤣��X�f�C\n", this_player());
    return 1;
}

int do_up(string arg)
{
    int x, y;
    object me, area, npc;
    string area_file = "/world/area/four_wheel_tower/fire_2f.c";

    me = this_player();
    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");

    if( me->is_busy() ) return notify_fail("�A�{�b���b���A�@�ɤ����L�k���ʡC\n");

    if( !userp(me) || !this_object()->query_data(x, y, "cord_up") ) return notify_fail("�o�Ӥ�V�S���X���C\n");

    if( !objectp(area = load_object(area_file)) ) return 0;
    if( !area->is_area() ) return 0;
    if( npc = present("_KING_ONE_", environment(me)) ) {
        message_vision("�q���G�Ӫ����Q$N�צ�F�A$n�L�k�q�L�C\n", npc, me);
        return 1;
    }
    message_vision("$N�w�w�a���W�ӥh�C\n", me);
    if( !area_move(area, me, x, y) ) return 0;
    return 1;
}

int do_out(string arg)
{
    int x, y;
    object me, area, npc;
    string area_file = "/world/area/four_wheel_tower/fire_0f.c";

    me = this_player();
    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");

    if( me->is_busy() ) return notify_fail("�A�{�b���b���A�@�ɤ����L�k���ʡC\n");

    if( !userp(me) || !this_object()->query_data(x, y, "door_out") ) return notify_fail("�o�Ӥ�V�S���X���C\n");

    if( !objectp(area = load_object(area_file)) ) return 0;
    if( !area->is_area() ) return 0;
    message_vision("$N���}�j�����F�X�h�C\n", me);
    if( !area_move(area, me, 15, 41) ) return 0;
    return 1;
}

object do_random(string category)
{
    int rnd, *key;
    key = keys(ITEM_D->do_query_all(category));
    rnd = key[random(sizeof(key))];
    return ITEM_D->get_item(category, rnd);
}

void do_ask(string arg, object who, string *inv)
{
    object room;
    int i;

    room = load_object("/world/area/wizard/guildhall.c");

    for(i=0;i<sizeof(inv);i++) {
        if( arg == inv[i] ) who->set_temp("check_robot_ok", 1);
    }
    if( !who->query_temp("check_robot_ok") ) {
        tell_object(who, HIR"\n�A�����F�I�@�D"HIY"�ѹp"HIR"�N�A���^�ѤW�H���I\n\n"NOR);
        if( !who->move(room) ) {
            tell_object(who, "\n�A�F����{...�~�M���ưk�L�ѹp�������I\n\n"NOR);
            return;
        }
        message_vision(HIW"�@�}�ե��L�h�A$N�u�����v�@�n�A��M�q�ѪŤ����F�U�F�A�^�F�Ӫ��Y�ˡC\n"NOR, who);
        who->set_stat_current("ap", 1);
        who->set_stat_current("hp", 1);
        who->set_stat_current("mp", 1);
    } else {
        who->delete_temp("ELF_HOUSE");
        tell_object(who, "\n�C�I���n���ǹL�A������G"HIG"�A�L���F�I\n\n"NOR);
    }
    who->delete_temp("check_robot_ok");
    return;
}

int valid_leave(object me, string dir)
{
    object ob, item;
    int x, y;
    string *inv;

    if( !me ) return 0;

    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");
    ob = this_object();

    // return 0; ��ܲ��ʥ���
    if( userp(me) && ob->query_data(x, y, "check_robot") ) {
        switch( random(4) ) {
            case 0: item = do_random("wp"); break;
            case 1: item = do_random("eq"); break;
            case 2: item = do_random("obj"); break;
            default: item = do_random("food"); break;
        }
        if( !objectp(item) ) {
            tell_object(this_player(), "���O�èS���o�ͥ���ơC\n");
        } else {
            inv = item->parse_command_id_list();
            tell_object(this_player(), RED"���M���_���Q�X�@�D�����I\n"NOR);
            tell_object(this_player(),"�Q�n�~��b�o�̲��ʡA�Х���J "+item->query("name")+" �����~�עҬ���G"NOR);
            input_to("do_ask", this_player(), inv);
        }
        destruct(item);
    }
    return ::valid_leave(me, dir);
}
