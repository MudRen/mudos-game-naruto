#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(HIG"��w"NOR, ({ "needle" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("unit", "��");
        set("base_value", 2);
        set("base_weight", 1);
        set("long", "�A�����ҦӪ������𤧸��l�A�e�ݵw�p�y�w�A���l�o�X�n����C");
    }
    setup();
}