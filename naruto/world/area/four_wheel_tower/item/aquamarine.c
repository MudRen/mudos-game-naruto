#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(BBLU+HIG"藍綠玉"NOR, ({ "aquamarine" }));
    if( !clonep() ) {
        set("base_unit", "顆");
        set("unit", "顆");
        set("base_value", 20000);
        set("base_weight", 1);
        set("no_box", 1);
        set("long", "擁有雙色的玉，在陽光下觀看呈現藍色，陰暗中卻變成綠色，非常的\n"
                    "神奇。因為顏色特殊，深受有錢人家的喜愛。\n");
    }
    setup();
}