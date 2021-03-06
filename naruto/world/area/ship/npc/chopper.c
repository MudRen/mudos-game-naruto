#include <npc.h>
#include <ansi.h>

inherit F_SOLDIER;
inherit F_VENDOR;

void do_say()
{
    do_chat( ({ 
        (: command, "say 騙人布做的武器很棒喔！" :),
        (: command, "say 娜美說想趁機撈一筆！結果叫我來賣騙人布做的武器！" :),
        (: command, "say 為什麼不是她自己來賣！" :),
        (: command, "cry" :),
    }) );
}

void create()
{
    set_name("喬巴", ({ "chopper" }) );
    set_race("human");
    set_level(40);
    set_class("thief_sea");  // 海賊
    set("age", 10);
    set("no_fight", 1);
    set("title", HIM"船醫"NOR);
    set("long", "藍色鼻子的貍貓，不對！是馴鹿！因為吃了惡魔果實加上藍色的鼻\n"
                "子，不但被馴鹿同伴驅趕人類也不接納他。後來發生了某些事而加\n"
                "入草帽海賊團成為船醫。\n");

    set("chat_chance", 3);
    set("chat_msg", ({
        (: do_say :),
    }) );

    // 設定商人所販賣的物品
    // set_goods(代碼, 種類, 編號, 數量, 單價)
    // 商人能販賣的東西只能由 query 指令裡查 eq, wp, food 能查出來的物品
    // 如 set_goods(1, "food", 1, 10, -1) 表示販賣 query 指令查出來的food編號為1的食品十個
    // 若數量設定 -1 表示無限量供應
    // 若單價設為 -1 表示價錢是使用該物件設定的value
    // 代碼是用於 buy 指令上，如 buy 1 則會向商人買下代碼為1的商品

    set_goods(1, "wp", 62, -1, -1);
    set_goods(2, "wp", 64, -1, -1);
    set_goods(3, "food", 76, -1, -1);
set_goods(4, "food", 10, -1, -1);
    set_goods(5, "food", 11, 50, -1);


    setup();
    set_skill("combat", 200);
    set_skill("dodge", 170);
    set_skill("parry", 150);
    set_skill("heavy hit", 150);
    set_skill("savage hit", 150);
    set_skill("continual hit", 150);
}
