#include <ansi.h>

inherit ITEM;

void create()
{
      set_name(HIC"�_"NOR"�j�L��"HIG"�����s��"NOR, ({ "tmr's dragon head", "head" }));

    set_weight(1);

    if( !clonep() ) {
        set("unit", "��");
        set("value", 0);
        set("long", "�@���p�p���ӥB���o�ܩ_�Ǫ��Y");
    }
    setup();

}
