#include <npc.h>
#include <ansi.h>

inherit F_VILLAGER;

void create()
{
    set_name("土著祭師" , ({ "wizard" }));
    set("long", "打扮非常奇怪的人，手拿著一根彎彎曲曲的木杖。\n");
    set_level(40);
    set("gender","male");
    set("title",HIG"右祭"NOR);
    set("age",40+random(50));

    // 一般時動作
    set("chat_chance", 6);
    set("chat_msg", ({
        (: command, "say 能到這裡也算與神木有緣。" :),
        (: command, "say 誰能將我所『需要』的東西拿來給我呢？" :),
        (: command, "say 身為祭師還是要懂些外來語言的。" :),
    }) );

    set("set_drop", ({
        ([ "type":"food", "id":40, "amount":1+random(4), "p1":80, "p2":100 ]),  // 乾果
        ([ "type":"food", "id":38, "amount":1+random(3), "p1":70, "p2":100 ]),  // 樹果
        ([ "type":"food", "id":39, "amount":1+random(1), "p1":50, "p2":100 ]),  // 水果
        ([ "type":"food", "id":41, "amount":1, "p1":20, "p2":100 ]),            // 水果王
        ([ "type":"eq", "id":71, "amount":1, "p1":20, "p2":100 ]),              // 樹葉
        ([ "type":"wp", "id":21, "amount":1, "p1":2, "p2":100 ]),               // 神杖
    }));
    setup();
}

void relay_say(object ob, string arg)
{
    if( arg == "需要" )  {
        do_chat( ({ 
            (: command, "say 只要能給我兩百顆猴牙，就給你神木的祝福項鍊。" :),
        }) );
        return;
    }
}

int give_check(object ob)
{
    if( ob->id("_WATER_FRUIT_") ) return 1;           // 水果
    if( ob->id("_MONKEY_TOOTH_") ) return 2;          // 猴牙
    else return 0;
}
int accept_object(object me, object ob)
{
    object item;
    if( this_object()->is_busy() ) {
        do_chat((: command, "say 急什麼！祝福可是很花時間的！" :));
        return 0;
    }
    if( this_object()->is_fighting() ) {
        do_chat((: command, "say 看我被打還不快幫忙！不想要項鍊啦！" :));
        return 0;
    }
    me->start_busy(1);
    this_object()->start_busy(1);
    switch( give_check(ob) ) {
        case 1:
            if( me->query_temp("quest/necklace") == 1) {
                if( ob->query_amount() != 70 ) {
                    do_chat((: command, "say 水果給的數目不對喔，再去多採點吧。" :));
                    return 0;
                }
                if( file_size(__DIR__"eq/necklace.c") < 0 ) return 0;
                if( catch(item = new(__DIR__"eq/necklace.c")) ) return 0;
                if( item->move(me) ) {
                    message_vision("$N將"HIM"水果"NOR"清點後從旁邊拿出一串" + item->name() + "給$n。\n", this_object(), me);
                    message_vision("土著祭師溫和地說﹕"HIG"$n快離開吧，其他土著們可不歡迎外人。\n"NOR, this_object(), me);
                } else if( item->move(this_object()) ) {
                    message_vision("$N將"HIY"樹果"NOR"清點後從旁邊拿出一串" + item->name() + "。\n", this_object(), me);
                    message_vision("土著祭師說道﹕"HIG"$n身上太重了，就丟在地上吧。\n"NOR, this_object(), me);
                } else {
                    me->delete_temp("quest/necklace");
                    destruct(item);
                    return 0;
                }
                me->delete_temp("quest/necklace");
                ob->set_amount(0);
                do_chat(({ 
                    (: command, "drop necklace" :),
                    (: destruct, ob :),
                }));
                break;
            } else {
                message_vision("土著祭師說道﹕"HIG"前一種還沒找完呢，急什麼。\n"NOR, this_object(), me);
                return 0;
            }
        case 2:
            if( me->query_temp("quest/necklace")) {
                message_vision("土著祭師說道﹕"HIG"已經給過啦！快找第二種吧。\n"NOR, this_object(), me);
                return 0;
            } else
            if( ob->query_amount() != 200 ) {
                do_chat((: command, "say 猴牙給的數目不對喔，再去多拿點吧。" :));
                return 0;
            } else {
                me->add_temp("quest/necklace", 1);
                message_vision(CYN"土著祭師清點著"HIW"猴牙"NOR""CYN"的數量。\n"NOR, this_object(), me);
                message_vision("土著祭師說道﹕"HIG"差點忘了我還需要七十顆水果，順便幫我吧。\n"NOR, this_object(), me);
            }
            do_chat( ({ ( : destruct , ob : ), }) );
            break;
        default:
            do_chat((: command, "say 除了目前需要的物品其他我不要！" :));
            return 0;
            break;
    }
    return 1;
}
