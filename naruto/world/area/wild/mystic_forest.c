// write by -Acme-

inherit AREA;

void create()
{
    set("name", "������");
    set("x_axis_size", 40);            // ��V�j�p
    set("y_axis_size", 25);            // �a�V�j�p
    setup();
}
void init()
{
    add_action("do_enter", "enter");
}

int do_enter(string arg)
{
    object me, area;
    string area_file = "/world/area/wild/hole.c";
    me = this_player();

    if( !arg ) return 0;
    if( arg != "����" && arg != "�}��") return 0;

    if( me->query("area_info/x_axis") != 1 || me->query("area_info/y_axis") != 6 ) return 0;

    if( !objectp(area = load_object(area_file)) ) return 0;
    if( !area->is_area() ) return 0;
    if( !area_move(area, me, 6, 9) ) return 0;

    return 1;
}
