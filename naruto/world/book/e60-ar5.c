#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("�i"HIG"����"HIW"60%"NOR"�j���m�O�q+5", ({ "book", "__BOOK__" }));
    set_weight(1);
    if( !clonep() ) {
        set("unit", "��");
        set("value", -1);
        set("no_box", 1);
        set("long", "�@�ӥi�H�W�j�����O�����b�C(help combine)");
    }
    // �ĪG
    set("effect", ([
        "type": "EQ",   // ������
        "success": 60,  // ���\�v
        "armor": 5,     // ���m+5
    ]) );
    setup();
}
