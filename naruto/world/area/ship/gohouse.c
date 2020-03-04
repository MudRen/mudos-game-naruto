#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "�Ǥ��X�ʶ�");
        set("long", @LONG
�@���ܯS�O���ж��A����|�P����O�����g�L�S��B�z�A�n���g
�ۤ@�h�����A�N��Q�����]���|�㱼�C�b�ж��k�䦳�@�Ӷ}���A�}
���������٦��@����O�P�|�P����O�����檺�A�]�\�M�}���������
�~�a�C����h��F�@�Ǽ�����Ψ�C
LONG);
    set("exits", ([
        "south" : ([ "filename" : __DIR__"lufi.c",
                       "x_axis" : 34,
                       "y_axis" : 28,
                  ]),
    ]));
    set("detail", ([
        "�}��": "�����D������Ϊ��}���A�i�H���}(open)�C",
    ]));
    setup();
}
void init()
{
    add_action("do_open", "open");
}

int do_open(string arg)
{
    object me, area;
    string area_file = "/world/area/benthal/sea2.c";

    me = this_player();

    if( !arg ) return 0;
    if( arg != "�}��" ) return 0;

    if( !objectp(area = load_object(area_file)) ) return 0;
    if( !area->is_area() ) return 0;
    message_vision("$N�ΤO�ԤU�}���A�j���u�I�v�a�@�n���F�_�ӡA�@�}�j����$N�R�X�h�F...\n", me);
    if( !area_move(area, me, random(15)+16, random(9)+24) ) return 0;
    message_vision("���G$N�Q�Ĩ�F�o�Ӧa��C\n", me);
    return 1;
}
