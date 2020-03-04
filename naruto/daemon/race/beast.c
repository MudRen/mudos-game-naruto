// beast.c

#define BASE_WEIGHT 10000

#include <ansi.h>
#include <statistic.h>
#include <race.h>

inherit HUMANOID;

string *combat_actions = ({
    "$N���W�ӱi�L��$n$l�r�h",
    "$N��$n$l���F�L�h�A�i�L�K�r",
    "$N�Τ��l��$n$l�����@��",
    "$N�h�����L�A�Ĥ��U���a��$n$l�����@�r",
});

string query_action()
{
    return combat_actions[random(sizeof(combat_actions))];
}

void create()
{
    ::create();

    seteuid(getuid());

    set("unit", "��");

    set("gender", "male-animal");

    set("limbs", ({ "�Y��", "����" }) );

    set("default_actions", (: call_other, __FILE__, "query_action" :) );

    DAEMON_D->register_race_daemon("beast");
}

void setup(object ob)
{
    ::setup(ob);

	ob->set_default_object(__FILE__);
	
	if( !ob->query_weight() ) ob->set_weight(BASE_WEIGHT);
}

void initialize(object ob)
{
    seteuid(geteuid(ob));

    if( !ob->query("age") )
	ob->set("age", 1);
    ob->set_default_object(__FILE__);
}
/*
// ���~�O���|���Z����
int valid_wield(object me, object ob, string skill) { return 1; }

// ���~�O���|�慨�㪺
int valid_wear(object me, object ob, string part) {	return 1; }
*/
