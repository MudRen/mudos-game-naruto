#include <ansi.h>

inherit F_FOOD;

void create()
{
    set_name(HIK"�¤�"HIW"�ե֤�"NOR, ({ "blackwhite pill" ,"pill"}));
    if( !clonep() ) {
        set("unit", "��");
        set("base_unit", "��");
        set("base_value", 1000000);
        set("base_weight", 1);
        set("food_stuff", 1);
        set("long", "�զ�~�֥]�۶¦⤦�ġA���ۻĲ��W�������ߵ����D�A�\�ण���C\n");
        set("condition", ([ 
            "apheal4": ([ "duration": 140 ]),
            "hpheal4": ([ "duration": 140 ]),
            "mpheal4": ([ "duration": 140 ]),
            "apheal3": ([ "duration": 160 ]),
            "hpheal3": ([ "duration": 160 ]),
            "mpheal3": ([ "duration": 160 ]),
            "apheal2": ([ "duration": 180 ]),
            "hpheal2": ([ "duration": 180 ]),
            "mpheal2": ([ "duration": 180 ]),
            "apheal1": ([ "duration": 200 ]),
            "hpheal1": ([ "duration": 200 ]),
            "mpheal1": ([ "duration": 200 ]),
        ]));
    }
    setup();
}
