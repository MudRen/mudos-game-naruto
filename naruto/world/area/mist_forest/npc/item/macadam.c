#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name("�H��", ({ "macadam" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("unit", "��");
        set("base_value", 1);
        set("base_weight", 1);
        set("long", "�p�H�ۤl�A�ݰ_�ӨS����S�O���C");
    }
    setup();
}