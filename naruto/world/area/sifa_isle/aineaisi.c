#include <ansi.h>
inherit AREA;

void create()
{
    set("name", "�㥧�㴵�j�U");
    set("x_axis_size", 30);            // ��V�j�p
    set("y_axis_size", 30);            // �a�V�j�p
    setup();
}
void init()
{
    object me = this_player();

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
int valid_leave(object me, string dir)
{
    int x, y;

    if( !me ) return 0;

    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");

    // return 0; ��ܲ��ʥ���
    if( !userp(me) && x == 14 && y == 28 && dir == "southeast" ) return 0;
    if( !userp(me) && x == 15 && y == 28 && dir == "south" ) return 0;
    if( !userp(me) && x == 16 && y == 28 && dir == "southwest" ) return 0;
    if( !userp(me) && x == 10 && y == 9 && dir == "northeast" ) return 0;
    if( !userp(me) && x == 20 && y == 9 && dir == "northwest" ) return 0;
    return ::valid_leave(me, dir);
}
