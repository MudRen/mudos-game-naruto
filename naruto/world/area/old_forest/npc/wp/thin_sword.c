#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;

void create()
{
    set_name("�ӼC"NOR, ({ "thin sword", "sword", "_FOUNDER_WP_" }));
    set_weight(500);
    setup_weapon(2, 4, 100, 1);
    if( !clonep() ) {
        set("wield_as", "lefthand");
        set("unit", "��");
        set("value", 0);
        set("no_combine", 1);
        set("coal_need", 12);
        set("iron_need", 6);
        set("copper_need", 20);
        set("long", "�y�ӵu�p�A�ݰ_�Ӥ��O�ܺ�����p�C�A�A�X����ϥΡC\n" );
    }
    setup();
}
