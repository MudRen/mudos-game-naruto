#include <ansi.h>
#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
    set_name(HIK"西瓜皮"NOR, ({ "watermelon hat", "hat" }) );

    set_weight(3300);

    setup_head_eq();

    if( !clonep() ) {
        set("unit", "頂");
        set("value", 3700);
        set("long", "一頂西瓜皮，塗成黑色的拿來當假髮用，裡頭還有著夾子，讓你遇到強風也吹不掉。");
        set("wear_as", "head_eq");
        set("apply_armor/head_eq", ([
            "armor": 6,
            "dex": 1,
        ]));
    }

    setup();
}

