#include <ansi.h>
#include <armor.h>

inherit F_CLOTH;

void create()
{
    set_name(MAG"紫晶霓裳"NOR, ({ "Amethyst ni shang", "shang" }) );

    set_weight(200);

    setup_cloth();

    if( !clonep() ) {
        set("unit", "件");
        set("value", 10);
        set("long", "絕世寶衣之一，據有大幅提高使用者靈敏的能力。傳說是仙女下凡洗澡\n"
                    "時衣服被ACME偷走。\n");
        set("wear_as", "cloth");
        set("apply_armor/cloth", ([
            "armor": 20,
            "dex": 5,
            "evade": 15,
            "wittiness": 15,
            "dodge": 12,
        ]));
    }
    setup();
}

