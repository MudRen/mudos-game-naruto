#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("�i�����y�H(Kuwa)�����ɮסj", ({ "kuwa's file", "file" }));

    set_weight(1);

    if( !clonep() ) {
        set("unit", "��");
        set("value", 0);
        set("long", "�@�� �����y�H(Kuwa) ���H�������ɡA����������X�K�|�P���C");
    }
    setup();

}
