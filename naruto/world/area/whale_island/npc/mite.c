//米特 mite.c -Tmr

#include <npc.h>

inherit F_VILLAGER;
inherit F_VENDOR;

void create()
{
        set_name("米特•富力士", ({ "mite fulishi", "mite", "fulishi" }) );
        set_race("human");
         set_attr("int", 30 );
        set_attr("str", 19);
        set_attr("cor", 17);
        set_attr("cps", 15);
        set_attr("dex", 18);
          set("gender", "female");
          set("age", 25);
        set("long",@long
米特為這間酒店的主人，和她的母親一起管理有好幾年的時間了。米
特留著一頭俏麗的短髮，一雙眼睛烏亮亮的十分有神。                                                     
long
);


    set_goods(1, "wp", 15, 10, 15);

        set("chat_chance", 5);
        set("chat_msg", ({
                "米特邊整理著桌子邊哼著輕快的歌曲。\n",
                "米特微笑地問你：「想要點些什麼嗎？」 \n",
                "米特望了望店門口，似乎在等待誰回來！？ \n",
        }));
        setup();
}

