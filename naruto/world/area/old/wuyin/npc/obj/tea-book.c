#include <ansi.h>

inherit ITEM;

void create()
{
    set_name(YEL"�u�����v"NOR, ({ "tea book", "book" }) );
    set_weight(10);

    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long", "�@�����z�p���د��𪺮��ǡA�Ѥ��Ǩ����ΡG���}�n������ڲ��A\n"
                    "�����X�W�~�������A�G�ѦW���u�����v�C\n");
    }
    setup();
}
