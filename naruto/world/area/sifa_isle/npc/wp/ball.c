#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name("�K�y", ({ "iron ball", "ball" }));
    set_weight(50000);
    setup_weapon(40, 40, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "��");
        set("value", 4740);
        set("long", "�I�����j�K�y�A�W���ٵe�ۮ��x���лx�C\n" );
    }
    // ���[��O
    set("apply_weapon/twohanded", 
        ([ "str" : 1 ]) );
    setup();
}
