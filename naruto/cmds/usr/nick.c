/*  nick.c

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

int main(object me, string arg)
{
    if( !arg ) return notify_fail("�A�n���ۤv������︹�S\n");

    arg = color(arg);

    if( strlen(uncolor(arg)) > 14 )
	    return notify_fail("�A���︹�Ӫ��F�M�Q�@�ӵu�@�I���B�T�G�@�I���C\n");

    seteuid(getuid());
    me->set("nickname", arg);    // use arg + NOR if colorful nick is open
    write("Ok�C\n");
    return 1;
}

int help(object me)
{
    write(@HELP
���O�榡 : nick <�~��, �︹>
 
�o�ӫ��O�i�H���A���ۤv���@���T�G���W�����Y�ΡC
�︹�i�H�ϥ� ANSI �C�ⱱ��X�A�п�J help ansi
HELP);
        return 1;
}
