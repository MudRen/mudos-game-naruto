#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;
inherit ENHANCE_D;

void create()
{
    set_name("���M", ({ "long blade", "blade" }));
    set_weight(8000);
    setup_weapon(30, 50, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", "righthand");
        set("unit", "��");
        set("value", 5440);
        set("long", "�M�f�}���ê����M�A�F�ޱj�s�̷R�Ϊ��L���C\n" );
    }
    set("apply_weapon/righthand", 
        ([ "str" : 2,
        ]) );
    setup();
}
