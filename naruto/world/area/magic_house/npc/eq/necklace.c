#include <ansi.h>
#include <armor.h>

inherit F_NECK_EQ;

void create()
{
    set_name(YEL"魔術"NOR"項圈", ({ "magic collar", "collar" }) );
    set_weight(600);
    setup_neck_eq();

    if( !clonep() ) {
        set("unit", "串");
        set("value", 5200);
        set("long", "一串魔術刻紋項圈，能讓兇猛的野獸都變的更兇猛。\n");
        set("wear_as", "neck_eq");
        set("apply_armor/neck_eq", ([
            "str": 4,
        ]));
    }
    setup();
}
