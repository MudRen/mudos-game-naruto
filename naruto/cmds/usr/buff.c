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
                return notify_fail("�A���G�S���Ԥ�...\n");
    } else ob = present(arg, environment(me));
        if(!ob) ob = find_player(arg);
        if(!ob) ob = find_living(arg);
        if( !ob ) ob = LOGIN_D->find_body(arg);
        if(!ob) return notify_fail("�A�n��ݽ֪����A�S\n");
        if(!living(ob)) return notify_fail("�A�u���ݥͪ������A�C\n");
        if( !wizardp(me) && (object)ob->query_owner() != me )
            return notify_fail("�u���Ův���ݧO�H�����A�C\n");
    }
    line += ob->name() + "�����A�G\n";
    line += "��������������������������������������������������������������������\n";
    buffering = ob->query_all_conditions();
    if( sizeof(buffering) ) {
        foreach(buf in keys(buffering) ) {
            tmp = "";
            if( undefinedp(buffering[buf]) ) continue;
            br++;
            sk = uncolor(buffering[buf]["name"]);
            tmp += sprintf("%-23s", sk + "("+ buffering[buf]["duration"]/30 + ":" + (buffering[buf]["duration"]*2)%60 + ")");
            tmp = replace_string(tmp, sk, buffering[buf]["name"]);
        
            // ����
            if( br%3 == 0 ) {
                br = 0;
                tmp += "\n";
            }
            line += tmp;
        }
    }
    if( br ) line += "\n";
    line += "��������������������������������������������������������������������\n";
    write(line);
    return 1;
}

int help(object me)
{
    write(@HELP
���O�榡 : buff
           buff <��H�W��>

�o�ӫ��O�i�H��ܧA(�p)�Ϋ��w��H(�t�Ǫ�)�����A�A�p�G�A����H��
�O�A���Ԥ��A�L�k�ϥγo�ӫ��O�A�A�]�i�H�Q�� buff _MY_PET_ �Ӷi��
�d�ߡC
HELP
);
    return 1;
}
