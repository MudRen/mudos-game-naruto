#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIC"�ѵM�~"NOR);
    set("long", @long
���o�ۦ۵M�𮧪��p�ΡA�|�P���Q�j�����˪L�ҥ]��A�ж�����
�\�]�]���O�Ѿ��һs���A�ƵۿW�S���쭻�C�u���ж������ۤ@��C
�~�k�l�A�L���n�ۮ�W����s�ѽL�A�W���¤l�դl�����E�P�A�A�W�e
��i�@�ݡA�o�{�o�ѧ��¥դ����A�������e�A�n���¤lĹ�L�դl�A�S
�Pı�դl���Ѹ������Ŷ��o�i�A�N�b�A�W�䶡��M�����A�t�I�s�ۤv
�]���i�o�ѽL���g�䤤�F�C
long);
    set("exits", ([
        "south" : ([ "filename": __DIR__"god_1.c",
                      "x_axis": 2,
                      "y_axis": 4,
                 ]),
    ]));
    set("objects", ([
        __DIR__"npc/man.c" : 1,
    ]));
    set("no_recall", 1);
    set("no_fight", 1);
    setup();
}
