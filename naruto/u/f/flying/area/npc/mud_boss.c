#include <npc.h>

inherit F_FIGHTER;

void create()
{
    set_name("�d�ڤ�", ({ "mud boss", "mud", "boss" }));
    set_race("human");
    set_level(30);
    
    set("long", "�c�h�����d�ڤ��A�A25�~�N��10�U�����W�Ѫd�ڡC\n"
                 );

    set("attitude", "aggressive");         // �D�ʧ���

     set("age", 99985);
    set("gender", "male");

    // �u�ۥX�f
    set("guard_exit", ({ "east" }));


    setup();

    }  
int do_guard_exit(int x, int y, string exit)
{
    message_vision("$n�N$N�צ�C\n", this_player(), this_object());
    return 1;
}

