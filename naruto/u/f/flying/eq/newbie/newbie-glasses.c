#include <ansi.h>
#include <armor.h>
inherit F_FACE_EQ;

void create()
{
    set_name("新手眼鏡", ({ "newbie glasses", "glasses" }) );

    set_weight(80);
    setup_face_eq();

    if( !clonep() ) {
        set("unit", "副");
        set("value", 10);
        set("long", "隨手可得的竹子貼上透明膠布後變成的眼鏡。\n");
        set("wear_as", "face_eq");
        set("apply_armor/face_eq", ([
                "exact": 1,
             ]));
    }
    setup();
}


