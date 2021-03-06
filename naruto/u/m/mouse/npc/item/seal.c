#include <ansi.h>

inherit ITEM;

void create()
{
    set_name(HIY"桃符紙"NOR, ({ "seal" }));
    if( !clonep() ) {
        set("unit", "張");
        set("value", 0);
        set("weight", 5);
        set("long", "黃色寫著奇怪文字的紙張。");
    }
    setup();
}
void init()
{
    add_action("do_spell", "spell");
}
int do_spell(string arg)
{
    string npc;
    object ob, zombie;

    if( !arg ) return notify_fail("指令格式: spell on <屍體> \n");
    if( sscanf(arg, "on %s", npc) !=1 ) return notify_fail("指令格式: spell on <屍體> \n");

    if( !(ob = present(npc, environment(this_player()))) ) return notify_fail(HIR"這裡沒有"NOR+npc+HIR"這號人物。\n"NOR);
    message_vision(HIR"$N不停揮動雙手然後大喊一聲：「急急如律令！」便將"NOR""HIY"符紙"NOR""HIR"貼在"NOR+ob->name()+HIR"頭上。\n"NOR, this_player());
    if( !ob->is_corpse()) {
        message_vision("不過並沒有發生任何事情。\n"NOR, this_object());
        tell_object(this_player(),HIK"因為不能對非屍體使用所以符紙消失了...\n"NOR);
        destruct(this_object());
        return 1;
    }
    if( ob->query("userp") >=1 ) {
        message_vision("不過並沒有發生任何事情。\n"NOR, this_object());
        tell_object(this_player(),HIG"不能對玩家的屍體使用此符紙。\n"NOR);
        return 1;
    }
    if( ob->query("no_zombie") >=1 ) {
        message_vision("不過並沒有發生任何事情。\n"NOR, this_object());
        tell_object(this_player(),HIG"已經死掉過的東西不能再度復活。\n"NOR);
        return 1;
    }
    zombie = new("/u/m/mouse/npc/zombie.c");
    if( !objectp(zombie) ) {
        write("這張符紙是假的∼你被耍啦！\n");
        destruct(this_object());
        return 1;
    }
    if( environment(this_player())->is_area() ) {
        if( !area_move(environment(this_player()), zombie, this_player()->query("area_info/x_axis"), this_player()->query("area_info/y_axis")) ) {
            message_vision("殭屍雖然站了起來，但是很快又倒了下去...\n"NOR, this_object());
            destruct(zombie);
            destruct(this_object());
            return 1;
        }
    } else {
        if( !zombie->move(environment(this_player())) ) {
            message_vision("殭屍雖然站了起來，但是很快又倒了下去...\n"NOR, this_object());
            destruct(zombie);
            destruct(this_object());
            return 1;
        }
    }
    zombie->set_name(ob->query("victim_name") + "的殭屍", ({ ob->query_id() + "'s zombie",  "zombie" }));
    message_vision("$N頭上桃符紙的字忽然發出紅光，只見$N立刻站了起來跟隨$n。\n"NOR, zombie, this_player());

    // 等級
    zombie->set("level", ob->query("level"));
    zombie->set("gender", ob->query("gender"));
    zombie->set("age", ob->query("age"));

    // 提高體質，力量隨機、降低敏捷、智慧
    zombie->set_attr("str", zombie->query("level")*(random(2)+2));
    zombie->set_attr("con", zombie->query("level")*(random(2)+4));
    zombie->set_attr("dex", zombie->query("level")/(random(1)+1)+10);
    zombie->set_attr("int", zombie->query("level")/(random(3)+1)+5);

    // 體力按照等級加乘
    zombie->set_stat_current("ap", zombie->query("level")*30);
    zombie->set_stat_maximum("ap", zombie->query("level")*30);
    zombie->set_stat_current("hp", zombie->query("level")*50);
    zombie->set_stat_maximum("hp", zombie->query("level")*50);
    zombie->set_stat_current("mp", zombie->query("level")*20);
    zombie->set_stat_maximum("mp", zombie->query("level")*20);

    // skill改變
    zombie->set_skill("continual hit", zombie->query("level")*2);
    zombie->set_skill("savage hit", zombie->query("level")*4);
    zombie->set_skill("heavy hit", zombie->query("level")*3);
    zombie->set_skill("combat", zombie->query("level")*4);
    zombie->set_skill("parry", zombie->query("level")*4);
    zombie->set_skill("dodge", zombie->query("level")*2);

    // 刪除基本功
    zombie->delete_skill("ninja");
    zombie->delete_skill("force");
    zombie->delete_skill("magic");
    zombie->delete_skill("strength");
    zombie->delete_skill("concrete");
    zombie->delete_skill("special");
    zombie->delete_skill("operation");
    zombie->delete_skill("emit");
    zombie->delete_skill("variation");

    // 跟隨 & 保護主人
    zombie->guard_ob(this_player());
    zombie->set_leader(this_player());

    destruct(ob);
    destruct(this_object());
    return 1;
}
