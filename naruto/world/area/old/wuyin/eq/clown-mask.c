#include <ansi.h>
#include <armor.h>
inherit F_FACE_EQ;

void create()
{
        set_name(HIM"小丑面具"NOR, ({ "clown mask","mask" }) );
        set_weight(3000);
        setup_face_eq();

        if( !clonep() ) {
                set("unit", "張");
                set("value", 100);
                set("long",
                        "面具是小丑的臉，一半畫著哀愁的臉，一半是微笑的臉，讓人感到害怕... 。\n");
                set("wear_as", "face_eq");
                set("apply_armor/face_eq", ([
                        "armor" :5,
                        "dodge":20,
                ]));
        }

        setup();
}
