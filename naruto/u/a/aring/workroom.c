#include <ansi.h>
inherit ROOM;
void create() 
{ 
    set("short", HIG"待客室"NOR);
    set("long", HIC"\n\n此區為接待貴賓的房間，旁邊有些雜誌可以先行翻閱\。

            "HIW"感謝您的配合，稍後會有專人為您服務！\n\n"NOR);

        set("light",1);    
        set("no_fight", 1);
        set("light",1);
        set("no_clean_up", 0);
        set("valid_startroom", 1);
        set("no_kill",1);  
        setup(); 
    load_object("/daemon/board/aring_b");
}


