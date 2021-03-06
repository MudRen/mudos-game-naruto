// write by -Acme-

inherit AREA;

void create()
{
    set("name", "祕之森");
    set("x_axis_size", 40);            // 橫向大小
    set("y_axis_size", 25);            // 縱向大小
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
    if( arg != "秘穴" && arg != "洞穴") return 0;

    if( me->query("area_info/x_axis") != 1 || me->query("area_info/y_axis") != 6 ) return 0;

    if( !objectp(area = load_object(area_file)) ) return 0;
    if( !area->is_area() ) return 0;
    if( !area_move(area, me, 6, 9) ) return 0;

    return 1;
}
