#include <npc.h>
#include <ansi.h>

inherit F_VILLAGER;

void create()
{
    set_name("���]���l", ({ "Gold Child", "child" }));
    set("nickname",HIC"�^�Ѵ��]"NOR);
    set("title",HIY"���s�Ȥs"NOR);
    set_race("human");
    set_level(10+random(5));
    set("age", 10);
    set("long", "��������a�Ȫ��A�@�ݴN���D�O�����H�a���p�ġC\n");
    set("set_drop", ({
        ([ "type":"obj", "id":28, "amount":1000, "p1":100, "p2":100 ]),
    }) );
    set("chat_chance", 6);
    set("chat_msg", ({
        (: random_move :),
        CYN"���]���l���W�������ϥ����A�������C\n"NOR,
    }));
    set("chat_chance_combat", 30);
    set("chat_msg_combat", ({
       (: command, "help!" :),
       (: random_move :),
    }) );
    setup();
}
int accept_fight(object ob)
{
    do_chat(CYN"���]���l�M�ߪ��Ƶ۶r���A�S�o�{�A���s�b�C"NOR"\n");
    return 0;
}
