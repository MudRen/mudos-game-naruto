#include <ansi.h>
#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
    set_name(HIR"蘋果頭飾"NOR, ({ "Apple archer" ,"archer"}) );

    set_weight(500);

    setup_head_eq();

    if( !clonep() ) {
        set("unit", "頂");
        set("value", 5000);
        set("long", "像蘋果一樣、帶有傳奇色彩的帽子，很久以前，一個技術高超的射手\n"
     "只用了一箭就在極遠的距離外射中這顆蘋果，讓使用者的熟練度提昇\n");
        set("wear_as", "head_eq");
        set("apply_armor/head_eq", ([
            "dex": 3,
        ]));
    }

    setup();
}

