#include <npc.h>
#include <ansi.h>

void to_do_say()
{
    do_chat( ({ 
        (: command, "say �o�̭쥻�u�O���ǳW�\�H�Ȧ��a��C" :),
        (: command, "say ��ӱڪ��������y�H��|�b�o�}�P�Ҹճ��a�C" :),
        (: command, "say ��M�������L�̺θ���a�I�N�ܦ����]�աI" :),
        (: command, "say �������綠�D��I������i�H�V�ڸ߰ݡu��J�v" :),
        (: command, "snicker" :),
    }) );
}
void create()
{
    set_name("�\��" , ({ "bow line", "line" }) );
    set_race("human");
    set("long", "�Ʊ�C�ѳ��p�|�P���Ҥ@������A�G�����W�C\n");
    set_level(40);
    set("gender", "male");
    set("camp", "bow");
    set("nickname", "���]����" );
    set("age", 60);
    // �@��ɰʧ@
    set("chat_chance", 1);
    set("chat_msg", ({
        (: to_do_say :),
    }) );
    setup();
}
void relay_say(object ob, string arg)
{
    if( arg == "��J" )  {
        do_chat( ({
            (: command, "wink " + this_player()->query("id") :),
            (: command, "say �@�ӬO�����ǥǳW���\�H���աC" :),
            (: command, "say ��M���i�൹�ȤH����I" :),
            (: command, "lick" :),
            (: command, "say �p�G�Q��J�𮧡A�_�X�Ȧ�n��10000��Ȥl��I" :),
            (: command, "say �M���z����(lodging)�N�i�H�աI" :),
            (: command, "say �u�n�����I�����w��I" :),
        }) );
        return;
    }
}
