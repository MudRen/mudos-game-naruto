#include <ansi.h>
inherit ITEM;

void create()
{
    set_name(YEL"�K�����P"NOR, ({ "golden medal", "_ITS_MY_LIFE_" }));
    set_weight(3);
    if( !clonep() ) {
        set("unit", "��");
        set("value", 1);
        set("no_box", 1);
        set("long", "���W���K�����P�A�u���|���_�C�~������I(��bag�S�@��)\n");
    }
    setup();
}
