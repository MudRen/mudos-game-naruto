#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name("�o�o", ({ "scrap" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("unit", "��");
        set("base_value", 0);
        set("base_weight", 200);
        set("no_drop", 1);
        set("no_auc", 1);
        set("no_give", 1);
        set("long", "�C��V�B���o��A���o�X�@�����ߪ���o���C");
    }
    setup();
}
