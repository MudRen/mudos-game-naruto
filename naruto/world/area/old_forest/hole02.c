#include <ansi.h>
inherit ROOM;

void create()
{
    set("short","�}�]��");
    set("long", @long
�S�Q�쨫�S�X�B�A�~�M�N�w�g�쩳�F�C�}�]�������u���@�Ӭݤ�
�������j�}�A�A���ե���Y�U�h���ղ`�סA���O�o�@�I�^���]�S����
�^�A�A����󪺦b�j�}����N���A�ש�b������F�@����÷�A�p�G
���Ȧ����ܤ]�\�i�H��(climb)�U�h�@�@....
long);
    set("exits", ([
        "north" : __DIR__"hole01.c",
    ]));
    set("detail", ([
        "��÷": "�N��ΤM�h��]�@�L�l�˪���w��÷�A���ӬO�g�۩һs�@���a�C",
    ]));
    set("no_recall", 1);
    setup();
}
void init()
{
    add_action("do_climb", "climb");
}
int do_climb(string arg)
{
    if( arg == "��÷") {
        message_vision("$N���÷�Y�A�����B�������F�U�h�C\n", this_player());
        this_player()->move(__DIR__"hole03.c");
        message_vision("$N�ש󪦨쩳�ݡA�֪����Y�j���C\n", this_player());
        return 1;
    }
    return notify_fail("�A�Q������F��H\n");
}
