#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(HIR"����ѫʨ�"NOR, ({ "red reel", "reel" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("unit", "��");
        set("base_value", 10);
        set("base_weight", 10);
        set("long", "���������b�A����������γB�C");
    }
    setup();
}
void do_use(object me)
{
    message_vision("$N�N$n�r�b�L�W�A���M�������X�����n��$N�I\n", me, this_object());
    message_vision("���@�|��A$N���y�W�G���F�i�Ȫ�"RED"���⯾��"NOR"�A�ӯ������w���������C\n", me);
    me->add_temp("quest/applaudbox", 1);
    destruct(this_object());
}
