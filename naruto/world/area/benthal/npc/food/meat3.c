#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name("���I��", ({ "fish's meat", "meat" }));
    if( !clonep() ) {
        set("unit", "��");
        set("base_unit", "��");
        set("base_value", 10);
        set("base_weight", 100);
        set("food_stuff", 20);              // �����q�A���~�@�w�n�������q
        set("long", "�����������A�t���״I��i�C\n");
    }
    setup();
}
