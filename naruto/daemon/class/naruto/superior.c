// Fighter class daemon.
void create()
{
	seteuid(getuid());
	DAEMON_D->register_class_daemon("superior");
}

string query_rank(object ob, string politeness)
{
	switch(politeness) {
		case "self": return "�b�U";
		case "rude self": return "�b�U";
		case "respectful": return "�Ԫ�";
		case "rude": return "�c��";
		default: return "�W��";
	}
}

void setup(object ob) {}

// �W�� 41-60��
int getMaxLV() { return 60; }
int getLvUpExp(object ob) { return ob->query_level()*ob->query_level()*60; }

void initialize(object ob)
{
/* �ɯŤ��ݳo�ӤF
    int lv;
	seteuid(geteuid(ob));
	lv = ob->query_level();
	// �]�w�U���ɯũһݸg��
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
/* �ɯŤ��ݳo�ӤF
    int lv;
	lv = ob->query_level();
	if( !lv ) return;
	
	// �]�w�U���ɯũһݸg��
	if( lv < 60 ) {
		if( lv > 50 )
			ob->set_target_scor("alevel", lv-50);
		else ob->set_target_score("blevel", lv-40);
	    ob->set_target_score("combat exp", lv*lv*1000);
	} else ob->delete("target_score");
*/

	// �]�w�ǲ��I�ơB����I�ơB�ݩ��I�ơB�ޯ��I��;
//	ob->add_point("learn", 100);
	ob->add_point("score", 150);
	ob->add_point("attribute", 4);
	ob->add_point("skill", 2);
}