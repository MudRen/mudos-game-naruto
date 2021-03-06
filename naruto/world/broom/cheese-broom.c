#include <ansi.h>

inherit ITEM;

#define MAX 3   /* 能記憶的數量 */

string *path = allocate(MAX);
string *name = allocate(MAX);
int *x = allocate(MAX);
int *y = allocate(MAX);

void create()
{
        set_name(HIY"起司飛天掃帚"NOR, ({ "cheese flying broom", "broom"}));

        set_weight(3);
        if( !clonep() ) {
                set("unit", "根");
                  set("value", 40000);
                set("long",@LONG
這是一根由大神以魔法創出來的飛天掃帚，你可以使用它快速地移動到任
何你想去的地方，當然，前提是你必須要先記住(remember)要去的目的地。由
於飛天掃帚被製造時的魔法效果不一，所以擁有不同程度的記憶能力，有些只
能記錄二個地點，有些卻能記錄六個地點以上，記憶能力越高的掃帚，當然越
是價值連城。

指令格式：
remember [id] : 將你目前的所在地記錄在第id個編號
remember      : 列出每一個id所記錄的目的地
move [id]     : 移動到你之前第id個編號所記住的所在地

LONG
);
        }
        setup();
}

void init()
{
        add_action("do_move", "move");
        add_action("do_remember", "remember");
}

//void moveTo(string files, int x, int y);
void moveTo(int index);

int do_remember(string arg)
{
        if( !arg ) {
                int i;
//                string msg = "ID: 地點\n";
        string msg  = "╭────────────────────────────╮\n";
                msg += sprintf("│"BRED"%|4s"NOR" "BBLU"%|50s"NOR" │\n", "編號", "地點");
                for(i=1;i<=MAX;i++) {
                        if( !stringp(path[i-1])) {
//                                msg += sprintf("%2d: [無]\n", i );
                msg += sprintf("│%|4d %-50s │\n", i, "[無]");
                        } else {
//                                msg += sprintf("%2d: %s at (%3d,%3d)\n", i, name[i-1], x[i-1], y[i-1] );
                msg += sprintf("│%|4d %-50s │\n", i, name[i-1] + " (" + x[i-1] + "," + y[i-1] + ")");
                        }
                }
        msg += "╰────────────────────────────╯\n";
                tell_object(this_player(), msg );
        } else {
                string file;
                int id;
                object me = this_player();
                if(sscanf(arg, "%d", id) != 1 || id < 1 || id > MAX ) return notify_fail("不正確的id編號。\n");  
                if( !environment(me)->is_area() ) return notify_fail("你無法記錄目前所處的地點。\n");
            if( environment(me)->query("no_recall") == 1 ) return notify_fail("這個位置不能記憶。\n");
                file = base_name(environment(me)) + ".c";
                path[id-1] = file;
                name[id-1] = environment(me)->query("name");
                x[id-1] = me->query("area_info/x_axis");
                y[id-1] = me->query("area_info/y_axis");
                write("你仔細將四週的景色記了下來。\n");
        }
        return 1;
}

int do_move(string arg)
{
        int id;
        if( !arg ) return notify_fail("你想要移動到什麼地方？\n");
        if( sscanf(arg, "%d", id) != 1 || id < 1 || id > MAX ) return notify_fail("不正確的id編號。\n");        
        if( !stringp(path[id-1]))  return notify_fail("這個id編號並沒有記錄到任何地點。\n");
        if( this_player()->is_busy() || this_player()->is_fighting() ) return notify_fail("你正忙著，沒有空移動。\n");
        moveTo( id-1 );
    return 1;
}

//void moveTo(string file, int x, int y) {
void moveTo(int index) {
        string file;
        int xc,yc;
    // goto 到區域 by -Acme-
        object obj;
        object me = this_player();

                file = path[index];
                xc = x[index];
                yc = y[index];
        if( file_size(file) >=0 && (obj=load_object(file)) ) {
        if( !obj->is_area() ) return;
               message_vision(HIW"$N騎上了"+query("name")+ HIW"，咻地一聲往["+name[index]+"]飛去...\n"NOR, me);
                       area_move(obj, me, xc, yc);
               message_vision(HIW"$N騎著"+query("name")+ HIW"飛也似地到了這裡...\n" NOR, me);
                return;
        }
 
       write("因為某些奇怪的原因，你無法移動到那個區域。\n");
}

