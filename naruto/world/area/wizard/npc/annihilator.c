#include <npc.h>

void create()
{
	set_name("���`�p�S", ({ "annihilator" }));
	set_race("human");
	set("title", "�Ѵ«Ұ�");
	set("age", 30);
	set("long", "�@��ӦۤѴ«Ұꪺ�j���C\n");
	set("no_fight", 1);
	set("chat_chance", 3);
	set("chat_msg", ({
		(: random_move :),
	}));
	setup();
}