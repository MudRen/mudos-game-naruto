#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(HIY"�F�t"NOR, ({ "gravel" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("unit", "��");
        set("base_value", 2);
        set("base_weight", 1);
        set("long", "�|�����E�_�Ӫ��Ӥp�F�l�A�N�_�Ӳʲʪ��Pı�C");
    }
    setup();
}