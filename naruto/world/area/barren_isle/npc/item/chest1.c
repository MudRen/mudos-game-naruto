#include <ansi.h>

inherit ITEM;

void create()
{
    set_name(HIB"�m���_�c�n"NOR, ({ "blue chest", "chest" }));
    set_weight(1);
    if( !clonep() ) {
        set("piece_test", 2);
        set("unit", "��");
        set("no_box", 1);
        set("value", 0);
        set("long", "�̭��ŪŪ��Ŧ��_�c�A���G�S������ȡC");
    }
    setup();
}
