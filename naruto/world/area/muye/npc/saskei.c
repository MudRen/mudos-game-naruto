#include <npc.h>

inherit F_FIGHTER;

void create()
{
    set_name("���U", ({ "saskei" }));
    set_race("human");
    set_level(60);
    
    set("long", "�֦��츭�����u���u�q�a�ڦ�Ρv�����U�A�H�Ĥ@�W�����Z���~���\n"
                "�̾ǮաA�O�����̬����ݪ��Y���s��C\n");

    set("age", 16);
    set("gender", "male");
    
    setup();
}
