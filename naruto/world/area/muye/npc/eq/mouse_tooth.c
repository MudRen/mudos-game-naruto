/* mouse_tooth.c
   �츭���U���D�����S�O����...
   write by -Acme-
*/

#include <ansi.h>
#include <armor.h>

inherit F_FACE_EQ;

void create()
{
    set_name(HIK"�j�ɤ�"NOR, ({ "mouse's tooth", "tooth" }) );

    set_weight(800);
    setup_face_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 101900);
        set("long", "��o�����b�L�W�A�K�֦��@��j�ɤ��C\n");
        set("wear_as", "face_eq");
        set("apply_armor/face_eq", ([
            "armor": 2,
            "exact": 10,
            "intimidate": 10,
            "continual hit": 10,
            "str": 3,
        ]));
    }
    setup();
}
