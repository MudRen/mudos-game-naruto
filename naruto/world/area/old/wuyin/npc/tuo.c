#include <npc.h>

inherit F_VILLAGER;

void create()
{
        set_name("滑駝夫人", ({ "hua tuo", "tuo" }) );
        set_race("human");
        set_level(20);
        set("title","獸醫");
        set("age", 70);
        set("long", "獸醫再世，醫術之高明，他用藥不過數種，針灸不過數處，多隨手而癒。\n");

        setup();
}
