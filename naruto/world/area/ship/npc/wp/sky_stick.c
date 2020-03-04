#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

string *combat_wp = ({
    "$N�o�ʡu"HIB"�N��w"NOR"�v��$n������Pı�@�}�B�N�A�~�M�Q��ˤF",
    "$N�N$w�@���X�u"YEL"�q��w"NOR"�v�ԼT�@�n�q��$n�z�z�j�s",
    "$N�j�X�@�����q�q���u"HIR"����w"NOR"�v�S��$n��$l���_�F�@�Ӥj���w",
});

string getCombatAction(object me, object weapon)
{
    if( weapon->is_weapon() ) return combat_wp[random(sizeof(combat_wp))];
    else return RACE_D(me->query_race())->query_action();
}

void create()
{
    set_name(HIC"�ѭԴ�"NOR, ({ "sky stick", "stick", "_WEATHER_" }));
    set_weight(2000);
    setup_weapon(75, 90, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "��");
        set("no_box", 1);
        set("value", 81740);
        set("have_mag", 1);
        set("long", "�F�H���Q�Ρu���v�һs�@���s�@�N�ѭԴΡA�¤O�j�j�C\n" );
    }
    set("apply_weapon/twohanded", 
        ([ "con" : 1,
           "dex" : 3,
           "int" : 1,
           "armor" : 30,
    ]) );
    setup();
}
