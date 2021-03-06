#include <ansi.h>
inherit ROOM;

string do_list()
{
    int index, size;
    string msg;

    if( !wizardp(this_player()) ) {
        msg  = "上面寫著一行大大的字：\n\n";
        msg += HIR"      玩家不得使用此溫泉！\n\n"NOR;
        return msg;
    }
    msg  = "╭─────────────────────────╮\n";
    msg += "│溫泉使用手則：　　　　　　　　　　　　　　　　　　│\n";
    msg += "├─────────────────────────┤\n";
    msg += "│沖洗身體(wash)、泡湯(sit)、起身(stand)　　　　　　│\n";
    msg += "├─────────────────────────┤\n";
    msg += "│尚未清洗身體的人不得泡湯！　　　　　　　　　　　　│\n";
    msg += "│不准在澡堂內任意打鬥！　　　　　　　　　　　　　　│\n";
    msg += "│泡完離開請將隨身的物品帶走！　　　　　　　　　　　│\n";
    msg += "╰─────────────────────────╯\n";

    return msg;
}
void create()
{
        set("short", HIG"草摩"HIY"溫泉"NOR);
        set("long", @LONG
草摩家後院開闢出來的溫泉地，裡面是岩石與流水溫泉的自然環
境，搭配溫泉所噴出的白煙彷彿置身仙境，只要進入這裡便會使人全
身放鬆，心情好像平靜了許多，如果再去泡個溫泉，哇∼那一身的疲
勞將會全部消失。後面貼了一張紙條(paper)，似乎是使用規則。
LONG);
    set("exits", ([
        "west" : __DIR__"workroom.c",
    ]));
    set("detail", ([
        "paper": (: do_list :),
    ]));
    setup();
}
void init()
{
    if( wizardp(this_player()) ) {
        add_action("do_wash", "wash");
        add_action("do_stand", "stand");
        add_action("do_sit", "sit");
    }
}
int do_wash(string arg)
{
    if( this_player()->query_temp("take/bath") < 1) {
        message_vision("$N"HIW"拿起旁邊的水桶舀水清洗身體。\n"NOR, this_player());
        this_player()->add_temp("take/bath", 1);
        return 1;
    }
    return notify_fail("你已經洗的很乾淨了。\n");
}
int do_sit(string arg)
{
    if( this_player()->query_temp("take/bath") == 1) {
        message_vision("$N"HIY"挪動身子泡進溫泉裡面∼喔∼真爽。\n"NOR, this_player());
        this_player()->add_temp("take/bath", 1);
        call_out("wash_1", 10, this_player());
        return 1;
    } else if( this_player()->query_temp("take/bath") > 1) {
        return notify_fail("你已經泡在溫泉裡了還要泡啥？\n");
    }
    return notify_fail("還沒清洗身體就泡！太髒了吧！\n");
}
int do_stand(string arg)
{
    if( this_player()->query_temp("take/bath") == 2) {
        message_vision("$N"HIC"似乎泡夠了，起身離開溫泉。\n"NOR, this_player());
        this_player()->add_temp("take/bath", -1);
        return 1;
    }
    return notify_fail("你沒在泡溫泉。\n");
}
int valid_leave(object me, string dir)
{
    if( !me ) return 0;
    if( userp(me) && dir == "west" ) { 
        if( me->query_temp("take/bath") == 2) {
            return notify_fail("你還泡在溫泉裡想跑哪去？\n");
        }
        message_vision("$N"HIB"拿了自己隨身的物品後離開溫泉地。\n"NOR, me);
        me->delete_temp("take/bath");
    }
    return ::valid_leave(me, dir);
}
void wash_1()
{
    object ob;
    ob = this_player();
    if( environment(ob) != this_object() ) return;

    if( ob->query_temp("take/bath") < 2) {
        return;
    }
    if( ob->is_fighting() ) {
        this_player()->add_temp("take/bath", -1);
        message_vision("$N"HIM"在溫泉中打架！\n"NOR, this_player());
        return;
    }
    message_vision("$N"HIR"正幸福的泡在溫泉中。\n"NOR, this_player());
    ob->heal_stat("ap", ob->query_stat_maximum("ap"));
    ob->heal_stat("hp", ob->query_stat_maximum("hp"));
    ob->heal_stat("mp", ob->query_stat_maximum("mp"));
    call_out("wash_1", 10, ob);
    return;
}
