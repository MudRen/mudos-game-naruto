#include <ansi.h>
#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
    set_name(YEL"銅頭盔"NOR, ({ "copper helmet", "helmet" }) );

    set_weight(3000);

    setup_head_eq();

    if( !clonep() ) {
        set("unit", "頂");
        set("value", 4000);
        set("long", "一頂相當耐用的頭盔，怎麼摔也摔不壞。");
        set("wear_as", "head_eq");
        set("apply_armor/head_eq", ([
            "armor": 8,
        ]));
    }

    setup();
}
