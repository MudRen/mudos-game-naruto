#include <ansi.h>
#include <npc.h>

void create()
{
    set_name(HIY"金．富力士"NOR, ({ "king fulishi", "fulishi", "king"}) );
    set_race("human");

    set_level(99);
    set("long", @long
金．富力士是整個世界最頂級的三星獵人，除了他是高超的念能力者
，他對於人類社會的貢獻及成就，都是古往今來沒有任何人能比得上的偉
大人物。
long
);

    setup();
}

