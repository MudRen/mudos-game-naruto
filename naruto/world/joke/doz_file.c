#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("�i���M(Doz)�����ɮסj", ({ "doz's file", "file" }));

    set_weight(1);

    if( !clonep() ) {
        set("unit", "��");
        set("value", 0);
        set("long", "�@�� ���M(Doz) ���H�������ɡA����������X�K�|�P���C");
    }
    setup();

}

