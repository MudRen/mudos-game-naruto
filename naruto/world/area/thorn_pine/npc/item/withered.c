#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(HIR"�\�K"NOR, ({ "withered branch", "branch", "_WITHERED_" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("unit", "��");
        set("base_value", 1);
        set("base_weight", 1);
        set("long", "�ܱ`�����\��K�A�@����G�Sԣ�γ~�C");
    }
    setup();
}
