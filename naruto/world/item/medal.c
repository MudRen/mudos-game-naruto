#include <ansi.h>
inherit ITEM;

void create()
{
    set_name(YEL"免死金牌"NOR, ({ "golden medal", "_ITS_MY_LIFE_" }));
    set_weight(3);
    if( !clonep() ) {
        set("unit", "塊");
        set("value", 1);
        set("no_box", 1);
        set("long", "身上有免死金牌，只有尚方寶劍才能殺死！(放bag沒作用)\n");
    }
    setup();
}
