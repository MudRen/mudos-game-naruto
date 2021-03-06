#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

string *combat_wp = ({
    "$N發瘋似的舉起$w使出一招「"HIY"橫掃千軍"NOR"」快速劈向$n的$l",
    "$N忽然轉起圈來「"HIC"旋風斧"NOR"」逐漸逼近$n猛砍",
    "$N用力將$w往地上一砸「"HIR"天崩地裂"NOR"」登時地面裂出一道鬥氣砍向$n",
});

string getCombatAction(object me, object weapon)
{
    if( weapon->is_weapon() ) return combat_wp[random(sizeof(combat_wp))];
    else return RACE_D(me->query_race())->query_action();
}

void create()
{
    set_name(HIY"鬥"NOR"斧", ({ "dou fu", "fu" }));
    set_weight(1000);
    setup_weapon(50, 100, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "twohanded" }) );
        set("unit", "把");
        set("value", 7272);
        set("have_mag", 1);
        set("long", "鬥神所用的斧頭，代號欺冷欺冷。\n" );
    }
    setup();
}
