#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("�i�����P(Neptune)�����ɮסj", ({ "neptune's file", "file" }));

    set_weight(1);

    if( !clonep() ) {
        set("unit", "��");
        set("value", 0);
        set("long", "�@�� �����P(Neptune) ���H�������ɡA����������X�K�|�P���C");
    }
    setup();

}

