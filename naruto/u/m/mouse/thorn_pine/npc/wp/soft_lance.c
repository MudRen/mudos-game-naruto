#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;

void create()
{
    set_name("�n�j", ({ "soft lance", "lance" }));
    set_weight(4000);
    setup_weapon(40, 50, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "��");
        set("value", 7545);
        set("long", "�j���n�Ӱ�T�A�A�X�s��ʪ������C\n" );
    }
    set("apply_weapon/twohanded", 
        ([ "continual hit" : 5,
    ]) );
    setup();
}
