#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("ű�j�v", ({ "found master", "master" }) );
    set_race("human");
    set_level(50);
    set("age", 35);
    set("long", "���ۨ��K�S�X�������٦סA�W���G�ۨ��Ҫ����{�C\n");
    set("chat_chance", 2);
    set("chat_msg", ({
        CYN"ű�j�v�V���۪Z���C\n"NOR,
        (: command, "say �X�����u�Z���v���`�O�R���쪺�C" :),
        (: command, "say �Q���D�u�X���v���ޥ��ܡH" :),
    }));
    setup();
}
void relay_say(object ob, string arg)
{
    object item;

    if( arg == "�X��" )  {
        do_chat(({
            (: command, "nod" :),
            (: command, "say �X���A²�满�N�O�j�Ƥ@��Z���A�b�Z���W�ĤW�s���X���C" :),
            (: command, "say ���L�@���ϥαj�ƨ��b���Z�����ӻݭn�Ψ�o�ا޳N�C" :),
            (: command, "say �ҥH�ثe�ӻ���ϥγo�ا޳N���Z���i�H���O�֤��S�֡C" :),
            (: command, "lick" :),
            (: command, "say �X�������n��S�w���u�@�Ǥ��~��i��C" :),
            (: command, "say �ڳo�̤]���@���u�@�ǡA���O�H�h�_�ӥi�O�S��k�P�ɦX�����C" :),
            (: command, "say �X���ݭn�Ψ�@�ǯS�O���q���A�����q�������ԡC" :),
            (: command, "think" :),
            (: command, "say �Ķ����a�I�O��{����s�}���A���̧t���״I���q���귽�C" :),
            (: command, "say �Q�n�Ķ��q����M���i��{����A�ݭn�ϥίS��u��u�Q�r��v" :),
            (: command, "say �S�O�����ܤ츭���K�Q�n������...�Ӥ[�S�h���I�ѰO�F�C" :),
            (: command, "say �]���{�b����N�u�h���ګ��q�F..." :),
            (: command, "blush" :),
        }));
        return;
    }
    if( arg == "�Z��" )  {
        do_chat(({
            (: command, "qk" :),
            (: command, "say �X���Ϊ��Z���A���������ܦX���ɪ����šC" :),
            (: command, "say �@��ڭ̩һs�@���Z�������A�X�C" :),
            (: command, "say ���L�o�����X���Z���A�o�]�]�������b���\�Τ���o���C" :),
            (: command, "say �i�H���O���Q�����C" :),
            (: command, "shrug" :),
            (: command, "say �ڤ]�u���X�ӤH�X���L�Z���C" :),
            (: command, "say �N�کҪ��A�L�̪��Z�����O�Ӧ۩�g�ۧ��̡C" :),
            (: command, "say ���L�ڤ]���L��j�άO�}�����g�۪Z���չL�A���G�`�O���Ѫ��C" :),
            (: command, "say ���ڤ��T�h�è��ǪZ�����X�B�C" :),
            (: command, "stare" :),
        }));
        return;
    }
}
