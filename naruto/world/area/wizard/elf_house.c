inherit AREA;

void create()
{
    set("name", "���F����");
    set("x_axis_size", 31);            // ��V�j�p
    set("y_axis_size", 31);            // �a�V�j�p
    setup();
    set("no_recall", 1);
}
void init()
{
    add_action("do_quit", "quit");
    add_action("do_fly", "sfly");
    add_action("do_fly", "move");
}
int do_quit(string arg)
{
    tell_object(this_player(),"\n�]�����_���O�q�A�A�����u�欰�ȳQ���m���~�C\n\n");
    this_player()->move(__DIR__"elf_door.c");
    this_player()->start_busy(1);
    return 1;
}
int do_fly(string arg)
{
    tell_object(this_player(),"�o�̥R���_�S���෽�A�ϧA������D�㥢�F�F�C\n");
    return 1;
}
int valid_leave(object me, string dir)
{
    int x, y;

    if( !me ) return 0;

    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");

    // return 0; ��ܲ��ʥ���
    if( !userp(me) && x == 15 && y == 17 && dir == "north" ) return 0;
    if( !userp(me) && x == 14 && y == 17 && dir == "northeast" ) return 0;
    if( !userp(me) && x == 16 && y == 17 && dir == "northwest" ) return 0;
    if( userp(me) && x == 15 && y == 17 && dir == "north" ) me->delete_temp("ELF_HOUSE");
    return ::valid_leave(me, dir);
}
