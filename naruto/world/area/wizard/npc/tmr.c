#include <npc.h>

void create()
{
	set_name("�_", ({ "tmr" }));
	set_race("human");
	set("age", 20);
	set("title", "�y�H�@��");
	set("long", "�@��Ӧ��y�H�@�ɪ��j���C\n");
	set("no_fight", 1);
	set("chat_chance", 3);
	set("chat_msg", ({
		(: random_move :),
	}));
	setup();
}