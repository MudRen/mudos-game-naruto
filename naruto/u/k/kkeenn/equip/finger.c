#include <ansi.h>
#include <armor.h>
inherit F_FINGER_EQ;
void create()
{
    set_name(BRED+HIR"血繼烈護"NOR, ({ "blood finger", "finger" }) );
    set_weight(100);
    setup_finger_eq();
    if( !clonep() ) {
        set("unit", "只");
        set("value", 0);
        set("long", "具有神秘功效的指環\n");
        set("wear_as", "finger_eq");
        set("apply_armor/finger_eq", ([
            "dex": 5,
            "str": 5,
            "int": 5,
            "con": 5,
            "armor": 10,
            "continual hit": 30,
            "parry": 30,
            "combat": 30,
            "ninja": 30,
            "magic": 30,
            "force": 30,
            "savage hit": 30,
            "heavy hit": 30,         
            ]) ); 
   set("wear_msg",RED+"$N戴上"+name()+RED"的同時，手中的暗紅查克拉突然爆現出來！\n"NOR);
    }

    setup();
}


