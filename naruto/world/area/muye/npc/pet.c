// write by -Acme-
/* pet.c �d���G�Ԥ� */

#include <ansi.h>
#include <npc.h>

inherit F_VILLAGER;

void create()
{
    set_name("�p��", ({ "dog" }));
    set_race("beast");
    set_level(1);
    set("no_fight", 1);
    set("age", 1);
    set("long", "�N�Юa�i�����C\n");
    setup();
}

int follow_me(object ob, string dir)
{
	object leader;
    this_object()->add("move_count", 1);
    if( objectp(leader = this_object()->query_leader()) )
        leader->start_busy(2);
    return ::follow_me(ob, dir);
}
