#include <ansi.h>

inherit AREA;

void create()
{
    set("name", "����_�w");
    set("x_axis_size", 20);            // ��V�j�p
    set("y_axis_size", 20);            // �a�V�j�p
    setup();
}
void init()
{
    object me = this_player();

    // muye���|������h
    if( me->hasCamp("rain") == 0 && this_player()->query("guild") == "muye" ) {
        tell_object(me,HIR"�B�Ԫ̧����Ԫ̵o�{�A�F�I�L�̻P�츭�����Y�@�������O�ܦn...\n"NOR);
        me->setCamp("rain", -50000);
    } else if( me->hasCamp("rain") == 0 ) {
        tell_object(me,HIR"�B���Ԫ̹�A���G���Ӥ͵��C\n"NOR);
        me->setCamp("rain", -10000);
    }
}
int valid_leave(object me, string dir)
{
    int x, y;
    if( !me ) return 0;
    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");
    // return 0; ��ܲ��ʥ���
    if( !userp(me) && x == 9 && y == 1 && dir == "north" ) return 0;
    return ::valid_leave(me, dir);
}
