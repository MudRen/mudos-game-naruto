#include <npc.h>

void create()
{
	set_name("流影", ({ "acme" }));
	set_race("human");
	set("age", 20);
	set("title", "火影忍者");
	set("long", "一位來自火影忍者的大神。\n");
	set("no_fight", 1);
	set("chat_chance", 3);
	set("chat_msg", ({
		(: random_move :),
	}));
	setup();
}