#include <npc.h>
#include <ansi.h>

inherit F_VENDOR;

void to_do_say()
{
    do_chat( ({ 
        (: command, "say �̪񪺮���U�ӷU�s��..." :),
        (: command, "say ���ǧڦѪ��Ӧ��F�I" :),
        (: command, "sigh" :),
    }) );
}
void create()
{
    set_name("�ѤH", ({ "oldman" }) );
    set_race("human");
    set_level(1);
    set("age", 80);
    set("long", "�h�Ъ����x�ѧL�A�]���������x�ߤU���֥\\�A�[�W�h�Ы�L�ۤv�ШD\n"
                "�b�q�k�q�W���L�\\�Фl�~��A�ҥH��ӫK��b�o����p�ΤF�C\n");

    // �@��ɰʧ@
    set("chat_chance", 3);
    set("chat_msg", ({
        (: to_do_say :),
    }) );

    set_goods(1, "wp", 57, -1, -1);
    setup();
}
