#include <ansi.h>
#include <armor.h>

inherit F_NECK_EQ;

void create()
{
    set_name(HIC"工作證"NOR, ({ "An I.D. Card", "card" }) );
    set_weight(600);
    setup_neck_eq();

    if( !clonep() ) {
        set("unit", "張");
        set("value", 10);
        set("long", "一張員工工作證，上面有著照片標明員工身份。\n");
        set("wear_as", "neck_eq");
        set("apply_armor/neck_eq", ([
            "int": 10,
        ]));
    }

    setup();
}
