inherit F_FOOD;
#include <ansi.h>

void create()
{
        set_name(YEL"�����N"NOR, ({ "taco burn","taco","burn" }));
        if( !clonep() ) {
                set("unit", "��");
                set("base_unit", "��");
                set("base_value", 70);             // ������ġA���ݭn�ӶQ�A�����a�R�o�_
                set("base_weight", 10);
                set("food_stuff", 5);              // �����q�A���~�@�w�n�������q
                set("long", "�@�ꭻ�Q�Q�������Y�l�A�C�ӤY�l�W���������߫�R�֪��ϮסA���I�I����������-�C\n");
                set("condition", ([ "hpheal2": ([ "duration": 8 ]) ]) );
        }
        setup();
}
