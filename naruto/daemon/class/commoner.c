// commoner.c

void create()
{
	seteuid(getuid());
	DAEMON_D->register_class_daemon("commoner");
}

string query_rank(object ob, string politeness)
{
	switch(politeness) {
		case "self": return "�p�H";
		case "rude self": return "���j��";
		case "respectful": return "�j��";
		case "rude": return "�c��";
		default: return "����";
	}
}

// ���� 1 ��
int getMaxLV() { return 1; }
int getLvUpExp(object ob) { return 0; }

void initialize(object ob) { seteuid(geteuid(ob)); }
void setup(object ob) { seteuid(geteuid(ob)); }
int valid_wield(object me, object ob, string skill) { return 1; }
int valid_wear(object me, object ob, string part) { return 1; }