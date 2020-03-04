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
    string area_file = "/world/area/lv60_area/fire_isle.c";

    me = this_player();

    if( !arg ) return 0;
    if( arg != "��" && arg != "�ý�" ) return 0;
    if( me->query("area_info/x_axis") != 23 || me->query("area_info/y_axis") != 12 ) return 0;

    if( !objectp(area = load_object(area_file)) ) return 0;
    if( !area->is_area() ) return 0;
    message_vision("$N�y�L�R�F�X�f�������O��֡A�~�w�w���W�ý��C\n", me);
    if( !area_move(area, me, 10, 7) ) return 0;
    message_vision("$N�M�a�@�n�q�������W�ӡC\n", me);
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

    if( !userp(me) && x == 1 && y == 36 && dir == "west" ) return 0;
    return ::valid_leave(me, dir);
}
