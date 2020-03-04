#include <npc.h>
#include <ansi.h>

inherit F_VILLAGER;

void create()
{
    set_name("�g�۲��v" , ({ "wizard" }));
    set("long", "����D�`�_�Ǫ��H�A�⮳�ۤ@���s�s����������C\n");
    set_level(40);
    set("gender","male");
    set("title",HIM"�D��"NOR);
    set("age",50+random(60));
    // �@��ɰʧ@
    set("chat_chance", 6);
    set("chat_msg", ({
        (: command, "say ���o�̤]��P���즳�t�C" :),
        (: command, "say �֯�N�کҡy�ݭn�z���F�讳�ӵ��کO�H" :),
        (: command, "say �������v�٬O�n���ǥ~�ӻy�����C" :),
    }) );
    set("set_drop", ({
        ([ "type":"food", "id":40, "amount":1+random(6), "p1":80, "p2":100 ]),  // ���G
        ([ "type":"food", "id":38, "amount":1+random(3), "p1":70, "p2":100 ]),  // ��G
        ([ "type":"food", "id":39, "amount":1+random(2), "p1":70, "p2":100 ]),  // ���G
        ([ "type":"food", "id":41, "amount":1+random(1), "p1":30, "p2":100 ]),  // ���G��
        ([ "type":"eq", "id":71, "amount":1, "p1":30, "p2":100 ]),              // ��
        ([ "type":"wp", "id":21, "amount":1, "p1":5, "p2":100 ]),               // ����
    }));
    setup();
}
void relay_say(object ob, string arg)
{
    if( arg == "�ݭn" )  {
        do_chat( ({ 
            (: command, "say �u�n�൹�ڥ|�Q���U���A�N���A����s�����Z���C" :),
        }) );
        return;
    }
}
int give_check(object ob)
{
    if( ob->id("_KING_FRUIT_") ) return 1;            // ���G��
    if( ob->id("_MONKEY_BRAIN_") ) return 2;          // �U��
    else return 0;
}
int accept_object(object me, object ob)
{
    object item;
    if( is_busy() ) {
        do_chat((: command, "say ���쪺�Z���s���ݭn�ɶ��C" :));
        return 0;
    }
    if( is_fighting() ) {
        do_chat((: command, "say �ڥ��b���H�O�I�S�Ųz�A�I" :));
        return 0;
    }
    me->start_busy(1);
    this_object()->start_busy(1);
    switch( give_check(ob) ) {
        case 1:
            if( me->query_temp("quest/treesword") == 1) {
                if( ob->query_amount() < 20 ) {
                    do_chat((: command, "say ���G���Ӥ֤F�A�o�ˤ����ΡC" :));
                    return 0;
                }
                if( file_size(__DIR__"wp/tree_sword.c") < 0 ) return 0;
                if( catch(item = new(__DIR__"wp/tree_sword.c")) ) return 0;
                if( item->move(me) ) {
                    message_vision("$N�N" + item->name() + "��W"HIM"���G��"NOR"���ĲG�浹$n�A�u��" + item->name() + "�o�X�@�}�}�����A�{�w$n�N�O�����D�H�C\n", this_object(), me);
                    message_vision("�g�۲��v���D�R"HIG"�}�W�]�����F�A$n�n�p�ߨϥΦ��C���C\n"NOR, this_object(), me);
                } else
                if( item->move(environment(me)) ) {
                    message_vision("$N�N" + item->name() + "�浹$n�A��$n�Q" + item->name() + "�����~�~��ӿ�����" + item->name() + "���b�a�W�C\n", this_object(), me);
                    message_vision("�g�۲��v���D�R"HIG"$n���ή`�Ȧ��C�����~�I���O�������֤����C\n"NOR, this_object(), me);
                } else {
                    me->delete_temp("quest/treesword");
                    destruct(item);
                    return 0;
                }
                me->delete_temp("quest/treesword");
                ob->set_amount(0);
                do_chat(((: destruct, ob :)));
                break;
            } else {
                message_vision("�g�۲��v���D�R"HIG"�e�@���٨S�䧹�O�A�椰��C\n"NOR, this_object(), me);
                return 0;
            }
        case 2:
            if( me->query_temp("quest/treesword") > 0) {
                message_vision("�g�۲��v���D�R"HIG"�w�g���L�աI�֧�ĤG�اa�C\n"NOR, this_object(), me);
                return 0;
            }
            if( ob->query_amount() < 40 ) {
                do_chat((: command, "say �U���Ӥ֤F�A�h�h���@�I�ӧa�C" :));
                return 0;
            }
            me->add_temp("quest/treesword", 1);
            message_vision(CYN"�g�۲��v�N"HIR"�U��"NOR""CYN"�˯}�A�̭����A��w�w�w���b��K�W�C\n"NOR, this_object(), me);
            message_vision("�g�۲��v���D�R"HIG"�t�I�ѤF���ٻݭn�G�Q�����G���A���K���ڧa�C\n"NOR, this_object(), me);
            do_chat(((: destruct, ob :)));
            break;
        default:
            do_chat((: command, "say �ثe�ݭn�����~�~��L�Ȯɤ��ΡC" :));
            return 0;
            break;
    }
    return 1;
}
