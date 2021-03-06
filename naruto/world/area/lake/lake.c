inherit AREA;

void create()
{
    set("name", "天鵝湖底");
    set("x_axis_size", 20);            // 橫向大小
    set("y_axis_size", 20);            // 縱向大小
    setup();
}
void init()
{
    add_action("do_enter", "enter");
}
int do_enter(string arg)
{
    object me, area;
    string area_file = __DIR__"relice.c";
    me = this_player();
    if( !arg ) return 0;
    if( arg != "遺址" && arg != "遺跡") return 0;
    if( me->query("area_info/x_axis") != 2 || me->query("area_info/y_axis") != 6 ) return 0;
    if( !objectp(area = load_object(area_file)) ) return 0;
    if( !area->is_area() ) return 0;
    message_vision("$N慢慢的游向遺址的入口，然後爬了進去。\n", this_player());
    if( !area_move(area, me, 20, 19) ) return 0;
    message_vision("$N不適應離開水中的感覺，從入口滾了下來，摔個四腳朝天。\n", this_player());
    return 1;
}
int valid_leave(object me, string dir)
{
    int x, y;
    if( !me ) return 0;
    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");
    // return 0; 表示移動失敗
    if( !userp(me) && x == 13 && y == 18 && dir == "south" ) return 0;
    return ::valid_leave(me, dir);
}

