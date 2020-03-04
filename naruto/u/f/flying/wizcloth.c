#include <ansi.h>
#include <armor.h>

inherit F_CLOTH;

void create()
{
    set_name(MAG"�Ův���@�t��"NOR, ({ "wiz cloth", "cloth" }) );

    set_weight(200);

    setup_cloth();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 10);
        set("long", "�M�T�~�C\n");
        set("wear_as", "cloth");
        set("apply_armor/cloth", ([
            "armor": 100,
            "dex": 50,
            "str": 50,
            "con": 50,
            "int": 50,
            "evade": 150,
            "wittiness": 150,
            "dodge": 120,
            "savage hit": 120,
            "continual hit": 120,
            "parry": 120,
            "combat": 120,
            "heavy hit": 120, 
       ]));
    }
    setup();
}

