#include <ansi.h>
#include <armor.h>

inherit F_CLOTH;

void create()
{
        set_name(HIK"�Ǧ�~�M"NOR, ({ "gray jacket","jacket" }) );
        set_weight(3000);
        setup_cloth();

        if( !clonep() ) {
                set("unit", "��");
        set("value", 10);
                set("long", "�@��`�Ǧ⪺�~�M�A�S�����ʪ��Ұ�����ֽs�s���C\n");
                set("wear_as", "cloth");
                set("apply_armor/cloth", ([
                        "armor": 3,
                ]));
        }

        setup();
}

