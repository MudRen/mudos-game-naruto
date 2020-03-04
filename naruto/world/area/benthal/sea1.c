inherit AREA;

void create()
{
    set("name", "����");
    set("x_axis_size", 50);            // ��V�j�p
    set("y_axis_size", 50);            // �a�V�j�p
    setup();
}
void init()
{
    add_action("do_climb", "climb");
}
int do_climb(string arg)
{
    object me, area;
    string area_file = "/world/area/sifa_isle/sifa.c";

    me = this_player();

    if( !arg ) return 0;
    if( arg != "����" && arg != "��" && arg != "����") return 0;

    if( me->query("area_info/x_axis") != 25 || me->query("area_info/y_axis") != 0 ) return 0;

    if( !objectp(area = load_object(area_file)) ) return 0;
    if( !area->is_area() ) return 0;
    message_vision("$N�����B������ۥ|�P�������F�W�h�C\n", me);
    if( !area_move(area, me, 45, 94) ) return 0;
    message_vision("$N�ֳt�a�q���̪��W���ӡC\n", me);

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

    if( !userp(me) && x == 48 && y == 23 && dir == "southeast" ) return 0;
    if( !userp(me) && x == 48 && y == 24 && dir == "east" ) return 0;
    if( !userp(me) && x == 48 && y == 25 && dir == "northeast" ) return 0;
    return ::valid_leave(me, dir);
}
