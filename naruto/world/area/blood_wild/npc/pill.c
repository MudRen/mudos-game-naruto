#include <npc.h>

inherit F_FIGHTER;

void create()
{
    set_name("�Ĥs�m", ({ "pill master", "master" }));
    set_race("human");
    set("nickname", "�s���k");
    set_level(1);
    set("long", "�@�y�y�]�˪��k�H�A���y���٦��@���Q���N�˪��Ͳ��C�����R���F�@\n"
                "�@�����Ĩ��A�b�p�Τl�������a���_���W�ħ������A���O�����c�٪�\n"
                "�ˤl�Pı��b�����O�ϤH�٥@����͡C\n");
    set("age", 45);
    set("gender", "male");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: command, "say ť���v�S�b�ѤW�H���}�~�F�C" :),
        (: command, "say �ħ��ħ�..." :),
    }) );
    setup();
}
