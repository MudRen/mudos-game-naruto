// little 小海賊
// 2006/2/26 -mouse

void create()
{
	seteuid(getuid());
	DAEMON_D->register_class_daemon("little_sea");
}

string query_rank(object ob, string politeness)
{
	switch(politeness) {
		case "self": return "在下";
		case "rude self": return "在下";
		case "respectful": return "海賊";
		case "rude": return "小賊";
		default: return "小海賊";
	}
}

// 小海賊 1-20級
int getMaxLV() { return 20; }
int getLvUpExp(object ob) { return ob->query_level()*ob->query_level()*20; }

void setup(object ob) {}

void initialize(object ob) {}

void advance_level(object ob)
{
	// 設定學習點數、潛能點數、屬性點數、技能點數;
	ob->add_point("score", 50);
	ob->add_point("attribute", 2);
	ob->add_point("skill", 2);
}