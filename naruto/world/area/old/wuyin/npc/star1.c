#include <npc.h>
#include <ansi.h>

void create()
{
    set_name(HIG"海星寶寶"NOR, ({ "sea star","star" }) );
    set_race("beast");
    set_level(19);

    set("long", "一隻很可愛的海星寶寶，牠可愛的模樣，讓你有一股想把牠當寵物的衝動。\n");

    set("limbs", ({ "頭部", "腹部" }) );
    set("verbs", ({ "bite" }) );
 
    set("chat_chance", 3);
    set("chat_msg", ({
        "海星寶寶露出陽光般燦爛的天真笑容。\n",
        }));

    setup();

    carry_money("silver", 50);

}
