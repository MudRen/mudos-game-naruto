#include <weapon.h>
#include <ansi.h>

inherit F_WEAPON;

void create()
{
    set_name(HIK"�M�D"HIW"�@��r"NOR, ({ "beta katana", "katana" }));
    set_weight(15000);
    setup_weapon(170, 190, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "��");
        set("no_box", 1);
        set("value", -1);
        set("long", "�I�t�ۭ��n�O�Ъ������R�M�A���ۥ����P�ڷQ�@�P�i�h���N�ӡC\n" );
    }
    // ���[��O
    set("apply_weapon/twohanded", 
        ([ "str": 10,
           "attack": 30,
           "evade": 15,
           "exact": 15,
           "continual hit": 10,
    ]) );
    setup();
}
