// buff.c

#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
int br;
    string line = "", tmp, buf, sk;
object ob;
mapping buffering;

    if( !arg ) ob = me;
    else {
        if( arg == "_MY_PET_" ) {
            if( !objectp(ob = me->query_temp("pet")) ) 
                return notify_fail("你似乎沒有忍犬...\n");
    } else ob = present(arg, environment(me));
        if(!ob) ob = find_player(arg);
        if(!ob) ob = find_living(arg);
        if( !ob ) ob = LOGIN_D->find_body(arg);
        if(!ob) return notify_fail("你要察看誰的狀態﹖\n");
        if(!living(ob)) return notify_fail("你只能察看生物的狀態。\n");
        if( !wizardp(me) && (object)ob->query_owner() != me )
            return notify_fail("只有巫師能察看別人的狀態。\n");
    }
    line += ob->name() + "的狀態：\n";
    line += "�������������������������������������������������������������������鱭n";
    buffering = ob->query_all_conditions();
    if( sizeof(buffering) ) {
        foreach(buf in keys(buffering) ) {
            tmp = "";
            if( undefinedp(buffering[buf]) ) continue;
            br++;
            sk = uncolor(buffering[buf]["name"]);
            tmp += sprintf("%-23s", sk + "("+ buffering[buf]["duration"]/30 + ":" + (buffering[buf]["duration"]*2)%60 + ")");
            tmp = replace_string(tmp, sk, buffering[buf]["name"]);
        
            // 換行
            if( br%3 == 0 ) {
                br = 0;
                tmp += "\n";
            }
            line += tmp;
        }
    }
    if( br ) line += "\n";
    line += "�������������������������������������������������������������������鱭n";
    write(line);
    return 1;
}

int help(object me)
{
    write(@HELP
指令格式 : buff
           buff <對象名稱>

這個指令可以顯示你(妳)或指定對象(含怪物)的狀態，如果你的對象不
是你的忍犬你無法使用這個指令，你也可以利用 buff _MY_PET_ 來進行
查詢。
HELP
);
    return 1;
}
