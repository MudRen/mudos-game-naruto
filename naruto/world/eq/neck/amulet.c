#include <ansi.h>
#include <armor.h>

inherit F_NECK_EQ;

void create()
{
    set_name(RED"平安符"NOR, ({ "amulet" }) );
    set_weight(600);
    setup_neck_eq();

    if( !clonep() ) {
        set("unit", "個");
        set("value", 450);
        set("long", "路邊的小廟隨便求來的平安符，一個破破的紅袋子，裡面裝著一張粉\n"
                    "紅色的紙，上面寫著「保佑出入平安」不過字體歪七扭八，粉紅紙也\n"
                    "也像是隨便拿一張Ａ４紙用手撕一塊般凹凹凸凸，不管怎麼看都覺得\n"
                    "這個平安符一定是黑心貨。\n");
        set("wear_as", "neck_eq");
        set("apply_armor/neck_eq", ([
            "evade": 3,
        ]));
    }
    setup();
}
