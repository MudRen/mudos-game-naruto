#include <ansi.h>
#include <armor.h>
inherit F_HEAD_EQ;
void create()
{
    set_name(HIY"�����Y��"NOR, ({ "Gold helmet", "helmet" }) );
    set_weight(1500);
    setup_head_eq();
    if( !clonep() ) {
        set("unit", "��");
        set("value", 20);
        set("long", "�ª����y���Y���D�`���ȿ�\n");
        set("wear_as", "head_eq");
        set("apply_armor/head_eq", ([
            "armor": 50,
            "str"  : 5,
            "con"  : 5,
            "dex"  : 5,
            "int"  : 5,
       ]));
    }
    setup();
}
