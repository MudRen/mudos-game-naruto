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
    add_action("do_push", "push");
}
int do_push(string arg)
{
    object me, area;
    string area_file = "/world/area/barren_isle/barren.c";

    me = this_player();

    if( !arg ) return 0;
    if( arg != "��" && arg != "�թ�" && arg != "���j����") return 0;
    if( me->query("area_info/x_axis") != 38 || me->query("area_info/y_axis") != 49 ) return 0;

    if( !objectp(area = load_object(area_file)) ) return 0;
    if( !area->is_area() ) return 0;
    message_vision("$N�����@���թ��A�o�{�̭��~�M�O�Ū��A��ӤH�u�F�i�h...\n", me);
    if( !area_move(area, me, 24, 3) ) return 0;
    message_vision("$N�q���_���u�F�X�ӡC\n", me);

    return 1;
}
