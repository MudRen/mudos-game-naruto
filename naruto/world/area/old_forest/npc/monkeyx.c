#include <npc.h>
#include <ansi.h>

void create()
{
    set_name(YEL"猴王"NOR, ({ "monkey king", "monkey", "king" }));
    set_race("beast");
    set_level(25);
    set("age", 150);
    set("title", "大金剛");
    set("long", "體型類似猩猩般壯碩的大猴子，手上的傷痕正是牠成為王者的證明。\n");
    set("limbs", ({ "猴頭", "身體", "肚子", "猴臂", "尾巴", "猴背", "屁股" }) );
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");         // 主動攻擊
    set("set_drop", ({
        ([ "type":"eq", "id":73, "amount":1, "p1":90, "p2":100 ]),              // 猴皮
        ([ "type":"food", "id":43, "amount":1+random(1), "p1":80, "p2":100 ]),  // 猴掌
        ([ "type":"food", "id":42, "amount":1, "p1":50, "p2":100 ]),            // 猴腦
        ([ "type":"eq", "id":72, "amount":1, "p1":30, "p2":100 ]),              // 猴臂
        ([ "type":"eq", "id":69, "amount":1, "p1":10, "p2":100 ]),              // 金剛臂
    }) );
    setup();

    // 加強
    add_temp("apply/hp", 500);
    add_temp("apply/armor", 100);
    add_temp("apply/attack", 100);
    add_temp("apply/intimidate", 20);

    // 有調整過 ap, hp, mp 的要 do_heal(), 才能讓狀態補滿
    do_heal();
}
