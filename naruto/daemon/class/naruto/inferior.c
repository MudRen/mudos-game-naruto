// Fighter class daemon.
void create()
{
	seteuid(getuid());
	DAEMON_D->register_class_daemon("inferior");
}

string query_rank(object ob, string politeness)
{
	switch(politeness) {
		case "self": return "�b�U";
		case "rude self": return "�b�U";
		case "respectful": return "�Ԫ�";
		case "rude": return "�c��";
		default: return "�U��";
	}
}

void setup(object ob) {}

// �U�� 1-20��
int getMaxLV() { return 20; }
int getLvUpExp(object ob) { return ob->query_level()*ob->query_level()*20; }
	
void initialize(object ob)
{
/* �ɯŤ��ݳo�ӤF
    int lv;
	seteuid(geteuid(ob));

    lv = ob->query_level();

    // �U�ԥu��ɨ�lv20
    if( lv < 20 ) {
		// �W�L�Q�ť��ݭn������E�ť���
    	if( lv > 10 ) ob->set_target_score("elevel", lv-10);
        ob->set_target_score("combat exp", lv*lv*100);
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
	if( lv < 20 ) {
		// �W�L�Q�ť��ݭn������E�ť���
    	if( lv > 10 ) ob->set_target_score("elevel", lv-10);
	    ob->set_target_score("combat exp", lv*lv*100);
	} else ob->delete("target_score");
*/	
	// �]�w�ǲ��I�ơB����I�ơB�ݩ��I�ơB�ޯ��I��;
//	ob->add_point("learn", 100);
	ob->add_point("score", 50);
	ob->add_point("attribute", 2);
	ob->add_point("skill", 2);
}