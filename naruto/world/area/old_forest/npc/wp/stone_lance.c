#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;

void create()
{
    set_name("�ۺj"NOR, ({ "stone lance", "lance", "_FOUNDER_WP_" }));
    set_weight(30000);
    setup_weapon(10, 10, 100, 1);
    if( !clonep() ) {
        set("wield_as", "twohanded");
        set("unit", "��");
        set("value", 0);
        set("no_combine", 1);
        set("coal_need", 6);
        set("iron_need", 20);
        set("copper_need", 12);
        set("long", "�I�����j�j�A�����εw�۩һs���A��������ڥ������ʡC\n" );
    }
    setup();
}
