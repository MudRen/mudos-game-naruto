#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(RED"�N�g"NOR, ({ "sinter" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("unit", "��");
        set("base_value", 5);
        set("base_weight", 1);
        set("long", "�]���a�μv�T�N�����g�[�A���M�ܵw���O�o���H�����C");
    }
    setup();
}