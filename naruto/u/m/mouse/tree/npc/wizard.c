#include <npc.h>
#include <ansi.h>

inherit F_VILLAGER;

void create()
{
    set_name("�g�۲��v" , ({ "wizard" }));
    set("long", "����D�`�_�Ǫ��H�A�⮳�ۤ@���s�s����������C\n");
    set_level(40);
    set("gender","male");
    set("title",HIY"����"NOR);
    set("age",40+random(50));
    // �@��ɰʧ@
    set("chat_chance", 6);
    set("chat_msg", ({
        (: command, "say ���o�̤]��P���즳�t�C" :),
        (: command, "say �֯�N�کҡy�ݭn�z���F�讳�ӵ��کO�H" :),
        (: command, "say �������v�٬O�n���ǥ~�ӻy�����C" :),
    }) );
    set("set_drop", ({
        ([ "type":"food", "id":40, "amount":1+random(4), "p1":80, "p2":100 ]),  // ���G
        ([ "type":"food", "id":38, "amount":1+random(3), "p1":70, "p2":100 ]),  // ��G
        ([ "type":"food", "id":39, "amount":1+random(1), "p1":50, "p2":100 ]),  // ���G
        ([ "type":"food", "id":41, "amount":1, "p1":20, "p2":100 ]),            // ���G��
        ([ "type":"eq", "id":71, "amount":1, "p1":20, "p2":100 ]),              // ��
        ([ "type":"wp", "id":21, "amount":1, "p1":2, "p2":100 ]),               // ����
    }));
    setup();
}
void relay_say(object ob, string arg)
{
    if( arg == "�ݭn" )  {
        do_chat( ({ 
            (: command, "say �u�n�൹�ڨ�����U���A�N���A���쪺���ֶ���C" :),
        }) );
        return;
    }
}
int give_check(object ob)
{
    if( ob->id("_TREE_FRUIT_") ) return 1;            // ��G
    if( ob->id("_MONKEY_TOOTH_") ) return 2;          // �U��
    else return 0;
}
int accept_object(object me, object ob)
{
    object item;
    if( is_busy() ) {
        do_chat((: command, "say �椰��I���֥i�O�ܪ�ɶ����I" :));
        return 0;
    }
    if( is_fighting() ) {
        do_chat((: command, "say �ݧڳQ���٤��������I���Q�n����աI" :));
        return 0;
    }
    me->start_busy(1);
    this_object()->start_busy(1);
    switch( give_check(ob) ) {
        case 1:
            if( me->query_temp("quest/necklace") == 1) {
                if( ob->query_amount() < 100 ) {
                    do_chat((: command, "say ��G�����ƥؤ����A�A�h�h���I�a�C" :));
                    return 0;
                }
                if( file_size(__DIR__"eq/necklace.c") < 0 ) return 0;
                if( catch(item = new(__DIR__"eq/necklace.c")) ) return 0;
                if( item->move(me) ) {
                    message_vision("$N�N"HIY"��G"NOR"�M�I��q���䮳�X�@��" + item->name() + "��$n�C\n", this_object(), me);
                    message_vision("�g�۲��v�ũM�a���R"HIG"$n�����}�a�A��L�g�ۭ̥i���w��~�H�C\n"NOR, this_object(), me);
                } else
                if( item->move(environment(me)) ) {
                    message_vision("$N�N"HIY"��G"NOR"�M�I��q���䮳�X�@��" + item->name() + "��$n�A���O���b�a�W�F�C\n", this_object(), me);
                    message_vision("�g�۲��v����a���R"HIG"$n�~�M�åᯫ�쪺����I���F�F��ֺu�I\n"NOR, this_object(), me);
                } else {
                    me->delete_temp("quest/necklace");
                    destruct(item);
                    return 0;
                }
                me->delete_temp("quest/necklace");
                ob->set_amount(0);
                do_chat( ({ ( : destruct , ob : ), }) );
                break;
            } else {
                message_vision("�g�۲��v���D�R"HIG"�e�@���٨S�䧹�O�A�椰��C\n"NOR, this_object(), me);
                return 0;
            }
            break;
        case 2:
            if( me->query_temp("quest/necklace")) {
                message_vision("�g�۲��v���D�R"HIG"�w�g���L�աI�֧�ĤG�اa�C\n"NOR, this_object(), me);
                return 0;
            } else
            if( ob->query_amount() < 200 ) {
                do_chat((: command, "say �U�������ƥؤ����A�A�h�h���I�a�C" :));
                return 0;
            } else {
                me->add_temp("quest/necklace", 1);
                message_vision(CYN"�g�۲��v�M�I��"HIW"�U��"NOR""CYN"���ƶq�C\n"NOR, this_object(), me);
                message_vision("�g�۲��v���D�R"HIG"�t�I�ѤF���ٻݭn�@������G�A���K���ڧa�C\n"NOR, this_object(), me);
            }
            do_chat( ({ ( : destruct , ob : ), }) );
            break;
        default:
            do_chat((: command, "say ���F�ثe�ݭn�����~��L�ڤ��n�I" :));
            return 0;
            break;
    }
    return 1;
}
