#include <npc.h>
#include <ansi.h>

inherit F_BANDIT;

int i;

string report_status(object ob)
{
    int ratio;
    if( !ob->query_stat_maximum("hp") ) return "\n";
    ratio = (int)ob->query_stat("hp")*100/(int)ob->query_stat_maximum("hp");
    if( ratio > 80 ) return HIK"["HIG"$n" + HIG + ratio + "%" + HIK"]\n"NOR;
    else if( ratio > 30 ) return HIK"["HIY"$n" + HIY + ratio + "%" + HIK"]\n"NOR;
    else return HIK"["HIR"$n" + HIR + ratio + "%" + HIK"]\n"NOR;
}
void do_fight()
{
    int damage;
    object enemy;
    // 沒有敵人
    enemy = this_object()->query_opponent();
    if( !enemy ) return;
    // 敵人在不同位置
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    if( i > 1 ) {
        message_vision("$N"HIG"慢慢往前走了一步！\n"NOR, this_object(), enemy);
        i = i-1;
        message_vision("$N"HIG"還距離"NOR"$n ("HIY+i+NOR") "HIG"步！\n"NOR, this_object(), enemy);
        return;
    }
    message_vision("$N"HIR"走到了"NOR"$n"HIR"身前，露出了奇怪的微笑...\n"NOR, this_object(), enemy);
    damage = enemy->query_stat_maximum("hp")/10;
    damage += random(50);
    if( random(10) >= 7) {
        message_vision("        $N拿起菜刀用力往空氣一戳...不知道在幹啥...(0)"+report_status(enemy)+""NOR, this_object(), enemy);
        i = random(10)+1;
        message_vision("$N"HIG"又往後跳離了"NOR"$n ("HIY+i+NOR") "HIG"步！\n"NOR, this_object(), enemy);
        return;
    }
    enemy->damage_stat("hp", damage, enemy);
    message_vision("        $N拿起菜刀往$n一戳，噗的一聲鮮血四濺。("+damage+")"+report_status(enemy)+""NOR, this_object(), enemy);
    i = random(10)+1;
    message_vision("$N"HIG"又往後跳離了"NOR"$n ("HIY+i+NOR") "HIG"步！\n"NOR, this_object(), enemy);
    return;
}
void do_garbage()
{
    int damage;
    object enemy;
    // 沒有敵人
    enemy = this_object()->query_opponent();
    if( !enemy ) return;
    // 敵人在不同位置
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    message_vision("$N"HIW"從懷裡拿出一堆垃圾往"NOR"$n"HIW"亂丟。\n"NOR, this_object(), enemy);
    damage = enemy->query_ability("intimidate")*2 + random(100);
    if( random(5) == 0) {
        message_vision("        $N力道太輕垃圾都丟歪了...(0)"+report_status(enemy)+""NOR, this_object(), enemy);
        return;
    }
    enemy->damage_stat("hp", damage, enemy);
    message_vision("        $n被垃圾砸的哭爹喊娘到處逃竄。("+damage+")"+report_status(enemy)+""NOR, this_object(), enemy);
    return;
}
void do_light()
{
    int damage;
    object enemy;
    // 沒有敵人
    enemy = this_object()->query_opponent();
    if( !enemy ) return;
    // 敵人在不同位置
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    if( this_object()->query_temp("quest/lightlight") == 1) {
    return;
    }
    message_vision("$N"HIG"搖晃著燈籠..往自己身上一照。\n"NOR, this_object(), enemy);
    this_object()->add_temp("quest/lightlight", 1);
    if( random(5) <= 1) {
        enemy->heal_stat("hp", 200);
        message_vision("        結果$N跌了一跤...光照到$n幫助$n回復體力(200)"+report_status(enemy)+""NOR, this_object(), enemy);
        call_out("light_1",20,this_object(),enemy);
        return;
    }
    this_object()->heal_stat("hp", 400);
    message_vision("        強光照在$n身上幫助回復體力。(400)"+report_status(this_object())+""NOR, enemy, this_object());
    call_out("light_1",20,this_object(),enemy);
    return;
}
void light_1()
{
    this_object()->delete_temp("quest/lightlight");
}
void create()
{
    set_name("通倍利", ({ "tonbeli" }));
    set_race("human");
    set_level(30);
    set("nickname",HIG"菜刀怪"NOR);
    set("age", 10+random(21));
    set("long","綠色提著燈籠的小妖怪，手上拿著一把奇怪的菜刀。\n");
    if( random(2) == 1) {
        set("gender", "female");
    } else {
        set("gender", "male");
    }
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
        CYN"通倍利緩緩的走著...\n"NOR,
    }));
    set("chat_chance_combat", 30);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"food", "id":23, "amount":1, "p1":30, "p2":100 ]),   // 高路魚
        ([ "type":"food", "id":24, "amount":1, "p1":30, "p2":100 ]),   // 路杰魚
        ([ "type":"food", "id":27, "amount":1, "p1":30, "p2":100 ]),   // 漱魚
        ([ "type":"food", "id":26, "amount":1, "p1":30, "p2":100 ]),   // 刷魚
        ([ "type":"food", "id":25, "amount":1, "p1":30, "p2":100 ]),   // 膏魚
        ([ "type":"obj", "id":77, "amount":1, "p1":1, "p2":200 ]),     // 通倍利燈籠
        ([ "type":"wp", "id":46, "amount":1, "p1":1, "p2":450 ]),      // 菜刀
        ([ "type":"eq", "id":86, "amount":1, "p1":5, "p2":100 ]),      // 通大衣
    }) );
    setup();
}
int accept_fight(object ob)
{
    do_chat((: command, "shake" :));
    return 0;
}
int accept_kill(object ob)
{
    if( this_object()->query_temp("quest/tonbeli_go") == 1 ) {
        message_vision("$N決定開始跟隨$n一起行動。\n", this_object(), this_player());
        this_object()->set_leader(this_player());
        return 0;
    }
    if( random(20) > 18) {
        set_name("通倍利王", ({ "tonbeli king", "king" }));
        set_race("human");
        set_level(40);
        set("nickname",HIY"菜刀王"NOR);
        set("age", 45);
        set("long","綠色提著燈籠的妖怪，手上拿著一把奇怪的菜刀，頭上戴著皇冠。\n");
        message_vision(HIG"「碰」的一陣煙霧竄起，"NOR"通倍利"HIG"居然變身成了"NOR"$N"HIG"！\n"NOR, this_object());
        set("chat_chance", 1);
        set("chat_msg", ({
            CYN"通倍利王拿著燈龍照亮四周。\n"NOR,
        }));
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
            (: do_fight :),
            (: do_garbage :),
            (: do_fight :),
            (: do_light :),
            (: do_fight :),
        }) );
        set("set_drop", ({
            ([ "type":"food", "id":28, "amount":1, "p1":20, "p2":100 ]),   // 鮑魚
            ([ "type":"food", "id":45, "amount":1, "p1":20, "p2":100 ]),   // 生蠔
            ([ "type":"obj", "id":77, "amount":1, "p1":5, "p2":100 ]),     // 通倍利燈籠
            ([ "type":"wp", "id":46, "amount":1, "p1":1, "p2":300 ]),      // 菜刀
            ([ "type":"eq", "id":86, "amount":1, "p1":20, "p2":100 ]),     // 通大衣
        }) );
        add_temp("apply", (["hp":1100, "ap":1100, "mp":1100, "attack":455,
                            "armor": 383, "intimidate":20, "wittiness":20,
                            "exact":50, "evade":50, "move":20 ]) );
        do_heal();
    }
    this_object()->add_temp("quest/tonbeli_go", 1);
    message_vision("$N決定開始跟隨$n一起行動。\n", this_object(), this_player());
    this_object()->set_leader(this_player());
    i = random(10)+1;
    message_vision("$N"HIG"還距離"NOR"$n ("HIY+i+NOR") "HIG"步！\n"NOR, this_object(), this_player());
}
