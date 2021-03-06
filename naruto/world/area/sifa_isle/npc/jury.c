#include <ansi.h>
#include <npc.h>

inherit F_SEASOLDIER;

void create()
{
    set_name("陪審團", ({ "jury" }) );
    set_race("human");
    set_level(40);
    set("title",HIC"司法島"NOR);
    set("nickname",BRED+HIW"　有　罪　"NOR);
    set("class", "guard_sea");
    set("camp", "police");
    set("age", 25+random(41));
    set("long", "一臉兇惡的人，口中不停的唸著「有罪...有罪...」。他就是司法島\n"
                "上的陪審團員之一。據說司法島上的陪審團員，都是來自深海大監獄\n"
                "的原海賊成員，他們因為一輩子都無法再離開那個黑暗的監獄，在獲\n"
                "得陪審團的資格後只想把被審判將人也拉進深海大監獄，因此在這司\n"
                "法島上還沒有任何一人獲判無罪的。\n");
    set("chat_chance", 15);
    set("chat_msg", ({
        (: command, "say 有罪！有罪！" :),
    }));
    set("chat_chance_combat", 20);
    set("chat_msg_combat", ({
        (: command, "say 有罪！有罪！" :),
    }) );
    set("set_drop", ({
        ([ "type":"obj", "id":100, "amount":1, "p1":60, "p2":100 ]),              // 彈夾
        ([ "type":"obj", "id":102, "amount":1, "p1":40, "p2":100 ]),              // 火繩
        ([ "type":"wp", "id":55, "amount":1, "p1":80, "p2":100 ]),                // 新生戰刀
        ([ "type":"wp", "id":52, "amount":1, "p1":1, "p2":450 ]),                 // 破碎刃
        ([ "type":"wp", "id":30, "amount":1, "p1":1, "p2":150 ]),                 // 突擊戰刀
       ([ "type":"obj", "id":109, "amount":1, "p1":1, "p2":500 ]),               // 夕陽飛天滑板
    }) );
    setup();
    carry_object(_DIR_WP_"blade.c")->wield();
    add_temp("apply/attack", 50);
    add_temp("apply/armor", 150);
}
