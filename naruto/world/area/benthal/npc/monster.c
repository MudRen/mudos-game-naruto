#include <npc.h>
#include <ansi.h>

string *name1 = ({ "����", "�w�h", "�Դ�", "���", "�ȭ�", "�}�w",
                   "��", "���", "�թ�", "����", "�`��", "�F�a", "�۹�", });

string *name2 = ({ "�K��", "����", "�w��P��", "�ĥd", "�ɤ�", "�Ǿ|",
                   "�~", "�J�y", "���i", "����", "��", "����", "����", });

void create()
{
    set_name( name1[random(sizeof(name1))] + name2[random(sizeof(name2))], ({ "monster" }) );
    set_race("beast");
    set("title", HIC"����������"NOR);
    set_level(55);
    set("age", 100 + random(5000));

    set("long", @LONG
���b����諸�F�a���𮧪������������A�]���髬�ܤj���W�`�`�|�d
���@�ǥi�ѳ�������L���v�ͪ����Ϊ��ݴ�A�]�������������H�i��
�|�@���p�ߴN�N�o�بF�a���������n���C���L�e�̬O����M��������
���A���|�D�ʧ����@��H�C
LONG);

    set("limbs", ({ "�Y��", "����", "���{", "���_", "����", "�I��", "���", "�H�ͳ�" }) );
    set("verbs", ({ "bite" }) );

    set("chat_chance", 5);
    set("chat_msg", ({
        CYN+this_object()->query("name")+"�o�X�o�H���ǥs...�u�Ȱ�..�q..�v\n"NOR,
    }) );

    set("set_drop", ({
          ([ "type":"eq", "id":106, "amount":1, "p1":5, "p2":100 ]),  // ���v����
    }) );
    setup();
    call_out("die_1", random(300)+300, this_object());
    add_temp("apply/attack", 100);
    add_temp("apply/intimidate", 100);
    add_temp("apply/wittiness", 100);
}
void die_1()
{
    message_vision(CYN"$N�o�X�C�I���s�n�A�S���^�F���~��𮧤F�C\n"NOR, this_object());
    destruct(this_object());
    return;
}
void die()
{
    object enemy, killer;
    int i;
    string msg;

    enemy = this_object()->last_damage_giver();
    i = 1 + random(3);

    if( !enemy ) {
        ::die();
        return;
    }
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) {
            ::die();
            return;
        } else
        if( environment(enemy) != environment(this_object()) ) {
            ::die();
            return;
        }
    }
    // �d��������D�H��
    if( !userp(enemy) && objectp(enemy->query_owner()) ) {
        killer = enemy->query_owner();
    } else {
        killer = enemy;
    }
    msg = "\n\n"HIC+this_object()->query("name")+"���L��½�_�j���A�|�P���������v�T�I\n\n"NOR;
    msg += HIR"�i���|�s�D�j"+this_object()->query("name")+"("+this_object()->query("id")+")����"+enemy->rank()+enemy->query("name")+"("+enemy->query("id")+")����F�I\n\n"NOR;

    killer->add("exchange", i);
    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    tell_object(killer, HIY"(�]���A����"+this_object()->query("name")+"��o�F "+i+" �I�I���I�ơC)\n"NOR);
    ::die();
    return;
}