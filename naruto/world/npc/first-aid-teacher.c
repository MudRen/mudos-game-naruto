#include <npc.h>

inherit F_VENDOR;

void create()
{
    set_name("急救教師", ({ "first-aid teacher", "teacher" }));
    set_race("human");
    set_level(50);
    set("age", random(50)+18);

    set("long", "一位可以教你如何學習急救技能的教師。\n"
                "學習急救技能： learn first-aid\n"
                "列出販賣的產品： list teacher\n" );

    // 設定商人所販賣的物品
    // set_goods(代碼, 種類, 編號, 數量, 單價)
    // 商人能販賣的東西只能由 query 指令裡查 eq, wp, food 能查出來的物品
    // 如 set_goods(1, "food", 1, 10, -1) 表示販賣 query 指令查出來的food編號為1的食品十個
    // 若數量設定 -1 表示無限量供應
    // 若單價設為 -1 表示價錢是使用該物件設定的value
    // 代碼是用於 buy 指令上，如 buy 1 則會向商人買下代碼為1的商品

   set_goods(1, "obj", 119, -1, -1);
    set_goods(2, "obj", 168, -1, -1);
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

    if( !arg || arg != "first-aid")
        return notify_fail("你想學習什麼？\n");

    sk = me->getProSkill("first-aid");

    // 從沒學過
    if( !mapp(sk) ) {
        message_vision("$N向$n討教有關急救方面的知識。\n", me, this_object());
        me->addProSkill("first-aid");
    } else tell_object(me, "你已經學會急救技能了。\n");

//    // 提升技能等級上限的例子
//    if( !mapp(sk) ) tell_object(me, "你沒學過急救技能。\n");
//    else {
//        // 75 -> 150  老師只教到150
//        if( sk["max_level"] >= 150 ) {
//            tell_object(me, "你似乎無法從xxx身上再學習更進一步的急救技能。\n");
//            return 1;
//        }
//
//        // 現在的技能等級要是滿的上限才能增加
//        if( sk["level"] != 75 ) {
//            tell_object(me, "你的急救技能等級不足以更進一步的學習。\n");
//            return 1;
//        }
//
//        // 提升上限
//        me->upProSkill("first-aid");
//    }

    return 1;
}
