/*  option.h

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
#include <command.h>

inherit F_CLEAN_UP;

private void create() { seteuid(getuid()); }

int main(object me, string arg)
{
    string term;
    mixed v;

    if( !arg )
    {
        mapping opt = me->query("option");
        string str = "�A�ثe�]�w���ϥΪ̿ﶵ�F\n";

        if( !mapp(opt) || !sizeof(opt) )
            str += "    �L�C\n";
        else
            foreach(term, v in opt)
                str += sprintf("    %-20s�G%O\n", term, v);
        write(str);
        return 1;
    }

    if( sscanf(arg, "%s %d", term, v)==2 || sscanf(arg, "%s %s", term, v)==2 ) {
        if( !v ) me->delete("option/" + term);
        else me->set("option/" + term, v);
        if( term == "map_unfreeze" ) {
            if( environment(me)->is_area() ) {
                if( !v ) {
                    me->set_temp("window/freeze", 1);
                    write(CLR+R(14, me->query_temp("window/height")));
                } else {
                    me->delete_temp("window/freeze");
                    write(SAVEC+R("","")+RESTC);
                }
            } else {
                if( v ) {
                    me->delete_temp("window/freeze");
                    write(SAVEC+R("","")+RESTC);
                }
            }
        }
    } else return notify_fail("���O�榡�Goption <�ﶵ> <�]�w��>\n");

    write("Ok.\n");
    return 1;
}

int help()
{
    write(@TEXT
���O�榡�Goption <�ﶵ> <�]�w��>

�o�ӫ��O���A�]�w�@�Ǧ����ϥΪ̤������ﶵ�C�䤤�]�w�� 0 �Ҭ��t�ιw�]�ȡC

�ﶵ�G                �����G                                  �]�w�ȡG
map_unfreeze          �a�Ϩt�Τ������ᵲ�a�ϵe��������W��    (0:��, 1:�})
map_hidden            �a�Ϩt�άO�_���æa�ϵe��                (0:�_, 1:�O)
map_obj_hidden        �a�Ϩt�Τ��O�_�������Ҫ��~              (0:�_, 1:�O)
map_obj_icon_hidden   �a�Ϩt�Τ��O�_���çY�ɪ����~�ϥ�        (0:�_, 1:�O)
map_exits_hidden      �a�Ϩt�Τ��O�_���åX�f                  (0:�_, 1:�O)
map_block             �a�Ϩt�Τ��O�_�u��ܻ�ê��              (0:�_, 1:�O)
map_build             �a�Ϩt�Τ��O�_�u��ܫؿv���Ϋئa        (0:�_, 1:�O)
map_through           �a�Ϩt�Τ��O�_�ҥά���Ҧ�(�Ův�M��)    (0:�_, 1:�O)
brief_room            �O�_²�Ʃж����Բӱԭz                  (0:�_, 1:�O)
brief_short           �O�_�u��ܪ��~�ΤH��������W��          (0:�_, 1:�O)
TEXT);
    return 1;
}
