#include <npc.h>
#include <ansi.h>

inherit F_FIGHTER;

int num=0;

string report_status(object ob)
{
    int ratio;
    if( !ob->query_stat_maximum("hp") ) return "\n";
    ratio = (int)ob->query_stat("hp")*100/(int)ob->query_stat_maximum("hp");
    if( ratio > 80 ) return HIK"["HIG"$N" + HIG + ratio + "%" + HIK"]\n"NOR;
    else if( ratio > 30 ) return HIK"["HIY"$N" + HIY + ratio + "%" + HIK"]\n"NOR;
    else return HIK"["HIR"$N" + HIR + ratio + "%" + HIK"]\n"NOR;
}
void do_check()
{
    if( num > 0) {
        set("chat_chance", 10);
        this_object()->heal_stat("hp", num);
        message_vision("$N"HIW"從地上撿起骸骨補充剛才消耗骨頭的傷害。("HIR+num+HIW")"+report_status(this_object())+""NOR, this_object());
        num = 0;
    }
}
void do_whip(object enemy)
{
    int damage, i;
    object* targets;
    // 沒有敵人
    set("chat_chance", 100);
    enemy = this_object()->query_opponent();
    targets = this_object()->query_enemy();
    if( !enemy ) return;
    // 敵人在不同位置
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    num = num + 30;
    message_vision("$N"NOR"從身上爆出幾根骨頭使出「"HIY"柳之舞"NOR"」骨頭像鞭子般打向四方！\n"NOR, this_object(), enemy);
    for(i=0;i<sizeof(targets);i++) {
        if( i > 9) break;   // 對十個人有用
        damage = random(401)+150;
        if( random(targets[i]->query_ability("evade")) > 250) {
            message_vision("        $N狼狽的躲過了攻擊！(0)"+report_status(targets[i])+"", targets[i], this_object());
            this_object()->start_busy(1);
        } else {
            targets[i]->damage_stat("hp", damage, targets[i]);
            message_vision("        $N被骨頭掃中，身上馬上多了一道傷痕。("+damage+")"+report_status(targets[i])+"", targets[i], this_object());
        }
    }
}
void do_flower()
{
    int damage;
    object enemy;
    // 沒有敵人
    set("chat_chance", 100);
    enemy = this_object()->query_opponent();
    if( !enemy ) return;
    // 敵人在不同位置
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    num = num + 50;
    message_vision("$N"NOR"手骨瞬間爆出，變成有如刺槍般的「"HIR"鐵線花之舞"NOR"」！\n"NOR, this_object(), enemy);
    damage = random(this_object()->query_ability("attack")) - random(enemy->query_ability("defend"));
    if( damage <= 0 || random(enemy->query_ability("wittiness")) > 250) {
        message_vision("        $N費了一番功夫才將此招化解！(0)"+report_status(enemy)+"", enemy, this_object());
        this_object()->start_busy(2);
        return;
    }
    enemy->damage_stat("hp", damage, enemy);
    message_vision("        「噗」地一聲在$N身上戳出一道血洞，血流不止。("+damage+")"+report_status(enemy)+"", enemy, this_object());
    enemy->start_busy(1);
    return;
}
void do_finger()
{
    int damage;
    object enemy;
    // 沒有敵人
    set("chat_chance", 100);
    enemy = this_object()->query_opponent();
    if( !enemy ) return;
    // 敵人在不同位置
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    num = num + 50;
    message_vision("$N"NOR"十指放平朝著$n射出「"HIW"指骨"NOR"」！\n"NOR, this_object(), enemy);
    damage = random(151)+50;
    if( random(enemy->query_ability("evade")) > 300) {
        message_vision("        $N快速的閃過了指骨！(0)"+report_status(enemy)+"", enemy, this_object());
        this_object()->start_busy(1);
    } else {
        enemy->damage_stat("hp", damage, enemy);
        message_vision("        $N「噗」地一聲被指骨戳出了一道傷口。("+damage+")"+report_status(enemy)+"", enemy, this_object());
    }
    damage = random(151)+50;
    if( random(enemy->query_ability("evade")) > 300) {
        message_vision("        $N快速的閃過了指骨！(0)"+report_status(enemy)+"", enemy, this_object());
        this_object()->start_busy(1);
    } else {
        enemy->damage_stat("hp", damage, enemy);
        message_vision("        $N「噗」地一聲被指骨戳出了一道傷口。("+damage+")"+report_status(enemy)+"", enemy, this_object());
    }
    damage = random(151)+50;
    if( random(enemy->query_ability("evade")) > 300) {
       message_vision("        $N快速的閃過了指骨！(0)"+report_status(enemy)+"", enemy, this_object());
        this_object()->start_busy(1);
        return;
    } else {
        enemy->damage_stat("hp", damage, enemy);
        message_vision("        $N「噗」地一聲被指骨戳出了一道傷口。("+damage+")"+report_status(enemy)+"", enemy, this_object());
        return;
    }
}
void do_fight()
{
    int damage;
    object enemy;
    // 沒有敵人
    set("chat_chance", 100);
    enemy = this_object()->query_opponent();
    if( !enemy ) return;
    // 敵人在不同位置
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    num = num + 200;
    message_vision("$N"NOR"身子往地下一沉，使出捨命必殺"HIY"『"HIR+BLINK"早蕨之舞"NOR+HIY"』"NOR"全身骨頭戳向四面八方！\n"NOR,this_object(), enemy);
    damage = random(this_object()->query_ability("attack"))*2 + 100;
    damage -= random(enemy->query_ability("defend"));
    if( damage <= 0 || random(enemy->query_ability("evade")) > 450) {
        message_vision("        $N率先看穿了攻擊才避開此招！(0)"+report_status(enemy)+"", enemy, this_object());
        this_object()->start_busy(2);
        return;
    }
    enemy->damage_stat("hp", damage, enemy);
    message_vision("        「噗噗」連續幾聲，$N早已被戳成蜂窩，血流如注。("+damage+")"+report_status(enemy)+"", enemy, this_object());
    return;
}
void do_clone()
{
    object enemy, item;
    // 沒有敵人
    set("chat_chance", 100);
    enemy = this_object()->query_opponent();
    item = new(__DIR__"wp/spinal.c");
    if( !enemy ) return;
    // 敵人在不同位置
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    if( this_object()->query_temp("quest/psychical") == 1) {
    return;
    }
    this_object()->add_temp("quest/psychical", 1);
    num = num + 300;
    message_vision("$N"HIW"背部慢慢凸起一塊白色骨頭，伸手拔出後居然是他自己的脊椎骨！\n"NOR, this_object());
    item->move(this_object());
    do_chat((: command, "wield sword" :));
    return;
}
void create()
{
    set_name("輝夜剛之郎", ({ "wheya gon lon", "lon" }) );
    set_level(60);
    set_class("superior");
    set_race("human");
    set("gender", "male");
    set("age", 85);
    set("title",HIR"輝夜族長"NOR);
    set("long",@LONG
輝夜族長，一個八十多歲的小老頭，但是他眼神銳利，四周的一切都
逃不過他的眼睛。當年輝夜族人被追殺時的傷痕全都留在身上，全身
各處都有大大小小的傷痕，不過這些傷痕看似圓形從內往外的撕裂傷
，據說輝夜族人有種血繼限界，能將自己身上的骨頭拔出，雖然會對
自己造成傷害，所拔出的武器卻能夠隨心所慾的變化，比一般的武器
還要好用。也因為這樣，所以輝夜一族又被稱為『惡魔一族』
LONG);
    set("chat_chance", 10);
    set("chat_msg", ({
        (: do_check :),
        (: command, "say 走了蛇人又來個怪物...":),
        (: command, "say 族人都派去對付蛇人了。":),
        (: command, "say 只要是大蛇丸大人託付的任務，一定要完成。":),
    }));
    set("chat_chance_combat", 15);
    set("chat_msg_combat", ({
        (: do_fight :),
        (: do_clone :),
        (: do_flower :),
        (: do_finger :),
        (: do_whip :),
    }) );
    set("set_drop", ({
        ([ "type":"obj", "id":28, "amount":1+random(5), "p1":60, "p2":100 ]), // 黃金
        ([ "type":"obj", "id":78, "amount":1, "p1":100, "p2":100 ]),   // 輝夜之證
        ([ "type":"wp", "id":50, "amount":1, "p1":1, "p2":200 ]),      // 脊骨劍
        ([ "type":"eq", "id":85, "amount":1, "p1":1, "p2":150 ]),      // 咒印覆面
    }) );
    setup();
}
void relay_say(object ob, string arg)
{
    if( arg == "蛇人" )  {
        do_chat(({
            (: command, "say 這裡跟神廟、戰事林、絕望沼澤以前都是蛇人的地盤。" :),
            (: command, "say 我們來了之後截斷骸骨戰場，讓牠們兩地無法溝通。" :),
            (: command, "say 接著全力攻擊戰事林那裡的蛇族本村。" :),
            (: command, "say 就在我們和蛇人兩敗俱傷時...忽然跑出一堆怪物。" :),
            (: command, "say 那些怪物把我們和蛇人打跑，就佔據了那裡。" :),
        }));
        return;
    }
    if( arg == "怪物" )  {
        do_chat(({
            (: command, "say 牠們有著綠色的身體，還拿著一把菜刀" :),
            (: command, "say 我們通稱牠們叫「通倍利」。" :),
            (: command, "say 牠們現在就定居在戰事林。" :),
            (: command, "say 攻擊牠們要小心。" :),
            (: command, "say 牠們的王也會偽裝成普通的通倍利混在裡面。" :),
            (: command, "ah" :),
            (: command, "say 還有...戰事林中間有兩間破屋。" :),
            (: command, "say 通倍利們好像不太願意接近其中的一間。" :),
            (: command, "say 不要問為什麼，知道這個一定對你有幫助的。" :),
        }));
        return;
    }
    if( arg == "大蛇丸" )  {
        do_chat(({
            (: command, "say 他是我們輝夜一族的恩人！" :),
        }));
        return;
    }
    if( arg == "族人" )  {
        do_chat(({
            (: command, "say 當然就是我們輝夜一族！" :),
        }));
        return;
    }
    if( arg == "任務" )  {
        if( this_player()->query_temp("quest/tonlight") == 1) {
        do_chat(({
            (: command, "say 不想幫忙就說「不幫」" :),
            (: command, "say 這種任務讓外人來辦也是我的疏失。" :),
        }));
        return;
        } else
        if( this_player()->query_temp("quest/tonlight") == 2) {
            do_chat(({
                (: command, "say 不想幫忙嗎？" :),
                (: command, "say 那就「停止」繼續幫忙吧。" :),
            }));
            return;
        }
        this_player()->add_temp("quest/tonlight", 1);
        do_chat(({
            (: command, "say 是大蛇丸託付給我們的任務。" :),
            (: command, "say 目標是戰事林通倍利所拿的燈籠。" :),
            (: command, "say 因為這燈籠具有療傷的功能，所以大蛇丸大人非常好奇。" :),
            (: command, "say 殺光牠們也能順便北上到沼澤滅了蛇人！" :),
            (: command, "say 有興趣可以「幫助」我阿！" :),
        }));
        return;
    }
    if( arg == "幫助" ) {
        if( this_player()->query_temp("quest/tonlight") == 2) {
            do_chat(({
                (: command, "say 你已經在幫我了！" :),
            }));
            return;
        } else
        if( this_player()->query_temp("quest/tonlight") == 1) {
            this_player()->add_temp("quest/tonlight", 1);
            do_chat(({
                (: command, "say 那就交給你了。" :),
                (: command, "say 給我通倍利的燈籠就好。" :),
            }));
            return;
        } else {
            do_chat(({
                (: command, "?" :),
                (: command, "say 不先聽聽任務是啥？" :),
            }));
            return;
        }
    }
    if( arg == "停止" || arg == "不幫" )  {
        if( this_player()->query_temp("quest/tonlight") < 1) {
            do_chat(({
                (: command, "?" :),
                (: command, "say 你沒有幫助我吧。" :),
            }));
        } else {
        this_player()->delete_temp("quest/tonlight");
            do_chat(({
                (: command, "hmm" :),
                (: command, "say 好吧，我們自己對付牠們。" :),
            }));
            return;
        }
    }
}
int give_check(object ob)
{
    if( ob->id("_TONBELI_A_") ) return 1;   // 通倍利燈籠
    else return 0;
}
int accept_object(object me, object ob)
{
    int amount;
    object item;

    amount = ob->query_amount();

    if( is_busy() ) {
        do_chat((: command, "say 稍等一下。" :));
        return 0;
    }
    if( is_fighting() ) {
        do_chat((: command, "say 好傢伙！受死吧！" :));
        return 0;
    }
    me->start_busy(1);
    this_object()->start_busy(1);
    switch( give_check(ob) ) {
        case 1:
            if( me->query_temp("quest/tonlight") != 2) {
                do_chat((: command, "say 我沒找你幫忙吧！" :));
                return 0;
            }
            amount = ob->query_amount();
            message_vision("$N接過$n後點點頭。\n"NOR, this_object(), ob);
            do_chat( ({
               (: command, "say 就是這個沒錯。" :),
               (: command, "say 你完成任務了！" :),
               ( : destruct , ob : ),
            }) );
            tell_object(me, "( "HIY+amount*50000+HIG" 兩銀子已經自動存在銀行裡。"NOR")\n");

            me->add("bank", amount*50000);

            // 移除暫存的資料
            me->delete_temp("quest/tonlight");
            break;
        default:
            do_chat((: command, "say 別拿其他的東西給我。" :));
            return 0;
            break;
    }
    return 1;
}
void die()
{
    object ob, *obs;
    obs = all_inventory(this_object());
    if( this_object()->query_temp("quest/psychical") == 1 ) {
        message_vision("因為$N死掉所以"HIW"脊骨劍"NOR"漸漸風化了...。\n"NOR, this_object());
        this_object()->delete_temp("quest/psychical");
        foreach( ob in obs ) destruct(ob);
    }
    ::die();
}
