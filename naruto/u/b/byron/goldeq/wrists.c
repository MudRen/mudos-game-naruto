#include <ansi.h>
#include <armor.h>
inherit F_WRIST_EQ;
void create()
{
    set_name(HIY"�����@��"NOR, ({ "Gold hands", "hands" }) );
    set_weight(1500);
    setup_wrist_eq();
    if( !clonep() ) {
        set("unit", "��");
        set("value", 20);
        set("long", "�ª����y���@�ëD�`���ȿ�\n");
        set("wear_as", "wrist_eq");
        set("apply_armor/wrist_eq", ([
            "armor": 50,
            "str"  : 5,
            "con"  : 5,
            "dex"  : 5,
            "int"  : 5,
       ]));
    }
    setup();
}


