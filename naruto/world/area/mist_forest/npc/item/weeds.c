#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(BGRN"����"NOR, ({ "weeds" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("unit", "��");
        set("base_value", 1);
        set("base_weight", 1);
        set("long", "�ͩR�S�O�x�j���p��A���L�w�g�a�a�@���F�C");
    }
    setup();
}