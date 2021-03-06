#include <ansi.h>

inherit ITEM;

#define MAX 3   /* 能記憶的數量 */

string *path = allocate(MAX);
string *name = allocate(MAX);
string *eid = allocate(MAX);

void create()
{
    set_name(HIW"白雲飛天滑板"NOR, ({ "cloud flying skateboard", "skateboard"}));
    set_weight(3);
    if( !clonep() ) {
        set("unit", "個");
        set("value", 40000);
        set("long",@LONG
這是一個由海軍工房用科技創出來的飛天滑版，你可以使用它快速地移動到指
定的玩家身旁，當然，前提是你必須要先記憶(assign)那位玩家的ＩＤ。由於
飛天滑板製造時會產生良品與不良品，所以擁有不同程度的記憶能力，有些只
能記錄二個ＩＤ，有些卻能記錄六個ＩＤ以上，記憶能力越高的滑板，當然越
是價值連城。

指令格式：
assign [編號] [ID] : 將編號記憶某玩家的英文ＩＤ
assign             : 列出每一個編號所記錄的內容
sfly [編號]        : 移動到你所記錄過的玩家身旁

LONG
);
    }
    setup();
}

void init()
{
    add_action("do_move", "sfly");
    add_action("do_remember", "assign");
}

void moveTo(int index);

int do_remember(string arg)
{
    if( !arg ) {
        int i;
        string msg  = "╭────────────────────────────╮\n";
        msg += sprintf("│"BRED"%|4s"NOR" "BBLU"%|50s"NOR" │\n", "編號", "人物");
        for(i=1;i<=MAX;i++) {
            if( !stringp(path[i-1])) {
                msg += sprintf("│%|4d %-50s │\n", i, "[無]");
            } else {
                msg += sprintf("│%|4d %-50s │\n", i, name[i-1] + "(" + eid[i-1] + ")");
            }
        }
        msg += "╰────────────────────────────╯\n";
        tell_object(this_player(), msg );
    } else {
        string ppl;
        object me, ob;
        int id;

        me = this_player();

        if(sscanf(arg, "%d %s", id, ppl) != 2 || id < 1 || id > MAX ) return notify_fail("使用方法為 assign [編號] [ID]。\n");

        if( !(ob = present(ppl, environment(me))) )
            return notify_fail(HIB"這裡沒有 "NOR+ppl+HIB" 這個人阿。\n"NOR);

        if( !userp(ob) || wizardp(ob) )
            return notify_fail(HIB"你只可以記憶玩家的ＩＤ。\n"NOR);

        if( ppl == this_player()->query("id") )
            return notify_fail(HIB"記憶你自己的ＩＤ做啥。\n"NOR);

        path[id-1] = ob->query("name");
        name[id-1] = ob->query("name");
        eid[id-1] = ob->query("id");
        write("你拿起滑板上的記憶器對"+ob->query("name")+"猛照。\n");
    }
    return 1;
}

int do_move(string arg)
{
    int id;
    if( !arg ) return notify_fail("你想要移動到哪個編號？\n");
    if( sscanf(arg, "%d", id) != 1 || id < 1 || id > MAX ) return notify_fail("不正確的編號。\n");        
    if( !stringp(path[id-1]))  return notify_fail("這個編號並沒有記錄到任何ＩＤ。\n");
    if( this_player()->is_busy() || this_player()->is_fighting() ) return notify_fail("你正忙著，沒有空移動。\n");
    moveTo( id-1 );
    return 1;
}

void moveTo(int index)
{
    object ob = LOGIN_D->find_body(eid[index]);
    object me = this_player();
    string obj = this_object()->query("name");

    if( !ob ) {
        tell_object(me,HIB"你指定的"+name[index]+"目前不在線上。\n"NOR);
        return;
    }
    if( environment(ob)->query("no_recall") == 1 ) {
        tell_object(me,HIB""+name[index]+"所在的位置似乎不能過去。\n"NOR);
        return;
    }
    if( environment(ob)->is_area() ) {
        if( area_environment(ob, me) ) {
            tell_object(me, "你已經在"+name[index]+"身旁了。\n");
            return;
        }
        message_vision(HIC"$N兩腳踩在"+obj+"上，咻地一聲快速飛向天際...\n"NOR, me);
        if( !area_move(environment(ob), me, ob->query("area_info/x_axis"), ob->query("area_info/y_axis")) ) {
            tell_object(me, obj+"出問題啦！快點送場維修吧。\n");
            return;
        }
        message_vision(HIC"$N順利的降落在["+name[index]+"]身旁。\n" NOR, me);
        return;
    } else {
        if( environment(ob) == environment(me) ) {
            tell_object(me, "你已經在"+name[index]+"身旁了。\n");
            return;
        }
        message_vision(HIC"$N兩腳踩在"+obj+"上，咻地一聲快速飛向天際...\n"NOR, me);
        if( !me->move(environment(ob)) ) {
            tell_object(me, obj+"出問題啦！快點送場維修吧。\n");
            return;
        }
        message_vision(HIC"$N順利的降落在["+name[index]+"]身旁。\n" NOR, me);
        return;
    }
}
