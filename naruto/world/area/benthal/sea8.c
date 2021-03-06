inherit AREA;

void create()
{
    set("name", "海底");
    set("x_axis_size", 50);            // 橫向大小
    set("y_axis_size", 50);            // 縱向大小
    setup();
}
void init()
{
    add_action("do_push", "push");
}
int do_push(string arg)
{
    object me, area;
    string area_file = "/world/area/barren_isle/barren.c";

    me = this_player();

    if( !arg ) return 0;
    if( arg != "岩" && arg != "白岩" && arg != "巨大岩石") return 0;
    if( me->query("area_info/x_axis") != 38 || me->query("area_info/y_axis") != 49 ) return 0;

    if( !objectp(area = load_object(area_file)) ) return 0;
    if( !area->is_area() ) return 0;
    message_vision("$N輕輕一推白岩，發現裡面居然是空的，整個人滾了進去...\n", me);
    if( !area_move(area, me, 24, 3) ) return 0;
    message_vision("$N從石縫中滾了出來。\n", me);

    return 1;
}
