#include <npc.h>
#include <ansi.h>

inherit F_VENDOR;

void create()
{
    set_name("喬伊托瑞", ({ "Joe Torre", "torre", "joe" }));
    set_race("human");
    set_level(1);
    set("age", 66);
    set("long", "年老的馬戲團團員，現在正在這柴房中整理薪火。\n"
                "如果想要學習生產專業技巧，也可以和他學習。\n"
                "指令： learn produce \n");
    set("chat_chance", 3);
    set("chat_msg", ({
        (: command, "say 最近常整理出一些枯枝...都是商人賣的黑心貨。" :),
        (: command, "say 好像常有人來跟我買枯枝...那到底能幹麻？" :),
    }) );
    // 設定商人所販賣的物品
    // set_goods(代碼, 種類, 編號, 數量, 單價)
    // 商人能販賣的東西只能由 query 指令裡查 eq, wp, food 能查出來的物品
    // 如 set_goods(1, "food", 1, 10, -1) 表示販賣 query 指令查出來的food編號為1的食品十個
    // 若數量設定 -1 表示無限量供應
    // 若單價設為 -1 表示價錢是使用該物件設定的value
    // 代碼是用於 buy 指令上，如 buy 1 則會向商人買下代碼為1的商品

    set_goods(1, "obj", 163, 5, -1);
    set_goods(2, "obj", 162, -1, 1);
    setup();
}

void init()
{
    add_action("do_learn", "learn");
}

int do_learn(string arg)
{
    object me;
    mapping sk;

    me = this_player();

    if( !arg || arg != "produce")
        return notify_fail("你想學習什麼？\n");

    sk = me->getProSkill("produce");

    // 從沒學過
    if( !mapp(sk) ) {
        message_vision(CYN"$N向$n尋問一些生產相關的知識。\n"NOR, me, this_object());
        message_vision("$n說道﹕"HIG"難得還有這麼有心求學的人，我就教教$N吧。\n"NOR, me, this_object());
        tell_object(me , "(你了解了生產學的基礎。)\n"NOR);
        me->addProSkill("produce");
    } else tell_object(me, "你已經已經會生產技能了。\n");
    return 1;
}
