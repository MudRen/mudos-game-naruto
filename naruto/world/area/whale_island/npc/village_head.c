#include <ansi.h>
#include <npc.h>

void create()
{
    set_name("����", ({ "village head", "head" }));
    set_race("human");
    set_level(1);
    set("title","�H���q����");
    set("long", "�o�O�H���q���{�������A�ݰ_�өMħ�i�ˡA���M�~���w�j�A�����M��\n"
                "�o�ܦ��믫�C\n");

    set("chat_chance", 1);
    set("chat_msg", ({
        "���������a�ĤF�f��A���G������дo���ߨơC\n",
    }));
    setup();
}
