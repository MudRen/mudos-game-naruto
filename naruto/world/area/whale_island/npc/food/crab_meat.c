#include <ansi.h>

inherit F_FOOD;

void create()
{
    set_name( "�ɦ�", ({ "crab meat","meat", "__CRAB_MEAT__"}));
    if( !clonep() ) {
        set("base_unit", "��");
        set("unit", "��");
        set("base_value", 4);
        set("base_weight", 10);
        set("food_stuff", 5);
        set("long", "�o�O�@�p���s�A���ɦסC\n");
    }
    setup();

}
