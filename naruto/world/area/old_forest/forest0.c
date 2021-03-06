#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",HIC"水藍之湖"NOR);
    set("long", @long
湖面潔淨沒有一點瑕疵，清澈的湖水彷彿可以看見湖底，因為此
處的水氣充足，樹枝的根部也特別粗大，但是卻只圍繞著湖邊吸收湖
水而不沾染湖面，還有枝葉將葉片撥開使陽光照到湖上，好像有生命
般地在為湖水營造最佳的視覺景觀。少許的陽光照射到湖面與葉上露
珠形成漂亮的彩紅，更為這有如仙境的地方更增添了不少美感。覺得
口渴可以就地飲用湖水，也許有什麼神奇的效果喔。
long);
    set("exits", ([
        "north" : __DIR__"forest0.c",
        "south" : __DIR__"forest0.c",
        "west" : __DIR__"forest0.c",
        "east" : __DIR__"forest0.c",
    ]));
    set("detail", ([
        "湖水": HIB"清澈的湖水，可以飲用(drink)。"NOR,
    ]));
    set("no_recall", 1);
    set("no_fight", 1);
    setup();
}
void init()
{
    add_action("do_drink", "drink");
}
int do_drink(string arg)
{
    mapping cnd = ([]), weapons;
    string skill;
    object ob;

    if( arg == "湖水") {
        if( this_player()->query_condition("blue_lake", 1) != 0 ) {
            tell_object(this_player(), HIB"太貪心了吧，再喝可能會被凍成冰人喔！\n"NOR);
            return 1;
        }
        if( mapp(weapons = this_player()->query_temp("weapon")) && sizeof(weapons) ) {
            foreach(skill, ob in weapons) ob->unequip();
        }
        message_vision(CYN"$N將武器放下伸出雙手舀起湖水，咕嚕咕嚕的喝了幾口。\n"NOR, this_player());
        tell_object(this_player(), HIC"(透•心•涼！美妙的感覺讓你簡直要飛上天了！)\n"NOR);

        cnd["name"] = HIC"透心涼"NOR;
        cnd["duration"] = 100;

        this_player()->set_condition("blue_lake", cnd);
        return 1;
    }
}
int valid_leave(object me, string dir)
{
    object mob;
    if( !me ) return 0;
    if( userp(me) && (dir == "west" || dir == "east" || dir == "south" || dir == "north" ) ) {
        message_vision("$N依依不捨地離開了這裡。\n", this_player());
        me->start_busy(1);
        call_out("oldtree", 2, me);
    }
    return notify_fail("");
}
void oldtree(object me)
{
    string area = __DIR__"forest"+random(20)+".c";
    me->move(area);
}
