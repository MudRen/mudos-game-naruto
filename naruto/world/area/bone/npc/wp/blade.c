#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name("��M", ({ "kitchen blade", "blade" }));
    set_weight(15000);
    setup_weapon(50, 55, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "��");
        set("value", 78552);
        set("long", "����Ϊ��M�l�A�q���Q�Ү����Z���C\n" );
    }
    set("apply_weapon/twohanded", 
        ([ "savage hit" : 5,
           "continual hit" : 5,
           "heavy hit" : 5,
    ]) );
    setup();
}
