#include <ansi.h>
#include <armor.h>
inherit F_PANTS;

void create()
{
        set_name(HIK"�Ǧ�u��"NOR, ({ "gray short","short" }) );
        set_weight(3000);
        setup_pants();

        if( !clonep() ) {
                set("unit", "��");
                set("value", 10);
                set("long",
                        "�@��`�Ǧ⪺�u�ǡA���O�S�����ʪ��Ұ�����ֽs�s�~�C\n");
                set("wear_as", "pants");
                set("apply_armor/pants", ([
                        "armor" :3,
                ]));
        }

        setup();
}
