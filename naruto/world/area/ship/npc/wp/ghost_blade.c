#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name(HIM"�����"HIY"���"NOR, ({ "tiger katana", "katana" }));
    set_weight(5000);
    setup_weapon(100, 120, 100, 1);

    if( !clonep() ) {
        set("wield_as", ({ "lefthand" }) );
        set("unit", "��");
        set("no_box", 1);
        set("value", 176010);
        set("long", "����ɥN���W�M����ҥ�y���M�A�M�����G�A�P��M�ۮt�����C\n" );
    }
    set("apply_weapon/lefthand",
        ([ "str" : 3,
           "exact" : 5,
           "intimidate" : 5,
    ]) );
    setup();
}
