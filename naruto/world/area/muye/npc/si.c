#include <npc.h>

inherit F_FIGHTER;

void create()
{
    set_name("�f��", ({ "si" }));
    set_race("human");
    set_level(50);
    set("camp", "muye");
    set("long", "�M�����|���Ӥ��v�H�諸��^�Юv�A�۫H�����ۤw���оɴN�O������\n"
                "�v���ֳ̧~�|�A�ثe���b�оɲĤT�N���v���]�l�C\n");

    set("age", 28);
    set("gender", "male");

    setup();
}
