inherit AREA;

void create()
{
    set("name", "湖底遺址");
    set("x_axis_size", 40);            // 橫向大小
    set("y_axis_size", 20);            // 縱向大小
    setup();
}
void init()
{
    add_action("do_out", "out");
    add_action("do_push", "push");
}
int do_out(string arg)
{
    object me, area;
    string area_file = __DIR__"lake.c";
    me = this_player();
    if( !arg ) return 0;
    if( arg != "遺址" && arg != "遺跡" && arg != "出入口" ) return 0;
    if( me->query("area_info/x_axis") != 20 || me->query("area_info/y_axis") != 19 ) return 0;
    if( !objectp(area = load_object(area_file)) ) return 0;
    if( !area->is_area() ) return 0;
    message_vision("$N爬到遺跡的出口處，緩緩游了出去。\n", this_player());
    if( !area_move(area, me, 6, 12) ) return 0;
    message_vision("$N迷失了方向，游到這裡才認得過來的路。\n", this_player());
    return 1;
}
int do_push(string arg)
{
    object me, area;
    string area_file = __DIR__"treasury.c";
    me = this_player();
    if( me->query("area_info/x_axis") == 23 && me->query("area_info/y_axis") == 12 ) {
        if( arg == "旁門" || arg == "門" ) {
            if( me->query_temp("quest/bighouse") == 3) {
                message_vision("$N推開了一旁的密門，偷偷的走了進去。\n", this_player());
                me->move(__DIR__"house4.c");
                message_vision("$N從外面偷偷溜了進來。\n", this_player());
                return 1;
                }
            message_vision("$N將門推開，走了進去。\n", this_player());
            me->move(__DIR__"house3.c");
            message_vision("$N從外面走進來。\n", this_player());
            return 1;
            }
        return notify_fail("你想推什麼？\n");
    }
    if( me->query("area_info/x_axis") == 19 && me->query("area_info/y_axis") == 1 ) {
        if( arg == "王座" ) {
            if( me->query_temp("quest/value") == 2) {
                if( !objectp(area = load_object(area_file)) ) return 0;
                if( !area->is_area() ) return 0;
                message_vision("$N將王座往反方向推，傳出磨擦的聲音。\n", this_player());
                message_vision("突然秘道在$N腳下開啟，$N一個不穩直接跌了進去。\n", this_player());
                if( !area_move(area, me, 9, 1) ) return 0;
                message_vision("$N從上面一路滾了進來。\n", this_player());
                return 1;
            }
            if( me->query_temp("quest/opengold") == 3) {
                message_vision("$N緩緩的推開王座，走進下面的地下室去。\n", this_player());
                me->move(__DIR__"wine.c");
                message_vision("$N從上面走下來。\n", this_player());
                return 1;
            }
        message_vision("$N用盡各種方法推動王座，但王座依然毫無動靜。\n", this_player());
        return 1;
        }
    return notify_fail("你想推什麼？\n");
    }
    return 0;
}
