#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("�i�p��(Llee)�����ɮסj", ({ "llee's file", "file" }));

    set_weight(1);

    if( !clonep() ) {
        set("unit", "��");
        set("value", 0);
        set("long", "�@�� �p��(Llee) ���H�������ɡA����������X�K�|�P���C");
    }
    setup();

}

