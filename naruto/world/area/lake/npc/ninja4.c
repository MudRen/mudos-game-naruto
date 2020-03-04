#include <npc.h>
#include <ansi.h>

void do_fight()
{
    message_vision("\n$N結出『"CYN"水遁"NOR"』之印後雙手在身旁畫出一個巨大的圓形「"HIC"水障壁"NOR"」\n", this_object());
    message_vision("但是$N笨手笨腳的，圓畫的歪七扭八，一點效果也沒有。\n\n"NOR, this_object());
    this_object()->start_busy(1);
    return;
}
void create()
{
    set_name("水藍", ({ "water ninja", "ninja" }));
    set_race("human");
    set_level(10);
    set("age", 16);
    set("nickname",HIC"雨之忍者"NOR);
    set("gender","female");
    set("long", "雨隱村忍者，卻不知道什麼原因躲在這間屋子裡。\n");
    set("chat_chance_combat", 15);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    setup();
}
