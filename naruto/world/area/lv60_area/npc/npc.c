#include <npc.h>
#include <ansi.h>
#include "skill.h"

string *name = ({ "行屍", "骷髏人", "腐屍", "骸骨", "斷臂屍", "無頭屍", "殭屍", "枯骨" });

void create()
{
    set("skill_list", random(6));
    set_level(45);
    set_race("human");

    switch( query("skill_list") ) {
        case 1:
            set_name(RED"吳氏"NOR+name[random(sizeof(name))], ({ "wu skeleton", "skeleton" }) );
            set("set_drop", ({
                ([ "type":"eq", "id":2, "amount":1, "p1":50, "p2":100 ]),     // 鐵胸甲
                ([ "type":"eq", "id":16, "amount":1, "p1":80, "p2":100 ]),    // 草鞋
                ([ "type":"obj", "id":129, "amount":1, "p1":30, "p2":100 ]),  // 魂玉
                ([ "type":"wp", "id":76, "amount":1, "p1":1, "p2":600 ]),     // 吳氏妖炎指
            }) );
            break;
        case 2:
            set_name(CYN"魏氏"NOR+name[random(sizeof(name))], ({ "wei skeleton", "skeleton" }) );
            set("set_drop", ({
                ([ "type":"eq", "id":2, "amount":1, "p1":50, "p2":100 ]),     // 鐵胸甲
                ([ "type":"eq", "id":16, "amount":1, "p1":80, "p2":100 ]),    // 草鞋
                ([ "type":"obj", "id":129, "amount":1, "p1":30, "p2":100 ]),  // 魂玉
                ([ "type":"wp", "id":80, "amount":1, "p1":1, "p2":600 ]),     // 魏氏薄冰劍
            }) );
            break;
        case 3:
            set_name(HIM"毛利家"NOR+name[random(sizeof(name))], ({ "mouri skeleton", "skeleton" }) );
            set("set_drop", ({
                ([ "type":"eq", "id":2, "amount":1, "p1":50, "p2":100 ]),     // 鐵胸甲
                ([ "type":"eq", "id":16, "amount":1, "p1":80, "p2":100 ]),    // 草鞋
                ([ "type":"obj", "id":129, "amount":1, "p1":30, "p2":100 ]),  // 魂玉
                ([ "type":"wp", "id":75, "amount":1, "p1":1, "p2":800 ]),     // 毛利遠弓
            }) );
            break;
        case 4:
            set_name(HIG"上杉家"NOR+name[random(sizeof(name))], ({ "uesugi skeleton", "skeleton" }) );
            set("set_drop", ({
                ([ "type":"eq", "id":2, "amount":1, "p1":50, "p2":100 ]),     // 鐵胸甲
                ([ "type":"eq", "id":16, "amount":1, "p1":80, "p2":100 ]),    // 草鞋
                ([ "type":"obj", "id":129, "amount":1, "p1":30, "p2":100 ]),  // 魂玉
                ([ "type":"wp", "id":78, "amount":1, "p1":1, "p2":900 ]),     // 長尾武士刀
            }) );
            break;
        case 5:
            set_name(HIW"織田家"NOR+name[random(sizeof(name))], ({ "oda skeleton", "skeleton" }) );
            set("set_drop", ({
                ([ "type":"eq", "id":2, "amount":1, "p1":50, "p2":100 ]),     // 鐵胸甲
                ([ "type":"eq", "id":16, "amount":1, "p1":80, "p2":100 ]),    // 草鞋
                ([ "type":"obj", "id":129, "amount":1, "p1":30, "p2":100 ]),  // 魂玉
                ([ "type":"wp", "id":77, "amount":1, "p1":1, "p2":900 ]),     // 種子島鐵砲
            }) );
            break;
        default: 
            set_name(HIR"武田家"NOR+name[random(sizeof(name))], ({ "takeda skeleton", "skeleton" }) );
            set("set_drop", ({
                ([ "type":"eq", "id":2, "amount":1, "p1":50, "p2":100 ]),     // 鐵胸甲
                ([ "type":"eq", "id":16, "amount":1, "p1":80, "p2":100 ]),    // 草鞋
                ([ "type":"obj", "id":129, "amount":1, "p1":30, "p2":100 ]),  // 魂玉
                ([ "type":"wp", "id":79, "amount":1, "p1":1, "p2":900 ]),     // 武田馬上槍
            }) );
            break;
    }
    if( random(2) == 1) set("gender", "male");
    else set("gender", "female");

    set("age", 200 + random(2000));
    set("long",@LONG
人不像人，鬼不像鬼，有的尚有血肉，有的卻只剩枯骨，從它們所拿
的武器和使用的武術可以看出所有的「它」並不是同一個族群的生物
，但是腐爛的程度落差如此之大，讓人不知道如何判斷它們是屬於哪
個年代的生物，不過能夠肯定的是，這裡一定曾經發生過很大的戰爭
，才會使這麼多的各路高手齊聚在此，遺留下了無數的骨骸亡屍。
LONG);
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 30);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    setup();
    add_temp("apply/attack", -250);
    if( query("skill_list") == 1 ) {
        carry_object(__DIR__"wp/finger.c")->wield("twohanded");
    } else if( query("skill_list") == 2 ) {
        carry_object(__DIR__"wp/sword.c")->wield();
    } else if( query("skill_list") == 3 ) {
        carry_object(__DIR__"wp/bow.c")->wield("twohanded");
    } else if( query("skill_list") == 4 ) {
        carry_object(__DIR__"wp/katana.c")->wield();
    } else if( query("skill_list") == 5 ) {
        carry_object(__DIR__"wp/gun.c")->wield("twohanded");
    } else {
        carry_object(__DIR__"wp/lance.c")->wield();
    }
}
