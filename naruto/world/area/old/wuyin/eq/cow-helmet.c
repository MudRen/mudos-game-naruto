#include <ansi.h>
#include <armor.h>
inherit F_HEAD_EQ;

void create()
{
        set_name(HIK"�u�����Y"NOR, ({ "cow helmet","helmet" }) );
        set_weight(3000);
        setup_head_eq();

        if( !clonep() ) {
                set("unit", "��");
                set("value", 1000);
                set("long",
                        "�@�����ۨⰦ�������Y���A���ַ|�Q���ۨe�W��H\n");
                set("wear_as", "head_eq");
                set("apply_armor/head_eq", ([
                        "armor" :5,
                        "defense":5,
                ]));
        }

        setup();
}
