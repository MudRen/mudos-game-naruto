/*  identify.c

    Copyright (C) 1994-2000 Annihilator <annihilator@muds.net>

    This program is a part of ES2 mudlib. Permission is granted to use,
    modify, copy or distribute this program provided this copyright notice
    remains intact and subject to the restriction that this program MAY
    NOT be used in any way for monetary gain.

    Details of terms and conditions is available in the Copyright.ES2 file.
    If you don't receive this file along with this program, write to the
    primary author of ES2 mudlib: Annihilator <annihilator@muds.net>
*/

#include <ansi.h>
#include <combat.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    object ob;
    string type, sub_type;
    mapping dp, apply;


    if( !arg ) return notify_fail("你要鑑定什麼東西?\n");
    ob = present(arg, me);
    if( !ob ) return notify_fail("你要鑑定什麼東西?\n");
    if( !(type = ob->query("equipped")) )
        return notify_fail("你必須先裝備" + ob->name() + "才能鑑定.\n");
    if( sscanf(type, "%s/%s", type, sub_type) != 2 )
        return notify_fail("這類物品無法鑑定.\n");

    write(ob->long() + "\n");

    if( type=="weapon" ) {
        string s;
        mixed sk = ob->query("wield_as");
        
        write("可使用方式：\n");
        if( stringp(sk) ) sk = ({ sk });
        foreach(s in sk)
            printf("%s%s (%s)\n", ((s==sub_type) ? HIY"＊"NOR : "  "), to_chinese(s), s);

        dp = ob->query("damage/" + sub_type);
        printf("\n傷害力： %d - %d (傷害力修正 %d%%，武器等級 %d)\n", 
            dp["lower"], dp["upper"], dp["bonus"], dp["level"] );

        printf("\n強化次數：%d/10\n", ob->query("changed"));
        apply = ob->query("apply_" + type + "/" + sub_type);
        if( mapp(apply) ) {
            string prop;
            mixed value;
            
            write("\n武器特性﹕\n");
            foreach(prop, value in apply) {
                prop = to_chinese(prop);
                printf("  %-30s %O\n", prop, value);
            }
        }
    }
    if( type=="armor" ) {
        apply = ob->query("apply_" + type + "/" + sub_type);
        printf("護具部位：%s\n", to_chinese(sub_type) );
        printf("強化次數：%d/3\n", ob->query("changed"));
        if( mapp(apply) ) {
            string prop;
            mixed value;
            
            write("護具特性：\n");
            foreach(prop, value in apply) {
                printf("  %-30s %O\n", to_chinese(prop), value);
            }
        }
    }

    return 1;        
}

int help(object ob)
{
    write(@TEXT
指令格式: identify <物件>

這個指令可以讓你鑑定一些武器裝備等物品。
TEXT
    );
    return 1;
}
