#include <weapon.h>
#include <ansi.h>

inherit F_WEAPON;

void create()
{
    set_name(HIW"�լӳD�j"NOR, ({ "whitesnake lance", "lance" }));
    set_weight(15000);
    setup_weapon(120, 150, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "��");
        set("value", 261935);
        set("long", "�j�����աA�Y�p�D�Y�A�����@�ݡA�N���@�����b�娫���ճD�C\n" );
        set("wield_msg", "$n"HIY"�u��v�a�@�n�q$N�I��u�X�Aíí�����b$N��W�C\n"NOR);
        set("unwield_msg", HIY"$N�N$n"HIY"�ªŤ��@�ߡA$n"HIY"�۰ʸ��^$N�I�W�C\n"NOR);
    }
    // ���[��O
    set("apply_weapon/twohanded", 
        ([ "str": 5,
           "con": 2,
           "attack": 10,
           "evade": 10,
           "continual hit": 10,
    ]) );
    setup();
}
