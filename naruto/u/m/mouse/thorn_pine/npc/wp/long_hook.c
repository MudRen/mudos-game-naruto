#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;

void create()
{
    set_name(HIY"�����K��"NOR, ({ "iron hook", "hook" }));
    set_weight(1000);
    setup_weapon(20, 35, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "lefthand" }) );
        set("unit", "��");
        set("value", 5454);
        set("long", "�������K�Ĥ��A�¤O���K�ħ�j�C\n" );
    }
    setup();
}
