#include <npc.h>

void create()
{
    set_name("小豬仔", ({ "baby pig", "pig" }) );
    set_race("beast");
    set_level(1);

    set("long", "一隻出生不過幾個月的小豬仔，看起來很可愛。\n");

    set("limbs", ({ "豬頭", "身體", "腹部", "豬腿", "尾巴" }) );
    set("verbs", ({ "bite" }) );

    set("attitude", "aggressive");         // 主動攻擊

    set("set_drop", ({
        ([ "type":"food", "id":31, "amount":1, "p1":80, "p2":100 ]),   // 豬腸
        ([ "type":"eq", "id":55, "amount":1, "p1":30, "p2":100 ]),   // 黑豬皮
        ([ "type":"eq", "id":56, "amount":1, "p1":20, "p2":100 ]),   // 黑豬頭
    }) );

    setup();
}