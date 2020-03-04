#include <npc.h>
#include <ansi.h>

void do_fight()
{
    object enemy;

    // �S���ĤH
    enemy = this_object()->query_opponent();
    if( !enemy ) return;

    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    if( this_object()->query_leader() != enemy ) {
        this_object()->set_leader(enemy);
        message_vision("$N�M�w�}�l���H$n�@�_��ʡC\n", this_object(), enemy);
    }
}
void create()
{
    set_name("���ѵU", ({ "fly monkey", "monkey" }) );
    set_race("beast");
    set_level(20);
    set("long", "���F�ͻH���U�l�A����]�����q���ӲӪ��C\n");
    set("limbs", ({ "�U�Y", "����", "����", "�U�u", "�ͻH" }) );
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");         // �D�ʧ���

    // �H������
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));

    // �԰��ʧ@
    set("chat_chance_combat", 80);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );

    setup();
    add_temp("apply/attack", 20);
}
