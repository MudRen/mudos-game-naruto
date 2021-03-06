#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name(HIK"蟑螂卵"NOR, ({ "cockroach's egg", "egg" }));
    if( !clonep() ) {
        set("base_unit", "顆");
        set("base_value", 8);
        set("base_weight", 100);
        set("food_stuff", 1);              // 食物量，食品一定要有食物量
        set("long", "一顆惡臭的蟑螂卵，如果你有愛心的話，可以孵(incubate)這顆蟑螂卵。\n");
    }
    setup();
}

void init()
{
    if( userp(environment(this_object())) ) add_action("do_incubate", "incubate");
}

int do_incubate(string arg)

{
    int love;

    object me = this_player();

    if( arg != "egg" )
        return notify_fail("你想要孵什麼東西？\n");

    if( me->is_busy() )
        return notify_fail("你現在沒有空。\n");

    if( me->query_stat("ap") < 10 )
        return notify_fail("你沒有夠多的精力來孵卵。\n");

    if( me->query_temp("cockroach/guard") > 5 )
        return notify_fail("你已經養太多隻蟑螂寶寶了。\n");

    message_vision("$N細心的將$n抱在懷中小心的呵護著。\n", me, this_object());

    love = 1 + random(10);
    me->damage_stat("ap", love*2);
    if( !me->query_temp("cockroach/love") ) me->set_temp("cockroach/love", love);
    else me->add_temp("cockroach/love", love);

    if( me->query_temp("cockroach/love") > 100 ) {
        object pet;
        string msg, ms;

        pet = new("/world/area/muye/npc/cockroach.c");
        pet->delete("attitude");

        message_vision("$N身上的$n已經相當成熟，你聽到幾聲輕脆的聲音" + pet->name() + "破蛋而出！\n", me, this_object());

        if( me->query("gender") == "male" ) {
            msg = "老爸";
            ms = "拔拔";
        } else if( me->query("gender") == "female" ) {
            msg = "老媽";
            ms = "馬麻";
        } else {
            msg = "主人";
            ms = "主人";
        }
        // 應該要有蟑螂上限才對
        me->delete_temp("cockroach/love");
        if( !me->query_temp("cockroach/guard") ) me->set_temp("cockroach/guard", 1);
        else me->add_temp("cockroach/guard", 1);

        if( environment(me)->is_area() ) move_side(pet, me);
        else pet->move(environment(me));

        pet->set_leader(me);     // 跟隨leader
        pet->guard_ob(me);       // 保護leader
        pet->set_owner(me);      // 設定owner
        pet->set("long", "一隻噁心的蟑螂。\n"
                         "牠的"+msg+"是"+me->query("name")+"。\n");

        pet->set("no_die", 1);   // 暈倒死亡直接消失判斷
        message_vision("$n一看到$N便高興的叫了聲：「"+ms+"！」\n", me, pet);

        // 個數減少, 直接減掉吧，堆疊一樣會重生
        this_object()->add_amount(-1);
        if( !this_object()->query_amount() ) destruct(this_object());
    }
    me->start_busy(2);
    return 1;
}
