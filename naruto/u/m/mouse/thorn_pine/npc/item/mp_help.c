#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("���d���", ({ "mp help", "help" }));
    set_weight(100);
    if( !clonep() ) {
        set("unit", "�]");
        set("value", 2000);
        set("long", "�԰�����ϱM�ΡA�H(use)�ϥΡC");
    }
    setup();
}
void do_use(object me)
{
    if( !this_player()->is_fighting() ) {
        write(CYN"�S�b�԰��Y�����ϥ]�C"NOR"\n");
        return;
    }
    message_vision("$N���}$n�N�̭����ī~�ֳt�]�F�U�h�C�n���^�_�ֳ\�ۢ�\n", me, this_object());
    me->heal_stat("hp", 100);
    destruct(this_object());
}
