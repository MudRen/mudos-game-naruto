#include <ansi.h>
#include <armor.h>
inherit F_CLOTH;
void create()
{
    set_name(HIY"�����Ԧ�"NOR, ({ "Gold cloth", "cloth" }) );
    set_weight(1500);
    setup_cloth();
    if( !clonep() ) {
        set("unit", "��");
        set("value", 20);
        set("long", "�ª����y����A�D�`���ȿ�\n");
        set("wear_as", "cloth");
        set("apply_armor/cloth", ([
            "armor": 50,
            "str"  : 5,
            "con"  : 5,
            "dex"  : 5,
            "int"  : 5,
       ]));
    }
    setup();
}
