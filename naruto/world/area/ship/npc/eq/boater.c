#include <ansi.h>
#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
    set_name(HIY"��U"NOR, ({ "boater" }) );
    set_weight(1);
    setup_head_eq();
    if( !clonep() ) {
        set("unit", "��");
        set("value", -1);
        set("no_box", 1);
        set("long", "�Y�H�e���|�Ҫ��H���A��|�Ҩӻ��O�D�`���n���F��C\n");
        set("wear_as", "head_eq");
        set("apply_armor/head_eq", ([
            "attack": 30,
        ]));

    }
    setup();
}
