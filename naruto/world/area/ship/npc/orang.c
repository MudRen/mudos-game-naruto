#include <ansi.h>
#include <npc.h>

inherit F_SEABANDIT;

void to_do_say()
{
    do_chat( ({ 
        (: command, "say ��s�s�I�Q���Q�u�[�J�v�ڭ̥����ζ���s�s�X�x�H" :),
        (: command, "say �����H���N�O�n���ڷQ���I��s�s�I" :),
        (: command, "say �A���ڤ��O�H���I�H�Q�����ڪ��q�n�ܡI�I" :),
    }) );
}

void do_fight()
{
    int exact, evade;
    object enemy;
    // �S���ĤH
    enemy = this_object()->query_opponent();
    if( !enemy ) return;
    if( enemy->is_busy() || this_object()->is_busy() ) return;
    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    exact = COMBAT_D->intimidate(this_object(), 1);
    evade = COMBAT_D->wittiness(enemy, 1);

    message_vision("\n$N���_���J���j�ۡG"HIG"�����ڪ��u"HIY"�L���R����I"HIG"�v�I\n"NOR+CYN"�|�P�}�l�ǥX�o�H�������I\n\n"NOR, this_object(), enemy);
    if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
        message_vision("$ní�w�߱��A���@�����o�}�����v�T�C\n\n"NOR, this_object(), enemy);
        this_object()->start_busy(2);
        return;
    }
    message_vision(CYN"$n�Q�����Ҽv�T�A�Y�h�����L�k��ʤF�I\n\n"NOR, this_object(), enemy);
    this_object()->start_busy(1);
    enemy->start_busy(4);
    return;
}
void create()
{
    set_name("�V�V", ({ "orang" }) );
    set_race("human");
    set_level(47);
    set("title",HIY"��s�s�X"NOR);
    set("nickname",HIG"������"NOR);
    set("gender", "male");
    set("class","big_sea");
    set("camp", "robber");
    set("age", 39);
    set("long", "���b������j�V�V�A�������G�O�@��H���T���A�L�d�F�@�Y������\n"
                "�Y�v�A�N����᭱���\��F�A��W�ٮ��۳��J���A�����D�Q������C\n");
    set("chat_chance", 5);
    set("chat_msg", ({
        (: command, "say �ڪ��Y�v�i�O�q�X�ͨ�{�b���S�ŹL�O�I" :),
        (: to_do_say :),
    }));
    set("chat_chance_combat", 30);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"obj", "id":28, "amount":2+random(4), "p1":30, "p2":100 ]),  // ����
        ([ "type":"eq", "id":102, "amount":1, "p1":1, "p2":300 ]),             // ��U�@�L
        ([ "type":"eq", "id":99, "amount":1, "p1":1, "p2":100 ]),              // ��c
        ([ "type":"eq", "id":100, "amount":1, "p1":20, "p2":100 ]),            // �����
    }) );
    setup();
    add_temp("apply/attack", 50);
    add_temp("apply/armor", 100);
}

// ��char��say���O�ɡA��mob���^��
int relay_say(object me, string arg)
{
    object test;

    if( arg == "�[�J" ) {
        if( me->query_class() != "commoner" ) {
            do_chat( ({ 
                (: command, "shake" :),
                (: command, "say �V�V���o�����I���w��"+me->rank()+"�I" :),
            }) );
            return 1;
        }
        if( me->query_temp("quest/mitp") ) {
            do_chat( ({ 
                (: command, "say "+me->query("name")+"�w�g����Ҩ��F���I" :),
                (: command, "say ������h�i�F�¡I��s�s�I" :),
            }) );
            return 1;
        }
        test = new(_DIR_AREA_"sifa_isle/npc/item/paper.c");
        if( !objectp(test) ) {
            do_chat( ({
                (: command, "say �V�|�I�@���p�ߧ�Ҩ����o���F�I" :),
                (: command, "say �֨ӤH�A�h�����@�ǦҨ��I" :),
            }) );
            return 1;
        }
        if( !test->move(this_object()) ) {
            do_chat( ({ 
                (: command, "ah" :),
                (: command, "say �Ҩ�����F�ܡH�I" :),
            }) );
            destruct(test);
            return 1;
        }
        // �]�w���a�Ȯ��ܼơA�H���@����Ҩ�
        if( test->move(me) ) {
            me->set_temp("quest/mitp", 1);
            // ���骽���ݥ[�J�N����
            me->set("guild", "piece");
            me->set("title", "������ժ�");
            do_chat( ({
                (: command, "say ���I�J�M"+me->query("name")+"���ߥ[�J�ڭ̷�s�s�X�I" :),
                (: command, "say ���N��o���Ҩ��g�@�g�a�I" :),
                (: command, "say ���M�O���x���䪺�ը��A���L�Q�V�V����N�ݩ�V�V���աI" :),
                (: command, "say �Ҩ��浹"+me->query("name")+"�F�I�g���N���V�V�a�C" :),
                (: command, "say �S�������藍��[�J��s�s�X�x�I��s�s�I" :),
            }) );
        } else if( environment(me)->is_area() ) {
            if( !area_move(environment(me), test, me->query("area_info/x_axis"), me->query("area_info/y_axis")) ) {
                tell_object(me, "�X���D�աI�֧�Ův�B�z�I\n");
                return 1;
            }
            me->set_temp("quest/mitp", 1);
            // ���骽���ݥ[�J�N����
            me->set("guild", "piece");
            me->set("title", "������ժ�");
            do_chat( ({
                (: command, "say ���I�J�M"+me->query("name")+"���ߥ[�J�ڭ̷�s�s�X�I" :),
                (: command, "say ���N��o���Ҩ��g�@�g�a�I" :),
                (: command, "say ���M�O���x���䪺�ը��A���L�Q�V�V����N�ݩ�V�V���աI" :),
                (: command, "say "+me->query("name")+"���W�ӭ��I�Ҩ��V�V��b�a�W�A�g���N���V�V�a�C" :),
                (: command, "say �S�������藍��[�J��s�s�X�x�I��s�s�I" :),
            }) );
            return 1;
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
        message_vision("$N���D�R"HIG"$n�O�q��L�a��k�Ӫ��a�I$N�����A�I\n"NOR, this_object(), me);
        return 0;
    }
    if( me->query_class() != "commoner" ) {
        message_vision("$N���D�R"HIG"$n�w�g��¾�~�F�a�I�H\n"NOR, this_object(), me);
        message_vision("$N���D�R"HIG"��$N�o��n�F�ܡI\n"NOR, this_object(), me);
        return 0;
    }
    score = item->do_check();
    message_vision("$N�n�ۦҨ��r��...���G�s�ۤv�����ӲM������...\n", this_object(), item);

    if( score != 100 ) {
        message_vision("$N���D�R"HIG"$n�u�O�ӥ�V�V���y�F�I\n"NOR, this_object(), me);
        message_vision("$N���D�R"HIG"�u��"+chinese_number(score)+"���]�Q�[�J��s�s�X�H\n"NOR, this_object(), me);
        return 0;
    }
    message_vision("$N���D�R"HIG"��s�s�I�g���ӴΰաI\n"NOR, this_object(), me);
    message_vision("$N���D�R"HIG"��$n�o�ؤH���@�w�n�[�J�ڭ̷�s�s�X�x���աI\n"NOR, this_object(), me);
    me->set("title", "��s�s�X�x");
    me->set_level(1);
    me->addCamp("robber");  // �W�[����}��
    me->set_class("little_sea");
    // �ϥ� do_chat �ө���I�s destruct ���� give �ʧ@����
    do_chat( ({
        (: destruct, item :),
        (: command, "say �[�J����n�٩I�V�V���j�����I" :),
        (: command, "say ����H�Q�n�j����ЧA�԰����ޥ��ܡH" :),
        (: command, "laugh" :),
        (: command, "say �j������۳N�i�O�S����e���Ǫ��I" :),
        (: command, "ah" :),
        (: command, "say "+this_player()->query("name")+"�i�H�h�j�������������ݬݡI�L�̷|�ЧA�԰��ޥ����I��s�s�I" :),
    }) );
    return 1;
}