#include <ansi.h>

inherit ITEM;

void create()
{
    set_name(HIR"�m���_�c�n"NOR, ({ "red chest", "chest" }));
    set_weight(1);
    if( !clonep() ) {
        set("piece_test", 1);
        set("unit", "��");
        set("no_box", 1);
        set("value", 0);
        set("long", "�̭��ŪŪ������_�c�A���G�S������ȡC");
    }
    setup();
}
