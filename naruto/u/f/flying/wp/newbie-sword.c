#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name("�s���C", ({ "newbie sword", "sword" }));
    set_weight(1500);
    setup_weapon(1, 2, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "lefthand" }) );
        set("unit", "��");
        set("value", 10);
        set("long", "�@��ӲӪ���C�A�C�`�W�K�۷s��M�ΡC\n" );
    }
     // ���[��O
        set("apply_weapon/righthand",
        ([ "exact" : 1,            
 ]) );
        set("apply_weapon/lefthand",
        ([ "exact" : 1,       
 ]) );

    setup();
}


