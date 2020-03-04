/* continual_hi.c �s��
*/

#include <ansi.h>
#define SKILL_NAME  "continual hit"
#define SKILL_CLASS "basic"

inherit SKILL;

void create()
{
        seteuid(getuid());
    DAEMON_D->register_skill_daemon(SKILL_NAME);
}

string query_class() { return SKILL_CLASS; }

void skill_advanced(object me, string skill)
{
    int lv = me->query_skill(skill, 1);
    switch( lv ) {
        case 189: me->set_skill_require(skill, 1500000); break; // ���d3 : 189��190
        case 149: me->set_skill_require(skill, 1000000); break; // ���d2 : 149��150
        case  99: me->set_skill_require(skill, 500000);  break; // ���d1 :  99��100
        default:  me->set_skill_require(skill, lv*lv*5); break;
    }
}

// �۰ʬI�i�ޡA�P�_�O�_�n�h���@�U
int autoCasting(object me, object target, object weapon)
{
    int lv;

    // �o�@��attack�O�ѳs���o�_���A�ҥH�����ӦA�P�_�O���O�n�s��
    if( me->query_temp("skill/" + SKILL_NAME) ) return 1;

    // �S������o�ʳs��
    lv = me->query_skill(SKILL_NAME);
    if( random(lv) < random(400) ) return 1;

    message_vision(HIW"$N�ݨ�F$n���}��A�H�Y�A�ɤW�@��...\n"NOR, me, target);

    // �]�w�Ȧs��ơA�ΨӪ���s�����X�h�����@�ۤ]Ĳ�ʳs��
    me->set_temp("skill/" + SKILL_NAME, 1);
    
    // �A������
    me->attack(target);
    
    // �M���Ȧs���
    me->delete_temp("skill/" + SKILL_NAME);
    
    // �W�[�ޯ�g��
    me->improve_skill(SKILL_NAME, 1);

    return 1;
}
