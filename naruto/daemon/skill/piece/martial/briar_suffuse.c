#include <ansi.h>
#define SKILL_NAME "briar suffuse"
#define SKILL_NAME_C "��Ƥ���"
#define SKILL_CLASS "martial"

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

// �j�ׯ�O�v�T
int evade(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)*3/25;
}

int attack(object me, object target, int ability, int type)
{
    string *name = ({ "�ӻH", "�k�j�L", "�{�l", "�k�u", "�I��", "�k�p�L", "�ݤf", 
                      "���j�L", "���u", "���p�L", "�k��", "����", "�߷F", "����",
                      "���\\", "����", "�@�B", "��m", "����", "���U", "���",
                      "�{��", "�Ǥl", "�@����", "����", });

    int sk, i, number;
    object *targets;

    if( !type ) return ability;

    sk = me->query_skill(SKILL_NAME, 1);
    targets = me->query_enemy();
    number = (sk/66) - 1;
    if( number <= 0 ) number = 0;

    // �P�_�O�_�Ұ�
    if( me->query_stat("mp") < 200 ) return ability;
    if( me->query_skill("martial", 1) < 180 ) return ability;
    if( me->query_skill("gun whip", 1) < 100 ) return ability;
    if( sk < 40 ) return ability;

    if( sk < 80 ) {                          // 20~80 �� 5%
        if( random(sk) < sk*19/20 ) return ability;
    } else if( sk < 150 ) {                  // 81~150 �� 10%
        if( random(sk) < sk*9/10 ) return ability;
    } else {                                 // 151~200 �� 20%
        if( random(sk) < sk*8/10 ) return ability;
    }
    message_vision("$N���ʵ������V�|�P"HIM"�y"HIG"��Ƥ���"HIM"�z"NOR"���֪���k���H�L�k�@��$N�O�_�����Z���C"NOR"�I\n", me, target);

    // �h�H�����P�w
    for(i=0;i<sizeof(targets);i++) {
        if( i > number ) break;   // �̦h�����T�H
        if( targets[i]->is_busy() ) {
            message_vision("\t$n���G�w�g�L�k�ʼu�C\n", me, targets[i]);
        } else {
            if( random(me->query_ability("exact")+me->query_ability("wittiness") ) <
                random(targets[i]->query_ability("evade")+targets[i]->query_ability("intimidate")) ) {

                message_vision("\t$n�Φۤv���Z����׹w���������u�A���Q���{�L�����C\n", me, targets[i]);
            } else {
                targets[i]->start_busy(sk/33);
                message_vision("\t$n���Ἲ�ä��ڳQ���������A���M�Pı�����·��L�k��ʡC\n", me, targets[i]);
                me->improve_skill(SKILL_NAME, 1);
            }
        }
    }
    // ����mp
    me->damage_stat("mp", 50*i, me);
    return ability;
}
