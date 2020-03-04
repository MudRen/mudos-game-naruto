#include <npc.h>

inherit F_BANDIT;

void create()
{
    set_name("鐵甲將軍", ({ "iron jiang jun", "iron", "jiang", "jun" }) );
    set("unit", "位");
    set("gender", "male");
    set_level(40);
    set("age", 18+random(60));
    set("long", "身經百戰的鐵甲將軍，身上的鐵甲也傷痕累累。\n");
    set("chat_chance", 1);
    set("chat_msg", ({
        "鐵甲將軍看著你說：想要經過這裡，就從我的屍體踏過去\n",
       
    }));

    // 守著出口
    set("guard_exit", ({ "west" }));

    setup();
}

int do_guard_exit(int x, int y, string exit)
{
    message_vision("$n將$N擋住。\n", this_player(), this_object());
    return 1;
}

