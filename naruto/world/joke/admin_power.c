#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("�i�j�����v�O�j", ({ "The admin power", "power" }));

    set_weight(1);

    if( !clonep() ) {
        set("unit", "��");
        set("value", 0);
        set("long", 
"�o�O�гy�o�ӥ@�ɪ��j�����O�q�Ҧb�C�u�n�z�֦��o�ӪF��A\n"
"�Y����֦����t�z�L�P�פ񪺤O�q�I�I"
);
    }
    setup();

}

