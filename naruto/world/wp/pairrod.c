#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name(MAG"���I��"NOR, ({ "pair rod", "rod" }));
    set_weight(6000);
    setup_weapon(24, 32, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "lefthand" }) );
        set("unit", "��");
        set("value", 5656);
        set("long", "��ڴҤl�������K�屵�b�@�_�����I�ҡC\n" );
    }

    setup();
}
