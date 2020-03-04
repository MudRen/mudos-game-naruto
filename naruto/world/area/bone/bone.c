#include <ansi.h>

inherit AREA;

void create()
{
    set("name", "�e���Գ�");
    set("x_axis_size", 41);            // ��V�j�p
    set("y_axis_size", 41);            // �a�V�j�p
    setup();
    set("no_recall", 1);
}
void init()
{
    object me = this_player();

    // muye���|������h
    if( me->hasCamp("music") == 0 && this_player()->query("guild") == "muye" ) {
        tell_object(me,HIR"�o�̬O��츭�ķN�D�`�`�������Ԫ̻�a...\n"NOR);
        me->setCamp("music", -60000);
    } else if( me->hasCamp("music") == 0 ) {
        tell_object(me,HIR"�����Ԫ̹��A���G�R���F�Ĺ�ߺA�C\n"NOR);
        me->setCamp("music", -35000);
    }
}
int valid_leave(object me, string dir)
{
    int x, y;

    if( !me ) return 0;

    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");

    // return 0; ��ܲ��ʥ���
    if( !userp(me) && x == 5 && y == 39 && dir == "southeast" ) return 0;
    if( !userp(me) && x == 6 && y == 39 && dir == "south" ) return 0;
    if( !userp(me) && x == 7 && y == 39 && dir == "southwest" ) return 0;
    if( !userp(me) && x == 5 && y == 40 && dir == "east" ) return 0;
    if( !userp(me) && x == 7 && y == 40 && dir == "west" ) return 0;
    if( !userp(me) && x == 1 && y == 6 && dir == "west" ) return 0;
    if( !userp(me) && x == 1 && y == 5 && dir == "southwest" ) return 0;
    if( !userp(me) && x == 1 && y == 7 && dir == "northwest" ) return 0;
    return ::valid_leave(me, dir);
}
