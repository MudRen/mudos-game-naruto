#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("�i"HIR"�Z��"HIW"60%"NOR"�j�ӱ�+2", ({ "book", "__BOOK__" }));

    set_weight(1);

    if( !clonep() ) {
        set("unit", "��");
        set("value", -1);
        set("long", "�@�ӥi�H�W�j�Z����O�����b�C(help combine)");
    }

    // �ĪG
    set("effect", ([
        "type": "WP",                // �Z����
        "success": 60,              // ���\�v
        "dex": 2,
    ]) );

    setup();
}
