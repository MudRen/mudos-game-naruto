#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(RED"������"NOR, ({ "chile", "_CHILI_C_" }));
    if( !clonep() ) {
        set("unit", "��");
        set("value", 1000);
        set("base_value", 1000);
        set("base_weight", 50);
        set("long","�δ¤ѴԻs�@�Ӧ���������A�~�l�W�ٶK�F�@�ӡm�����n���r�ˡC\n");
    }
    setup();
}
