#include <npc.h>
#include <ansi.h>

void create()
{
    set_name(HIC"���P�_�_"NOR, ({ "sea star","star" }) );
    set_race("beast");
    set_level(19);

    set("long", "�@���ܥi�R�����P�_�_�A�e�i�R���ҼˡA���A���@�ѷQ��e���d�����İʡC\n");

    set("limbs", ({ "�Y��", "����" }) );
    set("verbs", ({ "bite" }) );
 
    set("chat_chance", 3);
    set("chat_msg", ({
        "���P�_�_�S�X���������ꪺ�ѯu���e�C\n",
        }));

    setup();

    carry_money("silver", 50);

}
