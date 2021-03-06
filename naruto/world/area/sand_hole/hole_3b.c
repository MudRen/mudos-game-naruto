#include <ansi.h>

inherit AREA;

void create()
{
    set("name", "地下沙穴B-3");
    set("x_axis_size", 31);            // 橫向大小
    set("y_axis_size", 31);            // 縱向大小
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
            if( WAR_D->doStartWar(me, "/world/war/sun_scorpion.c") ) message_vision(YEL"四周忽然一陣強烈的震動！是地震！\n"NOR, this_object());
            else message_vision(CYN"$N覺得牆上的沙土好像掉落了一些。\n"NOR, this_object());
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

    if( me->is_busy() ) return notify_fail("你現在正在忙，一時之間無法移動。\n");

    if( !userp(me) || !this_object()->query_data(x, y, "cord_up") ) return notify_fail("這個方向沒有出路。\n");

    if( !objectp(area = load_object(area_file)) ) return 0;
    if( !area->is_area() ) return 0;
    message_vision("$N搓了搓兩手，手腳並用往上爬去。\n", me);
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

    if( me->is_busy() ) return notify_fail("你現在正在忙，一時之間無法移動。\n");
    if( !arg ) return 0;
    if( arg == "金杯" || arg == "杯" && (x == 11 && y == 25) ) {
        if( query("CUP_GOLDEN_WAR") == 1 ) return notify_fail("但是機關已經按下去了。\n");
        message_vision("$N把金杯下方的開關按了下去，不知道哪來的泉水將金杯裝滿水了。\n", me);
        this_object()->set("CUP_GOLDEN_WAR", 1);
        return 1;
    } else if( arg == "銀杯" || arg == "杯" && (x == 2 && y == 20) ) {
        if( query("CUP_SILVER_WAR") == 1 ) return notify_fail("但是機關已經按下去了。\n");
        message_vision("$N把銀杯下方的開關按了下去，不知道哪來的泉水將銀杯裝滿水了。\n", me);
        this_object()->set("CUP_SILVER_WAR", 1);
        return 1;
    }
    return 0;
}
