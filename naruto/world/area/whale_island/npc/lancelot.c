#include <npc.h>
#include <ansi.h>

void do_fight()
{
    int damage, raiseDamage, i;
    object enemy, wp;

    enemy = this_object()->query_opponent();
    wp = this_object()->query_temp("weapon/twohanded");

    if( !enemy ) return;
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    add_temp("apply/exact", 300);
    this_object()->damage_stat("mp", 15, this_object());
    message_vision(HIG"\n$N展現了自己操作系能力的技巧，靈活地操縱手中"+wp->query("name")+HIG"演出歌劇"HIW"「白色森林」\n\n"NOR, this_object(), enemy);

    for(i=1;i<6;i++) {
        message_vision(HIW"白葉劇曲 "HIG"第"+chinese_number(i)+"章節\n"NOR, this_object());
        COMBAT_D->fight(this_object(), enemy, wp);
        message_vision("\n"NOR, this_object());
    }
    add_temp("apply/exact", -300);
    message_vision(CYN"$N完成了演出！\n\n"NOR, this_object());
    return;
}

void to_do_say()
{
    do_chat( ({ 
        (: command, "say 在我身後的就是遠古高塔「四輪之塔」中的一座。" :),
        (: command, "say 因為在鯨魚島著個小村的附近，所以特別派獵人來看管。" :),
        (: command, "say 裡面怪物火暴，沒實力就別進去了。" :),
    }) );
}

void create()
{
    set_name("蘭斯洛特", ({ "lancelot" }));
    set_race("human");
    set_level(60);
    set("camp", "hunter");
    set("title", HIG"Sir Lancelot"NOR);
    set_class("hxh_senior");   // 全職獵人
    set("long", "獵人總會所屬的全職獵人，因為個人原則而不願意成為任何一種使命\n"
                "的特殊獵人，因此一直位在全職獵人無法升上星階，但實力早就超過\n"
                "星階水平了。尼特羅會長不想浪費此人的實力，因此派他看守此地。\n");

    set("age", 27);
    set("gender", "male");
    set("chat_chance", 1);
    set("chat_msg", ({
        (: to_do_say :),
    }) );
    set("chat_chance_combat", 25);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    setup();
    set_skill("operation", 200);
    set_skill("solid", 200);
    map_skill("parry", "solid");
    carry_object(_DIR_AREA_"bone/npc/wp/lance.c")->wield("twohanded");
}

void relay_say(object ob, string arg)
{
    if( arg == "四輪之塔" )  {
        do_chat( ({ 
            (: command, "say 四輪之塔共有四座。" :),
            (: command, "say 分別叫「紅蓮之塔」「琥珀之塔」「翡翠之塔」「紺碧之塔」" :),
            (: command, "say 但是除了名字目前沒人知道這些塔的用途。" :),
            (: command, "say 獵人公會還在派人調查中。" :),
        }) );
    }
}