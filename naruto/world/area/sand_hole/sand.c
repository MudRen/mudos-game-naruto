#include <ansi.h>

inherit AREA;

void create()
{
    set("name", "���~�F��");
    set("x_axis_size", 31);            // ��V�j�p
    set("y_axis_size", 31);            // �a�V�j�p
    setup();
}
int valid_leave(object me, string dir)
{
    int x, y;

    if( !me ) return 0;

    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");

    // return 0; ��ܲ��ʥ���
    if( !userp(me) && x == 21 && y == 1 && dir == "northeast" ) return 0;
    if( !userp(me) && x == 22 && y == 1 && dir == "north" ) return 0;
    if( !userp(me) && x == 23 && y == 1 && dir == "northwest" ) return 0;
    return ::valid_leave(me, dir);
}
void init()
{
    add_action("do_dig", "dig");
    if( userp(this_player()) && this_player()->hasCamp("sand_bandit") == 0 ) {
        tell_object(this_player(),HIR"�o�̪��F�ޱj�s�̦��G�����w��A�C\n"NOR);
        this_player()->setCamp("sand_bandit", -34999);
    }
}
int do_dig(string arg)
{
    object me, area;
    string area_file = "/world/area/sand_hole/hole_1b.c";

    me = this_player();

    if( me->is_busy() ) return notify_fail("�A�{�b���b���A�@�ɤ����L�k���ʡC\n");

    if( me->query("area_info/x_axis") == 4 && me->query("area_info/y_axis") == 4 ||
        me->query("area_info/x_axis") == 14 && me->query("area_info/y_axis") == 3 ||
        me->query("area_info/x_axis") == 25 && me->query("area_info/y_axis") == 10 ||
        me->query("area_info/x_axis") == 14 && me->query("area_info/y_axis") == 13 ||
        me->query("area_info/x_axis") == 0 && me->query("area_info/y_axis") == 13 ||
        me->query("area_info/x_axis") == 5 && me->query("area_info/y_axis") == 18 ||
        me->query("area_info/x_axis") == 16 && me->query("area_info/y_axis") == 21 ||
        me->query("area_info/x_axis") == 27 && me->query("area_info/y_axis") == 26 ) {

        if( !objectp(area = load_object(area_file)) ) return 0;
        if( !area->is_area() ) return 0;
        message_vision("$N�����g������ƨg�������a��...���X�@�Ӥj�|�^�F�i�h...\n", me);
        if( !area_move(area, me, me->query("area_info/x_axis"), me->query("area_info/y_axis")) ) return 0;
        message_vision("$N�q�W���^�F�U�ӡA���y���F�g�C\n", me);
        return 1;
    }
    return notify_fail("�o�̪��F�l���G�S����n�����C\n");
}
