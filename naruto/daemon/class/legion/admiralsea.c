// king ���x���N
// 2005/10/19 -tmr

void create()
{
	seteuid(getuid());
	DAEMON_D->register_class_daemon("admiral_sea");
}

string query_rank(object ob, string politeness)
{
	switch(politeness) {
		case "self": return "�b�U";
		case "rude self": return "�b�U";
		case "respectful": return "���N";
		case "rude": return "��N";
		default: return "���x���N";
	}
}

// ���x���N 81-99��
int getMaxLV() { return 99; }
int getLvUpExp(object ob) { return ob->query_level()*ob->query_level()*99; }

void setup(object ob) {}

void initialize(object ob) {}

void advance_level(object ob)
{
	// �]�w�ǲ��I�ơB����I�ơB�ݩ��I�ơB�ޯ��I��;
	ob->add_point("score", 100);
	ob->add_point("attribute", 2);
	ob->add_point("skill", 2);
}