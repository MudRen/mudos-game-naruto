#include <npc.h>

inherit F_VILLAGER;

void create()
{
    set_name("�w���H", ({ "man" }));
    set_race("human");
    set_level(10);
    
    set("long", "�@�ӥ���������w�b���l�̪��H�C\n");
    set("camp", "muye");
    set("age", 21+random(30));
    set("gender", "male");
    
    // �@��ɰʧ@
    set("chat_chance", 1);
    set("chat_msg", ({
        (: command, "say �j�N�˪L��������O�@�ʿ���������������C" :),
        (: command, "say ť���b�j�N�˪L�̦�ۤ@�s�֦����_�k�N�����v�C" :),
        (: command, "say �M�ӳo�ǲ��v�֦��ί���s�@�����C�C" :),
    }) );

    setup();
}
