#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(WHT"爐渣"NOR, ({ "residue" }));
    if( !clonep() ) {
        set("base_unit", "沱");
        set("unit", "沱");
        set("base_value", 0);
        set("base_weight", 50);
        set("no_drop", 1);
        set("no_auc", 1);
        set("no_give", 1);
        set("long", "黏黏灰黑色融合物，是合成液完成後剩餘的廢棄料。");
    }
    setup();
}
