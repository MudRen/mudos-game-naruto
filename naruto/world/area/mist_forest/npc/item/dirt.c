#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(BYEL"�o�g"NOR, ({ "dirt" }));
    if( !clonep() ) {
        set("base_unit", "�b");
        set("unit", "�b");
        set("base_value", 1);
        set("base_weight", 1);
        set("long", "�o�X���߯�����g�[�A�����D�O���Ӫ��C");
    }
    setup();
}