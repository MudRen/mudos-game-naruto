#include <npc.h>
#include <ansi.h>

inherit F_VILLAGER;

void create()
{
    set_name("����", ({ "fe" }));
    set_race("human");
    set_level(15);
    set("age", 20);
    set("nickname",HIR"����"NOR);
    set("long", "�L�G�N��ۤv�˧ꦨ�ª��|���ˤl�A���O�o�@�I�]�����C\n");
    set("gender", "male");
    set("chat_chance", 3);
    set("chat_msg", ({
        (: command, "say �ڪ����U�j�a����J�ª��|�S�e�~��" :),
        (: command, "sing" :),
    }));
    setup();
}
