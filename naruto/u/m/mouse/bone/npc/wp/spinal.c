#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;

void create()
{
    set_name(HIW"�ᰩ�C"NOR, ({ "spinal sword", "sword" }));
    set_weight(7000);
    setup_weapon(90, 110, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "righthand" }) );
        set("unit", "��");
        set("value", 180300);
        set("long", "�q��հ��ޥX�Ӫ������C�A�W���g���A��ݨӫD�`�i�ȡC\n" );
    }
    // ���[��O
    set("apply_weapon/righthand", 
        ([ "str": 4,
           "attack": 10,
           "intimidate": 10,
           "heavy hit": 10,
    ]) );
    setup();
}
