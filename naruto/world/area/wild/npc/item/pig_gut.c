#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name(RED"�޸z"NOR, ({ "pig's gut", "gut", "_PIG_GUT_" }));

    if( !clonep() ) {
        set("base_unit", "��");
        set("base_value", 10);
        set("base_weight", 600);
        set("food_stuff", 10);              // �����q�A���~�@�w�n�������q
        set("long", "�@����O�O���޸z�C\n");
    }
    setup();
}
