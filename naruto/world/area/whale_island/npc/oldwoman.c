#include <npc.h>

inherit F_VILLAGER;

void create()
{
    set_name("�ѱC�C", ({ "old woman", "woman" }));
    set_race("human");
    set_level(5);
    
    set("long", "�ѱC�C�_�ӷT�ܭW�y���A�n��������дo�@�ˡC\n");

    set("age", 70);
    set("gender", "female");
    
    // �@��ɰʧ@
    set("chat_chance", 1);
    set("chat_msg", ({
        (: command, "say ���I��|�������O�͡A�����n�ި줰��ɭ�.." :),
    }) );

    setup();
}
