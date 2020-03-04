#include <ansi.h>

inherit COMBINED_ITEM;
int i;

void create()
{
    set_name(HIY"黃金鐘"NOR, ({ "gold bell", "bell" }));
    if( !clonep() ) {
        set("base_unit", "尊");
        set("unit", "尊");
        set("base_value", 40000);
        set("base_weight", 500);
        set("long", "純金打造的金鐘，所敲響(use)的聲音柔順悅耳，讓人心神平順。");
    }
    setup();
}
int do_use(object me)
{
    if( i < 9) {
        message_vision("$N發出悅耳的聲音「噹∼∼噹∼∼噹∼∼」\n", this_object());
        i = i+1;
        return 1;
    } else if( i == 9) {
        message_vision("「砰噹」一聲巨響$n不小心把$N敲壞了！\n", this_object(), me);
        set_name("損壞的"HIY"黃金鐘"NOR, ({ "bad bell", "bell", "_BAD_BELL_" }));
        set("long", "珍貴的黃金鐘，可惜已經敲壞了。");
        set("base_value", 0);
        i = i+1;
        return 1;
    } else if( i > 9) {
        message_vision("$N發不出任何聲音。\n", this_object(), me);
        return 1;
    }
}
