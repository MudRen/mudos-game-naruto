#include <npc.h>
#include <ansi.h>

void to_do_say()
{
    do_chat( ({
        (: command, "say ����...�h���ڤF..." :),
        (: command, "say �i�c���½޶]�o���...�`�ڶ^�F�@���C" :),
        (: command, "cry" :),
    }) );
}
void create()
{
    set_name("�����S", ({ "tai site", "site" }) );
    set_race("human");
    set_level(5);
    set("nickname", "�ޤj�v");
    set("age", 25);
    set("long", "�l�v�ަӧV�O���Ӫ��k�H�A�i���{�b�˪������O�˵L�k�ʼu�C\n");
    set("chat_chance", 1);
    set("chat_msg", ({
        (: to_do_say :),
    }));
    setup();
}
