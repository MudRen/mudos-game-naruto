#include <npc.h>

void create()
{
    set_name("小狐熊", ({ "small fox bear", "bear" }) );
    set_race("beast");
    set_level(20);

    set("long", "小隻的狐熊，看起來很可愛。\n");

    set("limbs", ({ "熊頭", "身體", "腹部", "熊腿", "尾巴" }) );
    set("verbs", ({ "bite" }) );

    set("attitude", "aggressive");         // 主動攻擊

    set("set_drop", ({
    //  ([ "type":"obj", "id":??, "amount":1, "p1":40, "p2":100 ]),    // 狐毛
    //  ([ "type":"obj", "id":??, "amount":1, "p1":10, "p2":100 ]),    // 狐皮
    }) );
    setup();
}

