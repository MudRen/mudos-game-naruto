#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name(HIK"�����Z"NOR, ({ "cockroach's egg", "egg" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("base_value", 8);
        set("base_weight", 100);
        set("food_stuff", 1);              // �����q�A���~�@�w�n�������q
        set("long", "�@���c�䪺�����Z�A�p�G�A���R�ߪ��ܡA�i�H��(incubate)�o�������Z�C\n");
    }
    setup();
}

void init()
{
    if( userp(environment(this_object())) ) add_action("do_incubate", "incubate");
}

int do_incubate(string arg)

{
    int love;

    object me = this_player();

    if( arg != "egg" )
        return notify_fail("�A�Q�n�夰��F��H\n");

    if( me->is_busy() )
        return notify_fail("�A�{�b�S���šC\n");

    if( me->query_stat("ap") < 10 )
        return notify_fail("�A�S�����h����O�ӹ�Z�C\n");

    if( me->query_temp("cockroach/guard") > 5 )
        return notify_fail("�A�w�g�i�Ӧh�������_�_�F�C\n");

    message_vision("$N�Ӥߪ��N$n��b�h���p�ߪ����@�ۡC\n", me, this_object());

    love = 1 + random(10);
    me->damage_stat("ap", love*2);
    if( !me->query_temp("cockroach/love") ) me->set_temp("cockroach/love", love);
    else me->add_temp("cockroach/love", love);

    if( me->query_temp("cockroach/love") > 100 ) {
        object pet;
        string msg, ms;

        pet = new("/world/area/muye/npc/cockroach.c");
        pet->delete("attitude");

        message_vision("$N���W��$n�w�g�۷����A�Ať��X�n���ܪ��n��" + pet->name() + "�}�J�ӥX�I\n", me, this_object());

        if( me->query("gender") == "male" ) {
            msg = "�Ѫ�";
            ms = "�ީ�";
        } else if( me->query("gender") == "female" ) {
            msg = "�Ѷ�";
            ms = "����";
        } else {
            msg = "�D�H";
            ms = "�D�H";
        }
        // ���ӭn�������W���~��
        me->delete_temp("cockroach/love");
        if( !me->query_temp("cockroach/guard") ) me->set_temp("cockroach/guard", 1);
        else me->add_temp("cockroach/guard", 1);

        if( environment(me)->is_area() ) move_side(pet, me);
        else pet->move(environment(me));

        pet->set_leader(me);     // ���Hleader
        pet->guard_ob(me);       // �O�@leader
        pet->set_owner(me);      // �]�wowner
        pet->set("long", "�@�����ߪ������C\n"
                         "�e��"+msg+"�O"+me->query("name")+"�C\n");

        pet->set("no_die", 1);   // �w�˦��`���������P�_
        message_vision("$n�@�ݨ�$N�K�������s�F�n�G�u"+ms+"�I�v\n", me, pet);

        // �Ӽƴ��, ������a�A���|�@�˷|����
        this_object()->add_amount(-1);
        if( !this_object()->query_amount() ) destruct(this_object());
    }
    me->start_busy(2);
    return 1;
}
