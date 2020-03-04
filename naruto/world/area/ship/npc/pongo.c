#include <ansi.h>
#include <npc.h>
#include "bandit.h"

inherit F_SEABANDIT;

void create()
{
    set_name("�H��", ({ "pongo" }) );
    set_race("human");
    set_level(45);
    set("title",HIY"��s�s�X"NOR);
    set("nickname",HIC"������"NOR);
    set("gender", "male");
    set("class","thief_sea");
    set("camp", "robber");
    set("age", 35);
    set("long", "�����@�y��U�ˡA�S�ƴN�\�X�U�˧s�s�s�C�L���W��ۤ@��Q�a�ǡA\n"
                "�W���e�ۤ@���U�l�٦��u�������v���r�ˡC\n");
    set("chat_chance", 5);
    set("chat_msg", ({
        (: command, "say �����٨S��������I��s�s�I" :),
    }));
    set("set_drop", ({
        ([ "type":"obj", "id":28, "amount":2+random(4), "p1":30, "p2":100 ]),  // ����
        ([ "type":"eq", "id":101, "amount":1, "p1":1, "p2":100 ]),             // �Q�a��
        ([ "type":"eq", "id":102, "amount":1, "p1":1, "p2":400 ]),             // ��U�@�L
        ([ "type":"eq", "id":35, "amount":1, "p1":50, "p2":100 ]),             // ������
        ([ "type":"eq", "id":13, "amount":1, "p1":20, "p2":100 ]),             // �g������
    }) );
    setup();
    add_temp("apply/attack", 100);
    add_temp("apply/armor", 300);
}
