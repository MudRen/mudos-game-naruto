#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("�C�~�k�l", ({ "man" }));
    set_race("human");
    set_level(1);
    set("age", 21);
    set("long", "�ѭ��𮧪��k�l�A�u���L�@�y���P����s�ѽL�A�èS�o�{�A����ӡC\n");
    set("gender", "male");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: command, "think" :),
        CYN"�C�~�k�l���_�դl��b�ѽL�W�A�S�n�n�Y��դl���^�C\n"NOR,
        CYN"�C�~�k�l���_�¤l��b�ѽL�W�A�S�n�n�Y��¤l���^�C\n"NOR,
        (: command, "ah" :),
    }));
    setup();
}
int relay_say(object me, string arg)
{
    if( !objectp(me) || !stringp(arg) ) return 0;

    if( arg == "�T��" ) {
        do_chat(({
            (: command, "say �T��C�z�o�Ӧr�����Ӧ�ť�L�a�C" :),
            (: command, "say �@�ӤH����Ŧ���O�ѤT��C�z�Ҳզ��C" :),
            (: command, "say �z�]�����E�O���j�A�ƶq�]����h�A�ҥH���ҷl���|�۰ʭ׸ɡC" :),
            (: command, "say ��L�k�ۧڭ׸ɡA�S�e�����h�C" :),
            (: command, "say �ҥH�`�`�H�|���u��~���F�v�B�u�����v���O�o�˨Ӫ��C" :),
            (: command, "say �T��H�߻���A�t�~���u�O���U�C" :),
            (: command, "say �]�u���߻���������L��z�C" :),
            (: command, "say �@�Ǧ�ͨ��ת��ͪ��A�j�h���O���h�F�߻�C" :),
        }));
    }
    if( arg == "�s�Ťj��" ) {
        do_chat(({
            (: command, "say �s�Ťj���O�@�����s�C" :),
            (: command, "say �쥻���e�u�O�@�����D�}�F�C" :),
            (: command, "say ���L�]���׹D�����A�Q�����޲z�o���~�˪L�Ĥ@�h�C" :),
            (: command, "say ���e�޲z�o��A���O�̪�n��ť���˪L���I����..." :),
        }));
    }
    if( arg == "���" ) {
        do_chat(({
            (: command, "say �o�O�@���������C" :),
            (: command, "say �i�H�Ψ��X�ϧC�{�ת�����C" :),
            (: command, "say ���إs�u�ܤ��]�v�����ǫD�`���w�o�˪F��C" :),
        }));
    }
    if( arg == "�ܤ��]" ) {
        do_chat(({
            (: command, "say �M�����H��z�����ǡC" :),
            (: command, "say �ڻ��]�k��O�D�`�����A���w�ݦb�R���F��a��C" :),
            (: command, "say ���e���gť�����H�b���`�M�����ݹL�e�C" :),
        }));
    }
    return 1;
}
