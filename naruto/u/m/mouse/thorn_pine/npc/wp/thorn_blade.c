#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;

void create()
{
    set_name("���M", ({ "thorn blade", "blade" }));
    set_weight(1000);
    setup_weapon(15, 15, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "righthand" }) );
        set("unit", "��");
        set("value", 1515);
        set("long", "�����y�몺��M�C\n" );
    }
    setup();
}
