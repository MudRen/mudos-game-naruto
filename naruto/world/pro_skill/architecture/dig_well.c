#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("【建築學】挖井技巧", ({ "dig well book", "book" }));
    set_weight(1);
    if( !clonep() ) {
        set("unit", "本");
        set("value", 10000);
        set("long", "一本教你如何挖井的教學書籍。\n"
                    "條件：必須有建築學技能。\n"
                    "使用方式： use book\n");
    }

    setup();
}

void do_use(object me, string arg)
{
    mapping sk;
    sk = me->getProSkill("architecture");

    if( !mapp(sk) ) {
        tell_object(me, "你從未學過建築技能。\n");
        return;
    }

    if( member_array("well", sk["item"]) != -1 ) {
        tell_object(me, "挖井技巧你已經學會了。\n");
        return;
    }

    if( !me->addProItem("architecture", "well") ) {
        tell_object(me, "你沒辦法學習挖井技巧，可能是技能等級不足。\n");
        return;
    }


    message_vision("$N拿起手上的$n仔細的閱讀起來。\n", me, this_object());
    destruct(this_object());
}

