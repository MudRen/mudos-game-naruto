#include <ansi.h>
#include <armor.h>

inherit F_WAIST_EQ;

void create()
{
        set_name(HIB"青龍叩帶"NOR, ({ "dragon belt","belt" }) );
        set_weight(3000);
        setup_waist_eq();

        if( !clonep() ) {
                set("unit", "條");
        set("value", 600);
                set("long", "相傳是四大聖獸【青龍】的皮所製成的金屬叩帶，滑溜溜的看來要體型適合的人才繫的起來。\n");
                set("wear_as", "waist_eq");
                set("apply_armor/waist_eq", ([
                        "str": 3,
                ]));
        }

        setup();
}

