#include <npc.h>

inherit F_VILLAGER;

void create()
{
        set_name("�ƾm�ҤH", ({ "hua tuo", "tuo" }) );
        set_race("human");
        set_level(20);
        set("title","�~��");
        set("age", 70);
        set("long", "�~��A�@�A��N�������A�L���Ĥ��L�ƺءA�w�b���L�ƳB�A�h�H���¡�C\n");

        setup();
}
