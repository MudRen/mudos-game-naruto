#include <ansi.h>
inherit F_FOOD;
void create()
{
    set_name(HIR"��Y"NOR, ({ "pill" }));
        if( !clonep() ) {
        set("unit", "��");
        set("base_unit", "��");
        set("base_value", 10);
        set("base_weight", 0);
        set("food_stuff", 5);        
        set("long", "�@����_���^�ͪ��ĤY�C\n");
        set("heal_mp", 9999);
        set("heal_ap", 9999);
        set("heal_hp", 9999);
        }
        setup();
}
