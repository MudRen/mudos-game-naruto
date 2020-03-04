#include <ansi.h>
#include <armor.h>

inherit F_CLOTH;

void create()
{
        set_name(HIK"灰色外套"NOR, ({ "gray jacket","jacket" }) );
        set_weight(3000);
        setup_cloth();

        if( !clonep() ) {
                set("unit", "件");
        set("value", 10);
                set("long", "一件深灰色的外套，特有的動物所做的毛皮編製物。\n");
                set("wear_as", "cloth");
                set("apply_armor/cloth", ([
                        "armor": 3,
                ]));
        }

        setup();
}

