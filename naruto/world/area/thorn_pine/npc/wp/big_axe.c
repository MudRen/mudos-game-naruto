#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;

void create()
{
    set_name(HIW"����"NOR, ({ "big axe", "axe" }));
    set_weight(9000);
    setup_weapon(40, 60, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "��");
        set("value", 26450);
        set("long", "�򭱥[�e�����Y�A���q�]�Q���I���C\n" );
    }
    set("apply_weapon/twohanded", 
        ([ "str" : 2,
    ]) );
    setup();
}
