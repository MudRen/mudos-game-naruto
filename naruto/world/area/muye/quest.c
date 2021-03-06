/* write by -Acme- */
#include <ansi.h>
#define GUILD "mu"
#define GUILD_NAME "muye"
 
inherit ROOM;
 
// 提供的任務
int *quests = ({ 2, 3, 4, 5 });
 
string do_list()
{
    int index, size;
    string msg;
    mapping q;
 
    msg  = "\n╭─────────────────────────────╮\n";
    msg += sprintf("│%-58s│\n", this_object()->query("short"));
    msg += "├─────────────────────────────┤\n";
    msg += sprintf("│"BRED"%6s"NOR" "BBLU"%|51s"NOR"│\n", " 編號 ", " 任務名稱 ");
 
    size = sizeof(quests);
    for(index=0;index<size;index++) {
        if( mapp(q = QUEST_D->query_quest(GUILD, quests[index])) ) {
            msg += sprintf("│%|6d%s%-51s│\n",
                    index+1,
                    this_player()->query_quest(GUILD, quests[index]) ? HIY"a"NOR : " ",
                    q["name"] );
        }
    }

    msg += "╰─────────────────────────────╯";
    return msg;
}

void create()
{
    set("short", "木葉村任務接洽所");

    set("long", "你可以在這裡接下木葉村所提供的任務。\n"
                "輸入 list   查詢任務列表\n"
                "輸入 accept 接收任務\n"
                "輸入 giveup 放棄任務\n");

    set("exits", ([
        "east" : ([ "filename": __DIR__"muye.c",
                      "x_axis": 11,
                      "y_axis": 10,
                 ]),
    ]));

    setup();
}

void init()
{
    add_action("do_accept", "accept");
    add_action("do_giveup", "giveup");
}

int do_accept(string arg)
{
    int no;
    
    if( !arg ) return notify_fail("你要接下哪一個任務？\n");
    if( sscanf(arg, "%d", no) != 1 ) return notify_fail("你要接下哪一個任務？\n");
/*  升級任務能通用 -Tmr 2005/10/22
    if( this_player()->query("guild") != GUILD_NAME )
        return notify_fail("你不是木葉村的成員，不能接收任務。\n");
*/

    no -= 1;
    if( no < 0 || no >= sizeof(quests) ) return notify_fail("你要接下哪一個任務？\n");

    if( this_player()->query_quest(GUILD, quests[no]) )
        return notify_fail("你已經接下這個任務了。\n");

    this_player()->add_quest(GUILD, quests[no], 1);
    
    tell_object(this_player(), "你接下了這個任務！\n");

        return 1;
}

int do_giveup(string arg)
{
    int no;

    if( !arg ) return notify_fail("你要放棄哪一個任務？\n");
    if( sscanf(arg, "%d", no) != 1 ) return notify_fail("你要放棄哪一個任務？\n");
/*
    if( this_player()->query("guild") != GUILD_NAME )
        return notify_fail("你不是木葉村的成員，不能放棄任務。\n");
*/

    no -= 1;


    if( no < 0 || no >= sizeof(quests) ) return notify_fail("你要放棄哪一個任務？\n");

    if( !this_player()->query_quest(GUILD, quests[no]) )
        return notify_fail("你並沒有接下這個任務。\n");
    
    this_player()->delete_quest(GUILD, quests[no]);
    
    tell_object(this_player(), "你已經放棄了這個任務。\n");

        return 1;
}

