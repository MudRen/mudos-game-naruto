#include <ansi.h>
#include <armor.h>
inherit F_ARMOR;

void create()
{
    set_name(HIB"�����"NOR, ({ "diving suit", "suit" }) );
    set_weight(6000);
    setup_armor();
    if( !clonep() ) {
        set("unit", "��");
        set("value", 6750);
        set("long", "�򨭪�����ˡA�I�ᦳ�\���𵩪��a��A�L�W�i�H�j�]���C\n");
        set("wear_as", "armor");
        set("apply_armor/armor", ([
            "armor": 10,
            "exact": 5,
            "ap": 100,
        ]));
    }
    setup();
}
