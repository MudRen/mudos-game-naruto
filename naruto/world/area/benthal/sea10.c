inherit AREA;

void create()
{
    set("name", "����");
    set("x_axis_size", 50);            // ��V�j�p
    set("y_axis_size", 50);            // �a�V�j�p
    setup();
}
void init()
{
    add_action("do_climb", "climb");
}
int do_climb(string arg)
{
    object me, area;
    string area_file = "/world/area/ship/sunmoon.c";

    me = this_player();

    if( !arg ) return 0;
    if( arg != "��" ) return 0;

    if( me->query("area_info/x_axis") != 14 || me->query("area_info/y_axis") != 24 ) return 0;

    if( !objectp(area = load_object(area_file)) ) return 0;
    if( !area->is_area() ) return 0;
    message_vision("$N��ǤF�㪺�w�B�A�ֳt�a���F�W�h�C\n", me);
    if( !area_move(area, me, 9, 25) ) return 0;
    message_vision("$N�q�������F�W�ӡA�@�y�T�V�C\n", me);
    return 1;
}
