#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(HIK"��G"NOR, ({ "rotten fruit", "fruit" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("unit", "��");
        set("base_value", 1);
        set("base_weight", 1);
        set("long", "�]���\�Ӥ[���걼�����G�A�G�䪺�~�֪����F�ΡC");
    }
    setup();
}
