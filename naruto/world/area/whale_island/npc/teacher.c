/* guild: hunter  �y�H */
// write by Tmr 2005/10/22

#include <npc.h>

inherit F_VILLAGER;
inherit F_TRAINER;    // �V�m�ɮv

void to_do_say()
{
    do_chat( ({ 
        (: command, "say �Q���W���~�ת��y�H����ܡH���ɲ߯Z���еL���A�w��j�a�u���W�v�I" :),
        (: command, "say �u�n�A��q�L���ɲ߯Z���u�����ҡv�A�N�ন���L���y�H��I�I" :),
        (: command, "say ���ɲ߯Z���M�~�H�h�A�M�����ɵL���y�H���򥻰V�m�A���n�̫᪺�Ĩ�A�@�|�Ҩ��y�H���ӡI�I" :),
        (: command, "say �ӨӨӡ�㦳��L���A������N�������A�u�n���ߡA�H�H���ন���y�H�I�I" :),
    }) );
}

void create()
{
    set_name("�C�K��", ({ "hang tie-guan", "hang", "guan", "teacher"}) );
    set_race("human");
    set_level(40);
    set_class("hxh_intermediate");  //�����y�H
    set("age", 25);
    set("camp", "hunter");
    set("title", "�y�H�{�����v");
    set("long", "�C�K�ެO�@�W�㦳�������v���A�M�������y�H���Ӫ����V�u�@�C\n"
                "�Y�A�㦳�L���y�H�A�h��ܧA�㦳�ѥ[�y�H�Ҹժ����C�A�i�H�Q��\n"
                "train ���O�ӦV�C�K�޾ǲߧޯ�C�ϥ� list ���O�d�ߥi�ǲߪ��ޯ�C��C\n" );

    // �@��ɰʧ@
    set("chat_chance", 3);
    set("chat_msg", ({
        (: to_do_say :),
    }) );

    // �u�����y�H
    set("guild", "hunter");

    // �]�w��V�m���ޯ�
    //
    // set_train(�ޯ�W, �O�_�i�����߱o, �ǲ߸ӧޯ�һݭn�����ⵥ��, ���ޯ�i�ǲߨ쪺�W������)
    //
    // ���a�S���ӧޯ�ɡA�Y"�O�_�i�����߱o"�o�ӳ]�w�Ȭ��D�s�ȮɡA���a�V�V�m�̾ǲ߮ɫh�i�O��
    // �o�ӧޯ��lv1�A�Ӧ�lv���ޯ�~�i�H���I�~����m�C�G�i�Ω�S��ޡA�n�����o��lv���i�V�m�C
    //
    set_train_with_camp("combat", 1, 1, 160, "hunter", -2);            // �氫�ޥ�
    set_train_with_camp("dodge", 1, 1, 160, "hunter", -2);             // �{���ޥ�
    set_train_with_camp("parry", 1, 1, 160, "hunter", -2);             // �׮�ޥ�
    set_train_with_camp("heavy hit", 1, 5, 140, "hunter", -2);         // �������N
    set_train_with_camp("savage hit", 1, 5, 140, "hunter", -2);        // �������N
    set_train_with_camp("continual hit", 1, 5, 140, "hunter", -2);     // �s�����N
    set_train_with_camp("strength", 1, 10, 120, "hunter", -2);         // �j�ƨt
    set_train_with_camp("variation", 1, 10, 120, "hunter", -2);        // �ܤƨt
    set_train_with_camp("operation", 1, 10, 120, "hunter", -2);        // �ާ@�t
    set_train_with_camp("emit", 1, 10, 120, "hunter", -2);             // ��X�t
    set_train_with_camp("concrete", 1, 10, 120, "hunter", -2);         // ��{�t
    set_train_with_camp("special", 1, 10, 120, "hunter", -2);          // �S��t

    setup();

    // �H���������ޯ�]�w
    set_skill("solid", 100);               // ���ޡG��
    map_skill("parry", "solid");    
}

// ��char��say���O�ɡA��mob���^��
int relay_say(object me, string arg)
{
    if( !objectp(me) || !stringp(arg) ) return 0;

    if( arg == "���W"  ) {
        if( me->query("guild") )
                return 0;
        this_object()->force_me("say �ܦn�ܦn�I�q���H�� " + me->query("name") + " �N�O�ڭ̪��ǭ��F�I");
        me->set("guild", "hunter");
        me->set("title", "�y�H�ҥ�");
        return 1;
    }   

    if( arg == "������" || arg == "�ѥ[������" ) {
        object test;
        if( me->query("guild") != "hunter" ) {
            this_object()->force_me("say " + me->query("name") + "�A�A���O�ڭ̪��ǭ��A����ѥ[�����Ү@�C");
            return 1;
        }

        if( me->query_class() != "commoner" ) {
            this_object()->force_me("say " + me->query("name") + "�A���ɲ߯Z�������ҥu�A�Ω�@�몺�����@�C");
            return 1;
        }

        if( me->query_temp("quest/hunter_exam") ) {
            this_object()->force_me("say " + me->query("name") + "�A�A�褣�O�w�g��ڮ��L�Ҩ��F�H");
            return 1;
        }

        test = new( __DIR__"item/hunter_exam.c" );
        if( !objectp(test) ) {
            this_object()->force_me("say " + me->query("name") + "�A�����Ҫ��Ҹը��Χ��F�C");
            return 1;
        }

        if( !test->move(this_object()) ) {
            this_object()->force_me("say " + me->query("name") + "�A���r�I�ڧѤF���Ҹը��X�ӡC");
            destruct(test);
            return 1;
        }
        // �]�w���a�Ȯ��ܼơA�H���@����Ҩ�
        me->set_temp("quest/hunter_exam", 1);

        this_object()->force_me("give paper to " + me->query_id()) ;
        this_object()->force_me("say " + me->query("name") + "�A�N�Ҹը��W�����׶�@��A������A�����ڡC");
        return 1;
    }
    return 1;
}

int accept_object(object me, object item)
{
    int score;

    if( !objectp(me) || !objectp(item) ) return 0;
    if( item->is_test_paper() != "hunter" ) return 0;

    if( me->query("guild") != "hunter" ) {
        this_object()->force_me("say " + me->query("name") + "�A�A�ä��O�ڭ̪��ǭ��A�Х����W�ڭ̪��ҵ{�a�C");
        return 0;
    }
    
    if( me->query_class() != "commoner" ) {
        this_object()->force_me("say " + me->query("name") + "�A�����ҥu�A�Ω�@�몺�����@�C");
        return 0;
    }

    score = item->do_check();

    message_vision("$N�����ֳt�a���˵�$n...\n", this_object(), item);

    if( score != 100 ) {
        this_object()->force_me("say ����I�H�u��" + chinese_number(score) + "���]�Q�h���y�H���ӡI�H");
        return 0;
    }
    this_object()->force_me("say ���������I�ҤF�����A" + me->name() + "�A�q���H��N�֦����y�H���Ӫ����F�I�I");
    this_object()->force_me("cong " + me->query_id());

    me->set("title", "����O��");
    me->set_level(1);
    me->addCamp("hunter");  // �W�[�y�H���|�}��
    me->set_class("hxh_initial");

    // �ϥ� do_chat �ө���I�s destruct ���� give �ʧ@����
    do_chat((: destruct, item :));

    return 1;
}
