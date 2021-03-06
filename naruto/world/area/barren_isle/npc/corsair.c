#include <ansi.h>
#include <npc.h>
#include "skill.h"

inherit F_SEABANDIT;

string *name1 = ({ "蘇", "聖", "邦", "頑固", "愛", "掰", "沖田", "樓", "楊", "風",
                   "吸", "趴", "跛", "愛新覺羅", "娜", "莫", "巴圖", "無", "瑪", "西埃", 
                   "奪命", "莫", "莫" , "卡", "摩", "克", "阿", "巴", "傑克", "夢幻" });

string *name2 = ({ "普", "儒", "喬飛", "二筋", "西亞", "咖", "宗次郎", "四踢", "過", "驚雲",
                   "威威", "嗯機", "腳", "玄燁", "拉", "古", "魯", "盡", "莎", "一號",
                   "無尾熊", "嘎", "給", "巴吉", "奇", "洛", "金", "拉", "斯", "七域" });

string report_status(object ob)
{
    int ratio;
    if( !ob->query_stat_maximum("hp") ) return "\n";
    ratio = (int)ob->query_stat("hp")*100/(int)ob->query_stat_maximum("hp");
    if( ratio > 80 ) return HIK"["HIG"$n" + HIG + ratio + "%" + HIK"]\n"NOR;
    else if( ratio > 30 ) return HIK"["HIY"$n" + HIY + ratio + "%" + HIK"]\n"NOR;
    else return HIK"["HIR"$n" + HIR + ratio + "%" + HIK"]\n"NOR;
}

void create()
{
    set_name(name1[random(sizeof(name1))] + name2[random(sizeof(name2))], ({ "corsair", "_CORSAIR_" }) );
    set_race("human");
    set_level(20);
    set("attitude", "aggressive");         // 主動攻擊
    set("class", "little_sea");
    set("age", 10+random(51));
    set("long", "偷走寶箱人重要寶箱的海賊，一臉生氣樣肯定是拿到空寶箱的關係。\n");
    set("sktree", random(6)+1);
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 25);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"obj", "id":29, "amount":50+random(50), "p1":50, "p2":100 ]),  // 銀子
        ([ "type":"obj", "id":110, "amount":1, "p1":15, "p2":100 ]),             // 藍寶箱
        ([ "type":"obj", "id":111, "amount":1, "p1":15, "p2":100 ]),             // 紅寶箱
    }) );
    setup();

    // 狀態
    set_stat_current("hp", 800);
    set_stat_current("ap", 800);
    set_stat_current("mp", 800);
    set_stat_maximum("hp", 800);
    set_stat_maximum("ap", 800);
    set_stat_maximum("mp", 800);

    // 基本技能
    set_skill("parry", 90);
    set_skill("dodge", 90);
    set_skill("combat", 90);
    set_skill("heavy hit", 90);
    set_skill("savage hit", 90);
    set_skill("continual hit", 90);


    // 之前的考場 mob 都會dodge, parry and 一個sk
    // 算起來是兩個 sk 所以這次有些 mob 捨棄了dodge, parry 改用兩個 sk
    // 計算公式與技能指定技能相同，敘述上修改而另外寫
    // 直接把 sk 套在 mob 上有些自動技會發動
    // 有關 sk 本身的的條件會換成其他 sk 代替

    switch( query("sktree") ) {
        case 1: // 雜耍卡巴吉
            set("nickname",HIR"雜耍"NOR);
            set_skill("blade", 90);                  // 刀術
            break;
        case 2: // 猛獸使摩奇
            set("nickname",YEL"猛獸使"NOR);
            set_skill("activity", 90);               // 特殊
            break;
        case 3: // 黑貓船長
            set("nickname",HIK"黑貓船長"NOR);
            set_skill("martial", 90);                // 武術
            set_skill("noshadow step", 90);          // 無影腳
            break;
        case 4: // 催眠師傑克斯
            set("nickname",HIM"催眠師"NOR);
            set_skill("martial", 90);                // 武術
            break;
        case 5: // 鬼人阿金
            set("nickname",HIB"鬼人"NOR);
            set_skill("spurn", 90);                  // 踢技
            break;
        case 6: // 鐵壁巴拉
            set("nickname",HIW"鐵壁"NOR);
            set_skill("spurn", 90);                  // 踢技
            set_skill("iron wall", 90);              // 鐵壁
            break;
    }
    // 增強
    set_temp("apply/attack", 150);        // 攻擊力量
    set_temp("apply/armor", 50);          // 防禦力量
    set_temp("apply/exact", 37);          // 命中率
    set_temp("apply/evade", 50);          // 迴避率
    set_temp("apply/intimidate", 10);     // 攻擊能力
    set_temp("apply/wittiness", 10);      // 防禦能力
    set_temp("apply/int", 5);
    set_temp("apply/con", 5);
    set_temp("apply/str", 5);
    set_temp("apply/dex", 5);
}
