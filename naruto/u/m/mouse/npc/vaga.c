#include <npc.h>
#include <ansi.h>

inherit F_VILLAGER;

void create()
{
    set_name(HIW"僕人"NOR, ({ "servant" }));
    set_race("human");
    set_level(50);
    set("age", 16);
    set("long", "草摩家的家僕，每天都忙的汗流夾背。\n");
    set("gender", "female");                                 //性別
    set("chat_chance", 0);    // 乖啦 要安靜喔
    set("chat_msg", ({
        HIW"僕人"NOR+CYN"辛苦的整理著環境。\n"NOR,
        HIW"僕人"NOR+CYN"稍微休息著。\n"NOR,
    }));
    setup();
    carry_object(__DIR__"eq/worker/cloth.c")->wear();
}
void init()
{
    int i;
    if( this_player()->id("mouse") && userp(this_player()) ) {
        i = random(3);
        if( i == 2) {
            do_chat((: command, "say 歡迎回來，主人。" :));
            return;
        } else
        if( i == 1) {
            do_chat((: command, "say 別再製造髒亂了喔∼主人。" :));
            return;
        } else
        if( i == 0) {
            do_chat((: command, "sweat " + this_player()->query("id") :));
            return;
        }
    } else
    if( userp(this_player()) ) {
        i = random(5);
        if( i == 4) {
            do_chat((: command, "say 歡迎來到鼠的小窩。" :));
            return;
        } else
        if( i == 3) {
            do_chat((: command, "say 有點髒亂請別介意。" :));
            return;
        } else
        if( i == 2) {
            do_chat((: command, "sweat" :));
            return;
        } else
        if( i == 1) {
            do_chat((: command, "say 請隨便坐。" :));
            return;
        } else
        if( i == 0) {
            do_chat((: command, "courtesy" :));
            return;
        }
    }
    return;
}
int accept_fight(object ob)
{
    do_chat(HIW"僕人"NOR"生氣的說﹕"HIG"都快整理不完了還找我打架！"NOR"\n");
    return 0;
}
