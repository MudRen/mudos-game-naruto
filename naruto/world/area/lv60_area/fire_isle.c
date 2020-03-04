#include <ansi.h>

inherit AREA;

void create()
{
    set("name", "���s�C�q");
    set("x_axis_size", 21);            // ��V�j�p
    set("y_axis_size", 11);            // �a�V�j�p
    setup();
}
void init()
{
    add_action("do_jump", "jump");
}
int do_jump(string arg)
{
    object me, area;
    string area_file = "/world/area/benthal/sea12.c";

    me = this_player();

    if( !arg ) return 0;
    if( arg == "��" || arg == "�j��" ) {
        if( !objectp(area = load_object(area_file)) ) return 0;
        if( !area->is_area() ) return 0;
        message_vision("$N�ֳt�a�ĦV���䩹�����@�D�ӤU�C\n", me);
        if( !area_move(area, me, 23, 12) ) return 0;
        message_vision("$N�@�y�n�֪��q�������F�U�ӡC\n", me);
        return 1;
    }
}
