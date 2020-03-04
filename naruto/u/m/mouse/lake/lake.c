inherit AREA;

void create()
{
    set("name", "���Z��");
    set("x_axis_size", 20);            // ��V�j�p
    set("y_axis_size", 20);            // �a�V�j�p
    setup();
}
void init()
{
    add_action("do_enter", "enter");
}
int do_enter(string arg)
{
    object me, area;
    string area_file = __DIR__"relice.c";
    me = this_player();
    if( !arg ) return 0;
    if( arg != "��}" && arg != "���") return 0;
    if( me->query("area_info/x_axis") != 2 || me->query("area_info/y_axis") != 6 ) return 0;
    if( !objectp(area = load_object(area_file)) ) return 0;
    if( !area->is_area() ) return 0;
    message_vision("$N�C�C����V��}���J�f�A�M�᪦�F�i�h�C\n", this_player());
    if( !area_move(area, me, 20, 19) ) return 0;
    message_vision("$N���A�����}�������Pı�A�q�J�f�u�F�U�ӡA�L�ӥ|�}�¤ѡC\n", this_player());
    return 1;
}
int valid_leave(object me, string dir)
{
    int x, y;
    if( !me ) return 0;
    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");
    // return 0; ��ܲ��ʥ���
    if( !userp(me) && x == 13 && y == 18 && dir == "south" ) return 0;
    return ::valid_leave(me, dir);
}

