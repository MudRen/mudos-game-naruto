#include <ansi.h>
#include <armor.h>

inherit F_LEG_EQ;

void create()
{
        set_name(HIG"�ȪZ�@��"NOR, ({ "turtle legs","legs" }) );
        set_weight(4000);
        setup_leg_eq();

        if( !clonep() ) {
                set("unit", "��");
        set("value", 500);
                set("long", "�۶ǬO�|�j�t�~�i�ȪZ�j���ߩһs�����@���A�w�j�j���ݰ_�ӤQ����w�C\n");
                set("wear_as", "leg_eq");
                set("apply_armor/leg_eq", ([
                        "armor": 15,
                        "int": -1,
                ]));
        }

        setup();
}

