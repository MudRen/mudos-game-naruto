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
        tell_object(me,HIR"�������x���A��j�ǰ��~�������...�ߨ�Q���ؼФF�C\n"NOR);
        me->setCamp("robber", -34999);
    }
    if( userp(me) && me->hasCamp("police") == 0 && (this_player()->query_class() == "little_sea" || this_player()->query_class() == "thief_sea") ) {
        tell_object(me,HIR"�������骺�A�A����x�۵M�|�P�칽�c�C\n"NOR);
        me->setCamp("police", -34999);
    } 
}
int do_jump(string arg)
{
    object me, area;
    string area_file = "/world/area/benthal/sea10.c";

    me = this_player();

    if( !arg ) return 0;
    if( arg != "��" && arg != "�j��" ) return 0;

    if( me->query("area_info/x_axis") != 9 || me->query("area_info/y_axis") != 25 ) return 0;

    if( !objectp(area = load_object(area_file)) ) return 0;
    if( !area->is_area() ) return 0;
    message_vision("$N���ݥk�ݡA�ש�U�w�M�߸��J�����C\n", me);
    if( !area_move(area, me, 14, 24) ) return 0;
    message_vision("$N���G�ܤF�X�f�����A���L���I�F�U�ӡC\n", me);
    return 1;
}
