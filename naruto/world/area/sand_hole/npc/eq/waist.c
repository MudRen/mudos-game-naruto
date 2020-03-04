#include <ansi.h>
#include <armor.h>

inherit F_WAIST_EQ;

void create()
{
    set_name("�@�a", ({ "waist" }) );
    set_weight(6000);
    setup_waist_eq();
    if( !clonep() ) {
        set("unit", "��");
        set("value", 24000);
        set("long", "�۹����L���y�a�A���G�֦��U�ؤ��P����O�C\n");
        set("wear_as", "waist_eq");
    }
    set("apply_armor/waist_eq", ([
        "armor": 8,
    ]));
    setup();
}
