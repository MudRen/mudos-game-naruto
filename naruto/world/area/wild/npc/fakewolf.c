#include <npc.h>
#include <ansi.h>

void create()
{
    set_name(HIW"披著羊皮的狼"NOR, ({ "fake wolf", "wolf" }) );
    set_race("beast");
    set_level(30);

    set("long", "一隻長像很陰險的狼，還披著羊皮想矇混過去。\n");

    set("limbs", ({ "狼頭", "身體", "腹部", "狼腿", "尾巴" }) );
    set("verbs", ({ "bite" }) );

    set("attitude", "aggressive");         // 主動攻擊

    // 守著出口
    set("guard_exit", ({ "west", "east", "south" }));

    set("set_drop", ({
        ([ "type":"food", "id":32, "amount":1, "p1":80, "p2":100 ]),   // 狼心
        ([ "type":"food", "id":33, "amount":1, "p1":80, "p2":100 ]),   // 狼肺
        ([ "type":"eq", "id":57, "amount":1, "p1":20, "p2":100 ]),   // 狼腳
        ([ "type":"eq", "id":58, "amount":1, "p1":18, "p2":100 ]),   // 狼皮
        ([ "type":"eq", "id":59, "amount":1, "p1":20, "p2":100 ]),   // 狼腳
        ([ "type":"eq", "id":60, "amount":1, "p1":20, "p2":100 ]),   // 狼頭
        ([ "type":"eq", "id":61, "amount":1, "p1":25, "p2":100 ]),  // 狼尾
        ([ "type":"wp", "id":13, "amount":1, "p1":60, "p2":100 ]),  // 狼爪
    }) );

    setup();
}

int do_guard_exit(int x, int y, string exit)
{
    message_vision("$n將$N擋住。\n", this_player(), this_object());
    return 1;
}