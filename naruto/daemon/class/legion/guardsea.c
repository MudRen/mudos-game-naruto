// super 海軍校衛
// 2005/10/19 -tmr


void create()
{
        seteuid(getuid());
        DAEMON_D->register_class_daemon("guard_sea");
}

string query_rank(object ob, string politeness)
{
        switch(politeness) {
                case "self": return "在下";
                case "rude self": return "在下";
                case "respectful": return "校衛";
                case "rude": return "賊官";
                default: return "海軍校衛";
        }
}

// 海軍校衛 61-70級
int getMaxLV() { return 70; }
int getLvUpExp(object ob) { return ob->query_level()*ob->query_level()*70; }

void setup(object ob) {}

void initialize(object ob) {}

void advance_level(object ob)
{
        // 設定學習點數、潛能點數、屬性點數、技能點數;
        ob->add_point("score", 50);
        ob->add_point("attribute", 5);
        ob->add_point("skill", 1);
}
