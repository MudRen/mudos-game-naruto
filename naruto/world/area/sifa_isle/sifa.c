#include <ansi.h>
inherit AREA;

void create()
{
    set("name", "�q�k�q");
    set("x_axis_size", 90);            // ��V�j�p
    set("y_axis_size", 100);           // �a�V�j�p
    setup();
}
int valid_leave(object me, string dir)
{
    int x, y;

    if( !me ) return 0;

    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");

    // return 0; ��ܲ��ʥ���
    if( !userp(me) && x == 44 && y == 26 && dir == "northeast" ) return 0;
    if( !userp(me) && x == 45 && y == 26 && dir == "north" ) return 0;
    if( !userp(me) && x == 46 && y == 26 && dir == "northwest" ) return 0;
    return ::valid_leave(me, dir);
}
void init()
{
    object me = this_player();

    add_action("do_jump", "jump");
    // �]��������x�P�� piece...�ҥH�u�n�� class �P�_, �]��G�����Ӥ��|���H�|���a
    if( me->hasCamp("robber") == 0 && (this_player()->query_class() == "work_sea" || this_player()->query_class() == "soldier_sea") ) {
        tell_object(me,HIR"������x�e���̪����ɡA�A�U�ӷU���c����F�C\n"NOR);
        me->setCamp("robber", -34999);
    }
    if( me->hasCamp("police") == 0 && (this_player()->query_class() == "little_sea" || this_player()->query_class() == "thief_sea") ) {
        tell_object(me,HIR"�@�Ӯ���~�M�X�{�b���x��a...��M�ߨ�ް_�F���x���`�N�C\n"NOR);
        me->setCamp("police", -34999);
    }
}
int do_jump(string arg)
{
    object me, area;
    string area_file = "/world/area/benthal/sea1.c";

    me = this_player();

    if( !arg ) return 0;
    if( arg != "��" && arg != "����" && arg != "�L�v�j��") return 0;

    if( me->query("area_info/x_axis") != 45 || me->query("area_info/y_axis") != 94 ) return 0;

    if( !objectp(area = load_object(area_file)) ) return 0;
    if( !area->is_area() ) return 0;
    message_vision("$N�`�`�l�F�@�f��A���ۻ�l���j���@���I\n", me);
    if( !area_move(area, me, 25, 0) ) return 0;
    message_vision("$N�q�����I�F�U�ӡA���ǳ��O��w�C\n", me);

    return 1;
}
