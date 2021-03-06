#include <ansi.h>
#include <armor.h>
inherit F_WAIST_EQ;
void create()
{
    set_name(BRED+HIR"血繼漩護"NOR, ({ "blood waist", "waist" }) );
    set_weight(100);
    setup_waist_eq();
    if( !clonep() ) {
        set("unit", "條");
        set("value", 0);
        set("long", "具有神秘功效的腰帶\n");
        set("wear_as", "waist_eq");
        set("apply_armor/waist_eq", ([
            "dex": 5,
            "str": 5,
            "int": 5,
            "con": 5,
            "armor": 20,
            "continual hit": 50,
            "parry": 50,
            "combat": 50,
            "ninja": 50,
            "magic": 50,
            "force": 50,
            "savage hit": 50,
            "heavy hit": 50,         
        ]));
        set("wear_msg",RED"$N穿上"+name()+RED"身旁凝聚出萬道紅色絲狀查克拉！\n"NOR);
    }

    setup();
}

