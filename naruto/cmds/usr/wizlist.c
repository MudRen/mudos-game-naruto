/*  wizlist.c */

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    int i;
    string *list, str;
    string *admin = ({}), *arch = ({}), *wizard = ({}), *apprentice = ({}), *immortal = ({}), *unknown = ({});

    list = SECURITY_D->query_wizlist();
    for( i = 0; i < sizeof( list ); i++ ) {
        switch( SECURITY_D->get_status( list[i] ) ) {
            case "(admin)": admin += ({ list[i] }); break;
            case "(arch)": arch += ({ list[i] }); break;
            case "(wizard)": wizard += ({ list[i] }); break;
            case "(apprentice)": apprentice += ({ list[i] }); break;
            case "(immortal)": immortal += ({ list[i] }); break;
            default: unknown += ({ list[i] }); break;
        }
    }

    str  = "�~�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
    str += sprintf("�x%-68s�x\n", MUD_NAME + "�޲z�s");
    str += "�u�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��";

    str += "\n�x"HIY+BRED"�ϢҢۢע�\n"NOR"�x";
    if( admin ) for(i=0;i<sizeof(admin);i++) {
        str += sprintf("%-12s%s", admin[i], (i % 6 == 5 ) ? "\n�x" : "");
    }

    str += "\n�x\n�x"HIY+BRED"�Ϣ�Ѣ�\n"NOR"�x";
    if( arch ) for(i=0;i<sizeof(arch);i++) {
        str += sprintf("%-12s%s", arch[i], (i % 6 == 5 ) ? "\n�x" : "");
    }

    str += "\n�x\n�x"HIY+BRED"��ע�Ϣ��\n"NOR"�x";
    if( wizard ) for(i=0;i<sizeof(wizard);i++) {
        str += sprintf("%-12s%s", wizard[i], (i % 6 == 5 ) ? "\n�x" : "");
    }

    str += "\n�x\n�x"HIY+BRED"�Ϣޢޢ�Ӣܢ�עѢ�\n"NOR"�x";
    if( apprentice ) for(i=0;i<sizeof(apprentice);i++) {
        str += sprintf("%-12s%s", apprentice[i], (i % 6 == 5 ) ? "\n�x" :"");
    }

    str += "\n�x\n�x"HIY+BRED"�עۢۢݢ��Ϣ�\n"NOR"�x";
    if( immortal ) for(i=0;i<sizeof(immortal);i++) {
        str += sprintf("%-12s%s", immortal[i], (i % 6 == 5 ) ? "\n�x" : "");
    }
    str += "\n���w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";

    write( str );

    return 1;
}

int help(object me)
{
write(@HELP
���O�榡 : wizlist

�γ~: �C�X�ثe�Ҧ����Ův�W��.

�Ѧ�: finger, who -w
HELP
     );
     return 1;
}
