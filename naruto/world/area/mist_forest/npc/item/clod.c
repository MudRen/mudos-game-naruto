#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(YEL"����"NOR, ({ "clod" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("unit", "��");
        set("base_value", 5);
        set("base_weight", 1);
        set("long", "�b�F�Ф��C�C���E�_�Ӫ���������A�D�`�ܮz�A�@���Y�H�C");
    }
    setup();
}