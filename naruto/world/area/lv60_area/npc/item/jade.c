#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(HIM"��"HIC"��"NOR, ({ "soul jade", "jade" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("unit", "��");
        set("base_value", -1);
        set("base_weight", 1);
        set("long", "�o�X���C������~���ɲy�A�y���n�����y�ʪ����A������ʡC");
    }
    setup();
}
