#include <ansi.h>

inherit F_FOOD;

void create()
{
    set_name(HIW"��Į"NOR, ({ "Paciffic oyster","oyster" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("unit", "��");
        set("base_value", 150);
        set("base_weight", 500);
        set("food_stuff", 20);
        set("long", "�j�����H�A���D�����A���A�A�X�ͭ��A������Q�C\n");
    }
    setup();
}
