#include <ansi.h>
#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
    set_name("果凍帽", ({ "jelly hat", "hat" }) );
    set_weight(400);
    setup_head_eq();

    if( !clonep() ) {
        set("unit", "頂");
        set("value", 400);
        set("long", "帶在頭上軟軟ＱＱ的，只是有點臭。");
        set("wear_as", "head_eq");
        set("apply_armor/head_eq", ([
            "armor": 4,
        ]));
    }
    setup();
}
