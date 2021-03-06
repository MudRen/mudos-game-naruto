// write by -Acme-

inherit AREA;

void create()
{
    set("name", "天鵝湖");
    set("x_axis_size", 35);            // 橫向大小
    set("y_axis_size", 30);            // 縱向大小
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
    if( arg != "湖" && arg != "天鵝湖") return 0;

    if( me->query("area_info/x_axis") != 21 || me->query("area_info/y_axis") != 25 ) return 0;

    if( !objectp(area = load_object(area_file)) ) return 0;
    if( !area->is_area() ) return 0;
    if( !area_move(area, me, 13, 18) ) return 0;

    return 1;
}
