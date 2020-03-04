// cast.c

#include <skill.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    string martial_skill, act, trg;
    object target;

    if( !arg ) return notify_fail("���O�榡�Rperform <�ޯ�.����> on <�ؼ�>\n");
    
    if( me->query_condition("weak") ) return notify_fail("�A�ӵ�z�F�A�S��k�ϥΧޯ�C\n");

    if( sscanf( arg, "%s.%s on %s", martial_skill, act, trg ) == 3 ) {
        if( !me->skill_mapped(martial_skill) )
        	return notify_fail("�Х��� enable ���O��ܧA�n�ϥΪ��ޯ�C\n");
        
        // ���� mob �]�� id ���D
        // �b area ���|�P�_����A������������
        // �ҥH�t�~�� mob �@�ӧP�_���A�p�G�䤣����N�H�����ĤH
        if( userp(me) ) {
            if( !(target = present(trg, environment(me))) || !target->is_character() || target->is_corpse() ) return notify_fail("�o�̨S���o�ӤH�C\n");
        } else {
            if( !(target = present(trg, environment(me))) ) target = me->query_opponent();
            if( !target ) target = me;
            if( !target || !target->is_character() || target->is_corpse() ) return notify_fail("�o�̨S���o�ӤH�C\n");
        }
        
//        martial_skill = me->skill_mapped(martial_skill);
        
        return SKILL_D(me->skill_mapped(martial_skill))->perform_action(me, act, target);

    } else if( sscanf( arg, "%s.%s", martial_skill, act ) == 2 ) {
        if( !me->skill_mapped(martial_skill) )
        	return notify_fail("�Х��� enable ���O��ܧA�n�ϥΪ��ޯ�C\n");

//        martial_skill = me->skill_mapped(martial_skill);

        return SKILL_D(me->skill_mapped(martial_skill))->perform_action(me, act, target);

    } else return notify_fail("���O�榡�Rperform <�ޯ�.����> [on <�ؼ�>]\n");

    return 0;
}

int help (object me)
{
    write(@HELP
���O�榡�Rperform <�ޯ�.����> [on <�I�۹�H>]

�b�԰����ϥΩҾǧޯ઺���ۨөM�I�۹�H��ԡA���ۥi�H�Ѧ�
�ӧO���ޯ�Ҵ��Ѫ�HELP�C
HELP);
    return 1;
}
