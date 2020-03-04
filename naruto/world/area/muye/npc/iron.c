#include <npc.h>
#include <ansi.h>

inherit F_VENDOR;

void create()
{
    set_name("�K������", ({ "iron boss", "boss" }) );
    set_race("human");
    set_level(50);
    set("age", 61);
    set("long", "�U�ۿN�������K�l�A�M�߻s�@���㪺�Ѯv�šC\n");
    set("chat_chance", 2);
    set("chat_msg", ({
        CYN"�K�����󥿱M�ߦa�s�@�n�Ϊ����㤤...\n"NOR,
        (: command, "sweat" :),
    }));
    set_goods(1, "wp", 74, 10, -1);
    set_goods(2, "wp", 15, 10, -1);
    set_goods(3, "wp", 57, 10, -1);
    setup();
}
void relay_say(object ob, string arg)
{
    object item;

    if( arg == "�Q�r��" )  {
        do_chat(({
            (: command, "say �O�b�o�̶R�S���I" :),
            (: command, "say ���O�̪�R�Q�r��H�U�ӷU�h�A�w�g���ǯʳf�F�C" :),
            (: command, "say �ҥH�ڤS���F�X�ӾǮ{�M���s�@�o�˹D��C" :),
            (: command, "say �i���L�̪��޳N���O�ܦn���A�ҥH�~��S���O�ٳ�I" :),
            (: command, "say �ڤw�g�N���歰�C���d��Ȥl�F�C" :),
            (: command, "say ���ݭn�N��ڶR�a�C" :),
            (: command, "wink" :),
        }));
        return;
    }
}
