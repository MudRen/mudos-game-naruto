// vagabond.c

#include <npc.h>

inherit F_BANDIT;

void create()
{
    set_name("�����L��", ({ "vagabond" }));
    set_race("human");
    set_level(8);

    set("age", 24+random(20));
    set("long", "�@�Ӻ��y���ۡA�c��c�����L��~�A�̦n�O�a�L�Ӫ�C\n");
    set("chat_chance", 6);
    set("chat_msg", ({
        "�L��~�u�K�K�v�a�ǯ��ۡA�@�䤣�h�n�N�a�n�ۧA�C\n",
        "�L��~�˧@�Y�L��ƪ��ˤl����A����A�M��X�䤣�N�a���A�@�U�C\n",
        "�L��~�Ϋ����ߪ��覡��F���ˡA�M�᩹�A�o��@�u ... �ָ��I\n",
    }));

    set("set_drop", ({
        ([ "type":"obj", "id":29, "amount":26+random(10), "p1":50, "p2":100 ]),  // �Ȥl
        ([ "type":"eq", "id":7, "amount":1, "p1":10, "p2":100 ]),     // ����
    }) );

    setup();

    carry_object(_DIR_WP_"radish.c")->wield();
    carry_object(_DIR_WP_"radish.c")->wield("lefthand");
}
