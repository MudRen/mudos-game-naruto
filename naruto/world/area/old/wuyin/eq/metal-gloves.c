#include <ansi.h>
#include <armor.h>
inherit F_HAND_EQ;

void create()
{
        set_name(HIY"���ݤ�M"NOR, ({ "metal gloves","gloves" }) );
        set_weight(3000);
        setup_hand_eq();

        if( !clonep() ) {
                set("unit", "��");
                set("value", 100);
                set("long",
                        "�@�����ȩҰ�����M�A�S�����󪺪ŻءA�S�O���a��O��@�몺�֯�s´���٭n�Ӫ����C\n");
                set("wear_as", "hand_eq");
                set("apply_armor/hand_eq", ([
                        "armor" :5,
                ]));
        }

        setup();
}
