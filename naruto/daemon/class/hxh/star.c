// star �@�P�y�H 61-70
// 2005/10/19 -tmr


void create()
{
	seteuid(getuid());
	DAEMON_D->register_class_daemon("hxh_star");
}

string query_rank(object ob, string politeness)
{
	switch(politeness) {
		case "self": return "�b�U";
		case "rude self": return "�b�U";
		case "respectful": return "�y�H";
		case "rude": return "�c��";
		default: return "�@�P�y�H";
	}
}

// �@�P�y�H 61-70��
int getMaxLV() { return 70; }
int getLvUpExp(object ob) { return ob->query_level()*ob->query_level()*70; }

void setup(object ob) {}

void initialize(object ob)
{
/* �ɯŤ��ݳo�ӤF
    int lv;
	seteuid(geteuid(ob));
	lv = ob->query_level();
	// �]�w�U���ɯũһݸg��
	if( lv < 70 ) {
	    ob->set_target_score("slevel", lv-60);
	    ob->set_target_score("combat exp", lv*lv*1800);
	} else ob->delete("target_score");
*/
}

void advance_level(object ob)
{
/* �ɯŤ��ݳo�ӤF
    int lv;
	lv = ob->query_level();
	if( !lv ) return;
	
	// �]�w�U���ɯũһݸg��
	if( lv < 70 ) {
	    ob->set_target_score("slevel", lv-60);
	    ob->set_target_score("combat exp", lv*lv*1800);
	} else ob->delete("target_score");
*/
	// �]�w�ǲ��I�ơB����I�ơB�ݩ��I�ơB�ޯ��I��;
//	ob->add_point("learn", 100);
	ob->add_point("score", 100);
	//ob->add_point("attribute", 5);
	ob->add_point("skill", 4);
}
