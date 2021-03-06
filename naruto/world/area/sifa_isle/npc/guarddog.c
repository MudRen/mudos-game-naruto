#include <ansi.h>
#include <npc.h>

inherit F_SEASOLDIER;

void do_fight()
{
    object ob, enemy, me;

    me = this_object();
    enemy = me->query_opponent();

    // 沒有敵人
    if( !enemy ) return;

    // 敵人在不同位置
    if( environment(me)->is_area() ) {
        if( !area_environment(me, enemy) ) return;
    } else {
        if( environment(enemy) != environment(me) ) return;
    }
    // 找不到狗不命令
    if( ob = present("_SIFA_DOG_", environment(me)) ) {

        // 如果狗已經在攻擊敵人就不命令
        if( ob->is_fighting(enemy) ) return;

        message_vision("\n$N大喊著："HIG"上阿"+ob->query("name")+"！去咬"+enemy->query("name")+"！\n"NOR, me);
        ob->kill_ob(enemy);
        enemy->kill_ob(ob);
        return;
    }
    return;
}
void do_clone()
{
    object mob;
    int x, y;

    x = this_object()->query("area_info/x_axis");
    y = this_object()->query("area_info/y_axis");
    mob = new(__DIR__"dog.c");

    if( this_object()->query_temp("dog_clone") != 1 ) {
        message_vision("$N"HIY"拿出獸笛吹了幾聲，從旁邊跑出一隻司法犬。\n"NOR, this_object());
        if( environment(this_object())->is_area() ) {
            if( area_move(environment(this_object()), mob, x, y) ) {
                mob->guard_ob(this_object());
                mob->set_leader(this_object());
                this_object()->guard_ob(mob);
                this_object()->set_temp("dog_clone", 1);
                return;
            }
            message_vision("但是笛子好像壞掉了，吹不出聲音。\n", this_object());
            do_chat((: random_move :));
            return;
        }
        message_vision("但是這裡是房間，聲音傳不出去。\n", this_object());
        do_chat((: random_move :));
        return;
    }
    do_chat((: random_move :));
}
void create()
{
    set_name("守衛", ({ "guard", "_GUARD_" }) );
    set_race("human");
    set_level(30);
    set("title",HIC"司法島"NOR);
    set("nickname",HIR"法狗部隊"NOR);
    set("class", "guard_sea");
    set("camp", "police");
    set("age", 10+random(71));
    set("long", "騎著司法島大型犬類的特種士兵，利用手上所帶的利爪進行攻擊。\n");
    set("chat_chance", 15);
    set("chat_msg", ({
        (: do_clone :),
    }));
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"obj", "id":100, "amount":1, "p1":60, "p2":100 ]),              // 彈夾
        ([ "type":"obj", "id":102, "amount":1, "p1":40, "p2":100 ]),              // 火繩
        ([ "type":"wp", "id":38, "amount":1, "p1":20, "p2":100 ]),                // 長勾鐵爪
        ([ "type":"wp", "id":35, "amount":1, "p1":50, "p2":100 ]),                // 鐵勾
    }) );
    setup();
    carry_object(_DIR_AREA_"wild/npc/wp/wolf_claw.c")->wield();
    carry_object(_DIR_AREA_"wild/npc/wp/wolf_claw.c")->wield("lefthand");
}
