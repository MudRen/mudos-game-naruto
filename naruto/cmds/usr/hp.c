/*  hp.c

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

inherit F_CLEAN_UP;

private string status_color(object me, string stat);

int main(object me, string arg)
{
    object ob;
    string format;
    
    if( !arg ) ob = me;
    else {
        if( arg == "_MY_PET_" ) {
    ob = me->query_temp("pet");
    if( !ob ) return notify_fail("�A�S���d���C\n");
            write("[" + ob->name() + "] ");
        } else {
            if( !ob ) ob = present(arg, environment(me));
            if( !ob ) ob = find_living(arg);
            if( !ob ) return notify_fail("�S�� " + arg + " �o�ӤH���C\n");
            if( ob->query_owner() != me && !wizardp(me) )
            return notify_fail("�A�n�ݽ֪����A�H\n");
            write("[" + ob->name() + "] ");
        }
    }

        format = "��O�� %s%d/%d" NOR "  ��O�� %s%d/%d" NOR "  �]�O�� %s%d/%d\n"NOR;
    printf( format,
                status_color(ob, "ap"),
                ob->query_stat("ap"),
                ob->query_stat_maximum("ap"),
                status_color(ob, "hp"),
                ob->query_stat("hp"),
                ob->query_stat_maximum("hp"),
                status_color(ob, "mp"),
                ob->query_stat("mp"),
                ob->query_stat_maximum("mp"),
    );
    return 1;
}

private string status_color(object me, string stat)
{
    int current = me->query_stat(stat);
    int max = me->query_stat_maximum(stat);
    int ratio = max ? (current * 100) / max : 100;

    switch( ratio ) {
        case  0..30: return HIR;
                case 31..80: return HIY;
                case 81..100: return HIG;
                default: return HIC;
        }
}

int help(object me)
{
write(@HELP
���O�榡 : hp [<�H�� ID>]

�γ~ : ���U�A�ݨ�ثe��²�n���A�C�Ův�i�H�d�L�H��²�n���A�C

�i�H�d�ߦۤw�d�������A
ex: hp acme's dog �� hp _MY_PET_
HELP
     );
     return 1;
}

