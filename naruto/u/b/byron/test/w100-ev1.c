#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("�i"HIR"�Z��"HIW"100%"NOR"�j�j�ׯ�O+1", ({ "book", "__BOOK__" }));

    set_weight(1);

    if( !clonep() ) {
        set("unit", "��");
        set("value", -1);
        set("long", "�@�ӥi�H�W�j�����O�����b�C(help combine)");
    }

    // �ĪG
    set("effect", ([
        "type": "WP",                // ������
        "success": 100,              // ���\�v
        "evade": 1,                  // �j�ׯ�O+1
    ]) );

    setup();
}

