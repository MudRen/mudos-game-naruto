#include <ansi.h>
#include <npc.h>

inherit F_VILLAGER;

void create()
{
    set_name("伊乃森喜比", ({ "bi" }));
    set_race("human");
    set_level(60);
    set("camp", "muye");
    set("long", "為木葉的審判監獄長，擅長利用心理戰，問出讓人無法抉擇的問題，\n"
                "使其犯人陷入精神的痛苦中。\n");

    set("age", 27);
    set("gender", "male");
    setup();
}
