#include <ansi.h>
#include <npc.h>

inherit F_SOLDIER;

void create()
{
    set_name("土著射手", ({ "aborigines shooter", "shooter" }));
    set_race("human");
    set("gender", "female");
    set("age", 10+random(40));
    set_level(26);
    set("long", "土著的保衛戰士，手持弓箭驅逐外人進入。\n");
    set("attitude", "aggressive");
    set("set_drop", ({
        ([ "type":"food", "id":40, "amount":1+random(5), "p1":50, "p2":100 ]),  // 乾果
        ([ "type":"food", "id":38, "amount":1+random(2), "p1":20, "p2":100 ]),  // 樹果
        ([ "type":"food", "id":39, "amount":1+random(1), "p1":30, "p2":100 ]),  // 水果
        ([ "type":"food", "id":41, "amount":1, "p1":10, "p2":100 ]),            // 水果王
        ([ "type":"eq", "id":71, "amount":1, "p1":30, "p2":100 ]),              // 樹葉
        ([ "type":"wp", "id":19, "amount":1, "p1":10, "p2":100 ]),              // 弓
        ([ "type":"wp", "id":18, "amount":1, "p1":10, "p2":100 ]),              // 箭
    }) );
    setup();

    // 比較注重閃躲的土著，但還是擁有較強的體力和少許野性攻擊能力
    set_skill("dodge", 140);
    add_temp("apply/hp", 1000);
    add_temp("apply/attack", 20);
    add_temp("apply/intimidate", 20);

    // 有調整過 ap, hp, mp 的要 do_heal(), 才能讓狀態補滿
    do_heal();
}
