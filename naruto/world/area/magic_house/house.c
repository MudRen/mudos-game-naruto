inherit AREA;

void create()
{
    set("name", "魔術馬戲團");
    set("x_axis_size", 41);            // 橫向大小
    set("y_axis_size", 30);            // 縱向大小
    setup();
    set("no_recall", 1);
}
void init()
{
    add_action("do_move", "move");
    add_action("do_move", "sfly");
}
int do_move(string arg)
{
    message_vision("$N企圖飛上天空，但是撞到房頂又跌了下來。\n", this_player());
    return 1;
}

int valid_leave(object me, string dir)
{
    object ob;
    int x, y;

    if( !me ) return 0;

    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");
    ob = this_object();

    // return 0; 表示移動失敗
    if( userp(me) && x == 20 && y == 28 && dir == "south" ) {
        message_vision("$N一踏到門口就感覺四周景色變的糢糊...\n", me);
        me->delete_temp("gomagic");
    }
    if( !userp(me) && ob->query_data(x, y, "northeast") && dir == "northeast"
        || !userp(me) && ob->query_data(x, y, "northwest") && dir == "northwest"
        || !userp(me) && ob->query_data(x, y, "southeast") && dir == "southeast"
        || !userp(me) && ob->query_data(x, y, "southwest") && dir == "southwest"
        || !userp(me) && ob->query_data(x, y, "north") && dir == "north"
        || !userp(me) && ob->query_data(x, y, "south") && dir == "south"
        || !userp(me) && ob->query_data(x, y, "west") && dir == "west"
        || !userp(me) && ob->query_data(x, y, "east") && dir == "east" ) {

        return 0;
    }
    return ::valid_leave(me, dir);
}
