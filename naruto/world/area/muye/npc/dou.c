#include <npc.h>

inherit F_FIGHTER;

void to_do_say()
{
    do_chat( ({ 
        (: command, "say �Q�n�u�ѥ[�v���Ԫ��ҸնܡI�H" :),
        (: command, "say ����O���U�Ԭҥi�H���W�ѥ[�I" :),
    }) );
}

void create()
{
    set_name("�s��~����", ({ "dou" }));
    set_race("human");
    set_level(60);
    set("camp", "muye");
    set("long", "��l�W���G�L�A���G�P�j�D�Y���o�s�C\n");

    set("age", 24);
    set("gender", "female");

    // �@��ɰʧ@
    set("chat_chance", 3);
    set("chat_msg", ({
        (: to_do_say :),
    }) );

    setup();
}

// ��char��say���O�ɡA��mob���^��
int relay_say(object me, string arg)
{
    if( !objectp(me) || !stringp(arg) ) return 0;

    if( arg == "�ѥ[" || arg == "�ѥ[�Ҹ�" ) {
        if( me->query_level() < 20 ) {
            this_object()->force_me("say " + me->query("name") + "�A�A����O���㪺�����A�������A�ѥ[���ԦҸաC");
            return 1;
        }

        if( me->query_class() != "inferior") {
            this_object()->force_me("say " + me->query("name") + "�A�u���U�Ԥ~��ѥ[�Ҹծ@�C");
            return 1;
        }

        if( me->query_temp("middle_test") ) {
            this_object()->force_me("say " + me->query("name") + "�A�A�w�g�ѥ[���ԦҸդF�C");
            return 1;
        }

        this_object()->force_me("say �ܦn�ܦn�I" + me->query("name") + "�h�˪L�̮��Ѥ��ѻP�a���ѵ��ڡC");
        this_object()->force_me("say �����o�G�˪F���A��i�ҩ��A��������Ԫ���O�A�[�o�a�I");
        this_object()->force_me("say �Y����T���Ѥ��ѩΤT���a���ѡA��i�H�ҩ��A����O�I");

        me->set_temp("middle_test", 1);
    }

    return 1;
}

int accept_object(object me, object item)
{
    int pass=0;

    if( !objectp(me) || !objectp(item) ) return 0;
    if( !item->query("middle_test") ) return 0;

    if( me->query_level() < 20 ) {
        this_object()->force_me("say " + me->query("name") + "�A�A����O���㪺�����A�������A�ѥ[���ԦҸաC");
        return 0;
    }

    if( me->query_class() != "inferior") {
        this_object()->force_me("say " + me->query("name") + "�A�u���U�Ԥ~��ѥ[�Ҹծ@�C");
        return 0;
    }

    if( !me->query_temp("middle_test") ) {
        this_object()->force_me("say " + me->query("name") + "�A�A�S���ѥ[���ԦҸդF�C");
        return 0;
    }

    message_vision("$N���L$n����"+ item->query("name") +"���D�G��...���������I\n", this_object(), me);

    if( item->query("middle_test") == 1 ) me->add_temp("middle_test_b1", 1);
    if( item->query("middle_test") == 2 ) me->add_temp("middle_test_b2", 1);

    if( me->query_temp("middle_test_b1") >= 3 ) pass = 1;
    if( me->query_temp("middle_test_b2") >= 3 ) pass = 1;
    if( me->query_temp("middle_test_b1") >=1 && me->query_temp("middle_test_b2") >=1 ) pass = 1;

    if( pass ) {
    	me->delete_temp("middle_test");
    	me->delete_temp("middle_test_b1");
    	me->delete_temp("middle_test_b2");
        this_object()->force_me("say �ܦn�I" + me->name() + "�A�q���H��N�O���ԤF�I");
        this_object()->force_me("cong " + me->query_id());
        me->set_class("middle");
    }

    // �ϥ� do_chat �ө���I�s destruct ���� give �ʧ@����
    do_chat((: destruct, item :));

    return 1;
}
