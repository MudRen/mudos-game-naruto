#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
    object npc;

    if( !arg )
        return notify_fail("�A�n�ݽ֤���ơS\n");

    if( !objectp(npc = present(arg, environment(me))) )
        return notify_fail("�o�̨S���o�ӤH�C\n");

    if( !npc->is_character() ) {
        message_vision("$N���$n�ۨ��ۻy....\n", me, npc);
        return 1;
    }

    if( QUEST_D->doReward(npc, me) ) return 1;
    QUEST_D->doAssign(npc, me);
    
    return 1;
}

int help(object me)
{
   write( @HELP
���O�榡: ask <�Y�H>

�o�ӫ��O�b�����ɫܭ��n, �q�`�����ǥѦ��@���O�~����o�i�@�B����T�C
HELP
   );
   return 1;
}
