#include <npc.h>

void create()
{
    set_name("費沸短", ({ "fei fei duan", "fei", "duan" }) );
    set_race("human");
    set_level(40);
    set("age", 65);
    set("title", "新手導師");
    set("long", "另一位新手的導師，他精通古語，但他並不指導任何的技能。\n");
    setup();
}
void relay_say(object ob, string arg)
{
    if( arg == "嘎烏瓜哩拉呼" )  {
        do_chat( ({ 
            (: command, "say 這句的意思是：前進一步要退後兩步。" :),
            (: command, "say 我的解釋是：知難而退。" :),
        }) );
        return;
    }
    if( arg == "阿尼屋捏阿啦嘿" )  {
        do_chat( ({ 
            (: command, "say 這句的意思是：面朝神木舉手而拜。" :),
            (: command, "say 我的解釋是：土著的儀式之一。" :),
        }) );
        return;
    }
    if( arg == "轟巴哩！古拉尼蛙！" )  {
        do_chat( ({ 
            (: command, "say 這句的意思是：偉大的天！聆聽我們的願望！" :),
            (: command, "say 我的解釋是：祭師凝聚向心力的方法。" :),
        }) );
        return;
    }
    if( arg == "松枯松枯西蘇西蘇" )  {
        do_chat( ({ 
            (: command, "say 這句只是無聊發出的聲音而已。" :),
        }) );
        return;
    }
    if( arg == "空搭拉李拉更" )  {
        do_chat( ({ 
            (: command, "say 這句的意思是：傳承古老的詩詞。" :),
            (: command, "say 我的解釋是：好像沒什麼意思。" :),
        }) );
        return;
    }
    if( arg == "安山奇姆亞林" )  {
        do_chat( ({ 
            (: command, "say 這句的意思是：左右手是三比七。" :),
            (: command, "say 我的解釋是：右撇子比左撇子多。" :),
        }) );
        return;
    }
}
