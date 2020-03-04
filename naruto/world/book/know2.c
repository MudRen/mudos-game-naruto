#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("【"HIY"真。"HIK"寫輪眼之卷"NOR"】看穿NPC掉落物品列表與機率", ({ "book" }));
    set_weight(1);
    if( !clonep() ) {
        set("unit", "個");
        set("value", -1);
        set("long", "一個使用後可以暫時性的讓你看穿NPC掉落物品列表與機率。(help use)");
    }

    setup();
}

void do_use(object me, string arg)
{
    mapping c;
    mapping cnd = ([]);

    message_vision(HIW"$N將【"HIY"真。"HIK"寫輪眼之卷"NOR"】"NOR+HIW"卷軸咬在嘴中，雙手同時結印！！\n"NOR, me);

    if( !mapp(c = me->query_condition("know2")) ) c = ([]);

    cnd["name"] = HIY"真。"HIK"寫輪眼"NOR;
    cnd["duration"] = 1800 + c["duration"];
    me->set_condition("know2", cnd);


    destruct(this_object());
}
