#include <ansi.h>

inherit ITEM;

void create()
{
    set_name(HIC"模傲"HIW"ソ鏡"NOR, ({ "imitate mirror", "mirror" }));
    if( !clonep() ) {
        set("unit", "塊");
        set("value", 0);
        set("weight", 5);
        set("long", "花紋細密的鏡子，上面浮著一行文字「"HIR"copy on <某人>"NOR"」");
    }
    setup();
}
void init()
{
    add_action("do_copy", "copy");
}
int do_copy(string arg)
{
    string npc;
    object ob, fm;

    if( !arg ) return notify_fail("指令格式: copy on <某人> \n");
    if( sscanf(arg, "on %s", npc) !=1 ) return notify_fail("指令格式: copy on <某人> \n");

    ob = LOGIN_D->find_body(npc);
    if(!ob) return notify_fail(HIR"線上沒有 "NOR+npc+HIR" 這號人物。\n"NOR);
    message_vision("$N"HIY"拿出"NOR"$n"HIY"往"NOR+ob->name()+HIY"一照，"NOR"$n"HIY"忽然發出一陣耀眼的光芒！\n"NOR, this_player(), this_object());
    if( !ob->is_character() || ob->is_corpse() || !userp(ob)) {
        message_vision("不過並沒有發生任何事情。\n"NOR, this_object());
        tell_object(this_player(),HIR"謎之聲：我不能模仿非生命的東西。\n"NOR);
        return 1;
    }
    fm = new("/u/m/mouse/npc/fight.c");
    if( !objectp(fm) ) {
        write(HIR"謎之聲：因為不明原因使我無法模仿！\n"NOR);
        return 1;
    }
    if( environment(this_player())->is_area() ) {
        if( !area_move(environment(this_player()), fm, this_player()->query("area_info/x_axis"), this_player()->query("area_info/y_axis")) ) {
            message_vision("光芒漸漸變弱...卻沒發生任何事。\n"NOR, this_object());
            destruct(fm);
            return 1;
        }
    } else {
        if( !fm->move(environment(this_player())) ) {
            message_vision("光芒漸漸變弱...卻沒發生任何事。\n"NOR, this_object());
            destruct(fm);
            return 1;
        }
    }
    fm->set_name(ob->query("name")+"的複製人", ({ "copy's "+ob->query_id(), "copy"}));
    message_vision("$N從光芒中現形，與"+ob->name()+"的相似度幾乎百分之百。\n"NOR, fm, this_player());

    // 等級與本人相同
    fm->set("level", ob->query("level"));
    fm->set("gender", ob->query("gender"));
    fm->set("age", ob->query("age"));

    // 體質，力量、敏捷、智慧與本人相同
    fm->set_attr("str", ob->query_attr("str"));
    fm->set_attr("con", ob->query_attr("con"));
    fm->set_attr("dex", ob->query_attr("dex"));
    fm->set_attr("int", ob->query_attr("int"));

    // 體力與本人相同
    fm->set_stat_current("ap", ob->query_stat_current("ap"));
    fm->set_stat_maximum("ap", ob->query_stat_maximum("ap"));
    fm->set_stat_current("hp", ob->query_stat_current("hp"));
    fm->set_stat_maximum("hp", ob->query_stat_maximum("hp"));
    fm->set_stat_current("mp", ob->query_stat_current("mp"));
    fm->set_stat_maximum("mp", ob->query_stat_maximum("mp"));

    // skill只保留重暴連、格鬥、拆招、閃躲與本人相同
    fm->set_skill("continual hit", ob->query_skill("continual hit"));
    fm->set_skill("savage hit", ob->query_skill("savage hit"));
    fm->set_skill("heavy hit", ob->query_skill("heavy hit"));
    fm->set_skill("combat", ob->query_skill("combat"));
    fm->set_skill("parry", ob->query_skill("parry"));
    fm->set_skill("dodge", ob->query_skill("dodge"));

    // 刪除基本功
    fm->delete_skill("ninja");
    fm->delete_skill("force");
    fm->delete_skill("magic");
    fm->delete_skill("strength");
    fm->delete_skill("concrete");
    fm->delete_skill("special");
    fm->delete_skill("operation");
    fm->delete_skill("emit");
    fm->delete_skill("variation");
    return 1;
}
