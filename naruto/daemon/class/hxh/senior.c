// senior 全職獵人
// 2005/10/19 -tmr

void create()
{
	seteuid(getuid());
	DAEMON_D->register_class_daemon("hxh_senior");
}

string query_rank(object ob, string politeness)
{
	switch(politeness) {
		case "self": return "在下";
		case "rude self": return "在下";
		case "respectful": return "獵人";
		case "rude": return "惡賊";
		default: return "全職獵人";
	}
}

// 全職獵人 41-60級
int getMaxLV() { return 60; }
int getLvUpExp(object ob) { return ob->query_level()*ob->query_level()*60; }

void setup(object ob) {}

void initialize(object ob)
{
/* 升級不看這個了
    int lv;
	seteuid(geteuid(ob));
	lv = ob->query_level();
	// 設定下次升級所需經驗
	if( lv < 60 ) {
		if( lv > 50 )
			ob->set_target_scor("alevel", lv-50);
		else ob->set_target_score("blevel", lv-40);
	    ob->set_target_score("combat exp", lv*lv*1000);
	} else ob->delete("target_score");
*/
}

void advance_level(object ob)
{
/* 升級不看這個了
    int lv;
	lv = ob->query_level();
	if( !lv ) return;
	
	// 設定下次升級所需經驗
	if( lv < 60 ) {
		if( lv > 50 )
			ob->set_target_scor("alevel", lv-50);
		else ob->set_target_score("blevel", lv-40);
	    ob->set_target_score("combat exp", lv*lv*1000);
	} else ob->delete("target_score");
*/ 	
	// 設定學習點數、潛能點數、屬性點數、技能點數;
//	ob->add_point("learn", 100);
	ob->add_point("score", 150);
	ob->add_point("attribute", 4);
	ob->add_point("skill", 2);
}
