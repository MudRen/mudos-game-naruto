#include <npc.h>
#include <ansi.h>

inherit F_SOLDIER;
inherit F_TRAINER;    // �V�m�ɮv

void do_fight()
{
    object enemy;

    // �S���ĤH
    enemy = this_object()->query_opponent();

    if( !enemy ) return;

    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    // �P�}
    command("perform kick haze.kick on " + enemy->query_id() );
}
void to_do_say()
{
    do_chat( ({ 
        (: command, "say �d����I�F���S����c�N�O�b�o�̦��s�i�H�����ܡI" :),
        (: command, "say �Q�u�[�J�v���x���ܴN�ݧa�A�S�ƧO�ЧڡC" :),
        (: command, "say �u�d�������x�b�Q����..." :),
    }) );
}

void create()
{
    set_name("�`��", ({ "nai luo", "nai", "luo" }) );
    set_race("human");
    set_level(40);
    set_class("officer_sea");  // ���x�h�x
    set("age", 20);
    set("title", HIR"�Ѣޢ��s�H"NOR);
    set("long", "��[�J���x���K��´���H�A�H�e���g�O�ӱ���C�u���L���G���Ӻ��N\n"
                "�{�b���u�@�A�@���H�H��ۡG�~�M�b�s�ͥl�ҳB�ۦ��s�i�H���A�ڥi\n"
                "�O�F���S����c�������I�n��]�Ө��I���˪��u�@�I\n"
                "����M���x�ޯ�i���۾ǲߡA�Q�� train ���O�ӦV�`���ǲߧޯ�C\n"
                "�ϥ� list ���O�d�ߥi�ǲߪ��ޯ�C��C\n" );

    // �@��ɰʧ@
    set("chat_chance", 3);
    set("chat_msg", ({
        (: to_do_say :),
    }) );
    set("chat_chance_combat", 30);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    // ����������A���x����i���۾ǲߧޯ�
    set("guild", "piece");

    // �]�w��V�m���ޯ�
    //
    // set_train(�ޯ�W, �O�_�i�����߱o, �ǲ߸ӧޯ�һݭn�����ⵥ��, ���ޯ�i�ǲߨ쪺�W������)
    //
    // ���a�S���ӧޯ�ɡA�Y"�O�_�i�����߱o"�o�ӳ]�w�Ȭ��D�s�ȮɡA���a�V�V�m�̾ǲ߮ɫh�i�O��
    // �o�ӧޯ��lv1�A�Ӧ�lv���ޯ�~�i�H���I�~����m�C�G�i�Ω�S��ޡA�n�����o��lv���i�V�m�C
    //
    set_train_with_camp("combat", 1, 1, 120, "police", -2);           // �氫�ޥ�
    set_train_with_camp("dodge", 1, 1, 120, "police", -2);            // �{���ޥ�
    set_train_with_camp("parry", 1, 1, 120, "police", -2);            // �׮�ޥ�
    set_train_with_camp("heavy hit", 1, 5, 100, "police", -2);        // �������N
    set_train_with_camp("savage hit", 1, 5, 100, "police", -2);       // �������N
    set_train_with_camp("continual hit", 1, 5, 100, "police", -2);    // �s�����N
    set_train_with_camp("martial", 1, 10, 120, "police", -2);         // �Z�N��¦
    set_train_with_camp("spurn", 1, 10, 120, "police", -2);           // ��ް�¦
    set_train_with_camp("activity", 1, 10, 120, "police", -2);        // �S���¦
    set_train_with_camp("body iron", 1, 10, 100, "police", 0);        // �K��
    set_train_with_camp("paper step", 1, 10, 100, "police", 0);       // ��ø
    set_train_with_camp("gun finger", 1, 15, 100, "police", -1);      // �Z�N�G���j
    set_train_with_camp("kick haze", 1, 15, 120, "police", -1);       // ��ޡG�P�}

    setup();
    set_skill("martial", 150);
    set_skill("spurn", 150);
    set_skill("body iron", 100);
    set_skill("paper step", 100);
    set_skill("gun finger", 120);
    set_skill("kick haze", 120);
}

// ��char��say���O�ɡA��mob���^��
int relay_say(object me, string arg)
{
    if( !objectp(me) || !stringp(arg) ) return 0;

    if( arg == "�[�J" || arg == "�[�J���x" ) {
        if( me->query("guild") ) {
            if( me->query("guild") == "piece") {
                do_chat( ({ 
                    (: command, "say "+this_player()->query("name")+"�w�gť�L�ڻ��F�a�I" :),
                    (: command, "say �n�[�J���x�h�䴵��F�i���x�I" :),
                    (: command, "say ���x�H���Ӧb�㥧�㴵�j�U�G�ӧa�I" :),
                }) );
                return 1;
            }
            do_chat( ({ 
                (: command, "say "+this_player()->query("name")+"�w�g�[�J�O����´�աI" :),
                (: command, "say �O�Ӯ��O�ڪ��ɶ��I" :),
            }) );
            return 1;
        }
        me->set("guild", "piece");
        me->set("title", "���x�J����");
        do_chat( ({
            (: command, "say �������x���ޯ�i�H���۾ǲߡC" :),
            (: command, "say ���L�]���}���ߤ@�����|�ߨ�}���C" :),
            (: command, "say �ҥH�[�J�e�A�n�n�Ҽ{�@���a�I" :),
            (: command, "say �p�G�n�[�J���x�A�N��㥧�㴵�G�ӧ䴵��F�i���x�I" :),
        }) );
        return 1;
    }
    return 1;
}
