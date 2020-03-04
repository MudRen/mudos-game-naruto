#include <npc.h>
#include <ansi.h>

inherit F_VILLAGER;

void to_do_say()
{
    do_chat( ({
        (: command, "think" :),
        (: command, "say �u�a�����v�u���ӱj�F..." :),
        (: command, "say �Q���e���u���Сv�ӻs�@�u�s�ī~�v������..." :),
        (: command, "say �o�U�l�ӫ�����I" :),
        (: command, "scream" :),
    }) );
}
void create()
{
    set_name("�\­" , ({ "bow shao", "shao" }));
    set_race("human");
    set("long", "�]���H��s�a�������͡A�ҥH�ۺ�­�C\n");
    set_level(60);
    set("nickname","�Ī�");
    set("camp", "bow");
    set("gender","male");
    set("age",45);
    set("chat_chance", 5);
    set("chat_msg", ({
        (: to_do_say :),
    }) );
    setup();
}
void relay_say(object ob, string arg)
{
    if( arg == "�a����" )  {
        do_chat(({ 
            (: command, "say �e�N�b�F���r���U���I" :),
            (: command, "say �p���I��I�e�i�O�D�`�F�`���I" :),
        }));
        return;
    }
    if( arg == "�s�ī~" || arg == "�ī~" )  {
        do_chat(({ 
            (: command, "say �O�ڥ��b��s���s�ġC" :),
            (: command, "peer" :),
            (: command, "say �i�d�U����Q�ѭ�ť��I���M�L�S�n�|���V���ī~�C" :),
            (: command, "?" :),
            (: command, "say �ڭ��O�֡H�N�O�ĩ����\�����I�o�٬ݤ��X�ӡC" :),
        }));
        return;
    }
    if( arg == "����" )  {
        if( this_player()->query_temp("quest/helpowl") == 1) {
        do_chat(({ 
            (: command, "say �A�i�H�C�C�Ҽ{�C" :),
            (: command, "say ���Q�����N���u�����v" :),
        }));
        return;
        } else
        if( this_player()->query_temp("quest/helpowl") == 2) {
            do_chat(({ 
                (: command, "say �F�ѻa�������j�j�F�a�H" :),
                (: command, "say �`�ȥi�H�u����v�~�������ڡC" :),
            }));
            return;
        }
        this_player()->add_temp("quest/helpowl", 1);
        do_chat(({ 
            (: command, "think" :),
            (: command, "say �A���A�@�I�ɶ��Ҽ{�n�F�C" :),
            (: command, "say �����a�����D�`���j�j�I�@��H�j���L�k�P�e�ǼġI" :),
            (: command, "say �@�N���ܴN�u�����v�ڧa�I" :),
            (: command, "say ���@�N�N�^���u�����v" :),
        }));
        return;
    }
    if( arg == "����" || arg == "���A" ) {
        if( this_player()->query_temp("quest/helpowl") == 2) {
            do_chat(({ 
                (: command, "say �A�w�g�b���ڤF�I" :),
            }));
            return;
        } else
        if( this_player()->query_temp("quest/helpowl") == 1) {
            this_player()->add_temp("quest/helpowl", 1);
            do_chat(({ 
                (: command, "fear" :),
                (: command, "say ���@���N�a�A�F�I�d�U�O�x�j���I" :),
                (: command, "ah" :),
                (: command, "say �ѤF��...���y�O���٦b���窺�ī~�I" :),
                (: command, "say �@�ڱ��Хi�H������..." :),
                (: command, "say ����w���i�H��߭��ΡI" :),
            }));
            return;
        } else {
            do_chat(({ 
                (: command, "?" :),
                (: command, "say �{�b�O���򱡪p�H" :),
            }));
            return;
        }
    }
    if( arg == "����" || arg == "����" )  {
        if( this_player()->query_temp("quest/helpowl") < 1) {
            do_chat(({ 
                (: command, "?" :),
                (: command, "say �ڨS���ЧA���ڧa�C" :),
            }));
        } else {
            this_player()->delete_temp("quest/helpowl");
            do_chat(({ 
                (: command, "nod" :),
                (: command, "say �S���Y...�o���ȯu�������F�C" :),
            }));
            return;
        }
    }
}
int give_check(object ob)
{
    if( ob->id("_OWL_PLUME_") ) return 1;    // ����
    else return 0;
}
int accept_object(object me, object ob)
{
    int amount, i;
    object item;

    amount = ob->query_amount()*2;

    if( is_busy() ) {
        do_chat((: command, "say �Ӧ��F�I�����I" :));
        return 0;
    }
    if( is_fighting() ) {
        do_chat((: command, "say �֨ӱϱϧڪ��I" :));
        return 0;
    }
    i = random(3)+1;
    me->start_busy(1);
    this_object()->start_busy(1);
    switch( give_check(ob) ) {
        case 1:
            if( me->query_temp("quest/helpowl") == 2) {
                if( amount < 1 ) {
                    do_chat((: command, "say �_�X�n���ڤ@�ӥH�W�����СC" :));
                    return 0;
                }
                if( i == 3 ) {
                    if( file_size(__DIR__"item/god_pill.c") < 0 ) return 0;
                    if( catch(item = new(__DIR__"item/god_pill.c")) ) return 0;
                } else
                if( i == 2 ) {
                    if( file_size(__DIR__"item/ghost_pill.c") < 0 ) return 0;
                    if( catch(item = new(__DIR__"item/ghost_pill.c")) ) return 0;
                } else
                if( i == 1 ) {
                    if( file_size(__DIR__"item/man_pill.c") < 0 ) return 0;
                    if( catch(item = new(__DIR__"item/man_pill.c")) ) return 0;
                }
                if( amount ) {
                    if( function_exists("set_amount", ob) ) {
                    item->set_amount(amount);
                    } else
                    if( function_exists("set_volume", ob) ) {
                        item->set_volume(amount);
                    }
                }
                if( item->move(me) ) {
                    message_vision("$N���D�R"HIG"�ӷP��$n�F�I\n"NOR, this_object(), me);
                    message_vision("$N���D�R"HIG"�o�O���y�A�@"NOR"("HIY+amount+NOR")"HIG"��"+item->name()+"�C\n"NOR, this_object(), me);
                } else
                if( item->move(environment(me)) ) {
                    message_vision("$N���D�R"HIG"�ӷP��$n�F�I\n"NOR, this_object(), me);
                    message_vision("$N���D�R"HIG"�o�O���y�A�@"NOR"("HIY+amount+HIG")"HIG"��"+item->name()+"�C�ӭ���a�W��C\n"NOR, this_object(), me);
                } else {
                    destruct(item);
                    return 0;
                }
                ob->set_amount(0);
                do_chat( ({ ( : destruct , ob : ), }) );
                break;
            }
            message_vision("$N���D�R"HIG"�ڦn���S�ЧA�����I\n"NOR, this_object(), me);
            break;
        default:
            do_chat((: command, "say �o���O���СI�ڬ�s�F�X�Q�~���|�ݿ����I" :));
            break;
    }
    return 1;
}
