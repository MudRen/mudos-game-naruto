#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("�i"HIR"�Z��"HIW"100%"NOR"�j�O�q+100", ({ "book", "__BOOK__" }));

    set_weight(1);

    if( !clonep() ) {
        set("unit", "��");
        set("value", -1);
        set("long", "�@�ӥi�H���ƪZ����O�����b�C(help combine)");
    }

    // �ĪG
    set("effect", ([
        "type": "WP",                // �Z����
        "success": 100,              // ���\�v
        "str": 100,
    ]) );

    setup();
}

