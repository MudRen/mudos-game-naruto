#include <ansi.h>
#include <armor.h>

inherit F_WAIST_EQ;

void create()
{
    set_name(HIY"�Ӷ����@�a"NOR, ({ "sun waist", "waist" }) );
    set_weight(5000);
    setup_waist_eq();
    if( !clonep() ) {
        set("unit", "��");
        set("value", 227500);
        set("no_box", 1);
        set("long", "�����۹����L���@�a�A�@�a�N��b�·t���a��]��o�X���~�C\n");
        set("wear_as", "waist_eq");
        set("apply_armor/waist_eq", ([
            "armor": 10,
            "str": 5,
            "con": 5,
            "dex": 5,
            "int": 5,
        ]));
    }
    setup();
}
