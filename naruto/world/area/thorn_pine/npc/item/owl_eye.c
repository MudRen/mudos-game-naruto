#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(HIR"������"NOR, ({ "owl eyes", "eyes", "_OWL_EYE_" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("base_value", 50000);
        set("base_weight", 600);
        set("long", "�a�����������A�إ��U�Q�A�Q���îa�ҳ߷R�C\n");
    }
    setup();
}
