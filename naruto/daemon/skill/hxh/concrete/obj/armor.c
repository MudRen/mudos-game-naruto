#include <ansi.h>
#include <armor.h>
inherit F_ARMOR;

void create()
{
    set_name(GRN"�줧�Z"NOR, ({ "scale armor", "armor" }) );
    set_weight(10000);
    setup_armor();
    if( !clonep() ) {
        set("unit", "��");
        set("value", 0);
        set("no_box", 1);
        set("long", "�K�ǩ������Z�A�̨�{�̯�O�j�z�M�w�Z�Ҫ��{�סC\n");
        set("wear_as", "armor");
    }
    setup();
}