#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("�i"HIR"����"HIW"���b"NOR"�j, ({ "book", "__BOOK__" }));

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
        "str": 20,
        "con": 20,
        "dex": 20,
        "int": 20,
        "ap": 100,
        "hp": 100,
        "mp": 100,
        "exact": 20,
        "attack": 20,
        "intimidate": 20,
        "combat": 20,
        "parry": 20,
        "dodge": 20,
        "heavy hit": 20,
        "savage hit": 20,
        "solid": 20,
        "continual hit": 20,
    ]) );

    setup();
}

