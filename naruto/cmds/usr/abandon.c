/*  abandon.c

    Copyright (C) 1994-2000 Annihilator <annihilator@muds.net>

    This program is a part of ES2 mudlib. Permission is granted to use,
    modify, copy or distribute this program provided this copyright notice
    remains intact and subject to the restriction that this program MAY
    NOT be used in any way for monetary gain.

    Details of terms and conditions is available in the Copyright.ES2 file.
    If you don't receive this file along with this program, write to the
    primary author of ES2 mudlib: Annihilator <annihilator@muds.net>
*/

#include <command.h>

inherit F_CLEAN_UP;

private void create() { seteuid(getuid()); }

int main(object me, string arg)
{
    SECURED_COMMAND;

    if( !arg ) return notify_fail("你要放棄繼續學習什麼技能？\n");

    if( sscanf(arg, "-c %s", arg)==1 )
        me->abandon_skill(arg, 1);
    else
        me->abandon_skill(arg);

    write("Ok.\n");
    return 1;
}

int help()
{
    write(@TEXT
指令格式：abandon <技能名稱>

這個指令讓你「中止」學習一項技能，這個技能往後不會再經由使用或學習而進步
。但這並不表示你會完全忘記這項技能。中止學習的技能仍然可以使用，只是停止
學習而已。

如果有需要，你可以用 abandon -c <技能名稱> 來恢復被你中止的技能。

其它相關指令：enable、disable、skills
TEXT);
    return 1;
}
