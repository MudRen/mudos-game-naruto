#include <npc.h>

#define CATEGORY    "prize"             // ���૬����
#define ID1         3// �D�ָy�a����
#define ID2         4                   // ��z�����D�Y�j�H

inherit F_VILLAGER;

void to_do_say()
{
    do_chat( ({ 
        (: command, "say �D���U�س��쳣���䧮�Τ��B�A���̪񪺳D�O�V�ӶV���F�A����" :),
        (: command, "say �N�s���D�n��A�H�١u�ӴN���v�����D�Y�j�H�A�]�Q�j�D���r�ˤF..." :),
    }) );
}

void create()
{
    set_name("���^" , ({ "qin qin", "qin" }) );
    set("long", "����F�@����`�K�e�A�y��ô�F�Ӥp���M�A�@�Ʈ��D�H�a������C\n");

    set_level(35);

    set("gender", "female");
    set("title", "���D�H�a" );
    set("age", 42);

    // �@��ɰʧ@
    set("chat_chance", 3);
    set("chat_msg", ({
        (: to_do_say :),
    }) );

    setup();

}

void relay_say(object ob, string arg)
{
    if( arg == "�D��" )  {
        do_chat( ({ 
            (: command, "say �A�u�n���T�Q���D�֡A�A�I�@�ʻȨ�l�A�ڥi�H���A�s�@�D�ָy�a�C" :),
        }) );
        return;
    }

    if( arg == "�D�x" ) {
        do_chat( ({ 
            (: command, "say �ڻ��Q�γD�x�s�������ĥi�H�j���C" :),
        }) );
        return;
    }

    if( arg == "�D�J" ) {
        do_chat( ({ 
            (: command, "say �ڻ��Q�γD�J�s�������ĥi�H�P�i��G�`���C" :),
        }) );
        return;
    }

    if( arg == "���D�Y�j�H" || arg == "���D�Y" || arg == "�ӴN��" ) {
        do_chat( ({ 
            (: command, "say �۱q���D�Y�j�H�Q�D�r�ˤ���A����N�@���۷��z�C" :),
            (: command, "say ���ӭn��ǿL�@�Ǵ��Ĩ������D�Y�j�H�i�i�ɡC" :),
        }) );
        return;
    }

    if( arg == "�i��" || arg == "��" || arg == "����" || arg == "�L��" ) {
        if( ob->query_quest(CATEGORY, ID2) ) {
            do_chat( ({ 
                (: command, "say �A�u�n�����j�����Ӻ��x�B�Q���j���B�G�ӳD�x..." :),
                (: command, "say �٦��T���D�J�B�@���޸z�����t�Y..." :),
                (: command, "say �j���n���ӵ��ګK��F..." :),
            }) );
        } else {
            do_chat( ({ 
                (: command, "say �A�Q�����ڧ�@���ħ��ܡH" :),
            }) );
        }
        return;
    }

    if( arg == "�O" || arg == "�n" || arg == "�Q" || arg == "����" || arg == "�n" ) {
        if( !ob->query_quest(CATEGORY, ID2) ) {
            do_chat( ({ 
                (: command, "say �A�u�n�����j�����Ӻ��x�B�Q���j���B�G�ӳD�x..." :),
                (: command, "say �٦��T���D�J�B�@���޸z�����t�Y..." :),
                (: command, "say �j���n���ӵ��ګK��F..." :),
            }) );
            ob->add_quest(CATEGORY, ID2, 1);
        }
        return;
    }
}

int give_check(object ob)
{
    if( ob->id("_SNAKE_SKIN_") ) return 1;            // �D��
    else if( ob->id("_SNAKE_GALL_") ) return 2;       // �D�x
    else if( ob->id("_SNAKE_EGG_") ) return 3;        // �D�J
    else if( ob->id("_BEAR_PAW_") ) return 4;         // ���x
    else if( ob->id("_TURTLE_HEAD_") ) return 5;      // �t�Y
    else if( ob->id("_ABALONE_") ) return 6;          // �j��
    else if( ob->id("_PIG_GUT_") ) return 7;          // �޸z
    else return 0;
}

int accept_object(object me, object ob)
{
    object item;

    if( is_busy() ) {
        tell_object(me, "��西�b���L���A�е��@�U�C\n");
        return 0;
    }

    if( is_fighting() ) {
        do_chat((: command, "say �O�n�I�S�ݨ�ڥ��b���[�ڡI" :));
        return 0;
    }

    me->start_busy(1);
    this_object()->start_busy(1);

    switch( give_check(ob) ) {
        case 1:
            if( ob->query_amount() < 30 ) {
                do_chat((: command, "say �~�o�@�I�D�֡A�������@���y�a�a�C" :));

                return 0;
            }
            if( me->query("bank") < 100 ) {
                do_chat((: command, "say �A���Ȧ�̤����@�ʨ�]�Q��ڰ��D�ָy�a�H" :));
                return 0;
            }

            if( file_size(__DIR__"eq/snake_belt.c") < 0 ) return 0;
            if( catch(item = new(__DIR__"eq/snake_belt.c")) ) return 0;

            if( item->move(me) ) {
                message_vision("$N�q�I�᮳�X" + item->name() + "��$n�C\n", this_object(), me);
            } else {
                if( item->move(environment(me)) ) {
                    message_vision("$N�q�I�᮳�X" + item->name() + "��$n�A���O���b�a�W�F�C\n", this_object(), me);
                } else {
                    destruct(item);
                    return 0;
                }
            }

            me->add("bank", -100);
            ob->set_amount(0);
            do_chat( ({ ( : destruct , ob : ), }) );

            break;

        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            if( !me->query_quest(CATEGORY, ID2) ) {
                do_chat((: command, "say �ڤS�S�n�A���ڪ����A�o���n�N�䦬�U..." :));
                return 0;
            }

            me->add_temp("quest/" + CATEGORY+ID2 + "/" + give_check(ob), ob->query_amount() );

            if( me->query_temp("quest/"+CATEGORY+ID2+"/2") >= 2 && me->query_temp("quest/"+CATEGORY+ID2+"/3") >= 3 &&
                me->query_temp("quest/"+CATEGORY+ID2+"/4") >= 5 && me->query_temp("quest/"+CATEGORY+ID2+"/5") >= 6 &&
                me->query_temp("quest/"+CATEGORY+ID2+"/6") >= 10 && me->query_temp("quest/"+CATEGORY+ID2+"/7") >= 1 ) {
                me->delete_temp("quest/"+CATEGORY+ID2);
                me->delete_quest(CATEGORY, ID2);
                if( file_size(__DIR__"eq/snake_legging.c") < 0 ) return 0;
                if( catch(item = new(__DIR__"eq/snake_legging.c")) ) return 0;
                if( item->move(me) ) {
                message_vision("$N�q�I�᮳�X" + item->name() + "��$n�C\n", this_object(), me);
                } else {
                    if( item->move(environment(me)) ) {
                        message_vision("$N�q�I�᮳�X" + item->name() + "��$n�A���O���b�a�W�F�C\n", this_object(), me);
                    } else {
                        destruct(item);
                        return 0;
                    }
                 }
            }

            ob->set_amount(0);
            do_chat( ({ ( : destruct , ob : ), }) );

            break;

        default:
            do_chat((: command, "say �o�O���򪱷N��ڡH�ڤ��n�o�تF��I" :));
            return 0;
            break;
    }

    return 1;
}
