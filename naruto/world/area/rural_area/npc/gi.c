#include <npc.h>
#include <ansi.h>

inherit F_VILLAGER;

void create()
{
    set_name("����", ({ "gi" }));
    set_race("human");
    set_level(15);
    set("age", 21);
    set("nickname",YEL"�@��"NOR);
    set("long", "�L�G�N��ۤv�˧ꦨ�ª��|���ˤl�A���O�o�@�I�]�����C\n");
    set("gender", "male");
    set("chat_chance", 3);
    set("chat_msg", ({
        (: command, "say �ڪ��򵹤j�a����d�U�O�V�ª��|��" :),
        (: command, "sing" :),
    }));
    setup();
}
