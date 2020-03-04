inherit AREA;

void create()
{
    set("name", "�p��q");
    set("x_axis_size", 49);            // ��V�j�p
    set("y_axis_size", 49);            // �a�V�j�p
    setup();
    set("no_recall", 1);
}
int valid_leave(object me, string dir)
{
    int x, y;

    if( !me ) return 0;

    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");

    // return 0; ��ܲ��ʥ���
    if( !userp(me) && x == 15 && y == 11 && dir == "north" ) return 0;
    return ::valid_leave(me, dir);
}
void init()
{
    add_action("do_jump", "jump");
}
int do_jump(string arg)
{
    object me, area;
    string area_file = "/world/area/benthal/sea8.c";

    me = this_player();

    if( !arg ) return 0;
    if( arg != "��" && arg != "����" && arg != "�L�v�j��") return 0;
    if( me->query("area_info/x_axis") != 24 || me->query("area_info/y_axis") != 3 ) return 0;

    if( !objectp(area = load_object(area_file)) ) return 0;
    if( !area->is_area() ) return 0;
    message_vision("$N�`�`�l�F�@�f��A���ۻ�l���j���@���I\n", me);
    if( !area_move(area, me, 38, 48) ) return 0;
    message_vision("$N�q�����I�F�U�ӡA���ǳ��O��w�C\n", me);

    return 1;
}
