#include <npc.h>
#include <ansi.h>
#include "skill.h"

string *name1 = ({ "�ӶQ", "�[��", "�B�A", "����", "�[��", "����", "�@�l",
                   "�ե�", "���", "�դs", "����", "�Ѧa", "�կ�", "�°�",
                   "����", "����", "�ŷ�", "����", "�դ�", "�¤�", "����",
                   "�Y", "�z", "�s", "�t", "�e", "��", "�}", "�b", "��",
                   "�u", "�U", "�L", "�f", "�x", "��", "��", "��", "��",
                   "�b�L��", "������", "�l�ȭ�", "�W����", "�U����" });

void create()
{
    set_name("�˨�"+name1[random(sizeof(name1))], ({ "wheya ninja", "ninja" }) );
    set_level(35);
    set_class("middle");
    set_race("human");

    if( random(2) == 1) set("gender", "male");
    else set("gender", "female");

    set("age", 15+random(41));
    set("title",HIR"���~����"NOR);
    set("camp", "wheya");
    set("long",@LONG
�˨��@�ڡA�b�ܤ[�H�e���@���Ԫ���A��M�X�{���s�ڸs�A�L�̤j�h
�O�Ԫ��L��s���U�Ӫ��H�A�]���@�ǬO��N�l�]�C�L�̷|�Q�H�o�{��
�̤j��]�A�N�O�L�̯���N���Y�Ƭ��Q�b�A�b���n���ɨ��ٯ�N�ۤv
���W�����Y�ޥX�����Z���A�]�ӹL��{�ӳQ�@�H�{���O�c�]�@�ڡA��
���ӳQ����Ԫ��j�D�Y�Ҧ��d�A�K�w�~�b�L���H��ள��Z����
�y�e���Գ��z���U�j�D�Y�����䪺�D�H�@�ڡC
LONG);
    set("chat_chance", 10);
    set("chat_msg", ({
        (: do_check :),
        (: random_move :),
    }));
    set("chat_chance_combat", 40);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"obj", "id":29, "amount":100+random(200), "p1":60, "p2":100 ]), // �Ȥl
        ([ "type":"food", "id":16, "amount":1, "p1":3, "p2":100 ]),      // �j��O�Y
        ([ "type":"food", "id":18, "amount":1, "p1":5, "p2":100 ]),      // �j��O�Y
        ([ "type":"food", "id":20, "amount":1, "p1":3, "p2":100 ]),      // �j�d�J�Y
        ([ "type":"obj", "id":78, "amount":1, "p1":80, "p2":100 ]),      // ���]����
        ([ "type":"wp", "id":50, "amount":1, "p1":1, "p2":700 ]),        // �ᰩ�C
        ([ "type":"eq", "id":85, "amount":1, "p1":1, "p2":600 ]),        // �G�L�Э�
        ([ "type":"obj", "id":90, "amount":1, "p1":1, "p2":1000 ]),      // ���y�P���ѱ���
    }) );
    setup();
    add_temp("apply", (["hp":1500 ]) );
    // ���վ�L ap, hp, mp ���n do_heal(), �~�������A�ɺ�
    do_heal();
}
void die()
{
    object ob, *obs;
    obs = all_inventory(this_object());
    if( this_object()->query_temp("quest/psychical") == 1 ) {
        message_vision("�]��$N�����ҥH"HIW"�ᰩ�C"NOR"�������ƤF...�C\n"NOR, this_object());
        this_object()->delete_temp("quest/psychical");
        foreach( ob in obs ) destruct(ob);
    }
    ::die();
}
