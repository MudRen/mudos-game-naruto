#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;

void create()
{
    set_name(HIW"���ۼC"NOR, ({ "spiral sword", "sword" }));
    set_weight(2500);
    setup_weapon(30, 45, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "lefthand", "righthand" }) );
        set("unit", "��");
        set("value", 39224);
        set("long", "��W��C���A�観�������W�ѡA��J����|�y�����j�ˮ`�C\n" );
    }
    set("apply_weapon/righthand", 
        ([ "attack" : 10,
           "exact" : 5,
           "intimidate" : 10,
    ]) );
    set("apply_weapon/lefthand", 
        ([ "exact" : 5,
    ]) );
    setup();
}
