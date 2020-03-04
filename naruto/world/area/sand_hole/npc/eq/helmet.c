#include <ansi.h>
#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
    set_name("�j�N�Y��", ({ "ancient helmet", "helmet", "_ANCIENT_HELMET_" }) );
    set_weight(3500);
    setup_head_eq();
    if( !clonep() ) {
        set("unit", "��");
        set("value", 53400);
        set("no_drop", 1);
        set("no_sell", 1);
        set("no_box",1);
        set("long", "���۩_�ǲů����j�N���~�A���G�٨S�o���u�����O�q�C");
        set("wear_as", "head_eq");
        set("apply_armor/head_eq", ([
            "armor": 15,
            "wittiness": 10,
            "con": 2,
        ]));
    }
    setup();
}
