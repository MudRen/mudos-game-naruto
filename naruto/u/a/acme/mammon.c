#include <npc.h>
#include <ansi.h>

inherit F_SAVE;

string *players;

// 存檔的路徑與本身NPC路徑、檔名一樣
string query_save_file() { return file_name(this_object()); }

void create()
{
    set_name(HIR"財神爺"NOR, ({ "mammon" }) );
    set_race("human");
    set_level(1);
    set("age", 99);
    set("gender", "male");
    set("long", "有錢的神...(你可以跟財神爺領紅包 receive gift )\n");

    setup();

    if( !restore() ) {
        players = ({});
        save();
    }
}

void init()
{
    add_action("do_receive", "receive");
}

int do_receive(string arg)
{
    if( !arg || arg != "gift" )
        return notify_fail("你要領取什麼？\n");

    if( this_player()->query("level") < 20 )
        return notify_fail("你的等級不足二十級，無法領取紅包！\n");

    if( member_array( this_player()->query_id(), players ) != -1 )
        return notify_fail("你已經領取過了。\n");

    message_vision(HIR"$N朝著$n跪下，頭胡亂磕得響亮，嘴角猶自傻笑著...\n"NOR, this_player(), this_object() );
    tell_object(this_player(), "（你的口袋裡多了一個紅包。）\n");

    players += ({ this_player()->query_id() });
    save();

    return 1;
}
