#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name(GRN"�t�Y"NOR, ({ "turtle's head", "head", "_TURTLE_HEAD_" }));
    if( !clonep() ) {
        set("food_stuff", 10);              // �����q�A���~�@�w�n�������q
        set("base_unit", "��");
        set("base_value", 15);
        set("base_weight", 100);
        set("long", "�@���o�X�{������Q�t�Y�C\n");
    }
    setup();
}
