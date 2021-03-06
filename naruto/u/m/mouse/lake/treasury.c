inherit AREA;

void create()
{
    set("name", "遺跡寶庫");
    set("x_axis_size", 20);            // 橫向大小
    set("y_axis_size", 20);            // 縱向大小
    setup();
}
int valid_leave(object me, string dir)
{
    int x, y;
    if( !me ) return 0;
    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");
    // return 0; 表示移動失敗
    if( !userp(me) && x == 9 && y == 1 && dir == "north" ) return 0;
    return ::valid_leave(me, dir);
}
