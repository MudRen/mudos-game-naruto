#include <ansi.h>
#include <armor.h>
inherit F_PANTS;
void create()
{
    set_name(BRED+HIR"���~���@"NOR, ({ "blood pants", "pants" }) );
    set_weight(100);
    setup_pants();
    if( !clonep() ) {
        set("unit", "��");
        set("value", 0);
        set("long", "�㦳�����\�Ī��Z�N��\n");
        set("wear_as", "pants");
        set("apply_armor/pants", ([
            "dex": 5,
            "str": 5,
            "int": 5,
            "con": 5,
            "armor": 20,
            ]) ); 
        set("wear_msg",RED+"$N��W"+name()+RED"���P�ɡA�|�P�ϩ��}�B�۬��⪺���K�I\n"NOR);
    }

    setup();
}


