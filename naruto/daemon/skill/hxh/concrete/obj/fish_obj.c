/* update to �K�ǩ��� 
 Tmr 2006/06/04
 Mouse 2007/7/25 �ק�
*/

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
    message_vision("$N�ϤF�ϧ��ڴN�����b�o�ӥ@�ɤW�F...\n", this_object());
    set("WILL_DELETE", 1);

    // �������@�ǰʧ@���]�L
    do_chat( ({ (: destruct, this_object() :) }) );
    return;
}

// �H���ˬd�֦��̬O�_�������d�J�ԡA�åB�l��
void do_check()
{
    string name;
    object ob;

    name = owner->query("id");
    ob = LOGIN_D->find_body(name);

    // �֦��̤��b�u�W�A�h������
    if( !ob ) {
        do_destruct();
        return;
    }
    // �b���P��m�|�۰ʲ���D�H����A���O�n���Ӥ@�ǩ��O
    if( environment(owner)->is_area() ) {
        if( !area_environment(this_object(), owner) ) {
            area_move(environment(owner), this_object(), owner->query("area_info/x_axis"), owner->query("area_info/y_axis"));
            ob->damage_stat("mp", 5);
            message_vision("$N�l���F$n�����O���s�^��$n���ǡC\n", this_object(), owner);
            return;
        }
    } else {
        if( environment(this_object()) != environment(owner) ) {
            this_object()->move(environment(owner));
            ob->damage_stat("mp", 5);
            message_vision("$N�l���F$n�����O���s�^��$n���ǡC\n", this_object(), owner);
            return;
        }
    }
    if( owner->query_stat("mp") < 10 ) {
        message_vision("�]���D�H�L�k���ѩ��O...$N���������F...\n", this_object(), owner);
        do_destruct();
        return;
    }
    return;
}

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
    set_name("�K�ǩ���", ({ "fish", "__CHMABER_FISH_NPC__" }));
    set_race("beast");

    // ���ɰʧ@�G�ˬdowner�٦b���b�A�çl����d�J��
    set("chat_chance", 100);
    set("chat_msg", ({
        (: do_check :),
    }));

    // �԰��ɰʧ@�G�ˬdowner�٦b���b�A�çl����d�J��
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: do_check :),
    }) );

    set("no_fight", 1);
    setup();
}
