inherit F_FOOD;
#include <ansi.h>

void create()
{
        set_name(HIY"�G��"NOR, ({ "jelly" }));
        if( !clonep() ) {
                set("unit", "��");
                set("base_unit", "��");
                set("base_value", 10);             // ������ġA���ݭn�ӶQ�A�����a�R�o�_
                set("base_weight", 10);
                set("food_stuff", 5);              // �����q�A���~�@�w�n�������q
                set("long", "�@�ɳn�w�w���G��C\n");
                set("condition", ([ "apheal1": ([ "duration": 10 ]) ]) );
        }
        setup();
}
