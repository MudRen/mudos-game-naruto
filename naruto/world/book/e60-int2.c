#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("�i"HIG"����"HIW"60%"NOR"�j���z+2", ({ "book", "__BOOK__" }));
    set_weight(1);
    if( !clonep() ) {
        set("unit", "��");
        set("value", -1);
        set("long", "�@�ӥi�H�W�j�����O�����b�C(help combine)");
    }
    // �ĪG
    set("effect", ([
        "type": "EQ",        // ������
        "success": 60,       // ���\�v
        "int": 2,            // ���z
    ]) );
    setup();
}
