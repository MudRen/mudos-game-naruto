// write by -Acme-

inherit AREA;

void create()
{
    set("name", "���Z��");
    set("x_axis_size", 35);            // ��V�j�p
    set("y_axis_size", 30);            // �a�V�j�p
    setup();
}

void init()
{
    add_action("do_jump", "jump");
}

int do_jump(string arg)
{
    object me, area;
    string area_file = "/world/area/lake/lake.c";

    me = this_player();

    if( !arg ) return 0;
    if( arg != "��" && arg != "���Z��") return 0;

    if( me->query("area_info/x_axis") != 21 || me->query("area_info/y_axis") != 25 ) return 0;

    if( !objectp(area = load_object(area_file)) ) return 0;
    if( !area->is_area() ) return 0;
    if( !area_move(area, me, 13, 18) ) return 0;

    return 1;
}
