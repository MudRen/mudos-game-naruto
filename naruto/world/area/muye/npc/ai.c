#include <npc.h>

inherit F_VILLAGER;

void create()
{
    set_name("�R�l�p�j", ({ "ai zi", "zi" }));
    set_race("human");
    set_level(5);
    set("camp", "muye");
    set("long", "�R�l�p�j�ݰ_�ӷT�ܭW�y���A�n��������дo�@�ˡC\n");

    set("age", 23);
    set("gender", "female");
    
    // �@��ɰʧ@
    set("chat_chance", 1);
    set("chat_msg", ({
        (: command, "say ���Ǩ���B��¾�F�I�`��|�äC�K�V���C" :),
    }) );

    setup();
}
