#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(HIC"�Ŧ�ѫʨ�"NOR, ({ "blue reel", "reel" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("unit", "��");
        set("base_value", 10);
        set("base_weight", 10);
        set("no_box", 1);
        set("long", "���������b�A����������γB�C");
    }
    setup();
}
void do_use(object me)
{
    if( me->query_temp("quest/applaudbox") == 1) {
        message_vision("$N�N$n�r�b�L�W�A�u�������o�X�E�P���Ŧ���~�I\n", me, this_object());
        message_vision("���@�|��A$N���y�W���⯾�������L�ܡA���b����o��{�X"HIB"�Ŧ⯾��"NOR"�C\n", me);
        me->add_temp("quest/applaudbox", 1);
        destruct(this_object());
    } else {
        message_vision("$N�N$n�r�b�L�W�A���S������Ʊ��o�͡C\n", me, this_object());
        return;
    }
}
