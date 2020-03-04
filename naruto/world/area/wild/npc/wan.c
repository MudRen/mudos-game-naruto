#include <npc.h>

inherit F_VILLAGER;

void to_do_say()
{
    do_chat( ({ 
        (: command, "say ���r�r�� �����F�O�A�u�����ڡI" :),
        (: command, "say ����ɭԤ~��i�ɰڡ�" :),
    }) );
}

void create()
{
    set_name("���D�Y" , ({ "bu she wan", "wan" }) );
    set("long", "�@��ݰ_�Ӧ��F�@�I�~���A�B���y���g�ɮ᪺�Pı�C\n");

    set_level(45);

    set("gender", "male");
    set("title", "�u�ӴN���v" );
    set("age", 62);

    // �@��ɰʧ@
    set("chat_chance", 3);
    set("chat_msg", ({
        (: to_do_say :),
    }) );

    setup();

}

void relay_say(object ob, string arg)
{
    if( arg == "�i��" || arg == "��" || arg == "����" || arg == "�L��" || arg == "�ħ�")  {
        do_chat( ({ 
            (: command, "say ���^�o�X�Y���n���ڸɸɨ��l�A��򳣨S�����R�C" :),
        }) );
        return;
    }
}
