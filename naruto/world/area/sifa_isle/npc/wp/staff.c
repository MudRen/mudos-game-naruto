#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name(YEL"�I��"NOR, ({ "buddhist monk's staff", "staff" }));
    set_weight(10000);
    setup_weapon(50, 55, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "righthand" }) );
        set("unit", "��");
        set("value", 44452);
        set("long", "�W�湬�άO���C���H�|�H����a�������A�S�I�O�e�ݸ˦����C\n" );
    }
    // ���[��O
    set("apply_weapon/righthand", 
        ([ "str" : 2,
           "savage hit" : 10,
    ]) );
    setup();
}
