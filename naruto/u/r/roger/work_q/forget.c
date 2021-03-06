#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("【"HIW"記不住的過去"NOR"】遺忘技能", ({ "book" }));
    set_weight(1);
    if( !clonep() ) {
        set("unit", "個");
        set("value", -1);
        set("long", "一個使用後可以可以讓你遺忘掉學習過的技能。\n"
                    "使用方式： use book to <技能>\n");
    }

    setup();
}

void do_use(object me, string arg)
{
    int point;

    if( !arg ) {
        write("你要遺忘什麼技能？\n");
        return;
    }

    if( !me->query_skill(arg) ) {
        write("你沒有學過 " + arg + " 這個技能...\n");
        return;
    }

    message_vision(HIW"$N將"BGRN+HIY"【"HIW"記不住的過去"HIY"】"NOR+HIW"卷軸咬在嘴中，雙手同時結印！！\n\n"NOR, me);
    message_vision( "$N說道：" + HIG "忘掉【" + arg + "】的存在。\n\n"NOR +
                    HIW"天空忽然掉下一支超大的鐵槌，狠狠往$N頭上敲去！！！\n"NOR +
                    HIM"$N摀著頭上的大包，在地上不停打滾哀嚎，臉上佈滿鼻涕眼淚的，非常的狼狽...\n\n"NOR, me);

    point = me->query_skill_ability(arg);
    me->add_point("skill", point);
    me->delete_skill(arg);

#ifdef SAVE_USER
    if( (int)me->save() ) {
        write("檔案儲存完畢。\n");
        me->set_temp("last_save", (int)(time()/60) );
    }
#endif

    destruct(this_object());
}
