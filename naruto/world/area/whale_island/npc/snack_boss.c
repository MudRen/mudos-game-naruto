// write by Tmr 2005/10/22

#include <npc.h>
#define QCATE "level_p"
#define QID 10

inherit F_VILLAGER;
inherit F_VENDOR;

void create()
{
    set_name("�ѪO", ({ "snack boss", "boss" }) );
    set_race("human");
    set_level(5);
    set("age", 30);
    set("long",@long
�@��g��N��p�Y�����~�������A���b���i���X�C
long
);

    // �@��ɰʧ@
    set("chat_chance", 3);
    set("chat_msg", ({
        (: command, "say �̪��ɶ��N��V��V�n�A���Ƥ]�V�ζV���F..." :),
        (: command, "say �����D���S���H�@�N�����j�M�ɶ������ƩO..." :),
        (: command, "sweat" :),
    }) );

    set_goods(1, "food", 51, 100, 150); // ������������u�� 30 �۩w��
    set_goods(2, "food", 62, 20, 600); // ������������u�� 50 �۩w��
    set_goods(3, "food", 10, 50, -1);
    set_goods(4, "food", 11, 50, -1);

    setup();

}

// ��char��say���O�ɡA��mob���^��
int relay_say(object me, string arg)
{
    if( !objectp(me) || !stringp(arg) ) return 0;

    if( arg == "����" ) {
        if( me->query_quest(QCATE, QID) ) {
                this_object()->force_me("say �x...�ڤw�g���бz�����F���O�ܡH");
                return 1;
        }
        this_object()->force_me("say ���I�I�D�`�P�¡A���N�·бz���ڦ��������ɶ��ӧa�C");
        me->add_quest(QCATE, QID, 1);
        return 1;
    }   
    return 1;
}

int accept_object(object me, object item)
{
    int score;

    if( !objectp(me) || !objectp(item) ) return 0;
    if( me->query_quest(QCATE, QID) != 1 ) return 0;
    if( !item->id("__CRAB_ROE__") ) return 0;  //�@���O�ɶ�

    if( item->query_amount() < 5 ) {
        this_object()->force_me("say �ƶq�n���٤����C�A��·ЧA�A�h�ɻ��@�I��...");
         return 0;
        }

    this_object()->force_me("say �ګ����D�`���§A�������A���¤F�I�I");
        this_object()->force_me("thank " + me->query_id());
        tell_object(me, "(�A���ǲ��I�ƼW�[ " + 10*item->query_amount()/5 +" �I�F�C)\n");
        me->add_point("learn", 10*item->query_amount()/5 );
        // �����Ȧs�����
        me->delete_quest(QCATE, QID);

        // �ϥ� do_chat �ө���I�s destruct ���� give �ʧ@����
        do_chat((: destruct, item :));
        return 1;
}

