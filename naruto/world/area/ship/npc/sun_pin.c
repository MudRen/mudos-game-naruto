#include <ansi.h>
#include <npc.h>

inherit F_SEABANDIT;

void create()
{
    set_name("�~��", ({ "pin ke", "pin", "ke" }) );
    set_race("human");
    set_level(30);
    set("title",HIR"�T���"NOR);
    set("nickname", "¼�G�l���");
    set("gender", "male");
    set("class","thief_sea");
    set("camp", "robber");
    set("age", 45);
    set("long", "�y�W�����s�뫬���GŽ�A�@�y��˦��G�O�T������Ϊ�����C\n");
    set("chat_chance", 3);
    set("chat_msg", ({
        (: command, "say ť�����`�M�������������]�_�I�ڥ��b�Q��k�i�h�I" :),
        (: command, "angry" :),
    }));
    set("set_drop", ({
        ([ "type":"wp", "id":2, "amount":1, "p1":25, "p2":100 ]),         // �j�M
        ([ "type":"wp", "id":12, "amount":1, "p1":1, "p2":100 ]),         // �尨�j�M
        ([ "type":"wp", "id":69, "amount":1, "p1":10, "p2":100 ]),        // ���M
    }) );
    setup();
    carry_object("/world/area/wild/npc/wp/blade.c")->wield();
}
void relay_say(object ob, string arg)
{
    if( arg == "���`�M��" )  {
        do_chat(({
            (: command, "hehe" :),
            (: command, "say ���M���W���y�Ѭi���D�ܡH�I" :),
            (: command, "say �j�a����q��u�n���q���N�|�������a�I" :),
            (: command, "say ���L���W�������ӱj�F�I�ڥ��S�F��i�H��I" :),
            (: command, "say �̪�o���ڧ��@�˪F��@�w�i�H�I" :),
            (: command, "say �Q���D�ܡH�~���i�D�A�I" :),
        }));
        return;
    }
    if( arg == "�]�_" )  {
        do_chat(({
            (: command, "think" :),
            (: command, "say ť���O������٬Oԣ��..�ϥ����ӫܭȿ��I" :),
            (: command, "say ���M�]���|�@��H�m�ۭn�I" :),
        }));
        return;
    }
}
