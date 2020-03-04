#include <ansi.h>
#include <npc.h>

inherit F_SEABANDIT;

void create()
{
    set_name("�d�}��", ({ "cadina" }) );
    set_race("human");
    set_level(25);
    set("title",HIR"�T���"NOR);
    set("nickname", "����");
    set("gender", "male");
    set("class","thief_sea");
    set("camp", "robber");
    set("age", 21);
    set("long", "���I�D�D���������A�ݥL���m���޲�ޥ��A���ӬO�����a�C\n");
    set("chat_chance", 3);
    set("chat_msg", ({
        (: command, "say �ޡI���S���o�{����q���H�I" :),
        (: command, "say �W�����Ӯq���䤣��F...�ܦh�u���s�v�����y��..." :),
        (: command, "peer" :),
    }));
    set("set_drop", ({
        ([ "type":"wp", "id":15, "amount":1, "p1":70, "p2":100 ]),        // ���z
        ([ "type":"wp", "id":57, "amount":1, "p1":70, "p2":100 ]),        // ���e
        ([ "type":"wp", "id":39, "amount":1, "p1":25, "p2":100 ]),        // �n�j
        ([ "type":"wp", "id":42, "amount":1, "p1":35, "p2":100 ]),        // ���j
    }) );
    setup();
    carry_object("/world/area/thorn_pine/npc/wp/thorn_lance.c")->wield("twohanded");
}
void relay_say(object ob, string arg)
{
    if( arg == "���s" )  {
        do_chat(({
            (: command, "shrug" :),
            (: command, "say �ڤ]����������A�ܤ[�H�e�ڭ̨�L�@�Ӥ��s�q���C" :),
            (: command, "say ��ɲ���W����u�����S�_�áA�j�ٴN�{�H�F�C" :),
            (: command, "say ���L�W���h�L���`�M����j�S�X�ѡC" :),
            (: command, "say ����N�@���n�ۭn��o�y�q�C" :),
            (: command, "say ���L���y�q�p���Ծ����s�ڥh�����..." :),
            (: command, "sigh" :),
        }));
        return;
    }
}
