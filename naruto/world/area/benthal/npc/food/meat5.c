#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name("�T����", ({ "shark's meat", "meat" }));
    if( !clonep() ) {
        set("unit", "��");
        set("base_unit", "��");
        set("base_value", 10);
        set("base_weight", 100);
        set("food_stuff", 10);              // �����q�A���~�@�w�n�������q
        set("long", "�T���צ׽���w�A���G���ӾA�X���ΡC\n");
    }
    setup();
}
