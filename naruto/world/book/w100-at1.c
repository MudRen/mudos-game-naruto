#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("�i"HIR"�Z��"HIW"100%"NOR"�j�����O�q+1", ({ "book", "__BOOK__" }));

    set_weight(1);

    if( !clonep() ) {
        set("unit", "��");
        set("value", -1);
        set("long", "�@�ӥi�H�W�j�Z����O�����b�C(help combine)");
    }

    // �ĪG
    set("effect", ([
        "type": "WP",                // �Z����
        "success": 100,              // ���\�v
        "attack": 1,                 // �����O�q+1
    ]) );

    setup();
}
