#include <ansi.h>
#include <armor.h>

inherit F_PANTS;

void create()
{
    set_name(HIW"�}�˿�"NOR, ({ "open pants", "pants" }) );
    set_weight(1500);
    setup_pants();
    if( !clonep() ) {
        set("unit", "��");
        set("value", 5400);
        set("long", "�@���H�K�ɤ@�ɪ��}�Ǥl�A���L�z��׬O�L�ǥi��C\n");
        set("wear_as", "pants");
        set("apply_armor/pants", ([
            "armor": 8,
            "int": 2,
        ]));
    }
    setup();
}
