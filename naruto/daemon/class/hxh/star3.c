// star3 �T�P�y�H
// 2005/10/19 -tmr

void create()
{
	seteuid(getuid());
	DAEMON_D->register_class_daemon("hxh_star3");
}

string query_rank(object ob, string politeness)
{
	switch(politeness) {
		case "self": return "�b�U";
		case "rude self": return "�b�U";
		case "respectful": return "�y�H";
		case "rude": return "�c��";
		default: return "�T�P�y�H";
	}
}

// �T�P�y�H 81-99��
int getMaxLV() { return 99; }
int getLvUpExp(object ob) { return ob->query_level()*ob->query_level()*99; }

void setup(object ob) {}

void initialize(object ob)
{
/* �ɯŤ��ݳo�ӤF
    int lv;
	seteuid(geteuid(ob));
	lv = ob->query_level();
	// �]�w�U���ɯũһݸg��
	if( lv < 99 ) ob->set_target_score("combat exp", lv*lv*3000);
    else ob->delete("target_score");
*/
}

void advance_level(object ob)
{
/* �ɯŤ��ݳo�ӤF
    int lv;
	lv = ob->query_level();
	if( !lv ) return;
	
	// �]�w�U���ɯũһݸg��
	if( lv < 99 ) ob->set_target_score("combat exp", lv*lv*3000);
    else ob->delete("target_score");
*/
	// �]�w�ǲ��I�ơB����I�ơB�ݩ��I�ơB�ޯ��I��;
//	ob->add_point("learn", 100);
	ob->add_point("score", 100);
	ob->add_point("attribute", 2);
	ob->add_point("skill", 2);
}
