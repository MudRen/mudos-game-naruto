// write by -Acme-

inherit AREA;

void create()
{
    set("name", "���`�˪L");
    set("x_axis_size", 49);            // ��V�j�p
    set("y_axis_size", 49);            // �a�V�j�p
    set("no_recall", 1);               //����ϥ�recall���O
    setup();
}
void init()
{
    add_action("do_pass", "pass");
}
int do_pass(string arg)
{
    object me, area;
    string area_file = "/world/area/lv60_area/deadsite.c";

    me = this_player();

    if( !arg ) return 0;
    if( arg != "�K�L" ) return 0;
    if( me->query("area_info/x_axis") != 46 || me->query("area_info/y_axis") != 48 ) return 0;

    if( !objectp(area = load_object(area_file)) ) return 0;
    if( !area->is_area() ) return 0;
    message_vision("$N�V�O�a�N�������i�Ŷ����j����L���C\n", me);
    if( !area_move(area, me, 24, 1) ) return 0;
    message_vision("$N�n���e���~���F�i�ӡC\n", me);
    return 1;
}
int valid_leave(object me, string dir)
{
    int x, y;

    if( !me ) return 0;

    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");

    if( !userp(me) && x == 5 && y == 3 && dir == "north" ) return 0;

    if( userp(me) && x == 5 && y == 2 && dir == "south" && !me->query_temp("middle_test") ) {
        tell_object(me, "�u���ѥ[���ԦҸժ��H�~�i�H�i�h�C\n");
        return 0;
    }

    return ::valid_leave(me, dir);
}
