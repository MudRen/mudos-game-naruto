#include <npc.h>

void create()
{
	set_name("龍蝦", ({ "luky" }));
	set_race("human");
	set("age", 30);
	set("title", "夢幻七域");
	set("long", "一位來自夢幻七域的大神。\n");
	set("no_fight", 1);
	set("chat_chance", 3);
	set("chat_msg", ({
		(: random_move :),
	}));
	setup();
}