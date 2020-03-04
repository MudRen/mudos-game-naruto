#include <npc.h>
#include <ansi.h>

inherit F_VILLAGER;

void to_do_say()
{
    do_chat( ({
        (: command, "sigh" :),
        (: command, "say �ڪ��u�_�c�v��..." :),
    }) );
}
void create()
{
    set_name("�d�X", ({ "ka meng", "meng" }));
    set_race("human");
    set_level(5);

    set("long", "���F�Y���H�~�������Q�d�b�_�c���A�u����}�j�j�ଡ�ʪ��ǤH�C\n");
    set("nickname", HIG"�_�c�H"NOR);

    set("age", 34);
    set("gender", "male");

    // �@��ɰʧ@
    set("chat_chance", 1);
    set("chat_msg", ({
        (: to_do_say :),
    }) );
    setup();
}

// ��char��say���O�ɡA��mob���^��
int relay_say(object me, string arg)
{
    if( !objectp(me) || !stringp(arg) ) return 0;

    if( arg == "�_�c�H" ) {
        do_chat( ({
            (: command, "say �ڥ��Ӥ]�O����Ϊ������C" :),
            (: command, "say ������{���o�y�q�W���j�q�_�áI" :),
            (: command, "say ��O�ڭ̫K�U��_���M��A���O�̫��٬O�L�\�Ӫ�C" :),
            (: command, "say �ڭ̰ߤ@�S����L���a��A�N�O�q�W�@�ӥ��j�������C" :),
            (: command, "say ���L���̤Q���~�k�A�ڥ��L�k�W�h�C" :),
            (: command, "say �ڤU�w�M�߫_�I���W�����A�ש�ݨ쳻�W���G���X���_�c�I" :),
            (: command, "say �]�\�O�ڤӿ��ĤF...�~�M�q���W���^�F�U�ӡC" :),
            (: command, "say ���G���i�@�ӽc�l�̭�...�ܦ��{�b�o�ˡA�H�]���F�L�h�C" :),
            (: command, "say �����ӮɡA��N�w�g�����F�C" :),
            (: command, "say ��O�u�n�d�b�o�y�q�W�A�M�ʪ��@�_�ͬ��C" :),
        }) );
    }
    if( arg == "�_�c" ) {
        do_chat( ({
            (: command, "say �e�X�Ѷ]�Ӥ@���Y�a��U�u�\�X������ΡC" :),
            (: command, "say �L�̪�������ڧ⩥���W���c�l�����U�ӤF��I" :),
            (: command, "say ���M�O�Ū������H���L�A���O�����g�˺��F�ڪ��ڷQ�I" :),
            (: command, "cac" :),
            (: command, "say ���G�Q�Ѷ]�Ӥ@�s����A��c�l���m���F�I" :),
            (: command, "say ���S���H��u���U�v�ڹܦ^�Ӫ��I�I" :),
            (: command, "cry" :),
        }) );
    }
    if( arg == "���U" || arg == "��" ) {
        if( me->query_level() < 20 ) {
            do_chat( ({
                (: command, "shake" :),
                (: command, "say "+me->query("name")+"���ӥ���Ĺ�̭����s���c������C" :),
                (: command, "say �ڤ������L�d���H�i�h�e���C" :),
            }) );
            return 1;
        }
        if( me->query_class() != "work_sea" && me->query_class() != "little_sea" ) {
            do_chat( ({
                (: command, "wa" :),
                (: command, "say �o�ؤp�Ƨڦۤv�ӴN�i�H�F�I" :),
                (: command, "say ���ݭn�ҷ�"+me->query("name")+"�աI" :),
            }) );
            return 1;
        }
        if( me->query_temp("piece_test") ) {
            do_chat( ({
                (: command, "say "+me->query("name")+"���O�����n���ڤF�ܡI" :),
                (: command, "say �p�G�ѰO�n������N�A���@���a�I" :),
                (: command, "say ���ڮ��^���_�c�����_�c�A�άO�P���C��T�Ӥ]�i�H�C" :),
            }) );
            return 1;
        }
        do_chat( ({
            (: command, "say �@�N���U�ڶܡI�u�O�ӴΤF�I" :),
            (: command, "say ���s����N�b�n�䪺�]��̭��C" :),
            (: command, "say ���ڮ��^���_�c�����_�c�A�άO�P���C�⪺�_�c�T�Ӥ]�i�H�I" :),
            (: command, "say �@���N���U"+me->query("name")+"�F�I" :),
            (: command, "addoil" :),
        }) );
        me->set_temp("piece_test", 1);
    }
    return 1;
}
int accept_kill(object ob)
{
    this_player()->remove_all_killer();
    do_chat((: command, "say ���_�c������n..." :));
    return 1;
}
int accept_fight(object ob)
{
    do_chat((: command, "say ���_�c������n..." :));
    return 0;
}
int accept_object(object me, object item)
{
    int pass=0;

    if( !objectp(me) || !objectp(item) ) return 0;
    if( !item->query("piece_test") ) return 0;

    if( me->query_level() < 20 ) {
        do_chat( ({
            (: command, "say "+me->query("name")+"���ӥ���Ĺ���s����a�I���Ӫ��c�l�I" :),
        }) );
        return 0;
    }
    if( me->query_class() != "work_sea" && me->query_class() != "little_sea" ) {
        do_chat( ({
            (: command, "say ���M�ܹ��ڪ��c�l�I���ڤ��ব�C" :),
        }) );
        return 0;
    }
    if( !me->query_temp("piece_test") ) {
        do_chat( ({
            (: command, "say �ڨèS�����U"+me->query("name")+"���ڮ��c�l�A�ڤ��ব�C" :),
        }) );
        return 0;
    }
    message_vision("$N�ݨ�"+item->query("name")+"�����a�j�ۡG"HIG"�N�O�o�ӨS���I$n�F���Ӧn�F�I\n"NOR, this_object(), me);

    if( item->query("piece_test") == 1 ) me->add_temp("piece_test_b1", 1);
    if( item->query("piece_test") == 2 ) me->add_temp("piece_test_b2", 1);

    if( me->query_temp("piece_test_b1") >= 3 ) pass = 1;
    if( me->query_temp("piece_test_b2") >= 3 ) pass = 1;
    if( me->query_temp("piece_test_b1") >=1 && me->query_temp("piece_test_b2") >=1 ) pass = 1;

    if( pass ) {
        me->delete_temp("piece_test");
        me->delete_temp("piece_test_b1");
        me->delete_temp("piece_test_b2");

        call_out("pass_1", 5, this_object());
        if( me->query_class() == "work_sea" ) {
            message_vision("$N���D�G"HIG"�D�`�P��$n�����I���x�G�M�O�̥i�a�����I\n"NOR, this_object(), me);
            tell_object(me, "\n\n�A�Ұ����欰�Q���x�`���o���A�a�ɬ�"HIC"�u���x�h�L�v"NOR"�F�I\n\n");
            me->set_class("soldier_sea");
        } else if( me->query_class() == "little_sea" ) {
            message_vision("$N���D�G"HIG"�D�`�P��$n�����I�p�G���鳣��$n�@�˴N�n�աI\n"NOR, this_object(), me);
            tell_object(me, "\n\n�]���b���_�c���A���F�\�h���a���������A�Q�@�ɬF���C��"HIR"�u����v"NOR"�F�I\n\n");
            me->set_class("thief_sea");
        } else {
            message_vision(HIR"\n�o�Ϳ��~�աI�֧�Ův�ӳB�z�C\n\n"NOR, this_object());
        }
    }
    // �ϥ� do_chat �ө���I�s destruct ���� give �ʧ@����
    do_chat((: destruct, item :));
    return 1;
}
