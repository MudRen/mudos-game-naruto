inherit AREA;

void create()
{
    set("name", "����");
    set("x_axis_size", 50);            // ��V�j�p
    set("y_axis_size", 50);            // �a�V�j�p
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

    // return 0; ��ܲ��ʥ���
    if( userp(me) && ob->query_data(x, y, "leg") && dir == "west" 
        || userp(me) && ob->query_data(x, y, "leg") && dir == "southwest" 
        || userp(me) && ob->query_data(x, y, "leg") && dir == "northwest") {

        message_vision("$N���G�Q�|�P���y�v�T�A�C�C���F�i�h...\n", me);
    }
    if( !userp(me) && ob->query_data(x, y, "leg") && dir == "southwest" ) return 0;
    if( !userp(me) && ob->query_data(x, y, "leg") && dir == "west" ) return 0;
    if( !userp(me) && ob->query_data(x, y, "leg") && dir == "northwest" ) return 0;
    return ::valid_leave(me, dir);
}
