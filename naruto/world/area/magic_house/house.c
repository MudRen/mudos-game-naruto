inherit AREA;

void create()
{
    set("name", "�]�N������");
    set("x_axis_size", 41);            // ��V�j�p
    set("y_axis_size", 30);            // �a�V�j�p
    setup();
    set("no_recall", 1);
}
void init()
{
    add_action("do_move", "move");
    add_action("do_move", "sfly");
}
int do_move(string arg)
{
    message_vision("$N���ϭ��W�ѪšA���O����г��S�^�F�U�ӡC\n", this_player());
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
    if( userp(me) && x == 20 && y == 28 && dir == "south" ) {
        message_vision("$N�@�����f�N�Pı�|�P�����ܪ��U�k...\n", me);
        me->delete_temp("gomagic");
    }
    if( !userp(me) && ob->query_data(x, y, "northeast") && dir == "northeast"
        || !userp(me) && ob->query_data(x, y, "northwest") && dir == "northwest"
        || !userp(me) && ob->query_data(x, y, "southeast") && dir == "southeast"
        || !userp(me) && ob->query_data(x, y, "southwest") && dir == "southwest"
        || !userp(me) && ob->query_data(x, y, "north") && dir == "north"
        || !userp(me) && ob->query_data(x, y, "south") && dir == "south"
        || !userp(me) && ob->query_data(x, y, "west") && dir == "west"
        || !userp(me) && ob->query_data(x, y, "east") && dir == "east" ) {

        return 0;
    }
    return ::valid_leave(me, dir);
}
