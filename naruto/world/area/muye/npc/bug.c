#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("�i"HIM"�Τ���"NOR"�j", ({ "bug", "_BUG_WALL_" }));
    set_race("beast");
    set_level(50);
    set("limbs", ({ "�H�a��", "�j�H�a��", "�p�H�a��", "�αH�a��", "��H�a��", "�y�H�a��" }) );
    set("long", "�o�k�ӤD�ҩ�X���H�a�Τ����A���ΩҲզ��C\n");
    set("age", 1);
    set("no_combat", 1);
    set("no_evade", 1);
    setup();
    add_temp("apply/armor", 500);
    add_temp("apply/intimidate", -query_ability("intimidate"));
    add_temp("apply/wittiness", -query_ability("wittiness"));
    add_temp("apply/exact", -query_ability("exact"));
}

void die()
{
    object target;
    object *enemy;
    int ntar, i;

    target = this_object()->last_damage_giver();
    enemy = this_object()->query_enemy();
    ntar = sizeof(enemy);

    if( !target ) return;
    for(i=0;i<ntar;i++) {
        enemy[i]->delete_temp("bug_exit");
    }
    message_vision("\n$N"CYN"�Q���}�A�o�k�ӤD���ξ����N�]�]���Q�}�ѡC\n\n"NOR, this_object());
    return;
}
