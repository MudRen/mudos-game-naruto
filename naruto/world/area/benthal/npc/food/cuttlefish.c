#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name("�Q��", ({ "cuttlefish" }));
    if( !clonep() ) {
        set("unit", "��");
        set("base_unit", "��");
        set("base_value", 40);
        set("base_weight", 100);
        set("food_stuff", 30);              // �����q�A���~�@�w�n�������q
        set("long", "���v�ͪ��A���D�A���A�S��O�e�����ʤ覡�O�Q�g�����ʡC��J��M\n"
                    "�I�ɷ|�Q�X�u���ġv�M��k�R�C\n");
    }
    setup();
}
