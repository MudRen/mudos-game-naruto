#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name("�s��", ({ "lobster" }));
    if( !clonep() ) {
        set("unit", "��");
        set("base_unit", "��");
        set("base_value", 300);
        set("base_weight", 100);
        set("food_stuff", 50);              // �����q�A���~�@�w�n�������q
        set("long","�s���OŹ�ȩ��鱡�����W�A�~�A�R�e���A���B�ƹ�A�H���ܤƸU�d��\n"
                   "���k�C�u�n�ܤưt�f���ơA�N�������ȷP�����A���s���D�C\n");
    }
    setup();
}
