#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIG"�@����"NOR, ({ "amulet", "_ITS_MY_LIFE_" }));
        set_weight(3);
        if( !clonep() ) {
                set("unit", "�]");
                set("value", 1);
                set("no_box", 1);
                set("long", "���W�p�G����@���ťi�H�O���A�K�󦺤`�C (��bag�S�@��)\n");
        }
        setup();
}
