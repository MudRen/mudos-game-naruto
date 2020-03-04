#include <npc.h>
#include <ansi.h>

inherit F_BANDIT;

void create()
{
    set_name("�y�H", ({ "hunter" }) );
    set_race("human");
    set_level(15);
    set("long", "�b�˪L���M�k����������i�c�y�H�C\n");
    set("age", 20+random(30));
    set("gender", "male");
    set("attitude", "aggressive");
    set("chat_chance_combat", 10);
    set("chat_msg_combat", ({
         CYN"�y�H�𪺪����}�C\n"NOR,
         (: command, "say �i�c�������I�S��ڪ��~�����a�F�C":),
         (: command, "say ���}�I�O�׸��I" :),
    }) );
    set("set_drop", ({
        ([ "type":"obj", "id":29, "amount":51+random(10), "p1":50, "p2":100 ]),  // �Ȥl
        ([ "type":"obj", "id":30, "amount":1, "p1":5, "p2":100 ]),    // �¥��U
        ([ "type":"wp", "id":10, "amount":1, "p1":10, "p2":100 ]),    // �ñ�
    //  ([ "type":"obj", "id":??, "amount":1, "p1":10, "p2":100 ]),   // ���~��
    //  ([ "type":"wp", "id":??, "amount":1, "p1":5, "p2":100 ]),     // �Ӻֺj
    }) );
    setup();
}
