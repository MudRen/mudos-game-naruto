#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("【生產】綠色樹液榨取教科書", ({ "green sap book", "book" }));
    set_weight(1);
    if( !clonep() ) {
        set("unit", "本");
        set("value", 100);
        set("long", "薄薄一本的書，外皮是一張用木杯裝著樹液的圖。\n"
                    "條件：必須有生產技能。使用方式： use book。\n");
    }
    setup();
}

void do_use(object me, string arg)
{
    mapping sk;
    sk = me->getProSkill("produce");

    if( !mapp(sk) ) {
        tell_object(me, "你從未學過生產技能。\n");
        return;
    }

    if( member_array("green_sap", sk["item"]) != -1 ) {
        tell_object(me, "你早就學會書上的內容啦。\n");
        return;
    }

    if( !me->addProItem("produce", "green_sap") ) {
        tell_object(me, "因為你生產相關知識不足，看不懂書上的內容。\n");
        return;
    }
    message_vision("$N拿起手上的$n仔細的閱讀起來。\n", me, this_object());
    destruct(this_object());
}
