#include <ansi.h>
#include <armor.h>
inherit F_FACE_EQ;

void create()
{
        set_name(HIM"�p������"NOR, ({ "clown mask","mask" }) );
        set_weight(3000);
        setup_face_eq();

        if( !clonep() ) {
                set("unit", "�i");
                set("value", 100);
                set("long",
                        "����O�p�����y�A�@�b�e�۫s�T���y�A�@�b�O�L�����y�A���H�P��`��... �C\n");
                set("wear_as", "face_eq");
                set("apply_armor/face_eq", ([
                        "armor" :5,
                        "dodge":20,
                ]));
        }

        setup();
}
