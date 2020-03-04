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


    if( !arg ) return notify_fail("�A�nŲ�w����F��?\n");
    ob = present(arg, me);
    if( !ob ) return notify_fail("�A�nŲ�w����F��?\n");
    if( !(type = ob->query("equipped")) )
        return notify_fail("�A�������˳�" + ob->name() + "�~��Ų�w.\n");
    if( sscanf(type, "%s/%s", type, sub_type) != 2 )
        return notify_fail("�o�����~�L�kŲ�w.\n");

    write(ob->long() + "\n");

    if( type=="weapon" ) {
        string s;
        mixed sk = ob->query("wield_as");
        
        write("�i�ϥΤ覡�G\n");
        if( stringp(sk) ) sk = ({ sk });
        foreach(s in sk)
            printf("%s%s (%s)\n", ((s==sub_type) ? HIY"��"NOR : "  "), to_chinese(s), s);

        dp = ob->query("damage/" + sub_type);
        printf("\n�ˮ`�O�G %d - %d (�ˮ`�O�ץ� %d%%�A�Z������ %d)\n", 
            dp["lower"], dp["upper"], dp["bonus"], dp["level"] );

        printf("\n�j�Ʀ��ơG%d/10\n", ob->query("changed"));
        apply = ob->query("apply_" + type + "/" + sub_type);
        if( mapp(apply) ) {
            string prop;
            mixed value;
            
            write("\n�Z���S�ʡR\n");
            foreach(prop, value in apply) {
                prop = to_chinese(prop);
                printf("  %-30s %O\n", prop, value);
            }
        }
    }
    if( type=="armor" ) {
        apply = ob->query("apply_" + type + "/" + sub_type);
        printf("�@�㳡��G%s\n", to_chinese(sub_type) );
        printf("�j�Ʀ��ơG%d/3\n", ob->query("changed"));
        if( mapp(apply) ) {
            string prop;
            mixed value;
            
            write("�@��S�ʡG\n");
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
���O�榡: identify <����>

�o�ӫ��O�i�H���AŲ�w�@�ǪZ���˳Ƶ����~�C
TEXT
    );
    return 1;
}
