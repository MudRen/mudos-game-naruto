#include <ansi.h>
#include <armor.h>
inherit F_ARMOR;

void create()
{
    set_name(HIR"����"NOR, ({ "shrimp shell", "shell" }) );
    set_weight(1000);
    setup_armor();
    if( !clonep() ) {
        set("unit", "��");
        set("value", 300);
        set("long", "�s�����~�ߡA�Z��w���C\n");
        set("wear_as", "armor");
        set("apply_armor/armor", ([
            "armor": 3,
        ]));
    }
    setup();
}
