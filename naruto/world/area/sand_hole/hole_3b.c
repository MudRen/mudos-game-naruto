#include <ansi.h>

inherit AREA;

void create()
{
    set("name", "�a�U�F��B-3");
    set("x_axis_size", 31);            // ��V�j�p
    set("y_axis_size", 31);            // �a�V�j�p
    setup();
    set("no_recall", 1);
}
int valid_leave(object me, string dir)
{
    int x, y;

    if( !me ) return 0;

    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");

    if( userp(me) && x == 28 && y == 26 && dir == "west" ) {
        if( query("CUP_GOLDEN_WAR") == 1 && query("CUP_SILVER_WAR") == 1 ) {
            if( WAR_D->doStartWar(me, "/world/war/sun_scorpion.c") ) message_vision(YEL"�|�P���M�@�}�j�P���_�ʡI�O�a�_�I\n"NOR, this_object());
            else message_vision(CYN"$Nı�o��W���F�g�n�������F�@�ǡC\n"NOR, this_object());
            delete("CUP_GOLDEN_WAR");
            delete("CUP_SILVER_WAR");
        }
    }
    return ::valid_leave(me, dir);
}
void init()
{
    add_action("do_up", "up");
    add_action("do_push", "push");
}
int do_up(string arg)
{
    int x, y;
    object me, area;
    string area_file = "/world/area/sand_hole/hole_2b.c";

    me = this_player();
    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");

    if( me->is_busy() ) return notify_fail("�A�{�b���b���A�@�ɤ����L�k���ʡC\n");

    if( !userp(me) || !this_object()->query_data(x, y, "cord_up") ) return notify_fail("�o�Ӥ�V�S���X���C\n");

    if( !objectp(area = load_object(area_file)) ) return 0;
    if( !area->is_area() ) return 0;
    message_vision("$N�b�F�b���A��}�åΩ��W���h�C\n", me);
    if( !area_move(area, me, x, y) ) return 0;
    return 1;
}
int do_push(string arg)
{
    int x, y;
    object me;

    me = this_player();
    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");

    if( me->is_busy() ) return notify_fail("�A�{�b���b���A�@�ɤ����L�k���ʡC\n");
    if( !arg ) return 0;
    if( arg == "���M" || arg == "�M" && (x == 11 && y == 25) ) {
        if( query("CUP_GOLDEN_WAR") == 1 ) return notify_fail("���O�����w�g���U�h�F�C\n");
        message_vision("$N����M�U�誺�}�����F�U�h�A�����D���Ӫ��u���N���M�˺����F�C\n", me);
        this_object()->set("CUP_GOLDEN_WAR", 1);
        return 1;
    } else if( arg == "�ȪM" || arg == "�M" && (x == 2 && y == 20) ) {
        if( query("CUP_SILVER_WAR") == 1 ) return notify_fail("���O�����w�g���U�h�F�C\n");
        message_vision("$N��ȪM�U�誺�}�����F�U�h�A�����D���Ӫ��u���N�ȪM�˺����F�C\n", me);
        this_object()->set("CUP_SILVER_WAR", 1);
        return 1;
    }
    return 0;
}
