
#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(HIY"��l"NOR, ({ "shovel"}));
    set_weight(3);
    if( !clonep() ) {
        set("unit", "��");
        set("value", 10000);
        set("long", "�@��ݰ_�ӫܵw����l�A�����D����@��...\n");
    }
    setup();
}
