#include <ansi.h>

inherit ITEM;

void create()
{
    set_name(YEL"親熱天堂Ⅱ"NOR, ({ "kiss heaven book", "book"}));
    set_weight(1);
    if( !clonep() ) {
        set("unit", "本");
        set("value", 1);
        set("long", "親熱天堂的續集，因為尚未出版，被視為傳說中的讀本。");
    }
    setup();
}
