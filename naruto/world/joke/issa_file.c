#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("�i���ߡE�s����(Issa)�����ɮסj", ({ "issa's file", "file" }));

    set_weight(1);

    if( !clonep() ) {
        set("unit", "��");
        set("value", 0);
        set("long", "�@�� ���ߡE�s����(Issa) ���H�������ɡA����������X�K�|�P���C");
    }
    setup();

}

