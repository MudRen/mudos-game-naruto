#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(BYEL+HIY"����"NOR, ({ "topaz" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("unit", "��");
        set("base_value", 20000);
        set("base_weight", 1);
        set("no_box", 1);
        set("long", "�����⪺�ɡA�O�ӤH�̳̳��w���ɥۡA�]���b���~�U�����{�{��o��\n"
                    "�����Y�A���F����i�{�ӤH����աA�]����W�[���~���R��C");
    }
    setup();
}