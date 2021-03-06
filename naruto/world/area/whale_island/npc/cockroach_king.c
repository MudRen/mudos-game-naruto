#include <npc.h>
#include <ansi.h>

void create()
{
    set_name(YEL"海蟑王"NOR, ({ "the king of cockroach", "cockroach", "king" }) );
    set_race("beast");
    set_level(20);
    set("title", "壞海蟑螂");
    set("long", "一隻恐怖的海蟑王，通常都生活在海邊的沙灘上，而不是在下水道中\n"
                "，看起來與別的蟑螂不同。\n");

    set("limbs", ({ "蟑頭", "身體", "腹部", "蟑腿", "尾巴" }) );
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");         // 主動攻擊
    set("set_drop", ({
        ([ "type":"obj", "id":25, "amount":1, "p1":80, "p2":100 ]),   // 蟑螂觸角
        ([ "type":"food", "id":34, "amount":1, "p1":60, "p2":100 ]),  // 蟑螂卵
        ([ "type":"obj", "id":26, "amount":1, "p1":80, "p2":100 ]),   // 蟑螂腳
        ([ "type":"eq", "id":47, "amount":1, "p1":3, "p2":100 ]),     // 蟑翅
    }) );

    setup();
    add_temp("apply/attack", 20);
    set_skill("combat", 100);
    set_skill("dodge", 100);
    set_skill("parry", 100);
    set_skill("savage hit", 100);
    set_skill("heavy hit", 100);
    set_skill("continual hit", 100);
}
