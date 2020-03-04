#include <ansi.h>
#include <armor.h>
inherit F_HAND_EQ;

void create()
{
        set_name(HIY"金屬手套"NOR, ({ "metal gloves","gloves" }) );
        set_weight(3000);
        setup_hand_eq();

        if( !clonep() ) {
                set("unit", "雙");
                set("value", 100);
                set("long",
                        "一雙秘銀所做的手套，沒有任何的空隙，特別的地方是比一般的皮草編織的還要來的輕。\n");
                set("wear_as", "hand_eq");
                set("apply_armor/hand_eq", ([
                        "armor" :5,
                ]));
        }

        setup();
}
