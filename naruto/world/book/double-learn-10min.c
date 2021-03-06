
#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("【"HIG"學點二倍卷"NOR"】十分鐘", ({ "double learn-points book", "book", "__BOOK__" }));
    set_weight(1);
    if( !clonep() ) {
        set("unit", "個");
      set("value", -1);
         set("long", "一個使用後可以讓你在十分鐘內能獲得雙倍學習點數的神奇卷軸。\n"
                    "使用方式： use book\n");
    }

    setup();
}

void do_use(object me, string arg)
{
    mapping c;

    mapping cnd = ([]);

    message_vision(HIW"$N將$n"NOR+HIW"咬在嘴中，雙手同時結印！！\n\n"NOR, me, this_object());

    message_vision("$N四週散出數道光芒，整個人手舞足蹈的，不知道在高興什麼勁...\n",me);

    if( !mapp(c = me->query_condition("double-learn")) ) c = ([]);

    cnd["name"] = HIG"學點二倍"NOR;
    cnd["duration"] = 300 + c["duration"];
    me->set_condition("double-learn", cnd);

    destruct(this_object());
}
