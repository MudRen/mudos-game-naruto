
#include <ansi.h>
#include <room.h> 
inherit INN;

void create()
{
    set("short", "���޾_��");
    set("long", "�@�Ӭ۷�K�����a��A�o���õۤ@��}�_�j�Ǫ��ƪ��C\n");

    setup();
    load_object("/daemon/board/jolin");
}

