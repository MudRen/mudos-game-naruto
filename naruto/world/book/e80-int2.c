#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("�i"HIG"����"HIW"80%"NOR"�j���z+2", ({ "book", "__BOOK__" }));
    set_weight(1);
    if( !clonep() ) {
        set("unit", "��");
        set("value", -1);
        set("no_box", 1);
        set("long", "�@�ӥi�H�W�j�����O�����b�C(help combine)");
    }
    // �ĪG
    set("effect", ([
        "type": "EQ",        // ������
        "success": 80,       // ���\�v
        "int": 2,            // ���z
    ]) );
    setup();
}
