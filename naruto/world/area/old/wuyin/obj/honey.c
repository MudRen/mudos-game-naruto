inherit F_FOOD;
#include <ansi.h>

void create()
{
        set_name(HIY"���e"NOR, ({ "honey" }));
        if( !clonep() ) {
                set("unit", "��");
                set("base_unit", "�f");
                set("base_value", 10);             // ������ġA���ݭn�ӶQ�A�����a�R�o�_
                set("base_weight", 10);
                set("food_stuff", 5);              // �����q�A���~�@�w�n�������q
                set("long", "�@�f�������e�A�����ݨ���ƻD���ӨӡC\n");
                set("condition", ([ "hpheal1": ([ "duration": 10 ]) ]) );
        }
        setup();
}

