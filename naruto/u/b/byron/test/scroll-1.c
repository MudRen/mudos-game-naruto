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
    set("effect", ([
        "type": "EQ",                // ������
        "success": 100,              // ���\�v
        "dex": 5,
        "int": 5,
        "con": 5,
        "str": 5,
    ]) );
    setup();
}
