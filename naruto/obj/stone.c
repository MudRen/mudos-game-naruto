#include <ansi.h>

inherit ITEM;

void create()
{
    set_name(HIG"七"HIY"彩"HIW"石"NOR, ({ "color stone", "stone", "color" }));
    set_weight(100000);

    set("unit", "顆");
    set("value", 0);
    set("no_sac", 1);
    set("no_get", 1);

    set("long",
        "因為世界是不斷地再變遷，所已有些事物已經不復存在。\n"
        "在這個世界上時常出現新的東西，如果你是跟不上時代的人，\n"
        "你便可以摸一摸(touch)這顆七彩石，它會協助你，讓你也能\n"
        "順利的在這個世界中繼續旅行。\n" 
    );
    setup();
}

void init()
{
    add_action("do_touch", "touch");
}

void clear_skill(object me)
{
    int point;

    if( me->query_skill("magic") ) {
        point = me->query_skill_ability("magic");
        me->delete_skill("magic");
        me->add_point("skill", point);
        me->save();
        tell_object(me, "七彩石幫你移除了技能 幻術(magic) 並退還了 " + point + " 點的技能點。\n");
    }
}

void clear_vendetta(object me)
{
    if( me->query("vendetta/0") ) {
        me->delete("vendetta/0");
        me->save();
        tell_object(me, "七彩石幫你移除了見人就打的bug了。\n");
    }
}

void add_camp(object me)
{
    if( me->query("guild") == "muye" && me->getCamp("muye") != 1 ) {
        me->addCamp("muye");
    } else if( me->query("guild") == "hunter" && me->getCamp("hunter") != 1 ) {
        me->addCamp("hunter");
    } else if( (me->query_class() == "little_sea" || me->query_class() == "thief_sea" ) && me->getCamp("robber") != 1 ) {
        me->addCamp("robber");
    } else if( (me->query_class() == "work_sea" || me->query_class() == "soldier_sea" ) && me->getCamp("police") != 1 ) {
        me->addCamp("police");
    } else tell_object(me, "你的職業似乎沒被定義到，請找巫師處理。\n");
}


void reset_dog(object me)
{
    int lv;
    object pet;
    pet = me->query_temp("pet");

    if( !pet || !objectp(pet) ) return;
    if( !me->query("pet") ) return;

    // 設定名字
    if( me->query("pet/name") ) pet->set("name", me->query("pet/name"));
    
    // 設定ID
    pet->set("id", me->query_id() + "'s dog");
    
    // 設定title
    if( me->query("pet/title") ) pet->set("title", me->query("pet/title"));
    
    // 設定nickname
    if( me->query("pet/nickname") ) pet->set("nickname", me->query("pet/nickname"));

    // 設定long
    if( me->query("pet/long") ) pet->set("long", me->query("pet/long"));
    
    // 設定food
    if( me->query("pet/food") ) pet->food_gain(me->query("pet/food"));
    
    // 設定Level
    if( me->query("pet/level") ) pet->set_level(me->query("pet/level"));
    
    // 設定exp
    if( me->query("pet/exp") )
        pet->exp_gain(me->query("pet/exp"));

    lv = pet->query_level();
    
    // 依等級提升能力
    pet->set_attr("str", lv*150/100);
    pet->set_attr("con", lv*150/100);
    pet->set_attr("dex", lv*150/100);
    pet->set_attr("int", lv*150/100);
    pet->set_stat_maximum("ap", lv*50);
    pet->set_stat_maximum("hp", lv*50);
    pet->set_stat_maximum("mp", lv*50);
    pet->set_stat_current("ap", lv*50);
    pet->set_stat_current("hp", lv*50);
    pet->set_stat_current("mp", lv*50);
    pet->set_skill("combat", lv*3);
    pet->set_skill("parry", lv*3);
    pet->set_skill("dodge", lv*3);
    pet->set_skill("heavy hit", lv*3);
    pet->set_skill("savage hit", lv*3);
    pet->set_skill("continual hit", lv*3);
    pet->save();

    // 不需要了
    me->delete("pet");

    tell_object(me, "七彩石幫你處理了忍犬存檔問題！\n");
}

int do_touch(string arg)
{
    object me = this_player();

    if( !arg || arg != "stone" )
        return notify_fail("你要摸什麼？\n");
    
    message_vision(HIW"$N深情款款的撫摸著$n，嘴角微微的上揚。\n"NOR, me, this_object());

    // 2007.03.16 移除 技能幻術(magic)
    clear_skill(me);

    // 2007.03.17 移除見人就打bug
    clear_vendetta(me);

    // 2007.08.18 增加舊玩家的職業陣營
    add_camp(me);

    // 2009.03.24 忍犬改為會存檔
    reset_dog(me);

    return 1;
}
