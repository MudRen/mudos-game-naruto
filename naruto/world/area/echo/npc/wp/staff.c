#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name(HIG"�D��"NOR, ({ "snake staff", "staff" }));
    set_weight(7000);
    setup_weapon(40, 40, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "��");
        set("value", 4740);
        set("long", "�s�s�������C�����A�ݰ_�Ӭ����@���D�C\n" );
    }
    // ���[��O
    set("apply_weapon/twohanded", 
        ([ "int" : 1 ]) );
    setup();
}
