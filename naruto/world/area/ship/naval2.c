#include <ansi.h>
inherit AREA;

void create()
{
    set("name", "�j���W");
    set("x_axis_size", 30);            // ��V�j�p
    set("y_axis_size", 40);            // �a�V�j�p
    setup();
}
void init()
{
    object me = this_player();

    add_action("do_jump", "jump");
    // �]��������x�P�� piece...�ҥH�u�n�� class �P�_, �]��G�����Ӥ��|���H�|���a
    if( userp(me) && me->hasCamp("robber") == 0 && (this_player()->query_class() == "work_sea" || this_player()->query_class() == "soldier_sea") ) {
        tell_object(me,HIR"������x�e���̪����ɡA�A�U�ӷU���c����F�C\n"NOR);
        me->setCamp("robber", -34999);
    }
    if( userp(me) && me->hasCamp("police") == 0 && (this_player()->query_class() == "little_sea" || this_player()->query_class() == "thief_sea") ) {
        tell_object(me,HIR"�@�Ӯ���~�M�X�{�b���x��a...��M�ߨ�ް_�F���x���`�N�C\n"NOR);
        me->setCamp("police", -34999);
    }
}
int do_jump(string arg)
{
    object me, area;
    string area_file = "/world/area/benthal/sea5.c";

    me = this_player();

    if( !arg ) return 0;
    if( arg != "��" && arg != "�j��" ) return 0;

    if( me->query("area_info/x_axis") != 8 || me->query("area_info/y_axis") != 20 ) return 0;

    if( !objectp(area = load_object(area_file)) ) return 0;
    if( !area->is_area() ) return 0;
    message_vision("$N�µۺ��O���󪺮������F�U�h�C\n", me);
    if( !area_move(area, me, 22, 7) ) return 0;
    message_vision("$N�����񺡤F�����ƨ�o�̡C\n", me);
    return 1;
}
