#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;

void create()
{
    set_name("���Y", ({ "axe" }));
    set_weight(5000);
    setup_weapon(15, 30, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "��");
        set("value", 2922);
        set("long", "���`�ΨӬ�㪺�M�`���Y�C\n" );
    }
    // ���[��O
    set("apply_weapon/twohanded", 
        ([ "str" : 1,
    ]) );
    setup();
}
