#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;
void create()
{
    set_name(BRED+HIR"血繼左攻"NOR, ({ "blood sword", "sword" }) );
    set_weight(100);
    setup_weapon(40, 50, 200, 1);    
    if( !clonep() ) {
        set("unit", "把");
        set("value", 0);
        set("long", "具有神秘功效的雙面血刃\n");
        set("wield_as",  ({ "lefthand" }) );
        set("wield_msg",RED+"$N拿起一把"+name()+RED"臉上浮現出一股血光！\n"NOR);
    }

    setup();
}


