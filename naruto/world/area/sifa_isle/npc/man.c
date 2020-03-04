#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("罪犯", ({ "culprit" }) );
    set_race("human");
    set_level(1);
    set("age", random(20)+15);
    set("long", "原本應該是個大惡人，但是被送來司法島後氣勢全沒了，現在也許連\n"
                "個小孩子都能輕鬆打敗他。\n");

    // 一般時動作
    set("chat_chance", 3);
    set("chat_msg", ({
        (: command, "sigh" :),
        (: command, "say 我不想進深海大監獄阿..." :),
    }) );
    setup();
}
