#include <login.h>
#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("���ƥ]", ({ "bag", "_WP_BAG_" }));
    set_weight(3);
    if( !clonep() ) {
        set("unit", "�j�]");
        set("value", 1);
        set("no_box", 1);
        set("no_auc", 1);
        set("long", "�˪����������ƥ]�A���L�K�ʪ��ܺ򤣪��D�̭����O����F��C");
    }
    setup();
}
