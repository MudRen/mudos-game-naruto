#include <ansi.h>

inherit ROOM;

int i;

void create()
{
        set("short", "「轟天」旅館");
        set("long", @LONG
旅館「轟天」，在門口就放了一塊招牌，上面介紹著有關轟天旅
館名稱的由來。一樓的房間看起來又小又簡陋，二樓的房間則比較寬
大舒適，如果有想住宿可以詢問老闆看看。
LONG);
    set("exits", ([
        "south" : ([ "filename" : __DIR__"waterfall.c",
                       "x_axis" : 2,
                       "y_axis" : 5,
                  ]),
    ]));
    set("detail", ([
        "招牌": @LONG
轟天一字的由來，便是旁邊的轟天瀑布，因為瀑布取自於岩中山泉，
本該無法形成瀑布，但是這轟天瀑布卻不同，仍然擁有強大的水力衝
擊，導致下面煙霧迷漫、直衝雲宵，水聲轟隆不絕於耳，更壯大了瀑
布之霸氣，頗有與天對轟之氣勢。
LONG
    ]));
    set("objects", ([
        __DIR__"npc/line.c" : 1,
         __DIR__"npc/hxh_adv_master.c" : 1,
    ]));
    set("no_fight",1);
    setup();
}
void init()
{
    add_action("do_lodging", "lodging");
}
int do_lodging(string arg)
{
    if( this_player()->query("bank") < 10000) {
        message_vision("豹爛說道﹕"HIG"$N銀行裡的錢不夠呢！\n"NOR, this_player());
        return 1;
    }
    if( i < 5) {
        message_vision(HIY"$N轉了10000兩銀子給豹爛。\n\n"NOR, this_player());
        message_vision(HIW"豹爛交給了$N一把房間鑰匙。\n\n\n"NOR, this_player());
        this_player()->add("bank", -10000);
        i = i+1;
        this_player()->move(__DIR__"home"+i+".c");
        message_vision(HIC"$N睡了一覺感覺好多了。\n\n"NOR, this_player());
        this_player()->heal_stat("ap", 9999);
        this_player()->heal_stat("hp", 9999);
        this_player()->heal_stat("mp", 9999);
        this_player()->start_busy(4);
        call_out("home_check",1800,this_object());
        return 1;
    }
    message_vision("豹爛說道﹕"HIG"真對不起，沒空房間了。\n\n"NOR, this_player());
    return 1;
}
void home_check()
{
    i = 0;
}
