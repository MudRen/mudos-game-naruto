#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name(HIR"���ڽ�"NOR, ({ "beet", "_KARE_A_" }));
    if( !clonep() ) {
        set("unit", "��");
        set("base_unit", "��");
        set("base_value", 15);
        set("base_weight", 10);
        set("food_stuff", 20);
        set("no_sell", 1);
        set("long", "���⽭��A�t���״I�J�ڽ����C\n");
    }
    setup();
}
