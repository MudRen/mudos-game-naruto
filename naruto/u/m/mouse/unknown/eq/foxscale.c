#include <ansi.h>
#include <armor.h>
inherit F_HAND_EQ;

void create()
{
    set_name(HIY"����"NOR"��M", ({ "foxscale hands", "hands" }));
    set_weight(6000);
    setup_hand_eq();
    if( !clonep() ) {
        set("unit", "��");
        set("value", 5700);
        set("long", "������֩M���ƪ��h������һs���A��w�@�ΡC\n");
        set("wear_as", "hand_eq");
        set("apply_armor/hand_eq", ([
            "armor" : 4,
            "dex" : 1,
            "savage hit": 5,
        ]));
    }
    setup();
}
