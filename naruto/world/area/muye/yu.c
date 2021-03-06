/* write by -Acme- */
#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "油女家");

    set("long", @long
這裡是木葉村的油女家。
long);

    set("exits", ([
        "south" : ([ "filename": __DIR__"muye.c",
                     "x_axis": 17,
                     "y_axis": 18,
                  ]),
    ]));

    set("objects", ([
        __DIR__"npc/nai.c": 1
    ]) );

    setup();
}

int valid_leave(object me, string dir)
{
    object bug;
    int x, y, j;

    if( !me ) return 0;

    j = 10 + random(16);

    if( me->query_temp("bug_exit") && dir == "south" ) {
        if( userp(me) ) tell_object(this_player(), HIK"你想要逃走卻撞上了門口的【"HIM"蟲之壁"NOR"】"HIK"！還有不少蟲爬進了你身上！\n"NOR);
        if( bug = present("_GI_BUG_", me) ) {
            bug->add_amount(j);
        } else {
            if( file_size(__DIR__"npc/item/gi_bug.c") < 0 ) return ::valid_leave(me, dir);
            if( catch(bug = new(__DIR__"npc/item/gi_bug.c")) ) return ::valid_leave(me, dir);
            if( !bug->move(me) ) {
                destruct(bug);
            } else {
                bug->set_amount(j);
                bug->set_owner(me);
                bug->set("changed", 1);
            }
        }
        return notify_fail("這個方向沒有出路。\n");
    }
    return ::valid_leave(me, dir);
}
