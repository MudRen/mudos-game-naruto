#include <weapon.h>
#include <ansi.h>

inherit F_WEAPON;

void create()
{
    set_name("���@", ({ "whip" }));
    set_weight(800);
    setup_weapon(20, 20, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand" }) );
        set("unit", "��");
        set("value", 3220);
        set("long", "���`�Ψ��@���ʪ����@�l�C\n" );
    }
    // ���[��O
    set("apply_weapon/righthand",
        ([ "con" : 1,
           "hp" : 10,
    ]) );
    setup();
}
