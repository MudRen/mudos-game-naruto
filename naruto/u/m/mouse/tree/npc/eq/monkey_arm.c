#include <ansi.h>
#include <armor.h>
inherit F_WRIST_EQ;

void create()
{
    set_name(YEL"猴臂"NOR, ({ "monkey arm", "arm" }) );
    set_weight(800);
    setup_wrist_eq();
    if( !clonep() ) {
        set("unit", "個");
        set("value", 2000);
        set("long", "巨猴的手臂，將裡面骨頭清除後可當護臂使用。");
        set("wear_as", "wrist_eq");
        set("apply_armor/wrist_eq", ([
            "armor": 4,
        ]));
    }
    setup();
}
