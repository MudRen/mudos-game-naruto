#include <npc.h>
#include <ansi.h>

inherit F_SOLDIER;

void create()
{
    set_name("�����", ({ "oe mo", "oe", "mo" }) );
    set_race("human");
    set_level(55);
    set("age", 135);
    set("title", HIY"���H��"NOR);
    set("long", "�A�������٤���L���p�L�A�L�b�A�����e�N���@�y����Ať�����j��\n"
                "��D�W���q���O���H�ҥͦs���q�A�ݨӦ��H���ӴN�O�Ӧ۳o�y�q�a�I\n"
                "�uť���H�εL�`�a���G�u�u�n�u��q�k�q���Q�~�A�ڴN�ા�D�Y�ت�\n"
                "�U���աI�O�k�Q�����o�̳�I�v\n");

    set("set_drop", ({
        ([ "type":"wp", "id":43, "amount":1, "p1":50, "p2":100 ]),    // ����
        ([ "type":"wp", "id":32, "amount":1, "p1":1, "p2":100 ]),     // ����
        ([ "type":"wp", "id":59, "amount":1, "p1":1, "p2":2000 ]),    // ���H�ڤ��j�l
        ([ "type":"eq", "id":2, "amount":1, "p1":80, "p2":100 ]),     // �K�ݥ�
        ([ "type":"eq", "id":49, "amount":1, "p1":10, "p2":100 ]),    // ���򨭦�
        ([ "type":"eq", "id":36, "amount":1, "p1":5, "p2":100 ]),     // ���\
    }) );
    setup();
    carry_object(_DIR_AREA_"thorn_pine/npc/wp/thorn_staff.c")->wield("twohanded");
    add_temp("apply/attack", 400);
}
void init()
{
    if( this_object() == this_player() ) return;

    // �Y this_player() �ݤ����o�ӤH���A�h���޵o�԰��C
    if( ! this_object()->visible(this_player()) ) return;

    // �ϰ�]�w
    if( environment()->is_area() && !area_environment(this_object(), this_player()) ) return;

    // �Y���西���ۤ������A�}�l�԰��C
    if( this_player()->is_killing(query("id")) ) {
        COMBAT_D->auto_fight(this_player(), this_object(), "hatred");
        return;
    }
    if( is_killing(this_player()->query("id")) )
    {
        COMBAT_D->auto_fight(this_object(), this_player(), "hatred");
        return;
    }
    // �J�����¾�~���N�D�ʧ���
    if( this_player()->query_class() == "little_sea" 
        || this_player()->query_class() == "thief_sea" 
        || this_player()->query_class() == "big_sea" 
        || this_player()->query_class() == "reward_sea" 
        || this_player()->query_class() == "money_sea"
        || this_player()->query_class() == "king_sea" ) {

        message_vision(HIR"$N�@����$n�ߨ�W�e�����G�u���F�M���Y�ءI�@�w�n�u��q�k�q�I�v\n\n"NOR, this_object(), this_player());
        this_object()->kill_ob(this_player());
        this_player()->kill_ob(this_object());
        do_chat((: command, "kill " + this_player()->query("id") :));
    }
}
void die()
{
    object enemy, killer;
    string msg;

    enemy = this_object()->last_damage_giver();

    if( !enemy ) {
        destruct(this_object());  // �䤣����A��������
        return;
    }
    // �d��������D�H��
    if( !userp(enemy) && objectp(enemy->query_owner()) ) {
        killer = enemy->query_owner();
    } else {
        killer = enemy;
    }
    msg = "\n\n"+this_object()->query("name")+"�h�W�ۻ��D�G"HIG"�Ѥj���ڱϤ��F�A�̤F�����\n\t�@�@�@�@����x���n��u���a�@�ʦ~�N���A�̥X�ӡ��"NOR"\n\n"HIY"�~�M�b "+CHINESE_D->chinese_date(time())+" �Q"+enemy->query("name")+"���ѤF�����\n\n"NOR;
    msg += HIR"�i���|�s�D�j�㺸�˥��Ԥh"+this_object()->query("name")+"("+this_object()->query("id")+")�Q"+enemy->rank()+enemy->query("name")+"("+enemy->query("id")+")���ѩ�q�k�q�I\n\n"NOR;

    killer->add("exchange", 2);
    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    tell_object(killer, HIY"(�]���A����"+this_object()->query("name")+"��o�F 2 �I�I���I�ơC)\n"NOR);
    ::die();
    return;
}