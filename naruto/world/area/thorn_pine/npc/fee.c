#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("�\��", ({ "bow fee", "fee" }));
    set_race("human");
    set_level(35);
    set("age", 65);
    set("long", "�o�󪫦^����������A��ө�c�I�ߡA¼�ۤG���L�]���R���C\n");
    set("camp", "bow");
    set("chat_chance", 1);
    set("chat_msg", ({
        CYN"�\��@�y�R�z���z���ˤl�C\n"NOR,
        CYN"�\��w�w�a�R�۷ϰ�...�R...�R...�R...\n"NOR,
    }));
    setup();
}
