#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name("���~��", ({ "trap" }) );

    if( !clonep() ) {
        set("base_unit", "��");
        set("unit", "��");
        set("base_value", 100);
        set("base_weight", 800);
        set("long", "���~�Ϊ����l�A���O�w�g�a���F�C\n");
    }
    setup();
}
