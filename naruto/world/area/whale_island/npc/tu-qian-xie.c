/* guild: hunter  �y�H */
// write by Tmr 2005/10/22
// update by Acme ��s���s���ȫ��A

#include <npc.h>
#include <ansi.h>

/*
#define QCATE "level_e"
#define QID 4
*/

inherit F_VILLAGER;

void create()
{
    set_name("�O�d��", ({ "tu qian-xie", "tu", "xie"}) );
    set_race("human");
    set_level(5);
    set("title","�֪��F�H");
    set("age", 40);
    set("long",@long
�O�d�ɬO�o�@�N�������W�����A�֪��F�H�A�ר�O�L����ɦת�
�ղz�A�L�׬O��⪺�d�ܸU�ơA�٬O�f�����X���Q�s�A����D�`�H��
�ү�A�s�L�@�n�u�F�H�v�]�����L�C�L�u�ꪺ���W�w�g�Q�j�a��ѤF
�A�M�ӱO�d�ɧ����L�{�b�����N�C
long
);

    // �@��ɰʧ@
    set("chat_chance", 3);
    set("chat_msg", ({
        (: command, "say ��~�ӯu�O�V�ӶV���F�A�q�汵��������..." :),
        (: command, "sweat" :),
        (: command, "say �ɦץήƶV�ζV���A�����D���S���H�������j���O..." :),
    }) );


    setup();

}

/*
// ��char��say���O�ɡA��mob���^��
int relay_say(object me, string arg)
{
    if( !objectp(me) || !stringp(arg) ) return 0;

    if( arg == "����"  ) {
            if( me->query_score("elevel") >= 1000 ) {
                tell_object(me, "�O�d�ɦ��G���ݭn�z�������F�C\n");
                return 0;
             }
        if( me->query_quest(QCATE, QID) ) {
                this_object()->force_me("say �x...�ڤw�g���бz�����F���O�ܡH");
                return 1;
        }
        this_object()->force_me("say ���I�I�D�`�P�¡A���N�·бz���ڦ����������ɦרӧa�C");
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
    if( !item->id("__CRAB_MEAT__") ) return 0;  //�@���O�ɦ�

    if( item->query_amount() < 10 ) {
        this_object()->force_me("say ��..�ƶq�n���٤����C�A��·ЧA�A�h�ɻ��@�I��...");
         return 0;
        }


    this_object()->force_me("say �ګ����D�`���§A�������F�A�o�O�ڪ��@�I���S�A���¤F�C");
        this_object()->force_me("thank " + me->query_id());
    tell_object(me, "(�@ "HIY+item->query_amount()*100+NOR" �Ȥl�w�g�۰ʦs�b�Ȧ�̡C)\n");
    me->add("bank", item->query_amount()*100);
        // �[e�ť���1�I
    me->gain_score("elevel", item->query_amount()/10);
        // �����Ȧs�����
        me->delete_quest(QCATE, QID);

    // �ϥ� do_chat �ө���I�s destruct ���� give �ʧ@����
    do_chat((: destruct, item :));

    return 1;
}
*/
