/*  seasoldier.c
    by mouse 2007/7/26
*/
#include <ansi.h>

mixed do_chat(mixed chat);
varargs string name(int raw);
int is_fighting(object);
void kill_ob(object);

int accept_fight(object ob)
{
    switch(random(5)) {
        case 0: do_chat((: command, "shake" :));                      break;
        case 1: do_chat((: command, "say 海軍所代表的是正義！" :));   break;
        case 2: do_chat((: command, "say 找海軍打架？想被抓嗎？" :)); break;
    }
    return 0;
}

void accept_kill(object ob)
{
    if( is_fighting(ob) ) return;
    do_chat((: command, "say 竟敢對海軍出手！膽子不小..." :));
    
    // 增加區域判斷 by -Acme-
    if( environment()->is_area() ) {
        mapping info;
        info = this_object()->query("area_info");
        if( !info ) return;
        environment()->query_inventory(info["x_axis"], info["y_axis"])->soldier_assist(this_object(), ob);
    }
    else all_inventory(environment())->soldier_assist(this_object(), ob);
}

void soldier_assist(object alert, object ob)
{
    if( alert==this_object() || !living(this_object()) || is_fighting(ob) )
        return;

    switch(random(5)) {
        case 0: command("say 有人造反阿！快把他抓住！");       break;
        case 1: command("say 在世界政府的眼前撒野！抓住他！"); break;
        case 2: command("say 膽敢挑戰海軍！");                 break;
        case 3: command("pk");                                 break;
    }
    kill_ob(ob);
    ob->fight_ob(this_object());
}
