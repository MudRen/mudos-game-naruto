#include <npc.h>
#include <ansi.h>

inherit F_VILLAGER;

void create()
{
    set_name("�g�۲��v" , ({ "wizard" }));
    set("long", "����D�`�_�Ǫ��H�A�⮳�ۤ@���s�s����������C\n");
    set_level(40);
    set("gender","male");
    set("age",20+random(50));
    // �@��ɰʧ@
    set("chat_chance", 6);
    set("chat_msg", ({
        (: command, "say �ǯQ�ʭ��ԩI..." :),
        (: command, "say �����ή����ռK..." :),
    }) );
    set("set_drop", ({
        ([ "type":"food", "id":40, "amount":1+random(4), "p1":70, "p2":100 ]),  // ���G
        ([ "type":"food", "id":38, "amount":1+random(2), "p1":20, "p2":100 ]),  // ��G
        ([ "type":"food", "id":39, "amount":1+random(1), "p1":20, "p2":100 ]),  // ���G
        ([ "type":"food", "id":41, "amount":1, "p1":10, "p2":100 ]),            // ���G��
        ([ "type":"eq", "id":71, "amount":1, "p1":1, "p2":100 ]),               // ��
    }));
    setup();
}
