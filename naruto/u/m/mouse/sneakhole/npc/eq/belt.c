#include <ansi.h>
#include <armor.h>

inherit F_WAIST_EQ;

void create()
{
    set_name(HIB"忍者護腰"NOR, ({ "ninja belt", "belt" }) );
    set_weight(2000);
    setup_waist_eq();
    if( !clonep() ) {
        set("unit", "條");
        set("value", 11950);
        set("long", "忍者使用的腰帶，有許多可以擺藏暗器的小口。\n");
        set("wear_as", "waist_eq");
        set("apply_armor/waist_eq", ([
            "armor": 5,
            "con": 1,
            "wittiness": 5,
            "continual hit": 5,
        ]));
    }
    setup();
}
