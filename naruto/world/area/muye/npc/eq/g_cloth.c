#include <ansi.h>
#include <armor.h>

inherit F_CLOTH;

void create()
{
    set_name(GRN"���򨭦�"NOR, ({ "green cloth", "cloth" }) );

    set_weight(1200);

    setup_cloth();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 8900);
        set("long", "�@��`��⪺�򨭦�A��b���W�A�|�Pı��@�Ѽ��媺�𮧡C\n");
        set("wear_as", "cloth");
        set("apply_armor/cloth", ([
            "armor": 10,
            "dex": 3,
        ]));
    }
    setup();
}