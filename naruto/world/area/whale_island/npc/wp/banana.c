#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;

void create()
{
    set_name(HIY"香蕉"NOR, ({ "banana" }));
    set_weight(15000);
    setup_weapon(75, 90, 100, 1);
    
    if( !clonep() ) {
            set("wield_as", ({ "twohanded" }) );
        set("unit", "根");
          set("value", 44982);
        set("long", @long
    這是一根巨大的香蕉，根本就是一把長槍了，你試著用盡力氣也
無法剝下香蕉皮，看樣子就只能這樣子拿著了。
long
);
    }
    
    // 附加能力
      set("apply_weapon/twohanded", 
          ([ "str" : 1, "int" : 2, ]) 
   );

    setup();
}

