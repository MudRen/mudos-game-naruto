#include <ansi.h>

inherit F_FOOD;

void create()
{
    set_name( "�ɶ�", ({ "crab roe", "roe", "__CRAB_ROE__"}));
    if( !clonep() ) {
        set("base_unit", "��");
        set("unit", "��");
        set("base_value", 10);
        set("base_weight", 10);
        set("food_stuff", 5);
        set("long", "�o�O�@�p�ηs�A���ɶ��C\n");
    }
    setup();
}

