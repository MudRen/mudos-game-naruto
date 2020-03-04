#include <npc.h>
#include <ansi.h>

#define CATEGORY    "prize"             // ���૬����
#define ID1         3                   // ����1
#define ID2         4                   // ����2

inherit F_VENDOR;

void to_do_say()
{
    do_chat( ({ 
        (: command, "say �ڰ����F�観�f�O���I" :),
        (: command, "say �u�O�̪�������D�A�Q�u�@�]�����" :),
        (: command, "say �˪L�̪������M�h�������ڷQ�n���n����" :),
    }) );
}
void create()
{
    set_name("���K�_" , ({ "gin tkey", "tkey" }) );
    set("long", "��O�_�ͩ�����A���M�o�{�ѵM���ơA�N�ﰵ����h�F�C\n");
    set_level(40);
    set("gender", "male");
    set("title", "���㩱��" );
    set("age", 60);
    // �@��ɰʧ@
    set("chat_chance", 5);
    set("chat_msg", ({
        (: to_do_say :),
    }) );
    set_goods(1, "eq", 1, 10, -1);
    set_goods(2, "eq", 2, 10, -1);
    set_goods(3, "eq", 3, 10, -1);
    set_goods(4, "eq", 4, 10, -1);
    set_goods(5, "eq", 5, 10, -1);
    set_goods(6, "eq", 6, 10, -1);
    set_goods(7, "eq", 7, 10, -1);
    set_goods(8, "eq", 8, 10, -1);
    set_goods(9, "eq", 9, 10, -1);
    set_goods(10, "eq", 10, 10, -1);
    set_goods(11, "eq", 11, 10, -1);
    set_goods(12, "eq", 12, 10, -1);
    set_goods(13, "eq", 13, 10, -1);
    set_goods(14, "eq", 14, 10, -1);
    set_goods(15, "eq", 15, 10, -1);
    set_goods(16, "eq", 16, 10, -1);
    set_goods(17, "eq", 17, 10, -1);
    set_goods(18, "eq", 18, 10, -1);
    set_goods(19, "eq", 19, 10, -1);
    set_goods(20, "eq", 20, 10, -1);
    set_goods(21, "eq", 21, 10, -1);
    set_goods(22, "eq", 22, 10, -1);
    set_goods(23, "eq", 23, 10, -1);
    set_goods(24, "eq", 24, 10, -1);
    set_goods(25, "eq", 25, 10, -1);
    setup();
}
void relay_say(object ob, string arg)
{
    if( arg == "����" || arg == "�n����" )  {
        do_chat( ({ 
            (: command, "say ��M�ݭn�|�Ӫ��x�B�G�Q������B�Q�G������A�K�i���֡C" :),
            (: command, "say ��һݭn�K������B�|�Q������C" :),
            (: command, "peer" :),
            (: command, "say �A����������Ƴ��n�⭿�H" :),
            (: command, "say �b���o�ܶܡ㤣�M���Ȥ������" :),
            (: command, "say �Q�n�N�֥h�㵥�A��I" :),
        }) );
        return;
    }
    if( arg == "�u�@" ) {
        if( ob->query_quest(CATEGORY, ID1) ) {
            do_chat( ({ 
                (: command, "say �ثe�n�ڰ����O��ҡA�O�O���F�I�C" :),
            }) );
        } else
        if( ob->query_quest(CATEGORY, ID2) ) {
            do_chat( ({ 
                (: command, "say �ثe�n�ڰ����O��M�A�O�O���F�I�C" :),
            }) );
        } else {
            do_chat( ({ 
                (: command, "say �S���ƴN�S�u�@��" :),
                (: command, "say �S�u�@�N�S���ȡ�" :),
                (: command, "say �S���ȴN�����ΰ����I" :),
                (: command, "say ����I�Q��N�i�ȡC" :),
                (: command, "fear" :),
            }) );
        }
        return;
    }
    if( arg == "�f�O" ) {
        do_chat( ({ 
            (: command, "say �ڰ�����ҩM��M�i�O���f�O���C" :),
        }) );
        return;
    }
    if( arg == "���" ) {
        if( ob->query_quest(CATEGORY, ID1) ) {
           do_chat( ({ 
               (: command, "say ����I�ѰO�n������ơI" :),
               (: command, "say ��һݭn�K������B�|�Q������C" :),
               (: command, "say �O�A�ѤF�I" :),
           }) );
        } else
        if( ob->query_quest(CATEGORY, ID2) ) {
           do_chat( ({ 
               (: command, "say �n�ﰵ��ҡH" :),
               (: command, "say �n�զn�ա���Ʈ��ӳ��@�ˡI" :),
               (: command, "say ���L��~�����L���ƪ��ܡI��������Ƴ�I" :),
           }) );
           ob->delete_quest(CATEGORY, ID2);
           ob->add_quest(CATEGORY, ID1, 1);
        } else {
           do_chat( ({ 
               (: command, "say ����ҶܡI���ƥ�W�ӧa�I" :),
               (: command, "say �u�n�����ơA���W���A���~�I" :),
           }));
           ob->add_quest(CATEGORY, ID1, 1);
        }
        return;
    }
    if( arg == "��M" ) {
        if( ob->query_quest(CATEGORY, ID2) ) {
            do_chat( ({ 
                (: command, "say ����I�ѰO�n������ơI" :),
                (: command, "say ��M�ݭn�|�Ӫ��x�B�G�Q������B�Q�G������A�K�i���֡C" :),
                (: command, "say �O�A�ѤF�I" :),
           }) );
        } else
        if( ob->query_quest(CATEGORY, ID1) ) {
           do_chat( ({ 
               (: command, "say �n�ﰵ��M�H" :),
               (: command, "say �n�զn�ա���Ʈ��ӳ��@�ˡI" :),
               (: command, "say ���L��~�����L���ƪ��ܡI��������Ƴ�I" :),
           }) );
           ob->delete_quest(CATEGORY, ID1);
           ob->add_quest(CATEGORY, ID2, 1);
        } else {
            do_chat( ({ 
                (: command, "say ����M�ܡI���ƥ�W�ӧa�I" :),
                (: command, "say �u�n�����ơA���W���A���~�I" :),
            }));
            ob->add_quest(CATEGORY, ID2, 1);
        }
        return;
    }
}
int give_check(object ob)
{
    if( ob->id("_FOX_HAIR_") ) return 1;              // ����
    else if( ob->id("_FOX_LEATHER_") ) return 2;      // ����
    else if( ob->id("_FISH_SCALE_") ) return 3;       // ����
    else if( ob->id("_GIN_LINE_") ) return 4;         // ����
    else if( ob->id("_FOX_PAW_") ) return 5;          // ���x
    else return 0;
}

int accept_object(object me, object ob)
{
    object item;

    if( is_busy() ) {
        tell_object(me,"��西�b���L���A�е��@�U�C\n");
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
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            if( me->query_quest(CATEGORY, ID1) == 1) {
                me->add_temp("quest/" + CATEGORY+ID1 + "/" + give_check(ob), ob->query_amount() );
                if( me->query_temp("quest/"+CATEGORY+ID1+"/3") >= 40 &&
                    me->query_temp("quest/"+CATEGORY+ID1+"/4") >= 8 ) {
                    me->delete_temp("quest/"+CATEGORY+ID1);
                    me->delete_quest(CATEGORY, ID1);
                    if( file_size(__DIR__"eq/scalearmor.c") < 0 ) return 0;
                    if( catch(item = new(__DIR__"eq/scalearmor.c")) ) return 0;
                    if( item->move(me) ) {
                        message_vision("$N���L���ƨ��i�u�@�ǡA���@�|�K���X����" + item->name() + "��$n�C\n", this_object(), me);
                    } else {
                        if( item->move(environment(me)) ) {
                            message_vision("$N���L���ƨ��i�u�@�ǡA���@�|�K���X����" + item->name() + "��$n�A���O���b�a�W�F�C\n", this_object(), me);
                        } else {
                            destruct(item);
                            return 0;
                        }
                    }
                } 
            } else
            if( me->query_quest(CATEGORY, ID2) == 1) {
                me->add_temp("quest/" + CATEGORY+ID2 + "/" + give_check(ob), ob->query_amount() );
                if( me->query_temp("quest/"+CATEGORY+ID2+"/1") >= 20 &&
                    me->query_temp("quest/"+CATEGORY+ID2+"/2") >= 8 &&
                    me->query_temp("quest/"+CATEGORY+ID2+"/3") >= 12 &&
                    me->query_temp("quest/"+CATEGORY+ID2+"/5") >= 4 ) {

                    me->delete_temp("quest/"+CATEGORY+ID2);
                    me->delete_quest(CATEGORY, ID2);
                    if( file_size(__DIR__"eq/foxscale.c") < 0 ) return 0;
                    if( catch(item = new(__DIR__"eq/foxscale.c")) ) return 0;
                    if( item->move(me) ) {
                        message_vision("$N���L���ƨ��i�u�@�ǡA���@�|�K���X����" + item->name() + "��$n�C\n", this_object(), me);
                    } else {
                        if( item->move(environment(me)) ) {
                            message_vision("$N���L���ƨ��i�u�@�ǡA���@�|�K���X����" + item->name() + "��$n�A���O���b�a�W�F�C\n", this_object(), me);
                        } else {
                            destruct(item);
                            return 0;
                        }
                    }
                }
            } else {
                message_vision("$N�ôb�a�ݹD�R"HIG"$n�S���n�����򨾨�a�I\n"NOR, this_object(), me);
                return 0;
            }
            ob->set_amount(0);
            do_chat( ({ ( : destruct , ob : ), }) );
            break;
        default:
            do_chat((: command, "say �o����Ӯt�F�I" :));
            return 0;
            break;
    }
    return 1;
}
