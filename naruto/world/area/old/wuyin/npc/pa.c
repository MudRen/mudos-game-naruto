#include <npc.h>

inherit F_VILLAGER;

void create()
{
        set_name("�����w", ({ "lu lan pa","pa" }) );
        set_race("human");
        set_level(20);
        set("title","����");
        set("age", 70);
        set("long", "�������ӳ����w�A�u�����v�o���ѴN�O�L���ۧ@�A�۷��W�C\n");

        setup();
        carry_object(__DIR__"obj/tea-book.c");
}
