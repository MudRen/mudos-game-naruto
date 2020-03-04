inherit AREA;

void create()
{
    set("name", "�a�U�F��B-1");
    set("x_axis_size", 31);            // ��V�j�p
    set("y_axis_size", 31);            // �a�V�j�p
    setup();
}
int valid_leave(object me, string dir)
{
    object ob;
    int x, y;

    if( !me ) return 0;

    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");
    ob = this_object();

    if( userp(me) && ob->query_data(x, y, "northeast") && dir == "northeast"
        || userp(me) && ob->query_data(x, y, "northwest") && dir == "northwest"
        || userp(me) && ob->query_data(x, y, "southeast") && dir == "southeast"
        || userp(me) && ob->query_data(x, y, "southwest") && dir == "southwest"
        || userp(me) && ob->query_data(x, y, "north") && dir == "north"
        || userp(me) && ob->query_data(x, y, "south") && dir == "south"
        || userp(me) && ob->query_data(x, y, "west") && dir == "west"
        || userp(me) && ob->query_data(x, y, "east") && dir == "east" ) {

        message_vision("�y�F�N$N�ĤF�^�ӡI\n", me);
        return 0;
    }
    return ::valid_leave(me, dir);
}
void init()
{
    add_action("do_climb", "climb");
    add_action("do_down", "down" );
}
int do_climb(string arg)
{
    object me, area;
    string area_file = "/world/area/sand_hole/sand.c";

    me = this_player();

    if( me->is_busy() ) return notify_fail("�A�{�b���b���A�@�ɤ����L�k���ʡC\n");
    if( !arg ) return 0;
    if( arg != "���" && arg != "��" && arg != "��" ) return 0;
    if( me->query("area_info/x_axis") != 15 || me->query("area_info/y_axis") != 15 ) return 0;

    if( !objectp(area = load_object(area_file)) ) return 0;
    if( !area->is_area() ) return 0;
    message_vision("$N���F��ڡA����ӱ�����L�F�g���F�W�h�C\n", me);
    if( !area_move(area, me, 15, 15) ) return 0;
    return 1;
}
int do_down(string arg)
{
    int x, y;
    object me, area;
    string area_file = "/world/area/sand_hole/hole_2b.c";

    me = this_player();
    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");

    if( me->is_busy() ) return notify_fail("�A�{�b���b���A�@�ɤ����L�k���ʡC\n");

    if( !userp(me) || !this_object()->query_data(x, y, "cord_down") ) return notify_fail("�o�Ӥ�V�S���X���C\n");

    if( !objectp(area = load_object(area_file)) ) return 0;
    if( !area->is_area() ) return 0;
    message_vision("$N�b��W�R�F�f�f���A���÷�Y�ȤF�U�h�C\n", me);
    if( !area_move(area, me, x, y) ) return 0;
    return 1;
}
