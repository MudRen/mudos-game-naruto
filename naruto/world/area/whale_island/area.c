inherit AREA;

void create()
{
    set("name", "�H���q");
    set("x_axis_size", 49);            // ��V�j�p
    set("y_axis_size", 49);            // �a�V�j�p
    setup();
}
void init()
{
    add_action("do_jump", "jump");
}
int do_jump(string arg)
{
    string area_file = "/world/area/benthal/sea9.c";
    object me, area;
    int x, y;

    me = this_player();
    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");

    if( !arg ) return 0;
    if( arg != "��" && arg != "����" && arg != "�X�Y" ) return 0;

    if( x == 22 && y == 45 || x == 22 && y == 46 || x == 22 && y == 47 ) {
        if( !objectp(area = load_object(area_file)) ) return 0;
        if( !area->is_area() ) return 0;
        message_vision("$N�ݤF�ݮ����A�`�l�@�f����F�U�h�C\n", me);
        if( !area_move(area, me, 21, 1) ) return 0;
        message_vision("$N�q�����W�I�F�U�ӡC\n", me);
        return 1;
    }
    return 0;
}
