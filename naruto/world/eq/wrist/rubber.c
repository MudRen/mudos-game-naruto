#include <ansi.h>
#include <armor.h>

inherit F_WRIST_EQ;

void create()
{
    set_name(YEL"橡皮筋"NOR, ({ "rubber band", "band" }) );
    set_weight(100);
    setup_wrist_eq();

    if( !clonep() ) {
        set("unit", "條");
        set("value", 3900);
        set("long", "一條相當粗的橡皮筋，戴在手腕上太久手掌會壞死。\n");
        set("wear_as", "wrist_eq");
        set("apply_armor/wrist_eq", ([
            "str": 3,
        ]));
    }

    setup();
}
