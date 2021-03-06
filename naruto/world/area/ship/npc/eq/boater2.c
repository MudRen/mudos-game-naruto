#include <ansi.h>
#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
    set_name(YEL"草帽"NOR, ({ "boater" }) );
    set_weight(1);
    setup_head_eq();
    if( !clonep() ) {
        set("unit", "頂");
        set("value", -1);
        set("no_box", 1);
        set("long", "「四皇」之一的大海賊傑克所帶的草帽，後來轉送給了魯夫。現在草\n"
                    "帽上還縫了張當初在沙漠王國阿拉巴斯坦時「火拳」艾斯所送的紙，\n"
                    "因此這頂草帽已經是魯夫除了伙伴外最重要的東西了。\n");
        set("wear_as", "head_eq");
        set("apply_armor/head_eq", ([
            "attack": 30,
            "combat": 10,
            "armor": 10,
            "intimidate": 5,
            "str": 5,
        ]));
    }
    setup();
}
