#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("�i"HIR"�Z��"HIW"100%"NOR"�j�򥻧ޯ�+20", ({ "book", "__BOOK__" }));

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
            "evade": 20,
            "wittiness": 20,
            "dodge": 20,
            "savage hit": 20,
            "continual hit": 20,
            "parry": 20,
            "combat": 20,
            "heavy hit": 20, 
            "wittiness": 100,              // ���m�ޥ�+1
            "hp": 200,
            "mp": 200,
            "ap": 200,


     ]) );

    setup();
}

