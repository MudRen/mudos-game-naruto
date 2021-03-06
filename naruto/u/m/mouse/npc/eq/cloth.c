#include <ansi.h>
#include <armor.h>

inherit F_CLOTH;

void create()
{
    set_name(HIW"電子"NOR+HIG"戰衣"NOR, ({ "electorn cloth", "cloth" }));
    set_weight(500);
    setup_cloth();
    if( !clonep() ) {
        set("unit", "件");
        set("value", 10);
        set("long", "未來產物，擁有戰鬥中補助回復的功能。\n");
        set("wear_as", "cloth");
        set("wear_msg", "$n"HIM"化為分子狀態包住"NOR"$N"HIM"，慢慢形成一件合身的戰衣。\n"NOR);
        set("unequip_msg", "$n"HIM"「框啷」一聲，就像玻璃破碎般漸漸脫離"NOR"$N"HIM"。\n"NOR);
        set("apply_armor/cloth", ([
            "exact": 500,
            "evade": 500,
            "intimidate": 500,
            "wittiness": 500,
            "carriage": 1000,
            "savage hit": 50,
            "continual hit": 50,
            "heavy hit": 50,
            "combat": 20,
        ]));
    }
    setup();
}
void init()
{
    add_action("do_wear", "wear");
}
int do_wear(string arg)
{
    call_out("fightheal_1", 10, this_player());
}
void fightheal_1()
{
    int i, heal;
    i = random(3);
    if( !this_object()->query("equipped")) {
        return;
    }
    if( !this_player()->is_fighting() ) {
        call_out("fightheal_1", 20, this_player());
        return;
    }
    if( i == 0) {
        heal = random(130)+20;
        message_vision("\n$N"HIC"發出陣陣光芒，似乎回復了"NOR"$n"HIC"的精神。("+heal+")\n\n"NOR, this_object(), this_player());
        this_player()->heal_stat("ap", heal);
        call_out("fightheal_1", 10, this_player());
        return;
    }
    if( i == 1) {
        heal = random(250)+50;
        message_vision("\n$N"HIR"發出陣陣光芒，似乎回復了"NOR"$n"HIR"的體力。("+heal+")\n\n"NOR, this_object(), this_player());
        this_player()->heal_stat("hp", heal);
        call_out("fightheal_1", 10, this_player());
        return;
    }
    if( i == 2) {
        heal = random(120)+20;
        message_vision("\n$N"HIY"發出陣陣光芒，似乎回復了"NOR"$n"HIY"的ＭＰ。("+heal+")\n\n"NOR, this_object(), this_player());
        this_player()->heal_stat("mp", heal);
        call_out("fightheal_1", 10, this_player());
        return;
    }
    return;
}
