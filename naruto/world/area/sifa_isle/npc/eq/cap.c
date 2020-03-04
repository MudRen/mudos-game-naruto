#include <ansi.h>
#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
    set_name(HIC"海軍帽"NOR, ({ "service cap", "cap" }) );

    set_weight(1500);

    setup_head_eq();

    if( !clonep() ) {
        set("unit", "頂");
        set("value", 19200);
        set("long", "繡著「ＭＡＲＩＮＥ」字樣的海軍帽子。");
        set("wear_as", "head_eq");
        set("apply_armor/head_eq", ([
            "armor": 10,
            "evade": 6,
        ]));
    }
    setup();
}
