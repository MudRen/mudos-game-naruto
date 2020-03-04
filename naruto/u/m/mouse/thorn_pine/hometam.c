#include <ansi.h>

inherit ROOM;

int i;

void create()
{
        set("short", "�u�F�ѡv���]");
        set("long", @LONG
���]�u�F�ѡv�A�b���f�N��F�@���۵P�A�W�����еۦ����F�Ѯ�
�]�W�٪��ѨӡC�@�Ӫ��ж��ݰ_�ӤS�p�S²���A�G�Ӫ��ж��h����e
�j�ξA�A�p�G���Q��J�i�H�߰ݦ���ݬݡC
LONG);
    set("exits", ([
        "south" : ([ "filename" : __DIR__"waterfall.c",
                       "x_axis" : 2,
                       "y_axis" : 5,
                  ]),
    ]));
    set("detail", ([
        "�۵P": @LONG
�F�Ѥ@�r���ѨӡA�K�O���䪺�F���r���A�]���r�����۩󩥤��s�u�A
���ӵL�k�Φ��r���A���O�o�F���r���o���P�A���M�֦��j�j�����O��
���A�ɭP�U�������g���B���Ķ��d�A���n�F��������աA�󧧤j�F�r
�����Q��A�ᦳ�P�ѹ��F����աC
LONG
    ]));
    set("objects", ([
        __DIR__"npc/line.c" : 1,
    ]));
    setup();
}
void init()
{
    add_action("do_lodging", "lodging");
}
int do_lodging(string arg)
{
    if( this_player()->query("bank") < 10000) {
        message_vision("�\�껡�D�R"HIG"$N�Ȧ�̪��������O�I\n"NOR, this_player());
        return 1;
    }
    if( i < 5) {
        message_vision(HIY"$N��F10000��Ȥl���\��C\n\n"NOR, this_player());
        message_vision(HIW"�\��浹�F$N�@��ж��_�͡C\n\n\n"NOR, this_player());
        this_player()->add("bank", -10000);
        i = i+1;
        this_player()->move(__DIR__"home"+i+".c");
        message_vision(HIC"$N�ΤF�@ı�Pı�n�h�F�C\n\n"NOR, this_player());
        this_player()->heal_stat("ap", 9999);
        this_player()->heal_stat("hp", 9999);
        this_player()->heal_stat("mp", 9999);
        this_player()->start_busy(4);
        call_out("home_check",1800,this_object());
        return 1;
    }
    message_vision("�\�껡�D�R"HIG"�u�藍�_�A�S�ũж��F�C\n\n"NOR, this_player());
    return 1;
}
void home_check()
{
    i = 0;
}
