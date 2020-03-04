#include <ansi.h>
#include <npc.h>

inherit F_SOLDIER;

void create()
{
    set_name("�ݪ���", ({ "guard door dog", "dog" }));
    set_race("beast");
    set_level(22);

    // �u�ۥX�f
    set("guard_exit", ({ "west" }));

    set("set_drop", ({
        ([ "type":"eq", "id":5, "amount":1, "p1":70, "p2":100 ]),     // ÷�l
        ([ "type":"eq", "id":32, "amount":1, "p1":10, "p2":100 ]),     // �j�K�U
    }) );

    setup();
}
int do_guard_exit(int x, int y, string exit)
{
    if( userp(this_player()) ) {
        message_vision("$n���X���}�N$N�d��C\n", this_player(), this_object());
        do_chat((: command, "say �ɹɹɡI�A�i�O�����ڡC":));
        return 1;
    }
}
