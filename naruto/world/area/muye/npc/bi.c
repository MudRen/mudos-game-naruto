#include <ansi.h>
#include <npc.h>

inherit F_VILLAGER;

void create()
{
    set_name("��D�˳ߤ�", ({ "bi" }));
    set_race("human");
    set_level(60);
    set("camp", "muye");
    set("long", "���츭���f�P�ʺ����A�ժ��Q�Τ߲z�ԡA�ݥX���H�L�k��ܪ����D�A\n"
                "�Ϩ�ǤH���J�믫���h�W���C\n");

    set("age", 27);
    set("gender", "male");
    setup();
}
