#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;

void create()
{
    set_name(HIK"�����ԤM"NOR, ({ "assault blade", "blade" }));
    set_weight(2000);
    setup_weapon(30, 45, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "lefthand", "righthand" }) );
        set("unit", "��");
        set("value", 15174);
        set("long", "���ª��M���A�A�X�`�]�����@�ԡC\n" );
    }
    set("apply_weapon/righthand", 
        ([ "intimidate" : 10,
           "dex" : 1,
    ]) );
    setup();
}
