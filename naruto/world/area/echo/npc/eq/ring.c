#include <ansi.h>
#include <armor.h>
inherit F_FINGER_EQ;

void create()
{
    set_name(HIY"�ѯ���"NOR, ({ "noodlegod ring", "ring" }) );
    set_weight(200);
    setup_finger_eq();
    if( !clonep() ) {
        set("unit", "�T");
        set("value", 4700);
        set("no_box", 1);
        set("long", "�ѱi�P�u�@�֡v���ѩ����������Ӫ��٫��C\n");
        set("wear_as", "finger_eq");
        set("apply_armor/finger_eq", ([
            "combat": 5,
            "dex": 1,
            "armor": 2,
        ]));
    }
    setup();
}
