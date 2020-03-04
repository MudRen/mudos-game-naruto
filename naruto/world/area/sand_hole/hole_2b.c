inherit AREA;

void create()
{
    set("name", "�a�U�F��B-2");
    set("x_axis_size", 31);            // ��V�j�p
    set("y_axis_size", 31);            // �a�V�j�p
    setup();
}
void init()
{
    add_action("do_down", "down");
    add_action("do_up", "up");
}
int do_down(string arg)
{
    int x, y;
    object me, area;
    string area_file = "/world/area/sand_hole/hole_3b.c";

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
int do_up(string arg)
{
    int x, y;
    object me, area;
    string area_file = "/world/area/sand_hole/hole_1b.c";

    me = this_player();
    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");

    if( me->is_busy() ) return notify_fail("�A�{�b���b���A�@�ɤ����L�k���ʡC\n");

    if( !userp(me) || !this_object()->query_data(x, y, "cord_up") ) return notify_fail("�o�Ӥ�V�S���X���C\n");

    if( !objectp(area = load_object(area_file)) ) return 0;
    if( !area->is_area() ) return 0;
    message_vision("$N�b�F�b���A��}�åΩ��W���h�C\n", me);
    if( !area_move(area, me, x, y) ) return 0;
    return 1;
}
