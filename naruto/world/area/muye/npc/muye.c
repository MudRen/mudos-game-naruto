#include <npc.h>

inherit F_FIGHTER;

void create()
{
    set_name("�츭�Y", ({ "muye" }));
    set_race("human");
    set_level(15);
    set("camp", "muye");
    set("long", "�ĤT�N���v���]�l�A�ؼЬO���ѷݷݦ������v�C\n");

    set("age", 8);
    set("gender", "male");
    
    setup();

}
