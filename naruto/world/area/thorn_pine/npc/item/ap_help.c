#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("�믫���", ({ "ap help", "help" }));
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
    if( me->query_stat_current("ap") > me->query_stat_maximum("ap")/4 ) {
        write(CYN"�u���b�믫���ήɤ~��ϥΫ�ϥ]�C"NOR"\n");
        return;
    }
    message_vision("$N���}$n�N�̭����ī~�ֳt�]�F�U�h�C�n���^�_�ֳ\�믫\n", me, this_object());
    me->heal_stat("ap", 1500);
    destruct(this_object());
}
