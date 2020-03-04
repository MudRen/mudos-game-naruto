#include <npc.h>
#include <ansi.h>

inherit F_VILLAGER;

void to_do_say()
{
    do_chat( ({ 
        (: command, "say �n�u�[�J�v���x���H�N�ӧ�ڭ^��"+this_object()->query("name")+"�a�I" :),
        (: command, "say �ڴN�O�Y�N�������x�^�����j�H�����I" :),
    }) );
}
void create()
{
    set_name("����F�i", ({ "si pan da mu", "si", "pan", "da", "mu"}) );
    set_race("human");
    set_level(5);
    set_class("general_sea");  // ���x��N
    set("age", 28);
    set("title", HIR"�Ѣޢ����x"NOR);
    set("long", "�y�W���K�s������ҫO�@�A���G���g����L�Y�����ˮ`�C�L�N�O���x\n"
                "�ҳ����c�Ѣޢ������x����F�i�C���M�L�O���x�A���L�ھڮ��L�̩�\n"
                "���A�L�������|�Ѣޢ��S��ۦ��u�����v�A�s�@�몺���L������Ĺ�C\n");

    set("chat_chance", 3);
    set("chat_msg", ({
        (: to_do_say :),
    }) );
    setup();
}
// ��char��say���O�ɡA��mob���^��
int relay_say(object me, string arg)
{
    object test;

    if( arg == "�[�J" || arg == "�[�J���x" ) {
        if( me->query("guild") == 0 ) {
            do_chat( ({ 
                (: command, "say "+this_player()->query("name")+"���h���x����B�n�O�a�I" :),
            }) );
            return 1;
        }
        if( me->query("guild") != "piece" ) {
            do_chat( ({ 
                (: command, "shake" :),
                (: command, "say "+this_player()->query("name")+"�w�g�[�J��L��´�F�I" :),
                (: command, "say �������x���㦳�h�������I" :),
            }) );
            return 1;
        }
        if( me->query_class() != "commoner" ) {
            do_chat( ({ 
                (: command, "say "+this_player()->query("name")+"�w�g�֦�¾�~�F�I" :),
                (: command, "say �������x���㨭�ݦh¾�I" :),
            }) );
            return 1;
        }
        if( me->query_temp("quest/mitp") ) {
            do_chat( ({ 
                (: command, "say "+this_player()->query("name")+"�w�g�������ը��F�I" :),
                (: command, "say �������x���㨭�ݦh¾�I" :),
            }) );
            return 1;
        }
        test = new( __DIR__"item/paper.c" );
        if( !objectp(test) ) {
            do_chat( ({
                (: command, "say �V�|�I�@���p�ߧ�Ҩ����o���F�I" :),
                (: command, "say �������L�b�d���򰭡I�٤��e�s���ը��L�ӡI" :),
            }) );
            return 1;
        }
        if( !test->move(this_object()) ) {
            do_chat( ({ 
                (: command, "ah" :),
                (: command, "say ���ը��\���h�F�I" :),
            }) );
            destruct(test);
            return 1;
        }
        // �]�w���a�Ȯ��ܼơA�H���@����Ҩ�
        if( test->move(me) ) {
            me->set_temp("quest/mitp", 1);
            do_chat( ({ 
                (: command, "say ���ը��浹"+this_player()->query("name")+"�F�I�g���N���ڧa�C" :),
                (: command, "say �p�G�S�������藍��[�J���x�I" :),
            }) );
        } else if( test->move(environment(me)) ) {
            do_chat( ({ 
                (: command, "say "+this_player()->query("name")+"���W�ӭ��I�Ҹը��ک�b�a�W�A�g���N���ڧa�C" :),
                (: command, "say �p�G�S�������藍��[�J���x�I" :),
            }) );
        } else {
            destruct(test);
            return 0;
        }
    }
    return 1;
}

int accept_object(object me, object item)
{
    int score;

    if( !objectp(me) || !objectp(item) ) return 0;
    if( item->is_test_paper() != "piece" ) return 0;

    if( me->query("guild") != "piece" ) {
        message_vision("$N���D�R"HIG"$n�n���O��L��´���H�C�I\n"NOR, this_object(), me);
        return 0;
    }
    if( me->query_class() != "commoner" ) {
        message_vision("$N���D�R"HIG"$n�w�g��¾�~�F�a�I�H\n"NOR, this_object(), me);
        message_vision("$N���D�R"HIG"���$N�o��n�F�ܡI\n"NOR, this_object(), me);
        return 0;
    }
    score = item->do_check();
    message_vision("$N�n��$n�r��...�L�������H�H���...\n", this_object(), item);

    if( score != 100 ) {
        message_vision("$N���D�R"HIG"$n�u�O�Ӯt�l�F�I\n"NOR, this_object(), me);
        message_vision("$N���D�R"HIG"�u��"+chinese_number(score)+"���]�Q�[�J���x�H\n"NOR, this_object(), me);
        return 0;
    }
    message_vision("$N���D�R"HIG"�g�������I�ڦP�N$n�[�J�աI\n"NOR, this_object(), me);
    message_vision("$N���D�R"HIG"�q���Ѷ}�l$n�N�O���x���@���F�I\n"NOR, this_object(), me);
    message_vision("$N���D�R"HIG"�n�n�n�O�@�ڪ��w�����I\n"NOR, this_object(), me);
    me->set("title", "�@�ɬF�����x");
    me->addCamp("police");  // �W�[���x�}��
    me->set_level(1);
    me->set_class("work_sea");

    // �ϥ� do_chat �ө���I�s destruct ���� give �ʧ@����
    do_chat((: destruct, item :));
    return 1;
}
