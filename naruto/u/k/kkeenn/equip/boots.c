#include <ansi.h>
#include <armor.h>
inherit F_FEET_EQ;
void create()
{
    set_name(BRED+HIR"血繼日護"NOR, ({ "blood boots", "boots" }) );
    set_weight(100);
    setup_feet_eq();
    if( !clonep() ) {
        set("unit", "雙");
        set("value", 0);
        set("long", "具有神秘功效的健跑鞋\n");
        set("wear_as", "feet_eq");
        set("apply_armor/feet_eq", ([
            "dex": 5,
            "str": 5,
            "int": 5,
            "con": 5,
            "armor": 20,       
            ]) ); 
        set("wear_msg",RED+"$N穿上"+name()+RED"的同時，腳上的暗紅查克拉突然爆發出來！\n"NOR);
    }

    setup();
}


