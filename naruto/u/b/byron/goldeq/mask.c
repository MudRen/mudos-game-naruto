#include <ansi.h>
#include <armor.h>
inherit F_FACE_EQ;
void create()
{
    set_name(HIY"�������n"NOR, ({ "Gold mask", "mask" }) );
    set_weight(1500);
    setup_face_eq();
    if( !clonep() ) {
        set("unit", "��");
        set("value", 20);
        set("long", "�ª����y������D�`���ȿ�\n");
        set("wear_as", "face_eq");
        set("apply_armor/face_eq", ([
            "armor": 50,
            "str"  : 5,
            "con"  : 5,
            "dex"  : 5,
            "int"  : 5,
       ]));
    }
    setup();
}
