#include <ansi.h>
#include <armor.h>

inherit F_CLOTH;

void create()
{
    set_name("���l", ({ "bat wings", "wings" }));
    set_weight(500);
    setup_cloth();
    if( !clonep() ) {
        set("unit", "��");
        set("value", 300);
        set("long", "�����ͻH�A�O�@�س��ͪ������C\n");
        set("wear_as", "cloth");
        set("apply_armor/cloth", ([
            "armor": 3,
        ]));
    }
    setup();
}
