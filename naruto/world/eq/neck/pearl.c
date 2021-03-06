#include <ansi.h>
#include <armor.h>

inherit F_NECK_EQ;

void create()
{
    set_name(HIW"珍珠"NOR"項鍊", ({ "pearl necklace", "necklace" }) );
    set_weight(600);
    setup_neck_eq();

    if( !clonep() ) {
        set("unit", "條");
        set("value", 1500);
        set("long", "用一顆顆的珍珠串起來的項鍊，相當的高雅。\n");
        set("wear_as", "neck_eq");
        set("apply_armor/neck_eq", ([
            "hp": 30,
        ]));
    }

    setup();
}
