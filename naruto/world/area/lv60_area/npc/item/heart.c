#include <ansi.h>

inherit ITEM;

void create()
{
    set_name(HIY"���~"RED"��Ŧ"NOR, ({ "heart" }));
    set_weight(1);
    if( !clonep() ) {
        set("unit", "��");
        set("value", 0);
        set("no_box", 1);
        set("no_sell", 1);
        set("no_auc", 1);
        set("no_drop", 1);
        set("long", "�t���⪺��Ŧ�A���ʪ��t�׫D�`�w�C�A�~��Q�@�h�ե��]��C");
    }
    setup();
}
