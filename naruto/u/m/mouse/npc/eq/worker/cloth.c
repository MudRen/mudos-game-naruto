#include <ansi.h>
#include <armor.h>
inherit F_CLOTH;

void create()
{
    set_name(HIC"���u"HIW"��A"NOR, ({ "cloth" }));

    set_weight(1000);
    setup_cloth();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 200);
        set("long", "���ɥ������u�Ҭ�۪���A�C\n");
        set("wear_as", "cloth");
        set("apply_armor/cloth", ([
            "armor": 200,                             //���m(armor)
            "str": 20,
            "int": 20,
        ]));
    }

    setup();
}
