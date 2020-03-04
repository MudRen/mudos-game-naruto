#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name(HIK"�T�N����"NOR, ({ "ghost katana", "katana" }));
    set_weight(5000);
    setup_weapon(130, 150, 100, 1);

    if( !clonep() ) {
        set("wield_as", ({ "lefthand" }) );
        set("unit", "��");
        set("no_box", 1);
        set("value", -1);
        set("long", "�����Ҿ֦����W�M�A�ڻ����g�֦��L���C�ȥ�������D�R�A�O�⧯�M�C\n" );
    }
    set("apply_weapon/lefthand",
        ([ "dex": 10,
           "wittiness": 30,
           "savage hit": 10,
    ]) );
    setup();
}
