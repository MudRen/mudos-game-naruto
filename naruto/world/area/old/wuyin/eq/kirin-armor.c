#include <ansi.h>
#include <armor.h>
inherit F_ARMOR;

void create()
{
        set_name(HIW"�Q���_��"NOR, ({ "kirin armor","armor" }) );
        set_weight(3000);
        setup_armor();

        if( !clonep() ) {
                set("unit", "��");
                set("value", 1000);
                set("long",
                        "�@�M���ժ��@�ҡA����O�v��c�������A��몺�����n��W���C\n");
                set("wear_as", "armor");
                set("apply_armor/armor", ([
                        "armor" :10,
                        "con" :2
                ]));
        }

        setup();
}
