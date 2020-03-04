#include <npc.h>
#include <ansi.h>

inherit F_VILLAGER;

void to_do_say()
{
    do_chat( ({
        (: command, "say �o�ǻa�����u�O�Ӳs�g�F�C" :),
        (: command, "say �u�����D�ӫ���I�e�̡C" :),
        (: command, "sigh" :),
    }) );
}
void create()
{
    set_name("�\�Y", ({ "bow head", "head", "_BOW_HEAD_" }));
    set_race("human");
    set_level(60);
    set("title","�\�H�ڪ�");
    set("long", "�\�ڪ��ѡA�b�y���������o�a�ۤ@�شd�h�C\n");
    set("age", 80);
    set("camp", "bow");
    set("gender", "male");
    set("chat_chance", 1);
    set("chat_msg", ({
        (: to_do_say :),
        CYN"�n�ȵo�X�n�T...�u��..�v\n"NOR,
    }) );
    setup();
}

int relay_say(object me, string arg)
{
    if( !objectp(me) || !stringp(arg) ) return 0;

    if( arg == "�a����" || arg == "�s�g" ) {
        do_chat( ({
           (: command, "say ����e�N���ڥͮ�C" :),
           (: command, "angry" :),
           (: command, "say �ڦ~�����ɭԴN���@���a�����ӹL�F���r�C" :),
           (: command, "say ���G�Q�H�١u���Ⱚ�Ⱚ����v���ڵ����]�F�C" :),
           (: command, "cac" :),
           (: command, "eh _BOW_HEAD_" :),
           (: command, "say ����..���O�n���o�ӡC" :),
           (: command, "say �O�e�̳̪�~�M�S�]�Ӧ����F���r�C" :),
           (: command, "say �w�g�����ڭ̤��֥h�F���r�׽m���ڤH�F�I" :),
           (: command, "say �ڤ]�ѤF���e�̨S��k�ԡI" :),
           (: command, "say �u�O�����D�ӫ���~�n..." :),
        }) );
        return 1;
    }
    if( arg == "���Ⱚ�Ⱚ����" ) {
        do_chat( ({
           (: command, "?" :),
           (: command, "say ���O�ڦ~���ɭԪ��ƤF�C" :),
           (: command, "say ��~�\�ڳo���٬O���~�������a�ϡC" :),
           (: command, "say ���G�a�����s�Ĥ@����i�ڧ��A�@�ɶ��j�a���L�k��ܡC" :),
           (: command, "say ��n����W�s�]�s�P���y�H���|�����Ө�o�̡C" :),
           (: command, "say �N�ϥΥL������O�u�n�[���v�N���s�a���������F���l�C" :),
           (: command, "say ��ӧګK���H�L�M�L���H�q�����A�@�_��ܻa�����C" :),
           (: command, "say ���a���������}��A�]�s�P�~�M�N�\�ҥ������F�ڡC" :),
           (: command, "say �ҥH�~���o�Ӱ��⪺�ٸ�...��꦳�I���L���F�C" :),
        }) );
        return 1;
    }
    if( arg == "�]�s�P" ) {
        do_chat( ({
           (: command, "say �L�O�y�H���|�������A���F�ڭ̰\�ګܤj�����C" :),
           (: command, "say �]�]���L�A�\�ڤ~�|�P�y�H���|����w�C" :),
           (: command, "say �`���L�O�ڭ̧��l�����H�C" :),
        }) );
        return 1;
    }
    if( arg == "����" ) {
        do_chat( ({
           (: command, "say �]�s�P����Z�C" :),
           (: command, "say �n���ϥΤ@�ئW�s�u�����k�}�v������O�C" :),
           (: command, "say ��O�i�H���O�`���i���C" :),
        }) );
        return 1;
    }
    return 1;
}
