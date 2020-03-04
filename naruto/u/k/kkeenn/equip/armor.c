#include <ansi.h>
#include <armor.h>
inherit F_ARMOR;
void create()
{
    set_name(BRED+HIR"血繼皇護"NOR, ({ "blood armor", "armor" }) );
    set_weight(100);
    setup_armor();
    if( !clonep() ) {
        set("unit", "件");
        set("value", 0);
        set("long", "具有神秘功效的輕甲\n");
        set("wear_as", "armor");
        set("apply_armor/armor", ([
            "dex": 5,
            "str": 5,
            "int": 5,
            "con": 5,
            "armor": 90,
            "exact": 30,
            "hp"   : 9999,
            "ap"   : 9999,
            "mp"   : 9999,
        ]));
        set("wear_msg",RED"$N穿上"+name()+RED"四周瀰漫著淡淡的血腥味！\n"NOR);
    }

    setup();
}

