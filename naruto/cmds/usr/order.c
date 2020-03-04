/*  order.c

    Copyright (C) 1994-2000 Annihilator <annihilator@muds.net>

    This program is a part of ES2 mudlib. Permission is granted to use,
    modify, copy or distribute this program provided this copyright notice
    remains intact and subject to the restriction that this program MAY
    NOT be used in any way for monetary gain.

    Details of terms and conditions is available in the Copyright.ES2 file.
    If you don't receive this file along with this program, write to the
    primary author of ES2 mudlib: Annihilator <annihilator@muds.net>
*/

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
    int res;
    object ob;
    string who, cmd, verb, path;

    if( me != this_player(1) ) return 0;

    if( me->is_busy() ) return notify_fail("�A�{�b�S���šC\n");

    if( !arg || arg=="" || sscanf(arg, "%s to %s", who, cmd)!=2 )
        return notify_fail("�A�n�R�O�ְ�����ơS\n");

    if( who == "_MY_PET_" ) {
    	if( !objectp(ob = me->query_temp("pet")) ) 
    		return notify_fail("�A���G�S���Ԥ�...\n");
    } else {
        ob = present(who, environment(me));
        if( !ob || !ob->is_character())
            return notify_fail("�o�̨S���o�ӤH�C\n");
    }

    if( sscanf(cmd, "%s %*s", verb) != 2 ) verb = cmd;

    if( stringp(path = ob->find_command(verb)) && path != "/cmds/std/" + verb )
        return notify_fail("�A����R�O�O�H���o�بơC\n");

    if( wizardp(ob) && wiz_level(me) <= wiz_level(ob) )
        return notify_fail("�A��������o�ӤH�C\n");

    write("�A�R�O" + ob->name() + ": " + cmd + "\n");
    if( (object)ob->query_owner() != me || !ob->accept_order(me, verb) )
        return notify_fail( "�ݰ_��" + ob->name() + "�ä��Qť�A�����C\n");

    me->start_busy(2);

    notify_fail( ob->name() + "�L�k�����o�өR�O�C\n");
    seteuid(getuid());
    res = ob->force_me(cmd);
    return res;
}

int help(object me)
{
    write(@TEXT
���O�榡�Rorder <�Y�H> to <���O>

�R�O�L�H����Y�ӫ��O�C
�p�G�n�R�O�ۤw���Ԥ��A�i�����ϥ� _MY_PET_ �Ӥ��ݭn�ϥΧ�
����id�A�H�K�b�P�@��Ӧh�Ԥ��ӵo�Ϳ��áC
�ҡGorder _MY_PET_ to say hi
TEXT
    );
    return 1;
}
