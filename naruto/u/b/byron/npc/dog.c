/* dog.c
   write by -Acme-
*/
#include <npc.h>
void create()
{
    set_name("����", ({ "dog" }) );
    set_race("beast");
    set_level(19);
    set("long", "�@��ż�����������A�L���ٺw�ۤf���C\n");
    set("limbs", ({ "���Y", "����", "����", "���L", "����" }) );
    set("verbs", ({ "bite" }) );
    // �H������
    set("chat_chance", 1);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("set_drop", ({
        ([ "type":"eq", "id":5, "amount":1, "p1":10, "p2":100 ]),     // ÷�l
    }) );
    setup();
}

