#include <ansi.h>
#include <armor.h>

inherit F_PANTS;

void create()
{
    set_name(HIB"�u�@��"NOR, ({ "Work pants", "pants" }) );

    set_weight(1500);
    setup_pants();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 10);
        set("long", "����@�i�A�C����`�N���ż�F�]�ݤ��ӥX�ӡA�`���u�H�߷R�C\n");
        set("wear_as", "pants");
        set("apply_armor/pants", ([
            "armor": 10,
            "dex": 20,
        ]));
    }

    setup();
}
