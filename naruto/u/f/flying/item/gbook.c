#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("�i"HIG"����"HIW"100%"NOR"�j���ݩ�+5", ({ "book", "__BOOK__" }));

    set_weight(1);

    if( !clonep() ) {
        set("unit", "��");
        set("value", -1);
        set("long", "�@�ӥi�H�W�j�����O�����b�C(help combine)");
    }

    // �ĪG
    set("effect", ([
        "type": "EQ",                // ������
        "success": 100,              // ���\�v
        "str": 5, 
        "con": 5,
        "dex": 5,
        "int": 5,
    ]) );

    setup();
}
