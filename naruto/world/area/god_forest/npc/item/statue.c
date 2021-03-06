#include <ansi.h>

inherit ITEM;

void create()
{
    set_name(WHT"龍空大王石像"NOR, ({ "statue", "_DRAGON_STATUE_" }));
    set_weight(1);
    if( !clonep() ) {
        set("unit", "尊");
        set("value", 0);
        set("no_box", 1);
        set("no_get", 1);
        set("long", "看起來栩栩如生的石像，唯獨胸口的部份被開了一個大洞，從裡面的\n"
                    "構造來看，似乎是什麼東西被拔走了。不過就算如此依然不減此石像\n"
                    "所散發的氣勢，感覺這不是一般的石像。\n"
                    "也許你可以找東西鑲嵌(beset)進這個大洞中。\n");
    }
    setup();
}
void init()
{
    add_action("do_beset", "beset");
}
int do_beset(string arg)
{
    object me, obj;

    me = this_player();

    if( !me->query_temp("know_dragon") ) {
        me->set_temp("know_dragon", 1);
        tell_object(me, CYN"聲音傳進你的腦海中...『青年！...心臟！...』\n"NOR);
        tell_object(me, CYN"可惜聲音非常微弱，聽不出個所以然來。\n"NOR);
    }
    if( !arg ) return notify_fail("你想要鑲嵌什麼東西？\n");
    if( me->is_busy() ) return notify_fail("你正在忙碌中，不能鑲嵌。\n");
    if( !objectp(obj = present(arg, me))) return notify_fail("你身上沒有這樣東西。\n");
    if( obj->query("keep_this") ) return notify_fail("這樣東西你已經 keep 無法鑲嵌。\n");
    if( me->query_level() != 40 ) return notify_fail("石像發出強大的氣息讓你無法鑲嵌。\n");

    if( obj->query("name") == HIY"神獸"RED"心臟"NOR ) {
        message_vision("$N將"+obj->query("name")+"鑲進$n之中！\n"NOR, me, this_object());
        me->start_busy(6);
        call_out("lvup_1", 5, me, this_object());
        destruct(obj);
    } else {
        return notify_fail("這樣東西不適合嵌入。\n");
    }
    return 1;
}
void lvup_1(object me, object ob)
{
    message("system", HIY"\n\n\t從神獸森林一層發出強烈的金光！\n\t"NOR+YEL"金色光芒漸漸幻化成龍型，對天空發出怒吼！"NOR"\n\n\t神獸森林一層之主─"HIG"龍空大王"NOR"的封印\n\t"HIW"被英勇的"NOR+HIC+BLINK+me->query("name")+NOR"("CYN+BLINK+me->query_id()+NOR")"HIW"給破解了..."NOR"\n\n\t"HIC"而在其所屬陣營 "HIR+me->query("title")+HIC" 之中，也無人不知曉他的名號了！\n\n\n"NOR, users());
    me->move(_DIR_AREA_"god_forest/king2.c");
    if( me->query("class") == "hxh_intermediate" ) {
        me->set_class("hxh_senior");
        tell_object(me, HIY"因為名聲的提高，獵人公會升你為全職獵人了！\n"NOR);
    } else if( me->query("class") == "middle" ) {
        me->set_class("superior");
        tell_object(me, HIY"因成功的解決重大事件，木葉忍者村決定將你提升為上忍！\n"NOR);
    } else if( me->query("class") == "thief_sea" ) {
        me->set_class("big_sea");
        tell_object(me, HIY"世界政府更重視你的威脅性，提高對你的懸賞金額成為大海賊！\n"NOR);
    } else if( me->query("class") == "soldier_sea" ) {
        me->set_class("officer_sea");
        tell_object(me, HIY"你完成任務有功，被授予士官的階級了！\n"NOR);
    } else {
        tell_object(me, HIR+BLINK"似乎出了什麼問題...\n"NOR);
    }
    me->add("level", 1);
    CLASS_D(me->query_class())->advance_level(me);
    RACE_D(me->query_race())->advance_level(me);
    tell_object(me, HIY"你的等級提升至 "+me->query_level()+" 級。\n"NOR);
    if( me->query_temp("dolomite_ok") ) me->delete_temp("dolomite_ok");
    return;
}
