inherit ROOM;

void create()
{
        set("short", "決鬥之地");
        set("long", @LONG
豹人族在第三代族長時就定下規則：「在平常時間不可隨意與人
比武或打架，凡是犯規者，罰至轟天瀑布修練五十天，且不得參與任
何的打獵活動。」唯一例外的便是在這巨大的比武場中決鬥，在此處
豹人便可以全力的與對方戰鬥。
LONG);
    set("exits", ([
        "east" : __DIR__"pk07.c",
        "north" : __DIR__"pk01.c",
        "south" : __DIR__"pk11.c",
    ]));
        setup();
}
