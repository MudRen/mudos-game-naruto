#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("�i���P�v��(Sakuratomb)�����ɮסj", ({ "sakuratomb's file", "file" }));

    set_weight(1);

    if( !clonep() ) {
        set("unit", "��");
        set("value", 0);
        set("long", "�@�� ���P�v��(Sakuratomb) ���H�������ɡA����������X�K�|�P���C");
    }
    setup();

}

