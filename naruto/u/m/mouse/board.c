#include <ansi.h>

#define BOARD_CAPACITY  query("capacity")
#define NO_PLAYER_POST  query("NO_PLAYER_POST")

inherit ITEM;
inherit F_SAVE;

void create()
{
    set_name(HIY"工作"HIW"計劃板"NOR,({"work board","board"}));
    set("long",@LONG
一塊巨大的白板，記錄一些工作事項和計劃。使用指令：

post <標題>                提出一份工作計劃
read <編號>                閱讀一份工作計劃
discard <編號>             刪除一份工作計劃
mark <編號>                標記一份工作計劃
followup <編號>[<新標題>]  回覆一份工作計劃[不加則使用原標題]

LONG);
    set("no_get", 1);
    set("location","/u/m/mouse/workroom.c");
    set("capacity",500);
    set("board_id", "board");
    set("board_owner","board");
    setup();
}

void setup()
{
    string loc;

    seteuid(getuid());
    ::setup();
    if( stringp(loc = query("location")) )
        move(loc);
    restore();
}

void init()
{
    add_action("do_post", "post");
    add_action("do_read", "read");
    add_action("do_discard", "discard");
    add_action("do_followup", "followup");
    add_action("do_mark","mark");
}

string query_save_file()
{
    string id;

    if( !stringp(id = query("board_id")) ) return 0;
    return "/u/m/mouse/board/" + id;
}

string short()
{
    mapping *notes;
    int i, unread, last_read_time;

    notes = query("notes");
    if( !pointerp(notes) || !sizeof(notes) )
        return ::short() + " [ 沒有任何工作計劃 ]";

    if( this_player() && this_player()->link() ) {
        last_read_time = (int)this_player()->link()->query("board_last_read/" + (string)query("board_id"));
        for(unread = 0, i=sizeof(notes)-1; i>=0; i--, unread ++)
            if( notes[i]["time"] <= last_read_time ) break;
    }
    if( unread )
        return sprintf("%s [ %d 份工作計劃﹐%d 份未閱讀 ]", ::short(), sizeof(notes), unread);
    else
        return sprintf("%s [ %d 份工作計劃 ]", ::short(), sizeof(notes));
}

string long()
{
    mapping *notes;
    
    int i, last_time_read;
    string msg, tmp;

    notes = query("notes");
    msg = query("long");
    if( !msg ) msg = "";

    last_time_read = this_player()->link()->query("board_last_read/" + (string)query("board_id"));

    msg += "╭────────────────────────────────────────╮\n";
    msg += sprintf("│%-67s  容量%|5d份│\n", query("name"), BOARD_CAPACITY);
    msg += "├────────────────────────────────────────┤\n";
    msg += sprintf("│"BGRN+HIW"%s"NOR" "BRED+HIW"%|33s"NOR" "BBLU+HIW"%|24s"NOR" "BMAG+HIW"%|16s"NOR"│\n", "編號", "主題", "計劃人", "時間");
    if( pointerp(notes) && sizeof(notes) ) {
         for(i=0; i<sizeof(notes); i++) {
             msg += sprintf("│%|4s%s%-33s %|24s %16s│\n",
                            notes[i]["time"] > last_time_read ? sprintf(HIC"%|4d"NOR, i+1) : ""+(i+1),
                            notes[i]["mark"] ? HIY"M"NOR : " ",
                            strlen(notes[i]["
title"]) > 32 ? notes[i]["title"][0..29] + ".." : notes[i]["title"],
                            notes[i]["author"],
                            CHINESE_D->chinese_date_brief(notes[i]["time"]));
         }
    }
    msg += "╰────────────────────────────────────────╯\n";
    return msg;
}

// This is the callback function to process the string returned from the
// editor defined in F_EDIT of player object.
void done_post(object me, mapping note, string text)
{
    mapping *notes;
    string sig;
    int i=0,j=0;
    if( stringp(sig = me->link()->query("signature")) )
        text += "--\n" + sig;   // 加 -- 好在 followup 可以知道

    note["msg"] = text+NOR;
    notes = query("notes");
    if( !pointerp(notes) || !sizeof(notes) )
        notes = ({ note });
    else
        notes += ({ note });

    // Truncate the notes if maximum capacity exceeded.
    if( sizeof(notes) > BOARD_CAPACITY ) {
        while( i < BOARD_CAPACITY && !j ) {
                if( notes[i]["mark"] ) i++;
                else {
                        notes -= ({ notes[i] });
                        j++;
                }
        }

    }
    set("notes", notes);
    tell_object(me, "新工作計劃製定完畢。\n");

    save();
    return;
}

int do_post(string arg)
{
    mapping note;
    if(!arg) return notify_fail("工作計劃必須要有標題。\n");

    // 玩家不能製作
    if( NO_PLAYER_POST && (!wizardp(this_player())))
        return notify_fail("玩家不能製訂工作計劃。\n");

    if( sizeof(query("notes")) > BOARD_CAPACITY )
        return notify_fail("白版寫滿了，沒空位製定工作計劃。\n");

    if( strlen(arg) > 40 )
        return notify_fail("您的計劃名稱太長了﹐換一個 40 個字元以內的吧。\n");
        
    note = allocate_mapping(4);
    note["title"] = arg;
    note["author"] = this_player()->name() + "(" +this_player()->query("id") + ")";
    note["time"] = time();
    this_player()->edit( (: done_post, this_player(), note :) );
    return 1;
}

int do_read(string arg)
{
    int num, tmp;
    mapping *notes, last_read_time;
    string myid, msg;

    // 玩家不能看工作計畫
    if( !wizardp(this_player()) )
        return notify_fail("你盯著計劃板猛看，卻只看到一團黑影。\n");

    last_read_time = this_player()->link()->query("board_last_read");
    myid = query("board_id");
    notes = query("notes");

    if( !pointerp(notes) || !sizeof(notes) )
        return notify_fail("計劃板上目前沒有任何工作計劃。\n");

    if( !arg ) return notify_fail("指令格式﹕read <編號>|new|next\n");
    if( arg=="new" || arg=="next" ) {
        if( !mapp(last_read_time) || undefinedp(last_read_time[myid]) )
           num = 1;
        else
            for(num = 1; num<=sizeof(notes); num++)
                if( notes[num-1]["time"] > last_read_time[myid] ) break;
                        
    } else if( !sscanf(arg, "%d", num) )
        return notify_fail("你要讀第幾份工作計劃﹖\n");

    if( num < 1 || num > sizeof(notes) ) return notify_fail("沒有這份工作計劃。\n");
    num--;

    msg = sprintf(BGRN+HIW"%|4d"NOR" "BRED+HIW"%-33s"NOR" "BBLU+HIW"%|24s"NOR" "BMAG+HIW"%|16s"NOR"\n",
                   num+1,
                   strlen(notes[num]["title"]) > 32 ? notes[num]["title"][0..29] + ".." : notes[num]["title"],
                   notes[num]["author"],
                   CHINESE_D->chinese_date_brief(notes[num]["time"]) );
//                 ctime(notes[num]["time"])[0..9] + ctime(notes[num]["time"])[19..23] );
    msg += "────────────────────────────────────────\n";
    msg += notes[num]["msg"];
    msg += "────────────────────────────────────────";

    this_player()->start_more(msg);

    if( !mapp(last_read_time) ) {
            this_player()->link()->set("board_last_read", ([ myid: notes[num]["time"] ]) );
    } else if( undefinedp(last_read_time[myid]) || notes[num]["time"] > last_read_time[myid] )
            last_read_time[myid] = notes[num]["time"];

    return 1;
}

int do_discard(string arg)
{
    mapping *notes;
    int num;

    // 玩家不能刪除計劃
    if( !wizardp(this_player()) )
        return notify_fail("看都看不到了還想刪什麼？\n");

    if( !arg || sscanf(arg, "%d", num)!=1 )
        return notify_fail("指令格式﹕discard <編號>\n");
    notes = query("notes");
    if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
        return notify_fail("沒有這份工作計劃。\n");
    num--;
    if( notes[num]["author"] != (string) this_player(1)->query("name")+ "(" + this_player(1)->query("id") + ")"
    &&  wiz_level(this_player(1)) < 4 && query("board_owner") != this_player()->query_id() )
        return notify_fail("這個工作計劃不是你寫的。\n");

    if( notes[num]["mark"] ) 
        return notify_fail("這工作計劃已設定標記，請先清除標記。\n");

    notes = notes[0..num-1] + notes[num+1..sizeof(notes)-1];
    set("notes", notes);
    save();
    write("刪除第 " + (num+1) + " 份工作計劃....Ok。\n");
    return 1;
}

int do_followup(string str)
{
    mapping *notes, note;
    string *text, title;
    int i, num;
        
    // 玩家不能回應工作
    if ( !wizardp(this_player()) )
        return notify_fail("要回應啥米東東哩？\n");

    if( !str )
        return notify_fail("指令格式﹕followup <編號> [新的標題]\n");

    if( sscanf(str, "%d %s", num, title) != 2 )
        if( sscanf(str, "%d", num) != 1 )
            return notify_fail("你要回應第幾份工作計劃﹖\n");
        
    notes = query("notes");
        
    if( num < 1 || num > sizeof(notes) )
        return notify_fail("沒有這份工作計劃。\n");

    num--;
    if( !title ) title = "Re﹕" + notes[num]["title"];
    note = allocate_mapping(4);
    note["title"]  = title;
    note["author"] = this_player()->query("name") + "(" + this_player()->query("id") + ")";
    note["time"]   = time();

    text = explode( notes[num]["msg"], "\n" );
    // title, num 這兩個變數拿來再利用
    title = sprintf(GRN"> %s 在 %s 留下這份工作計劃﹕\n"NOR,
        notes[num]["author"],
        "(" + ctime(notes[num]["time"])[0..9] + ")" );
    num = sizeof(text);
    for( i=0; i<num; i++ ) 
    {
        // 空行跳過, 上上一篇跳過
        if( text[i] == "" || strsrch(text[i], "> ") != -1)
            continue;
        // 簽名檔, 結束
        if( text[i][0..1] == "--" )
            i=num;
        else title = title + GRN + "> " + text[i] + NOR + "\n";
    }
    note["msg"] = title;
    this_player()->edit( (: done_post, this_player(), note :), title );
    return 1;
}

int do_mark(string arg)
{
    mapping *notes;
    int num;

    // 玩家不能標記工作
    if ( !wizardp(this_player()) )
        return notify_fail("標記一團黑影嗎？\n");

    if( !arg || sscanf(arg, "%d", num)!=1 )
        return notify_fail("指令格式﹕mark <編號>\n");
    notes = query("notes");
    if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
        return notify_fail("沒有這份工作計劃。\n");
    num--;

    if( wiz_level(this_player(1)) < 4 && query("board_owner") != this_player()->query_id() )
        return notify_fail("你沒有權利標記工作計劃。\n");

    if( !notes[num]["mark"] ) {
        write("將第"+(num+1)+"份工作計劃設定標記。\n");
        notes[num]["mark"]=1;
    } else {
        write("將第"+(num+1)+"份工作計劃取消標記。\n");
        notes[num]["mark"]=0;
    }
    save();
    return 1;
}
