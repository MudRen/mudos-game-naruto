#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("�u��", ({ "clip", "_CLIP_" }));
    set_weight(100);
    if( !clonep() ) {
        set("unit", "��");
        set("value", 50);
        set("long", "�Ψӧ󴫤l�u�Ϊ��u��");
    }
    setup();
}
