#include <ansi.h>
#include <npc.h>

inherit F_SEABANDIT;

void create()
{
    set_name("�֨�", ({ "lays" }) );
    set_race("human");
    set_level(25);
    set("title",HIR"�T���"NOR);
    set("nickname", "���v");
    set("gender", "male");
    set("class","thief_sea");
    set("camp", "robber");
    set("age", 25);
    set("long", "�f���ð�@�q�A����J�ä񹺡A���ӬO��ԣ�����|���_�P���v�C\n");
    set("chat_chance", 3);
    set("chat_msg", ({
        (: command, "say ��H�ڪ��t�g�����h�F�H" :),
        (: command, "say �V�|...��ůȤS�֥Υ���..." :),
        (: command, "say �����D�o�y���n�U�Y�O����N��..." :),
    }));
    set("set_drop", ({
        ([ "type":"wp", "id":9, "amount":1, "p1":79, "p2":100 ]),         // �ڽ�
        ([ "type":"wp", "id":21, "amount":1, "p1":1, "p2":1500 ]),        // �����
        ([ "type":"wp", "id":43, "amount":1, "p1":10, "p2":100 ]),        // ����
    }) );
    setup();
    carry_object("/world/wp/pairrod.c")->wield();
}
