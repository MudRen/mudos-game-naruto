#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name(HIY"���x�o"NOR, ({ "cod liver oil", "oil" }));
    if( !clonep() ) {
        set("unit", "��");
        set("base_unit", "��");
        set("base_value", 100);
        set("base_weight", 100);
        set("food_stuff", 50);              // �����q�A���~�@�w�n�������q
        set("long", "�γ�����Ŧ�һs�������d���~�C\n");
    }
    setup();
}
