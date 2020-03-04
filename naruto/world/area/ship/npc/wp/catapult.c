#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

string *combat_wp = ({
    "$N�԰_$w�˷�$n��$l�ΤO�@�u�A�g�X�@�T�u�Y",
    "$N��F�@����Y��b$w�W��$n�u�h�A�@��H���Y�����g�V$n",
    "$N�H���֪��t�׳s�򮳥X�T���u�Y�u�X�g�V$n",
});

string getCombatAction(object me, object weapon)
{
    if( weapon->is_weapon() ) return combat_wp[random(sizeof(combat_wp))];
    else return RACE_D(me->query_race())->query_action();
}

void create()
{
    set_name("�u�}", ({ "catapult", "_CATAPULT_" }));
    set_weight(2000);
    setup_weapon(1, 3, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "��");
        set("value", 202);
        set("have_mag", 1);
        set("long", "�F�H�������p�u�}�A�ݰ_���٤����ΡC\n" );
    }
    setup();
}
