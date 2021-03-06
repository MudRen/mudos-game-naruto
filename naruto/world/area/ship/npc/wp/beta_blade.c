#include <weapon.h>
#include <ansi.h>

inherit F_WEAPON;

void create()
{
    set_name(HIR"菊"HIW"一文字"NOR, ({ "chrysanthemum katana", "katana" }));
    set_weight(15000);
    setup_weapon(120, 150, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "把");
        set("no_box", 1);
        set("value", 320935);
        set("long", "菊一文字是後鳥羽上皇時御命所鍛之刀，因為刃部刻有代表皇家的菊\n"
                    "花紋，其下又雕上一橫一字紋，故稱為菊一文字。\n");
    }
    // 附加能力
    set("apply_weapon/twohanded", 
        ([ "dex": 5,
           "int": 2,
           "armor": 10,
           "exact": 10,
           "continual hit": 10,
    ]) );
    setup();
}
