#include <ansi.h>
inherit AREA;

void create()
{
    set("name", "�j���W");
    set("x_axis_size", 48);            // ��V�j�p
    set("y_axis_size", 48);            // �a�V�j�p
    setup();
}
void init()
{
    object me = this_player();

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
