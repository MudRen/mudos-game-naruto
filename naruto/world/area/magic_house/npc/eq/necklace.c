#include <ansi.h>
#include <armor.h>

inherit F_NECK_EQ;

void create()
{
    set_name(YEL"�]�N"NOR"����", ({ "magic collar", "collar" }) );
    set_weight(600);
    setup_neck_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 5200);
        set("long", "�@���]�N�课����A�������r�����~���ܪ�����r�C\n");
        set("wear_as", "neck_eq");
        set("apply_armor/neck_eq", ([
            "str": 4,
        ]));
    }
    setup();
}
