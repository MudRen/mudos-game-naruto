#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("�i�ߤ��P(Uranus)�����ɮסj", ({ "uranus's file", "file" }));

    set_weight(1);

    if( !clonep() ) {
        set("unit", "��");
        set("value", 0);
        set("long", "�@�� �ߤ��P(Uranus) ���H�������ɡA����������X�K�|�P���C");
    }
    setup();

}
