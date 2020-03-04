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
    add_action("do_swim", "swim");
}
int do_climb(string arg)
{
    object me, area;
    string area_file = "/world/area/ship/naval2.c";

    me = this_player();

    if( !arg ) return 0;
    if( arg != "��" ) return 0;

    if( me->query("area_info/x_axis") != 22 || me->query("area_info/y_axis") != 7 ) return 0;

    if( !objectp(area = load_object(area_file)) ) return 0;
    if( !area->is_area() ) return 0;
    message_vision("$N����㪺�K��A��}�åΪ��F�W�h�C\n", me);
    if( !area_move(area, me, 8, 20) ) return 0;
    message_vision("$N�q���̪��F�W�ӡC\n", me);
    return 1;
}
int do_swim(string arg)
{
    object me, area;
    string area_file = "/world/area/benthal/sea9.c";

    me = this_player();

    if( !arg ) return 0;
    if( arg != "����s" ) return 0;

    if( me->query("area_info/x_axis") != 49 || me->query("area_info/y_axis") != 3 ) return 0;

    if( !objectp(area = load_object(area_file)) ) return 0;
    if( !area->is_area() ) return 0;
    message_vision("$N���������A�w�w���®��y���W���F�W�h�C\n", me);
    if( !area_move(area, me, 2, 46) ) return 0;
    message_vision("$N���W��L�F�j�j�����y�C\n", me);
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

    // return 0; ��ܲ��ʥ���
    if( userp(me) && ob->query_data(x, y, "northeast") && dir == "northeast"
        || userp(me) && ob->query_data(x, y, "northwest") && dir == "northwest"
        || userp(me) && ob->query_data(x, y, "southeast") && dir == "southeast"
        || userp(me) && ob->query_data(x, y, "southwest") && dir == "southwest"
        || userp(me) && ob->query_data(x, y, "north") && dir == "north"
        || userp(me) && ob->query_data(x, y, "south") && dir == "south"
        || userp(me) && ob->query_data(x, y, "west") && dir == "west"
        || userp(me) && ob->query_data(x, y, "east") && dir == "east" ) {

        message_vision("�j�j�����y�N$N�ĤF�^�ӡI\n", me);
        return 0;
    }
    if( !userp(me) && x == 1 && y == 27 && dir == "west" ) return 0;
    if( !userp(me) && x == 2 && y == 48 && dir == "southeast" ) return 0;
    if( !userp(me) && x == 3 && y == 48 && dir == "south" ) return 0;
    if( !userp(me) && x == 4 && y == 48 && dir == "southwest" ) return 0;
    return ::valid_leave(me, dir);
}
