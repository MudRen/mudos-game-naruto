#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string str)
{
        object ob, where, *ob_list;
        string msg="", dir_str;
        int i;

        if (!str) {
                ob_list = sort_array( users(), (:
                        strcmp( environment($1) ? file_name(environment($1)) : "",
                                        environment($2) ? file_name(environment($2)) : "" )
                :) );
        msg  = "�~�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
        msg += "�x"BBLU"        �W��(ID)        "NOR" "BGRN"                       �a   �I                               "NOR"�x\n";
                foreach(ob in ob_list) {
                        if( !environment(ob) || !ob->visible(this_player()) ) continue;
                        msg += sprintf("�x%12s%-12s %-61s�x\n",
                                ob->name(),
                                "("+ ob->query_id() +")",
                               (environment(ob)->is_area() ? environment(ob)->query("name") : environment(ob)->query("short")) + " " + HIK + file_name(environment(ob)) + 
                               ( environment(ob)->is_area() ? " (" + ob->query("area_info/x_axis") + "," + ob->query("area_info/y_axis") + ")" : "") + NOR
                        );
                }
        msg += "���w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��";
                me->start_more(msg);
                return 1;
        }

        ob = find_player(str);
        if( !ob ) ob = find_living(str);
        if( !ob ) ob = LOGIN_D->find_body(str);
        if( ob && ob->visible(me) ) {
                where = environment(ob);
                if (!where) return notify_fail("�o�ӤH�����D�b���̭C...\n");
                printf("%s(%s) �{�b�b %s (%s), %s\n",
                        ob->name(),
                        ob->query("id"),
                        where->is_area() ? where->query("name") + "("+ob->query("area_info/x_axis")+","+ob->query("area_info/y_axis")+")": where->query("short"),
                        file_name(where),
                        ob->link() ? ( living(ob) ? "�o�b " + query_idle(ob)/60 + " ����" : "���ˤ�") : (userp(ob) ? "�_�u��":"NPC ��"), 
                );
                return 1;
        }

        // locate the children of object
        dir_str = resolve_path(me->query("cwd"), str);
        if( sizeof(ob_list = children(dir_str)) ) {
                for(i=0; i<sizeof(ob_list); i++) {
                        if( !ob = environment(ob_list[i]) ) continue;
                        msg += sprintf("%O\n", ob );
                        // show until ob is room
                        while( ob = environment(ob) )
                                msg += sprintf("%O\n", ob );
                        msg += "\n";
                }
                msg += "Object " + dir_str + ".c located.\n";
                this_player()->start_more(msg);
                return 1;
        }
        if (!ob) return notify_fail("�{�b�S " + str + " �o�ӤH�� (include ppl and npc), �]�S�� " + dir_str + ".c ���s�b.\n");
}

int help(object me)
{
        write(@HELP
���O�榡: where <�Ѽ�>

�Ѽƥi��:
�L          �C�X�Ҧ� users �Ҧb��m�C
grain       ��ϥΪ� "grain" . �Y�L, �h�C�X���W�� "grain" �� npc��m, �B�|
            �q�X "�o�b", "����", "�_�u", "NPC" �����A��ܡC
kao yeu     �C�X���W ( set_name ���Ĥ@�� string ), ���e�z�� npc��m�C
/obj/bottle �C�X�Ҧ��ɦW���e�z�������m, �B�|�@�h�h�q�X, ����ҳB���Ҭ�
            room ����C
bottle      �P�W��, ���u�j�M��e�ؿ� (current directory)�C
bottle.c    �P�W��C
HELP);
        return 1;
}
