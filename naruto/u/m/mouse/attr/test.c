#include <ansi.h>
inherit ITEM;

void create()
{
    set_name(HIW"替死"NOR"奴隸"NOR, ({ "scapegoat", "_ITS_MY_LIFE_" }));
    set_weight(3);
    if( !clonep() ) {
        set("unit", "位");
        set("value", 1);
        set("no_box", 1);
        set("no_sell", 1);
        set("long", "滿臉癡呆的奴隸，是香波地群島人口販子....不對！職業介紹所的產\n"
                    "物！可以用來當沙包，或是當做替死鬼也可以，想要練功或是被強敵\n"
                    "追殺時最好用的產品！"HIY"(護身符狀態，放bag沒作用)\n"NOR);
    }
    setup();
}

void init()
{
    if( userp(environment(this_object())) )
        add_action("do_sandbag", "sandbag");
}

int do_sandbag(string arg)
{
    object me, scap;

    me = this_player();

    if( arg != "scapegoatg" ) return notify_fail("想叫什麼東西當沙包？\n");
    if( me->is_busy() ) return notify_fail("你現在沒有空。\n");
    if( me->is_fighting() ) return notify_fail("戰鬥中還要什麼沙包。\n");

    message_vision(NOR"$N用著命令的語氣跟$n說："HIG"喂！在那裡站好！\n"NOR, me, this_object());

    scap = new("/world/npc/scap.c");
    scap->set("master_name", me->query("id"));

    if( environment(me)->is_area() ) move_side(scap, me);
    else scap->move(environment(me));

    message_vision(CYN+scap->name()+"馬上將沙包的道具穿好站著不動！\n", me, this_object());

    destruct(this_object());
    return 1;
}
