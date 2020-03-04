#include <ansi.h>
#include <armor.h>

inherit F_FACE_EQ;

void create()
{
    set_name(HIK"�G�L�Э�"NOR, ({ "spells mask", "mask" }) );
    set_weight(1000);
    setup_face_eq();
    if( !clonep() ) {
        set("unit", "��");
        set("value", 142200);
        set("no_box", 1);
        set("long", "�j�D�Y���G�L�A�Цb�y�W��O�N�j�T���ɡC\n");
        set("wear_as", "face_eq");
        set("apply_armor/face_eq", ([
            "armor": 5,
            "exact": 15,
            "attack": 10,
            "continual hit": 10,
            "str": 2,
            "con": 2,
        ]));
    }
    setup();
}
