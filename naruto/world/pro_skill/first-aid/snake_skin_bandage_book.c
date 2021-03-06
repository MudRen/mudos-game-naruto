#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("【急救】製作蛇皮繃帶教學書藉", ({ "snake-skin-bandage book", "book" }));
    set_weight(1);
    if( !clonep() ) {
        set("unit", "本");
        set("value", 100);
        set("long", "一本教你如何製作蛇皮繃帶的教學書籍。\n"
                    "條件：必須有急救技能。\n"
                    "使用方式： use book\n");
    }

    setup();
}

void do_use(object me, string arg)
{
    mapping sk;
    sk = me->getProSkill("first-aid");

    if( !mapp(sk) ) {
        tell_object(me, "你從未學過急救技能。\n");
        return;
    }

    if( member_array("snake_skin_bandage", sk["item"]) != -1 ) {
        tell_object(me, "這個產品你已經學會了。\n");
        return;
    }

    if( !me->addProItem("first-aid", "snake_skin_bandage") ) {
        tell_object(me, "你沒辦法學習這樣產品，可能是技能等級不足。\n");
        return;
    }


    message_vision("$N拿起手上的$n仔細的閱讀起來。\n", me, this_object());
    destruct(this_object());
}

