#include <ansi.h>
#include <armor.h>
inherit F_FINGER_EQ;

void create()
{
        set_name(RED"����"NOR, ({ "bird ring","ring" }) );
        set_weight(100);
        setup_finger_eq();

        if( !clonep() ) {
                set("unit", "��");
                set("value", 1000);
                set("long",
                        "�۶ǬO�|�j�t�~�i�����j�������һs�����٫��A�{�{�o�۬����ݰ_�ӴN�ܰ��Q���ˤl�C\n");
                set("wear_as", "finger_eq");
                set("apply_armor/finger_eq", ([
                        "con" :2,
                ]));
        }

        setup();
}
