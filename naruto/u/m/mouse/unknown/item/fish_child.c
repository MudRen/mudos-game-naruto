#include <ansi.h>
inherit F_FOOD;
void create()
{
    set_name(HIR"���l"NOR, ({ "fish's child", "child" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("unit", "��");
        set("base_value", 30);
        set("base_weight", 100);
        set("food_stuff", 5);
        set("long", "�S�ٳ��Z�A�O���ب��D�̨Ϊ������C\n");
    }
    setup();
}
