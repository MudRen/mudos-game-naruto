#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",GRN"叢林外側"NOR);
    set("long", @long
樹根纏滿了山洞的外側石壁，除了一條非常糢糊的人為痕跡之外
似乎完全感覺不出這裡曾經有人來過，鳥蟲高聲鳴叫，完全與世隔絕
的叢林。從附近的大樹來看，一棵樹幾乎要數十人才能圍抱住，可見
這應該是非常古老的地方了。
long);
    set("exits", ([
        "north" : __DIR__"hole03.c",
        "south" : __DIR__"forest1.c",
        "west" : __DIR__"forest1.c",
        "east" : __DIR__"forest1.c",
    ]));
    set("no_recall", 1);
    setup();
}
int valid_leave(object me, string dir)
{
    string area = __DIR__"forest"+random(20)+".c";
    object mob;
    if( !me ) return 0;
    if( userp(me) && (dir == "west" || dir == "east" || dir == "south" ) ) {
        me->move(area);
        switch( random(500) ) {
            case 50..105: message_vision(HIR"$N走著走著，四周忽然傳出一陣野獸的暴怒聲！\n"NOR, me);
                          mob = new(__DIR__"npc/sacrier.c");
                          mob->move(environment(me));
                          break;
            case 260..315: message_vision(HIW"嘹亮的號角聲中，白光從茂密的枝葉上破空而下！\n"NOR, me);
                          mob = new(__DIR__"npc/sworder.c");
                          mob->move(environment(me));
                          break;
            case 420..475: message_vision(HIG"綠樹在瞬間變的更加茂盛！但卻伴隨著詭異的笑聲...\n"NOR, me);
                          mob = new(__DIR__"npc/doctor.c");
                          mob->move(environment(me));
                          break;
        }
        return notify_fail("");
    }
    return ::valid_leave(me, dir);
}
