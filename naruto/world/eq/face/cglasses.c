#include <ansi.h>
#include <armor.h>
inherit F_FACE_EQ;

void create()
{
    set_name(BWHT+BLK"寫輪"NOR+HIW"眼鏡"NOR, ({ "copy glasses", "glasses" }) );

    set_weight(800);
    setup_face_eq();

    if( !clonep() ) {
        set("unit", "副");
        set("value", 1500);
        set("long", "一副鏡片上頭畫著寫輪眼樣子的眼鏡，是用來欺敵的戰術？\n");
        set("wear_as", "face_eq");
        set("apply_armor/face_eq", ([
        	"armor": 1,
            "str": 2,
        ]));
    }
    setup();
}
