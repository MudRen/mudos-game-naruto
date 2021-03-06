#include <weapon.h>
#include <ansi.h>

inherit F_WEAPON;

int i = 0;
int do_attack(object obj);

string *combat_wp = ({
    "$N單手舉起沉重的火砲大喊「戰艦砲」然後一砲轟向$n",
    "$N提起$w衝向，隨手一記反扣，用$w砲側擊向$n$l",
    "$N對著一旁的空曠處發出一砲，利用反衝力快速撞向$n",
});

string getCombatAction(object me, object weapon)
{
    if( weapon->is_weapon() ) return combat_wp[random(sizeof(combat_wp))];
    else return RACE_D(me->query_race())->query_action();
}

void create()
{
    set_name("海軍制式火砲", ({ "fire gun", "gun" }));
    set_weight(5000);
    setup_weapon(20, 20, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "柄");
        set("value", 2020);
        set("have_mag", 1);
        set("long", "海兵單兵作戰需要高傷害時會使用的大型手持火炮。\n"
                    "火砲只能發射一次，發射過後必須更換火繩才能再次射擊。\n"
                    "使用"HIY"[change gun]"NOR"可以更換火繩(需要有火繩才能更換)\n"
                    "使用"HIY"[gun attack on (目標)]"NOR"射擊敵人。\n");
    }
    set("wield_msg", "$N將沉重的$n扛在肩膀上。\n");
    setup();
}

void init()
{
    add_action("do_firegun", "gun");
    add_action("do_change", "change");
}

int do_change(string arg)
{
    object cord;

    if( this_player()->is_busy() )
        return notify_fail("你正在忙碌，沒時間換火繩。\n");

    if( !objectp(cord = present("_CORD_", this_player())) )
        return notify_fail("火繩都沒有想換什麼火繩。\n");

    if( arg == "gun" ) {
        if( i >= 1) {
            i = 0;
            message_vision(CYN"$N拿出火繩塞進火砲後端。\n"NOR, this_player());
            write("火繩已經塞好了。\n");
            cord->add_amount(-1);
            if( cord->query_amount() <= 0 ) destruct(cord);
            return 1;
        } else {
            write("火繩還在阿，要換什麼？。\n");
            return 1;
        }
        if( this_player()->is_fighting() ) {
            write("你在戰鬥中更換火繩，一時間無法行動！");
            this_player()->start_busy(3);
        } else {
            this_player()->start_busy(1);
        }
    }
    return 0;
}

int do_firegun(string arg)
{
    string func,target;
    object ob;

    if( this_player()->is_busy() )
        return notify_fail("你正在忙碌中，沒空使用。\n");

    if( !this_object()->query("equipped") )
        return notify_fail("你沒拿火砲怎麼用。\n");

    if( !this_player()->is_fighting() )
        return notify_fail("沒有戰鬥亂放火炮很危險的。\n");

    if( !arg || sscanf(arg, "%s on %s", func, target)!=2 )
        return notify_fail("使用指令為 gun attack on <目標>\n");

    if( !objectp(ob = present(target, environment(this_player()))) )
        return notify_fail("找不到目標對象。\n");

    if( !ob || !ob->is_character() || ob->is_corpse() || ob == this_player() )
        return notify_fail("對付他不需要用到火砲。\n"NOR);

    if( func == "attack" ) {
        do_attack(ob);
    }
    return 1;
}

int do_attack(object ob)
{
    string msg;
    object me;
    int damage, exact, evade;

    me = this_player();
    exact = me->query_level();
    evade = ob->query_level();

    if( i > 0 ) {
        message_vision("$N妄想使用火砲，但是根本沒裝火繩。\n", me);
        return 1;
    }
    me->add_temp("apply/attack", 300);
    damage = COMBAT_D->isDamage(me, ob, this_object());
    me->add_temp("apply/attack", -300);

    if( damage < 100 ) damage = random(100);

    message_vision("\n$N用火砲對準$n，轟隆一聲發射出去，$N整個人跌了一跤。\n", me, ob);
    if( !COMBAT_D->SkillHit(me, ob, exact, evade) ) {
        message_vision("結果火砲打中了地面，地上一片焦黑。\n\n", me, ob);
    } else {
        ob->damage_stat("hp", damage, me);
        message_vision( sprintf("$n$n「磅」地一聲，火彈在$n的身上炸開，受到嚴重的傷害(%d) %s\n\n", damage, COMBAT_D->report_status(ob) ), me, ob);
    }
    i++;
    me->start_busy(4);
    return 1;
}
