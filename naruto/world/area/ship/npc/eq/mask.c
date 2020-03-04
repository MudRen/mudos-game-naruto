#include <ansi.h>
#include <armor.h>

inherit F_FACE_EQ;

void create()
{
    set_name(YEL"������"HIR"����"NOR, ({ "snipe mask", "mask" }) );
    set_weight(1000);
    setup_face_eq();
    if( !clonep() ) {
        set("unit", "��");
        set("value", -1);
        set("no_box", 1);
        set("long", "�������Ұt�a������A�ݰ_�ӹ��ӦV�鸪�A���I�ǡC\n");
        set("wear_as", "face_eq");
        set("apply_armor/face_eq", ([
            "armor": 20,
            "exact": 30,
            "dodge": 10,
            "dex": 10,
        ]));
    }
    setup();
}
