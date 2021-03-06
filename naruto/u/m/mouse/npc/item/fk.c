#include <ansi.h>

inherit ITEM;

void create()
{
    set_name(HIR"殘殺之力"NOR, ({ "kill all", "all" }));
    set_weight(1);
    if( !clonep() ) {
        set("unit", "式");
        set("value", 1);
        set("long", "可以命令兩個NPC互相攻擊。"HIR"(fkill mob1 with mob2)"NOR);
    }
    setup();
}
void init()
{
    add_action("do_fk", "fk");
}
int do_fk(string arg)
{
    string str, npc;
    object ob, me, obj;

    me = this_player();

    seteuid(getuid());
    if( !arg || sscanf(arg, "%s with %s", str, npc) != 2 )
        return notify_fail("指令格式﹕fk <Mob> with <Mob>\n");

    if( !(ob = present(str, environment(me))) )
        return notify_fail(HIR"這裡沒有 "NOR+str+HIR" 這號人物。\n"NOR);

    if( !(obj = present(npc, environment(me))) )
        return notify_fail(HIR"這裡沒有"NOR+npc+HIR"這號人物。\n"NOR);

    if( !ob->is_character() || !obj->is_character() )
        return notify_fail(HIY"兩個物件中有其中之一無法執行命令。\n"NOR);

    if( userp(ob) || userp(obj) )
        return notify_fail(HIY"被命令的雙方不可是玩家。\n"NOR);

    message_vision(HIR"$N發出神力讓"NOR+ob->name()+HIR"主動攻擊"NOR+obj->name()+HIR"！\n"NOR, me);
    ob->kill_ob(obj);
    obj->kill_ob(ob);
    return 1;
}
