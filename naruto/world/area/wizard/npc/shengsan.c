#include <npc.h>

void create()
{
	set_name("���Ū���", ({ "shengsan" }));
	set_race("human");
	set("age", 30);
	set("title", "�ڤۤC��");
	set("long", "�@��Ӧ۹ڤۤC�쪺�j���C\n");
	set("no_fight", 1);
	set("chat_chance", 3);
	set("chat_msg", ({
		(: random_move :),
	}));
	setup();
}