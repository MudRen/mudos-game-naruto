#include <ansi.h>
inherit ROOM;

string do_list()
{
    int index, size;
    string msg;

    if( !wizardp(this_player()) ) {
        msg  = "�W���g�ۤ@��j�j���r�G\n\n";
        msg += HIR"      ���a���o�ϥΦ��Ŭu�I\n\n"NOR;
        return msg;
    }
    msg  = "�~�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
    msg += "�x�Ŭu�ϥΤ�h�G�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�x\n";
    msg += "�u�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�t\n";
    msg += "�x�R�~����(wash)�B�w��(sit)�B�_��(stand)�@�@�@�@�@�@�x\n";
    msg += "�u�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�t\n";
    msg += "�x�|���M�~���骺�H���o�w���I�@�@�@�@�@�@�@�@�@�@�@�@�x\n";
    msg += "�x����b���󤺥��N�����I�@�@�@�@�@�@�@�@�@�@�@�@�@�@�x\n";
    msg += "�x�w�����}�бN�H�������~�a���I�@�@�@�@�@�@�@�@�@�@�@�x\n";
    msg += "���w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";

    return msg;
}
void create()
{
        set("short", HIG"��"HIY"�Ŭu"NOR);
        set("long", @LONG
�󼯮a��|�}�P�X�Ӫ��Ŭu�a�A�̭��O���ۻP�y���Ŭu���۵M��
�ҡA�f�t�Ŭu�ҼQ�X���շϧϩ��m���P�ҡA�u�n�i�J�o�̫K�|�ϤH��
�����P�A�߱��n�����R�F�\�h�A�p�G�A�h�w�ӷŬu�A�z�㨺�@�����h
�ұN�|���������C�᭱�K�F�@�i�ȱ�(paper)�A���G�O�ϥγW�h�C
LONG);
    set("exits", ([
        "west" : __DIR__"workroom.c",
    ]));
    set("detail", ([
        "paper": (: do_list :),
    ]));
    setup();
}
void init()
{
    if( wizardp(this_player()) ) {
        add_action("do_wash", "wash");
        add_action("do_stand", "stand");
        add_action("do_sit", "sit");
    }
}
int do_wash(string arg)
{
    if( this_player()->query_temp("take/bath") < 1) {
        message_vision("$N"HIW"���_���䪺�������M�~����C\n"NOR, this_player());
        this_player()->add_temp("take/bath", 1);
        return 1;
    }
    return notify_fail("�A�w�g�~���ܰ��b�F�C\n");
}
int do_sit(string arg)
{
    if( this_player()->query_temp("take/bath") == 1) {
        message_vision("$N"HIY"���ʨ��l�w�i�Ŭu�̭�����u�n�C\n"NOR, this_player());
        this_player()->add_temp("take/bath", 1);
        call_out("wash_1", 10, this_player());
        return 1;
    } else if( this_player()->query_temp("take/bath") > 1) {
        return notify_fail("�A�w�g�w�b�Ŭu�̤F�٭n�wԣ�H\n");
    }
    return notify_fail("�٨S�M�~����N�w�I��ż�F�a�I\n");
}
int do_stand(string arg)
{
    if( this_player()->query_temp("take/bath") == 2) {
        message_vision("$N"HIC"���G�w���F�A�_�����}�Ŭu�C\n"NOR, this_player());
        this_player()->add_temp("take/bath", -1);
        return 1;
    }
    return notify_fail("�A�S�b�w�Ŭu�C\n");
}
int valid_leave(object me, string dir)
{
    if( !me ) return 0;
    if( userp(me) && dir == "west" ) { 
        if( me->query_temp("take/bath") == 2) {
            return notify_fail("�A�٪w�b�Ŭu�̷Q�]���h�H\n");
        }
        message_vision("$N"HIB"���F�ۤv�H�������~�����}�Ŭu�a�C\n"NOR, me);
        me->delete_temp("take/bath");
    }
    return ::valid_leave(me, dir);
}
void wash_1()
{
    object ob;
    ob = this_player();
    if( environment(ob) != this_object() ) return;

    if( ob->query_temp("take/bath") < 2) {
        return;
    }
    if( ob->is_fighting() ) {
        this_player()->add_temp("take/bath", -1);
        message_vision("$N"HIM"�b�Ŭu�����[�I\n"NOR, this_player());
        return;
    }
    message_vision("$N"HIR"�����֪��w�b�Ŭu���C\n"NOR, this_player());
    ob->heal_stat("ap", ob->query_stat_maximum("ap"));
    ob->heal_stat("hp", ob->query_stat_maximum("hp"));
    ob->heal_stat("mp", ob->query_stat_maximum("mp"));
    call_out("wash_1", 10, ob);
    return;
}
