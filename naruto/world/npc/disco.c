#include <npc.h>

void create()
{
    set_name("迪斯可", ({ "disco" }));
    set_race("human");
    set_level(1);
    set("age", 27);
    set("long", "香波地職業介紹所(人口販子)的老闆，但是在幕後還有一位大老闆
                 就是世界政府任可海賊「七武海」中的「唐吉訶德·多佛朗明哥」\n");
    setup();
}
