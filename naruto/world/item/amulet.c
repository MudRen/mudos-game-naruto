#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIG"護身符"NOR, ({ "amulet", "_ITS_MY_LIFE_" }));
        set_weight(3);
        if( !clonep() ) {
                set("unit", "包");
                set("value", 1);
                set("no_box", 1);
                set("long", "身上如果放個護身符可以保佑你免於死亡。 (放bag沒作用)\n");
        }
        setup();
}
