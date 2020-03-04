#include <npc.h>

inherit F_VILLAGER;

object owner;

// �]�w�֦���
int set_owner(object obj)
{
    if( !objectp(obj) ) return 0;
    owner = obj;
}

// �d�߾֦���
object query_owner()
{
    if( !objectp(owner) ) return 0;
    return owner;
}

// �R���v����
void do_destruct()
{
    // �w�g�n�������d���N���Τ@���ۭn�����F
    if( query("WILL_DELETE") ) return;

    // �o�{�d���l��L�h���|�o�ͫO�@���~
    // �]�����}�ɨS���R���d���O�@
    // �ҥH�ֿn�F�L�h�� guard ��T  by mouse 2009/2/16
    this_object()->guard_ob(0);
    message_vision("$N�N���]�o���a�C�C�����b�Ť�...\n", this_object());
    set("WILL_DELETE", 1);

    // �������@�ǰʧ@���]�L
    do_chat( ({ (: destruct, this_object() :) }) );
    return;
}

// �H���ˬd�֦��̬O�_�������d�J�ԡA�åB�l��
void do_check()
{
    // �֦��̮����A�h�v��������
    if( !objectp(owner) ) {
        do_destruct();
        return;
    }
    
    // �b���P��m�]�|����
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), owner) ) {
            do_destruct();
            return;
        }
    } else {
        if( environment(this_object()) != environment(owner) ) {
            do_destruct();
            return;
        }
    }

    // �֦��̪��d�J�Ԥ���
    if( owner->query_stat("mp") < query_level() ) {
        do_destruct();
        return;
    }

    if( query_stat("hp") < 10 ) {
        do_destruct();
        return;
    }

    // �֦��̮����@�Ǭd�J��
    owner->damage_stat("mp", query_level() , owner);
    return;
}

// ���`�Ω��ˮɴN�ǳƮ��� 2007/7/25�s�W by mouse
void unconcious()
{
    do_destruct();
    return;
}
void die()
{
    do_destruct();
    return;
}

// �O�_�����R�O
int accept_order(object who, string cmd)
{
    return 0;  // �����O�������
}

void create()
{
    set_name("�a�H", ({ "family", "__FAMILY_NPC__" }));
    set_race("beast");

    // ���ɰʧ@�G�ˬdowner�٦b���b�A�çl����d�J��
    set("chat_chance", 3);
    set("chat_msg", ({
        (: do_check :),
    }));

    // �԰��ɰʧ@�G�ˬdowner�٦b���b�A�çl����d�J��
    set("chat_chance_combat", 5);
    set("chat_msg_combat", ({
        (: do_check :),
    }) );

    set("no_fight", 1);
    setup();
}
