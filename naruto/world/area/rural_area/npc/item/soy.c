#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(HIK"��o"NOR, ({ "soy", "_PILL_SOY_" }));
    if( !clonep() ) {
        set("unit", "�~");
        set("value", 500);
        set("base_value", 500);
        set("base_weight", 20);
        set("long","�W���g�ۡmž�ҸU�n�̯���o�A�n�������̤��ӹ�H\n");
    }
    setup();
}
