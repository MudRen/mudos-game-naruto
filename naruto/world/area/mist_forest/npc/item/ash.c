#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(NOR"����"NOR, ({ "ash" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("unit", "��");
        set("base_value", 2);
        set("base_weight", 1);
        set("long", "�]���N���L���Ӫ����Ƭ�����������A��F�l�٭n�Ӥp�C");
    }
    setup();
}