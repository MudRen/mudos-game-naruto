#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("�b�~�H�׸��p�l", ({ "orc man", "man" }) );
    set_level(1);
    set_race("human");
    set("age", 12);
    set("no_fight", 1);
    set("long", "���M�X�𥼲�o���@�س��ʪ��Pı�A�ݰ_�Ӵ����q�q���b�~�H�p�l�C\n");
    set("guard_exit", ({ "south", "southwest", "southeast" })); // �u�ۥX�f
    setup();
}
int do_guard_exit(int x, int y, string exit)
{
    message_vision("$n�צ�F$N���h���C\n"NOR, this_player(), this_object());
    do_chat((: command, "say �H�����٦b��פ��A�ثe�Ȥ��}��C"NOR:));
    return 1;
}
