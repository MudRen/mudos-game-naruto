#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(BBLU+HIG"�ź��"NOR, ({ "aquamarine" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("unit", "��");
        set("base_value", 20000);
        set("base_weight", 1);
        set("no_box", 1);
        set("long", "�֦����⪺�ɡA�b�����U�[�ݧe�{�Ŧ�A���t���o�ܦ����A�D�`��\n"
                    "���_�C�]���C��S��A�`�������H�a���߷R�C\n");
    }
    setup();
}