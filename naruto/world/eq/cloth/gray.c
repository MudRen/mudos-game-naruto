#include <ansi.h>
#include <armor.h>

inherit F_CLOTH;

void create()
{
    set_name(HIK"�Ǧ�l��"NOR, ({ "gray cloth", "cloth" }) );

    set_weight(1200);

    setup_cloth();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 800);
        set("long", "�@��Ƕª���A�A�ݧA�ݰ_�ӫܯ������Pı�C\n");
        set("wear_as", "cloth");
        set("apply_armor/cloth", ([
            "armor": 8,
        ]));
    }
    setup();
}

