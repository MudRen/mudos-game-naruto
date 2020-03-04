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
    string area_file = "/world/area/whale_island/area.c";
    object me, area;
    int x, y;

    me = this_player();
    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");

    if( !arg ) return 0;
    if( arg != "����" ) return 0;

    if( x == 19 && y == 0 || x == 20 && y == 0 ||
        x == 21 && y == 0 || x == 22 && y == 0 ) {

        if( !objectp(area = load_object(area_file)) ) return 0;
        if( !area->is_area() ) return 0;
        message_vision("$N�ΤO����u�A�⳨���H��U����ۤv���F�W�h�C\n", me);
        if( !area_move(area, me, 22, 45+random(3)) ) return 0;
        message_vision("$N�q���̪��F�W�ӡC\n", me);
        return 1;
    }
    return 0;
}
int valid_leave(object me, string dir)
{
    string area_file = "/world/area/benthal/sea5.c";
    object ob, area;
    int x, y;

    if( !me ) return 0;

    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");
    ob = this_object();

    if( x == 2 && y == 47 && dir == "south" || 
        x == 2 && y == 47 && dir == "southwest" ) {

        if( !objectp(area = load_object(area_file)) ) return 0;
        if( !area->is_area() ) return 0;
        if( !userp(me) ) return 0;
        message_vision("���y��M�N$N���F�i�h�I�s�N�Ӥ]�Q�Ԩ��F...\n", me);
        if( !area_move(area, me, 43+random(7), 8+random(7)) ) return 0;
        message_vision("$N�Q���y�Ĩ�o�̤~���L�ӡA����������C\n", me);
        return 1;
    }
    return ::valid_leave(me, dir);
}
