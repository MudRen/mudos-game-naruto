#include <ansi.h>

inherit ITEM;

void create()
{
    set_name(HIR"�s"HIW"��"NOR, ({ "dragon soul", "soul" }));
    set_weight(1);
    if( !clonep() ) {
        set("unit", "��");
        set("value", 2);
        set("no_box", 1);
        set("no_sell", 1);
        set("no_drop", 1);
        set("long", "�s����z�A�s��b��z�~���Φ��@�D�O�@���A�D�`�_�S�C");
    }
    setup();
}
