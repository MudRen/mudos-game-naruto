// write by -Acme-

#include <npc.h>

inherit F_VILLAGER;
inherit F_TRAINER;    // �V�m�Ԫ�

/* guild: muye   �츭�Ԫ̧�
          yinyin �����Ԫ̧�
          wuyin  �����Ԫ̧�
          shayin �����Ԫ̧�
          yuyin  �B���Ԫ̧�
          yunyin �����Ԫ̧�
          caoyin �����Ԫ̧�
          puyin  �r���Ԫ̧�
*/

void to_do_say()
{
    do_chat( ({ 
        (: command, "say �Q�����츭�����@���ܡH�w��U��n�~�u�[�J�v�I" :),
        (: command, "say ��A�ѥ[�Ԫ̾Ǯաu���~�ҡv�o������A�Y�i�����U�ԡI" :),
        (: command, "say �����츭�����@����A�K�i�H�b�Ԫ̾Ǯվǲ߰򥻧ޯ�C" :),
    }) );
}

void create()
{
    set_name("��|�d", ({ "yi lu ka", "ka" }) );
    set_race("human");
    set_level(40);
    set_class("middle");  //����
    set("age", 25);
    set("camp", "muye");
    set("title", "�츭�Ԫ̾ǮձЮv");
    set("long", "��|�d�O�@�W���|�츭�������Ӿ԰��O���Ԫ̾ǮձЮv�A���ɥH�о�\n"
                "���D�A�������ȮɡA�]�|�ɤ��Ԫ��d���C�֦��u�q�~��O�L���Q��\n"
                "���X���ϯť��ȡA�ƨ����h�H��A�]���Q�D�令���Юv�A����֦~��\n"
                "�N���g���t�W����|�d�ӻ��A�Юv���u�@����ȧ�[�A�X�L�C\n"
                "�Y�A�O�츭�����Ԫ̡A�i�H�Q�� train ���O�ӦV��|�d�ǲߧޯ�C\n"
                "�ϥ� list ���O�d�ߥi�ǲߪ��ޯ�C��C\n" );

    // �@��ɰʧ@
    set("chat_chance", 3);
    set("chat_msg", ({
        (: to_do_say :),
    }) );

    // �]�w�Ԫ̧��A�ۦP���Ԫ̧��~�|��
    set("guild", "muye");

    // �]�w��V�m���ޯ�
    //
    // set_train(�ޯ�W, �O�_�i�����߱o, �ǲ߸ӧޯ�һݭn�����ⵥ��, ���ޯ�i�ǲߨ쪺�W������)
    //
    // ���a�S���ӧޯ�ɡA�Y"�O�_�i�����߱o"�o�ӳ]�w�Ȭ��D�s�ȮɡA���a�V�V�m�̾ǲ߮ɫh�i�O��
    // �o�ӧޯ��lv1�A�Ӧ�lv���ޯ�~�i�H���I�~����m�C�G�i�Ω�S��ޡA�n�����o��lv���i�V�m�C
    //
    set_train_with_camp("combat", 1, 1, 160, "muye", -2);             // �氫�ޥ�
    set_train_with_camp("dodge", 1, 1, 160, "muye", -2);              // �{���ޥ�
    set_train_with_camp("parry", 1, 1, 160, "muye", -2);              // �׮�ޥ�
    set_train_with_camp("heavy hit", 1, 5, 140, "muye", -2);          // �������N
    set_train_with_camp("savage hit", 1, 5, 140, "muye", -2);         // �������N
    set_train_with_camp("continual hit", 1, 5, 140, "muye", -2);      // �s�����N
    set_train_with_camp("force", 1, 10, 120, "muye", -2);             // ��N
    set_train_with_camp("ninja", 1, 10, 120, "muye", -2);             // �ԳN
    set_train_with_camp("substitute", 1, 10, 120, "muye", 0);         // �ԳN�G�����N
    set_train_with_camp("muye wind", 1, 15, 120, "muye", -1);         // ��N�G�줧���P��
    set_train_with_camp("alter ego", 1, 15, 120, "muye", -1);         // �ԳN�G�����N
    set_train_with_camp("hundred palm", 1, 15, 120, "muye", -1);      // ��N�G�ʯP�x
    set_train_with_camp("animal taming", 1, 15, 120, "muye", -1);     // �ԳN�G���~�N
    set_train_with_camp("double physique", 1, 15, 120, "muye", -1);   // �ԳN�G���ƳN
    set_train_with_camp("cell activation", 1, 15, 120, "muye", -1);   // �ԳN�G�ӭM����

    setup();

    set_skill("substitute", 100);          // �ԳN�G �����N
    map_skill("dodge", "substitute");      // �ϥΧޯ�u�����N�v��j�קޥ��W
}

// ��char��say���O�ɡA��mob���^��
int relay_say(object me, string arg)
{
    if( !objectp(me) || !stringp(arg) ) return 0;

    if( arg == "�[�J" || arg == "�[�J�츭��" ) {
        if( me->query("guild") ) {
            if( me->query("guild") == "muye") this_object()->force_me("say " + me->query("name") + "�A�A�w�g�O�츭�������F�C");
            else this_object()->force_me("say " + me->query("name") + "�A�A�w�g�O�O���Ԫ̧������F�C");
            return 1;
        }
        this_object()->force_me("say �ܦn�ܦn�I�q���H�� " + me->query("name") + " �N�O�ڭ̤츭�����@���F�I");
        me->set("guild", "muye");
        me->set("title", "�츭������");
        return 1;
    }

    if( arg == "���~��" || arg == "�ѥ[���~��" ) {
        object test;
        if( me->query("guild") != "muye" ) {
            this_object()->force_me("say " + me->query("name") + "�A�A���O�ڭ̤츭���������A����ѥ[���~�Ү@�C");
            return 1;
        }

        if( me->query_class() != "commoner" ) {
            this_object()->force_me("say " + me->query("name") + "�A�Ԫ̾Ǯղ��~�ҥu�A�Ω�@�몺�����@�C");
            return 1;
        }

        if( me->query_temp("quest/mitp") ) {
            this_object()->force_me("say " + me->query("name") + "�A�A�褣�O�w�g��ڮ��L�Ҩ��F�H");
            return 1;
        }

        test = new( _DIR_ITEM_"mitp.c" );
        if( !objectp(test) ) {
            this_object()->force_me("say " + me->query("name") + "�A���~�Ҫ��Ҹը��Χ��F�C");
            return 1;
        }

        if( !test->move(this_object()) ) {
            this_object()->force_me("say " + me->query("name") + "�A���r�I�ڧѤF���Ҹը��X�ӡC");
            destruct(test);
            return 1;
        }

        // �]�w���a�Ȯ��ܼơA�H���@����Ҩ�
        me->set_temp("quest/mitp", 1);

        this_object()->force_me("give paper to " + me->query_id()) ;
        this_object()->force_me("say " + me->query("name") + "�A�N�Ҹը��W�����׶�@��A������A�����ڡC");
        return 1;
    }
    return 1;
}

int accept_object(object me, object item)
{
    int score;

    if( !objectp(me) || !objectp(item) ) return 0;
    if( item->is_test_paper() != "muye" ) return 0;

    if( me->query("guild") != "muye" ) {
        this_object()->force_me("say " + me->query("name") + "�A�A���O�츭�����@���C");
        return 0;
    }
    
    if( me->query_class() != "commoner" ) {
        this_object()->force_me("say " + me->query("name") + "�A�Ԫ̾Ǯղ��~�ҥu�A�Ω�@�몺�����@�C");
        return 0;
    }

    score = item->do_check();

    message_vision("$N�����ֳt�a���˵�$n...\n", this_object(), item);

    if( score != 100 ) {
        this_object()->force_me("say ����I�H�u��" + chinese_number(score) + "���]�Q�q�Ԫ̾Ǯղ��~�I�H");
        return 0;
    }
    this_object()->force_me("say ���������I�ҤF�@�ʤ��A" + me->name() + "�A�q���H��N�O�츭�����U�ԤF�I");
    this_object()->force_me("cong " + me->query_id());

    me->set("title", "�츭���Ԫ�");
    me->set_level(1);
    me->addCamp("muye");  // �W�[�츭���}��
    me->set_class("inferior");

    // �ϥ� do_chat �ө���I�s destruct ���� give �ʧ@����
    do_chat((: destruct, item :));
    return 1;
}
