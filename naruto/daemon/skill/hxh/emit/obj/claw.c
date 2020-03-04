#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

string *combat_wp = ({
    "$N�i�}$w�R�q�@�n�A�ֳt�a��$n$l�۩I�L�h",
    "$N$w�W�o�X�@�D�{���A�H�ײ��L�k���Ѫ��t�����V$n$l",
    "$N�Q�Φۤv�����l�N$n�]��A�������_�a����$n",
});

string getCombatAction(object me, object weapon)
{
    if( weapon->is_weapon() ) return combat_wp[random(sizeof(combat_wp))];
    else return RACE_D(me->query_race())->query_action();
}

void create()
{
    set_name("�s��", ({ "dragon claw", "claw" }));
    set_weight(8000);
    setup_weapon(40, 55, 100, 1);

    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "��");
        set("value", 47094);
        set("have_mag", 1);
        set("long", "���s��O���j�ɩҾ֦����Q���C\n" );
    }
    setup();
}