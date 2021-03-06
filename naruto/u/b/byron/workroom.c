#include <ansi.h>
#include <room.h>

inherit ROOM;

void create() 
{
    set("short", "落下孤燈");
    set("long", @LONG
這個地方異常寒冷，什麼也沒有，只有隱隱約約聽到很哀傷的旋律。
LONG);
    set("exits", ([ /* sizeof() == 2 */
       "north"  : "/u/b/byron/workroom2.c",  
       "down"   : "/world/area/jail.c",
       "wizard" : "/world/area/wizard/guildhall",
       "south"  : ([ "filename" : "/world/area/wizard/wizard.c",
                      "x_axis" : 35,
                      "y_axis" : 15, ])
    ]));
    set("no_clean_up", 0);
    setup();
    load_object("/daemon/board/byron");
}
private void goin(string arg, object me)
{
    if( arg != "" ) {
        if( arg[0] == 'y' || arg[0] == 'Y' ) {
            tell_object(me, HIK"\n你正愁沒錢吃飯...決定去監獄吃牢飯。\n"NOR);
            this_player()->move("/world/area/jail.c");
            return;
        } else if( arg[0] == 'N' || arg[0] == 'n' ) {
            tell_object(me, HIW"\n你想了想還是決定不進去了。\n"NOR);
            return;
        }
    }
    tell_object(me, HIR"\n往下走是監獄重地！你確定要進去？"HIW"(Y/n)"NOR);
    input_to("goin", me);
    return;
}
int valid_leave(object me, string dir, string arg)
{
    if( !me ) return 0;
    if( !wizardp(me) && dir == "north" ) {
        return notify_fail("那裡只有巫師才能進去\n");
    }
    if( dir == "down" ) {
        if( !userp(me) ) return 0;
        tell_object(me, HIR"往下走是監獄重地！你確定要進去？"HIW"(Y/n)"NOR);
        input_to("goin", me);
        return notify_fail("");
    }
    return ::valid_leave(me, dir);
}
