#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

string *combat_wp = ({
    "$N�N$w�i�}�A�k���F��������$w�W�������A�@�D�U�Q���u�Y�g�V$n$l",
    "$N�Q�ΤF$w���u�ʻP���׸��t�A�H�ߪ��u���覡�g�X�u�Y�{�V$n�Y��",
    "$N���g�X��T���Y���$n��ʦ�m�A�M��N�u�Y�����˷�$n$l�g�X",
});

string getCombatAction(object me, object weapon)
{
    if( weapon->is_weapon() ) return combat_wp[random(sizeof(combat_wp))];
    else return RACE_D(me->query_race())->query_action();
}

void create()
{
    set_name(HIG"�¤}"NOR, ({ "du bow", "bow", "_CATAPULT_" }));
    set_weight(8000);
    setup_weapon(80, 80, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "��");
        set("no_box", 1);
        set("value", 51320);
        set("have_mag", 1);
        set("long", "�j�ƹL���j���u�}�A�S�٬��u�W���P�v�C\n" );
    }
    set("apply_weapon/twohanded", 
        ([ "dex" : 5,
           "exact" : 30,
    ]) );
    setup();
}
