#include <ansi.h>
#include <armor.h>
inherit F_HEAD_EQ;
void create()
{
    set_name(HIY"黃金頭盔"NOR, ({ "Gold helmet", "helmet" }) );
    set_weight(1500);
    setup_head_eq();
    if( !clonep() ) {
        set("unit", "頂");
        set("value", 20);
        set("long", "純金打造的頭盔非常的值錢\n");
        set("wear_as", "head_eq");
        set("apply_armor/head_eq", ([
            "armor": 50,
            "str"  : 5,
            "con"  : 5,
            "dex"  : 5,
            "int"  : 5,
       ]));
    }
    setup();
}
