#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name("�D��", ({ "snake's tooth", "tooth" }));
    set_weight(6000);
    setup_weapon(14, 18, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "lefthand" }) );
        set("unit", "��");
        set("value", 3232);
        set("long", "�@�ڥ��j���D���A�i�H���ӷ�Z���ϥΡC\n" );
    }

    setup();
}
