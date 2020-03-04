#include <npc.h>
#include <ansi.h>

object owner;

void create()
{
    set_name("����", ({ "cockroach" }) );
    set_race("beast");
    set_level(1);
    set("long", "�@�����ߪ������C\n");
    set("limbs", ({ "���Y", "����", "����", "���L", "����" }) );
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");         // �D�ʧ���

    set("set_drop", ({
        ([ "type":"obj", "id":25, "amount":1, "p1":80, "p2":100 ]),   // ����Ĳ��
        ([ "type":"food", "id":34, "amount":1, "p1":60, "p2":100 ]),   // �����Z
        ([ "type":"obj", "id":26, "amount":1, "p1":80, "p2":100 ]),   // �����}
    }) );
    setup();
}

// �]�w�D�H
int set_owner(object obj)
{
    if( !objectp(obj) ) return 0;
    owner = obj;
}

// �d�ߥD�H
object query_owner()
{
    if( !objectp(owner) ) return 0;
    return owner;
}

// ���H���j�ǳ��w�ۤ@�������h��
// ���O�O�@�԰��ä��|�N�H����
// �ɭP�w�˪��������ӫ�S�O�@�Ӧn����
// �ҥH�w�����Ӫ��������A�קK�S�Q�ϥ�
void unconcious()
{
    die();
    return;
}

void die()
{
    // �w�g�n�����N���Τ@�����ܤF
    if( query("WILL_DIE") ) return;

    if( !query("no_die") ) {
        ::die();
        return;
    }
    message_vision("$N���M���G"HIG"$N���i�|�����ڥu������즹�F�I�A���I\n"NOR, this_object(), owner);
    message_vision(CYN"$N�@�ȷϦa�N�k���F�C\n"NOR, this_object());
    this_object()->guard_ob(0);
    if( owner ) {
        if( owner->query_temp("cockroach/guard") <= 1 ) owner->delete_temp("cockroach/guard");
        else owner->add_temp("cockroach/guard", -1);
    }
    set("WILL_DIE", 1);
    do_chat((: destruct, this_object() :));  // ����A���Q�����ˮ`���]�X��
    return;
}
