#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name("�|���R�W���C", ({ "noname sword", "sword", "_CREATION_SWORD_" }));
    set_weight(5000);
    setup_weapon(1, 1, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand" }) );
        set("unit", "��");
        set("value", 0);
        set("no_box", 1);
        set("no_drop", 1);
        set("long", "�@�⥼�g�L��v���C�A�p�G�A�ݨ�o��C�ӧ�Ův�B�z�F�C\n" );
    }
    setup();
}
