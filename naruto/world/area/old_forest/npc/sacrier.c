#include <npc.h>
#include <ansi.h>
#include "wp.h"

void do_fight()
{
    mapping cnd = ([]);

    if( this_object()->query_condition("bladewolf") != 0 ) return;

    message_vision(HIR"\n$N�����x���A��⨳�t�G����Ӳ��W�A�C���C���n�S�A�����z�o�X���~�몺�~�ʡI\n\n"NOR, this_object());

    cnd["name"] = RED"�g��"NOR;
    cnd["duration"] = 600;
    cnd["intimidate"] = 300;
    cnd["evade"] = 0;

    this_object()->damage_stat("mp", 10, this_object());
    this_object()->set_condition("bladewolf", cnd);
    return;
}
void create()
{
    set_name("�g�ۨg�Ԥh", ({ "aborigines sacrier", "sacrier" }) );
    set_level(50);
    set_race("human");
    set("gender", "male");
    set("attitude", "aggressive");
    set("wp_number", 3);
    set("age", 15+random(41));
    set("nickname",HIR"�ݦ�"NOR);
    set("long", "���²�����g�ۡA�S�X�@���i�Ȫ��٦סA�y�W�����a��ʵۡA�f���R\n"
                "�X�զ⪺�𮧡A���p�W�իݵo�����~�C�L�N�O�ǻ������~�����H��\n"
                "�z�ʧ�o�F�A�����ٯ৹���o���~�ʪ����ɨg�Ԥh�C\n");
    set("chat_chance_combat", 80);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    setup();
    add_temp("apply/hp", random(300));
    set_temp("apply/exact", -(50 + random(101)));
    carry_object(__DIR__"wp/lance.c")->wield("twohanded");
    call_out("die_1", 120+random(240), this_object());
    do_heal();
}

void die_1()
{
    message_vision(GRN"$N�ݤF�@�ݥ|�P�A�S���^�O�L���F�C\n"NOR, this_object());
    destruct(this_object());
    return;
}
