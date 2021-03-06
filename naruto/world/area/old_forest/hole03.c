#include <ansi.h>
inherit ROOM;

string *wheres = ({
  MAG"四周噴出一陣紫霧，讓你搞不清楚東南西北...\n"NOR,
  HIB"一道藍色的閃光劃過你的眼睛，讓你腦袋一片混亂...\n"NOR,
  HIW"白色的煙霧彌漫著，根本就沒辦法分清楚位置...\n"NOR,
  HIK"沒有燈火的漆黑洞窟中，伸手不見五指...\n"NOR,
  BLK"噁心的硫磺味被你大量的吸入鼻中，忽然一陣暈眩...\n"NOR,
});

void create()
{
    set("short","洞窟平臺");
    set("long", @long
平臺上往四個方向都有洞穴可以進入，但是連接洞穴的路只是一
條用石臺所搭建的小道要是踩的太大力或是跳歪了，可是會掉到洞底
摔個粉身碎骨呢！也許因為四周太黑了，居然讓你一時間喪失方向感
，如果想離開就趕緊的找繩子吧...應該還在附近才對...
long);
    set("exits", ([
        "north" : __DIR__"hole03.c",
        "south" : __DIR__"hole03.c",
        "east" : __DIR__"hole03.c",
        "west" : __DIR__"hole03.c",
    ]));
    set("detail", ([
        "繩子": HIK"你隱約中好像看到上面有繩子...要爬(climb)看看嗎？"NOR,
    ]));
    set("no_recall", 1);
    setup();
}
void init()
{
    add_action("do_climb", "climb");
}
int do_climb(string arg)
{
    if( arg == "繩子") {
        if( this_player()->is_busy() ) {
            tell_object(this_player(), "你目前無法動彈，不能爬繩子。\n"NOR);
            return 1;
        }
        if( this_player()->query_stat_current("ap") < 100 ) {
            tell_object(this_player(), "你的精神過於疲憊，現在爬繩子太危險了。\n"NOR);
            return 1;
        }
        if( this_player()->query_temp("oldtree") ) {
            message_vision(CYN"$N往空中一跳似乎想抓什麼東西，但是卻抓了個空差點掉到無底深淵中。\n"NOR, this_player());
            tell_object(this_player(), HIR"(你嚇的滿頭冷汗，給予精神極大的壓力！)\n"NOR);
            this_player()->damage_stat("ap", 100);
            this_player()->start_busy(5);
            return 1;
        }
        message_vision("$N往前一跳，剛好抓住繩頭爬了上去。\n", this_player());
        this_player()->move(__DIR__"hole02.c");
        message_vision("$N擦了擦額頭的汗水，從下面爬了上來。\n", this_player());
        return 1;
    }
    return notify_fail("你想爬什麼東西？\n");
}
int valid_leave(object me, string dir)
{
    if( !me ) return 0;
    if( userp(me) && (dir == "west" || dir == "east" || dir == "north" || dir == "south") ) {
        if( me->query_temp("oldtree/west") == 3 && me->query_temp("oldtree/east") == 7 &&
            me->query_temp("oldtree/south") == 1 && me->query_temp("oldtree/north") == 2 ) {

            tell_object(this_player(), HIY"(你的眼前豁然開朗，終於穿過洞穴到達一片叢林！)\n"NOR);
            me->delete_temp("oldtree");
            me->start_busy(1);
            call_out("oldtree", 2, me);
            return notify_fail("");
        } else if( random(20) < 2 ) {
            tell_object(this_player(), HIW"(你走著走著似乎又走回到了起點)\n"NOR);
            me->delete_temp("oldtree");
        } else {
            tell_object(me, wheres[random(sizeof(wheres))]);
            me->add_temp("oldtree/"+dir, 1);
        }
    }
    return ::valid_leave(me, dir);
}
void oldtree(object me)
{
    string area = "/world/area/old_forest/forest1.c";
    me->move(area);
}
