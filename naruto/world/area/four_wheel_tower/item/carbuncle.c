#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(BRED+HIR"����"NOR, ({ "carbuncle" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("unit", "��");
        set("base_value", 20000);
        set("base_weight", 1);
        set("no_box", 1);
        set("long", "�q�馨�����ɡA�o�X����⪺���A�A�O�@�ǬӫǶQ�گS�O���w������\n"
                    "�A����o�X�����~�V�A���A����V���C\n");
    }
    setup();
}