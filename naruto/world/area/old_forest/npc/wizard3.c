#include <npc.h>
#include <ansi.h>

inherit F_VILLAGER;

void create()
{
    set_name("土著祭師" , ({ "wizard" }));
    set("long", "打扮非常奇怪的人，手拿著一根彎彎曲曲的木杖。\n");
    set_level(40);
    set("gender","male");
    set("title",HIM"主祭"NOR);
    set("age",50+random(60));

    // 一般時動作
    set("chat_chance", 6);
    set("chat_msg", ({
        (: command, "say 能到這裡也算與神木有緣。" :),
        (: command, "say 誰能將我所『需要』的東西拿來給我呢？" :),
        (: command, "say 身為祭師還是要懂些外來語言的。" :),
    }) );

    // 物品掉落機率
    set("set_drop", ({
        ([ "type":"food", "id":40, "amount":1+random(6), "p1":80, "p2":100 ]),  // 乾果
        ([ "type":"food", "id":38, "amount":1+random(3), "p1":70, "p2":100 ]),  // 樹果
        ([ "type":"food", "id":39, "amount":1+random(2), "p1":70, "p2":100 ]),  // 水果
        ([ "type":"food", "id":41, "amount":1+random(1), "p1":30, "p2":100 ]),  // 水果王
        ([ "type":"eq", "id":71, "amount":1, "p1":30, "p2":100 ]),              // 樹葉
        ([ "type":"wp", "id":21, "amount":1, "p1":5, "p2":100 ]),               // 神杖
    }));
    setup();
}

void relay_say(object ob, string arg)
{
    if( arg == "需要" )  {
        do_chat( ({ 
            (: command, "say 只要能給我四十顆猴腦，就給你神木製成的武器。" :),
        }) );
        return;
    }
}

int give_check(object ob)
{
    if( ob->id("_KING_FRUIT_") ) return 1;            // 水果王
    if( ob->id("_MONKEY_BRAIN_") ) return 2;          // 猴腦
    else return 0;
}
int accept_object(object me, object ob)
{
    object item;
    if( this_object()->is_busy() ) {
        do_chat((: command, "say 神木的武器製成需要時間。" :));
        return 0;
    }
    if( this_object()->is_fighting() ) {
        do_chat((: command, "say 我正在打人呢！沒空理你！" :));
        return 0;
    }
    me->start_busy(1);
    this_object()->start_busy(1);

    switch( give_check(ob) ) {
        case 1:
            if( me->query("treeswordquest") == 1) {
                if( ob->query_amount() != 20 ) {
                    do_chat((: command, "say 水果王要二十個，不會算算數嗎？" :));
                    return 0;
                }
                if( file_size(__DIR__"wp/tree_sword.c") < 0 ) return 0;
                if( catch(item = new(__DIR__"wp/tree_sword.c")) ) return 0;
                if( item->move(me) ) {
                    message_vision("$N將" + item->name() + "澆上"HIM"水果王"NOR"的汁液交給$n，只見" + item->name() + "發出一陣陣金光，認定$n就是它的主人。\n", this_object(), me);
                    message_vision("土著祭師說道﹕"HIG"開鋒也完成了，$n要小心使用此劍阿。\n"NOR, this_object(), me);
                } else {
                    if( item->move(this_object()) ) {
                        message_vision("$N將" + item->name() + "澆上"HIM"水果王"NOR"的汁液交給$n，只見" + item->name() + "發出一陣陣金光。\n", this_object(), me);
                        message_vision("土著祭師說道﹕"HIG"$n身上太重了，丟在地上吧。\n"NOR, this_object(), me);
                    } else {
                        me->delete("treeswordquest");
                        destruct(item);
                        return 0;
                    }
                }
                me->delete("treeswordquest");
                ob->set_amount(0);
                do_chat(({ 
                    (: command, "drop sword" :),
                    (: destruct, ob :),
                }));
                break;
            } else {
                message_vision("土著祭師說道﹕"HIG"我有說過要這個東西嗎？\n"NOR, this_object(), me);
                return 0;
            }

        case 2:
            if( me->query("treeswordquest") > 0) {
                message_vision("土著祭師說道﹕"HIG"已經給過啦！快找第二種吧。\n"NOR, this_object(), me);
                return 0;
            }
            if( ob->query_amount() != 40 ) {
                do_chat((: command, "say 猴腦要四十個！太多太少都不行。" :));
                return 0;
            }
            me->add("treeswordquest", 1);
            message_vision(CYN"土著祭師將"HIR"猴腦"NOR""CYN"弄破，裡面的鮮血緩緩滴落在木枝上。\n"NOR, this_object(), me);
            message_vision("土著祭師說道﹕"HIG"差點忘了我還需要二十顆水果王，順便幫我吧。\n"NOR, this_object(), me);
            do_chat(((: destruct, ob :)));
            break;

        default:
            do_chat((: command, "say 不需要這樣東西。" :));
            return 0;
            break;
    }
    return 1;
}
