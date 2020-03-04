#include <weapon.h>
#include <ansi.h>

inherit F_WEAPON;

void create()
{
    set_name(HIR"��"HIW"�@��r"NOR, ({ "chrysanthemum katana", "katana" }));
    set_weight(15000);
    setup_weapon(120, 150, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "��");
        set("no_box", 1);
        set("value", 320935);
        set("long", "��@��r�O�᳾�ФW�Ӯɱs�R���뤧�M�A�]���b���観�N��Ӯa����\n"
                    "�᯾�A��U�S�J�W�@��@�r���A�G�٬���@��r�C\n");
    }
    // ���[��O
    set("apply_weapon/twohanded", 
        ([ "dex": 5,
           "int": 2,
           "armor": 10,
           "exact": 10,
           "continual hit": 10,
    ]) );
    setup();
}
