#include <ansi.h>
#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
    set_name(HIK"�T"HIW"��"RED"�Y"NOR, ({ "shark head", "head" }) );
    set_weight(5000);
    setup_head_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 80000);
        set("long", "�@����O�O�T�����Y���A�h�����L���n�۾���Y���C");
        set("wear_as", "head_eq");
        set("apply_armor/head_eq", ([
            "armor": 15,
            "dex": -2,
            "con": 7,
            "parry": 10,
        ]));
    }

    setup();
}

