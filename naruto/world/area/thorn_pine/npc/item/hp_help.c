#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("��O���", ({ "hp help", "help" }));
    set_weight(100);
    if( !clonep() ) {
        set("unit", "�]");
        set("value", 4000);
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
    if( me->query_stat_current("hp") > me->query_stat_maximum("hp")/4 ) {
        write(CYN"�u���b���A���ήɤ~��ϥΫ�ϥ]�C"NOR"\n");
        return;
    }
    message_vision("$N���}$n�N�̭����ī~�ֳt�]�F�U�h�C�n���^�_�ֳ\��O\n", me, this_object());
    me->heal_stat("hp", 1500);
    destruct(this_object());
}
