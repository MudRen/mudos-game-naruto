#include <ansi.h>
inherit ROOM;

string do_abc_list()
{
    int index, size, x, y;
    string msg;

    msg  = "�~�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
    msg += "�x                                                �x\n";
    msg += "�x  "HIC"�t�s�W�H    �t��s��    �s�C�U��    �C�M����"NOR"  �x\n";
    msg += "�x                                                �x\n";
    msg += "�x  "HIY"�߸۫h�m    �߷Q�Ʀ�    ���C�}��    �S�ѦӦ�"NOR"  �x\n";
    msg += "�x                                                �x\n";
    msg += "���w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��";

    return msg;
}
void create()
{
    set("short", HIW+BLK"�L�W"NOR"�C��");
    set("long", @LONG
�����O�ͪ��@����s�A�b��襤�o�������m���g�a�A�u���@��a
�ۼC�T�����C�A�����b�Ŧa���g��W�C���C�Ҵ��o�X���𮧧l�ޤF�A
���`�N�A��A�µ۪��C���h�A�o�Pı���W�U�ӷU�H�N�A�ϩ��m����B
�ѳ��a�����C��A���W������g�來�ثe�ɡA�@�ѱj�P���N���j�V�A
�����X�A�ϧA�����X�G�ᵲ�ӵL�k�e�i�C�A��_�Y�ӱ�V�g��A�o�o
�{�g�諸����٦��@�����j������A�W�����G�g�F����C
LONG);
    set("exits", ([
        "south" : __DIR__"workroom.c",
    ]));
    set("detail", ([
        "����": (: do_abc_list :),
    ]));
    set("objects", ([
        __DIR__"npc/item/sword.c" : 1,
    ]));
    set("no_fight", 1);
    setup();
}
