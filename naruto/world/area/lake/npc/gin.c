#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("��}�l", ({ "fonton gin", "gin" }) );
    set_race("human");
    set("gender", "male"); 
    set_level(1);
    set("age", 30);
    set("long", "���Y�鸣���ˤl�A�@�ݴN�@�Ʀl�ˡC\n");
    set("chat_chance", 7);
    set("chat_msg", ({
       (: command, "say ���ӥj���ӤH�ӥi�c�F�I�~�M�Q�|�ڪ����I" :),
       (: command, "say �o�i�_�Ǫ��ȬO�ڤU���h�n���e���~��쪺�ȡI" :),
       (: command, "say ���ӥj���ӤH�~�M���O�o�ȡI�٥s�ڽ�L�@��Ȥl�I" :),
       (: command, "say �o�}��~�פ@�פ]�i�H��Ӧn�����I���j���ӤH�~�M�����I" :),
    }));
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
       (: command, "say �z�I���H���I" :),
    }));
    set("set_drop", ({
        ([ "type":"obj", "id":43, "amount":1, "p1":30, "p2":100 ]),     // �H��
        ([ "type":"obj", "id":50, "amount":1, "p1":80, "p2":100 ]),     // ������
    }) );
    setup();
}
void relay_say(object ob, string arg)
{
    if( arg == "�_�Ǫ���" || arg == "�o��" || arg == "��" )  {
        do_chat(({ 
           (: command, "say �A�]�Q�n�ȶܡH" :),
           (: command, "say �ڴN�������A�I" :),
           (: command, "cac" :),
           NOR"��}�l���D�R"HIG"����ڦ��o�i���n���Ȫ���\n"NOR,
           NOR"��}�l���D�R"HIG"����ڴN�O�����A����\n"NOR,
           (: command, "jump" :),
           NOR"��}�l���D�R"HIG"����ڦ��o�i���n���Ȫ���\n"NOR,
           NOR"��}�l���D�R"HIG"����ڴN�O�����A����\n"NOR,
           (: command, "jump" :),
           NOR"��}�l���D�R"HIG"���ڪ���³J��\n"NOR,
        }));
    }
    if( arg == "�}��~" )  {
        do_chat(({ 
           CYN"��}�l�n�F�n�����C\n"NOR,
           (: command, "say �j�H���������I" :),
           (: command, "say �}�i�}�A�D�`�}" :),
           (: command, "say �A���}�F�A�ڪ��i�S�}" :),
           (: command, "say �A�S�ݹL�A��򪾹D�ڪ���~�}���C" :),
           (: command, "think" :),
           NOR"��}�l���D�R"HIG"��F��ڤ@��Ū�ѤH����A�n�o�Ӹ��D��\n"NOR,
           (: command, "gy" :),
        }));
    }
}
int accept_fight(object ob)
{
    do_chat(NOR"��}�l���D�R"HIG"���N���D�A�����ʤ�㫢�����I"NOR"\n");
    return 0;
}
