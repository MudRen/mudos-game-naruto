#include <ansi.h>
inherit ROOM;
void create() 
{ 
    set("short", HIG"�ݫȫ�"NOR);
    set("long", HIC"\n\n���Ϭ����ݶQ�����ж��A���䦳�����x�i�H����½�\\�C

            "HIW"�P�±z���t�X�A�y��|���M�H���z�A�ȡI\n\n"NOR);

        set("light",1);    
        set("no_fight", 1);
        set("light",1);
        set("no_clean_up", 0);
        set("valid_startroom", 1);
        set("no_kill",1);  
        setup(); 
    load_object("/daemon/board/aring_b");
}


