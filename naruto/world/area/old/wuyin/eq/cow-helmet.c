#include <ansi.h>
#include <armor.h>
inherit F_HEAD_EQ;

void create()
{
        set_name(HIK"真極牛頭"NOR, ({ "cow helmet","helmet" }) );
        set_weight(3000);
        setup_head_eq();

        if( !clonep() ) {
                set("unit", "頂");
                set("value", 1000);
                set("long",
                        "一頂有著兩隻牛角的頭盔，有誰會想戴著牠上街？\n");
                set("wear_as", "head_eq");
                set("apply_armor/head_eq", ([
                        "armor" :5,
                        "defense":5,
                ]));
        }

        setup();
}
