#include <npc.h>
#include <ansi.h>

inherit F_VILLAGER;

void to_do_say()
{
    do_chat( ({
        (: command, "say �ƶq�٤֤F�n�h..." :),
        (: command, "say �u�Ʊ榳�H��������..." :),
    }) );
}
void create()
{
    set_name("���A", ({ "in san", "san" }));
    set_race("human");
    set_level(20);
    set("title",HIB"���b�H"NOR);
    set("long", "�⮳�ۤ@���b�U�A�����D�b�p�⤰��C\n");
    set("age", 22);
    set("gender", "male");
    set("chat_chance", 5);
    set("chat_msg", ({
        (: to_do_say :),
        (: command, "say ��...�S����F :(" :),
    }) );
    setup();
}
int relay_say(object me, string arg)
{
    if( !objectp(me) || !stringp(arg) ) return 0;

    if( arg == "�ƶq" ) {
        do_chat( ({
           (: command, "say �j�D�Y�j�H�n�ڭ̦b�X�Ӥ뤺�M���j��}�q�K�D�C" :),
           (: command, "say ���L�o�s�j���ٯu�|��...��򥴳��������C" :),
           (: command, "say ���S���H���������j����I���" :),
        }) );
        return 1;
    }
    if( arg == "�j��" ) {
        do_chat( ({
           (: command, "say �N�O���v�}�޸̪����Ǭr�j��I" :),
           (: command, "say �e�̪����F�ڭ̭������츭�I���p���I" :),
           (: command, "ack" :),
           (: command, "say ���O���O�I�O�n�}�P�s���m�\�a�ϰա㫢�����C" :),
        }) );
        return 1;
    }
    if( arg == "�츭�I���p��" ) {
        do_chat( ({
           (: command, "headshake" :),
           (: command, "say �Ať���F�A�ڨS���L�o�تF��C" :),
        }) );
        return 1;
    }
    if( arg == "����" || arg == "���A" ) {
        if( this_player()->query_temp("quest/spiderkill") == 1) {
            do_chat( ({
               (: command, "say �����F�N���I�������a�I" :),
            }) );
        } else {
            do_chat( ({
               (: command, "nod" :),
               (: command, "say �u�n����50���j��Х��N�i�H�F�I" :),
               (: command, "say �浹�A�O�I" :),
               (: command, "say ���y�O�g������I" :),
            }) );
        this_player()->add_temp("quest/spiderkill", 1);
        }
        return 1;
    }
    return 1;
}

int give_check(object ob)
{
    if( ob->id("__SAMPLE__") ) return 1;    // �j��Х�
    else return 0;
}
int accept_object(object me, object ob)
{
    object item;
    if( is_busy() ) {
        do_chat((: command, "say �椰��I���ڲM�I�@�U�I�Q���زV�]��I" :));
        return 0;
    }
    if( is_fighting() ) {
        do_chat((: command, "say �֦��աI�ϩR���I" :));
        return 0;
    }
    me->start_busy(1);
    this_object()->start_busy(1);

    switch( give_check(ob) ) {
        case 1:
            if( this_player()->query_temp("quest/spiderkill") < 1 ) {
                do_chat((: command, "say �S���m��ԡA�D�l�Y�s�C" :));
                return 0;
            }
            if( ob->query_amount() != 50 ) {
                do_chat((: command, "say �u�n���ڤ��Q���N�n�C" :));
                return 0;
            }
            if( file_size("/world/book/know1.c") < 0 ) return 0;
            if( catch(item = new("/world/book/know1.c")) ) return 0;
            if( item->move(me) ) {
                message_vision("$N�M�I$n�ỡ�D�R"HIG"�F���n�I�U���A��A������I\n"NOR, this_object(), ob);
            } else {
                if( item->move(environment(me)) ) {
                    message_vision("$N�M�I$n�ỡ�D�R"HIG"�F���n�I�U���A��A������I\n"NOR, this_object(), ob);
                    message_vision("$N���D�R$n���W�ӭ��աA���A��b�a�W�C\n"NOR, this_object(), me);
                } else {
                    destruct(item);
                    return 0;
                }
            }
            do_chat(( : destruct , ob : ));
            me->delete_temp("quest/spiderkill");
            break;
        default:
            do_chat((: command, "say �o�O���򳾪F����C" :));
            return 0;
            break;
    }
    return 1;
}
