#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("�i��", ({ "zhang ying", "ying" }) );
    set_race("human");
    set_level(5);
    set("gender", "female");
    set("nickname", HIG"�j�ŧ���"NOR);
    set("age", 27);
    set("long", "�ۺپ֦��D�k���O���H�A�H�K����@��N�ள���F�ġC\n");
    set("chat_chance", 1);
    set("chat_msg", ({
        CYN"�i�o���۲����H�⩹�Ť��@���A���M�h�X�@���¦��ĤY�b�o�⤤�C\n"NOR,
        (: command, "say �ڪ��޳N�i���O�H�K�N��I�i���C" :),
        CYN"�i�o���j�N�ۦo���Ħ��h���_�C\n"NOR,
    }));
    setup();
}
