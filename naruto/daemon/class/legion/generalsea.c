// money ���x��N
// 2006/2/26 -mouse

void create()
{
        seteuid(getuid());
        DAEMON_D->register_class_daemon("general_sea");
}

string query_rank(object ob, string politeness)
{
        switch(politeness) {
                case "self": return "�b�U";
                case "rude self": return "�b�U";
                case "respectful": return "��N";
                case "rude": return "��N";
                default: return "���x��N";
        }
}

// ���x��N 71-80��
int getMaxLV() { return 80; }
int getLvUpExp(object ob) { return ob->query_level()*ob->query_level()*80; }

void setup(object ob) {}

void initialize(object ob) {}

void advance_level(object ob)
{
        // �]�w�ǲ��I�ơB����I�ơB�ݩ��I�ơB�ޯ��I��;
        ob->add_point("score", 150);
        ob->add_point("attribute", 1);
        ob->add_point("skill", 3);
}
