#include <ansi.h>
#include <npc.h>

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
    message_vision(HIG"\n$N�ֳt�����_���l�A�������a�ۤ@�ا��]�몺���N�A�R�X�@���g�L���t���Y�������I\n\n\t\t"HIW"�y"BGRN+BLINK"���s����"NOR+HIW"�z"NOR"\n\n���Y���ϩ����|�P���L���A�Ҩ줧�B�_���ݾ��s�کް_�I\n"NOR, this_object(), enemy);
    message_vision(HIR"\n$n�ڥ��L�q�{���A�u��Q�������J�A���e�@���V��...\n\n"NOR, this_object(), enemy);
    this_object()->start_busy(2);
    this_object()->remove_all_killer();
    this_object()->do_heal();
    enemy->unconcious();
    return;
}

void create()
{
    set_name("�s�Ťj��", ({ "lich dragon king", "king" }));
    set_level(80);
    set_race("human");
    set("age", 15001);
    set("limbs", ({ "�s�Y", "�s��", "�s��", "����", "����", "�sŽ", "�s��" }) );
    set("long", "�������j�����ǡA�������o�X�@�������s�ڪ��𮧡C�ǻ����p�G���]\n"
                "�׹D�����A�]�O�i�H�����s�ڪ��A�o�짯�Ǥ]�\�N�O�w�g�������s��\n"
                "�䤤���@�a�C�u���e�L�ۦb�Ǥ����۬W�W�A���b�l���۳o�R���]�OŢ\n"
                "�n�����~�˪L����A���F�^�_�H�e�Ҩ����жˡC\n");
    set("nickname", HIG"���_���D"NOR);
    set("title", HIW"���s"NOR);
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    setup();
}
