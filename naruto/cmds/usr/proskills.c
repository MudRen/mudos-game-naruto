/* proskills.c
*/
#define SK_DIR "/daemon/pro_skill/"
#include <ansi.h>
inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

private string getSkill(string sk_name, string sk_id)
{
    return sk_name + "(" + sk_id + ")";
}

private string getLevel(int level, int max_level)
{
    string str;
    str = sprintf("%|40s", level + "/" + max_level);
    str = sprintf("%s%s", LINE + BGRN + str[0..(level*40/max_level)] + NOR, LINE + BBLU + str[(level*40/max_level)+1..39] + NOR);

    return str;
}

private string getHead(string name)
{
    string str = "";
    str += "�~�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
    str += sprintf("�x%|30s�x\n", name);
    str += "�u�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�r�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
    return str;
}

private string getBody(mapping skills)
{
    string str = "";
    string sk_dir, sk, *sks = keys(skills);

    foreach(sk in sks) {
        sk_dir = SK_DIR + sk + ".c";
        str += sprintf("�x%|30s  %40s�x\n", 
                       getSkill(sk_dir->getName(), sk),
                       getLevel(skills[sk]["level"], skills[sk]["max_level"]) );
    }
    return str;
}

private string getTail()
{
    return "���w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
}

private string getHead2(string sk_name, string sk_id, int level, int max_level)
{
    string str = "";
    str += "�~�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
    str += sprintf("�x%|30s  %s�x\n", getSkill(sk_name, sk_id), getLevel(level, max_level) );
    str += "�u�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�t\n";
    return str;
}

private string getBody2(string sk, string *item)
{
    string item_dir, str = "";
    int i, max = sizeof(item);

    for(i=0; i<max; i++) {
        item_dir = SK_DIR + sk + "/" + item[i] + ".c";
        if( file_size(item_dir) == -1 || file_size(item_dir) == -2 ) continue;

        str += sprintf("�x%-30s%-42s�x\n", getSkill(item_dir->getName(), item[i]), item_dir->getBrief());
    }

    return str;
}

private int list(object player)
{
    string msg = "";

    msg += getHead("�M�~�ޯ�");
    msg += getBody(player->getProSkills());
    msg += getTail();

    write(msg);

    return 1;
}

private int listSK(object player, string sk)
{
    string msg = "";
    string sk_dir = SK_DIR + sk + ".c";
    mapping sk_info;

    if( file_size(sk_dir) == -1 || file_size(sk_dir) == -2 ) return 0;

    sk_info = player->getProSkill(sk);
    if( !mapp(sk_info) ) return 0;
    msg += getHead2(sk_dir->getName(), sk, sk_info["level"], sk_info["max_level"]);
    msg += getBody2(sk, sk_info["item"]);
    msg += getTail();

    write(msg);

    return 1;
}

private int listProduct(object player, string sk, string product)
{
    string sk_dir, pdt_dir, msg;
    string key, *kkey;
    mapping stuff;
    object p;
    
    sk_dir = SK_DIR + sk + ".c";
    pdt_dir = SK_DIR + sk + "/" + product + ".c";

    if( file_size(sk_dir) == -1 || file_size(sk_dir) == -2 ) return 0;
    if( file_size(pdt_dir) == -1 || file_size(pdt_dir) == -2 ) return 0;

    msg  = HIY"�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n"NOR;
    msg += pdt_dir->getName() + "(" + product + ")\n";
    msg += HIY"�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n"NOR;
    msg += pdt_dir->getDetail() + "\n";
    
    msg += "�һݧޯ൥�šG" + pdt_dir->getLearnLevel() + "��\n";
    msg += "���~�O�_�j�w�G" + (pdt_dir->isBinding() ? "�O" : "�_") + "\n\n";
    
    msg += "�һݧ��ơG\n";
    stuff = pdt_dir->getStuff();
    kkey = keys(stuff);
    foreach(key in kkey) {
        p = new(key);
        
        if( !objectp(p) ) {
            destruct(p);
            continue;
        }
        
        msg += "    " + p->name() + "(" + p->query("id") + ") �G" + stuff[key] + "\n";
        destruct(p);
    }
    
    pdt_dir = pdt_dir->getProduct();
    if( pdt_dir ) {
        p = new(pdt_dir);
        if( objectp(p) )
            msg += "\n���~�G" + p->name() + "(" + p->query("id") + ")\n";
        destruct(p);
    }
    
    msg += HIY"�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n"NOR;
    write(msg);
    
    return 1;
}

int main(object me, string arg)
{
    object player;
    string who, sk, product, ctrl;

    if( !arg ) {
        list(me);
        return 1;
    }

    if( sscanf(arg, "%s %s -%s", sk, product, ctrl) == 3) {
        if( ctrl != "m" ) 
            return notify_fail("���O�榡�����A�� help proskills �C\n");
        
        if( !me->make(sk, product) )
            return notify_fail("�A�L�k�s�y�o�˲��~�C\n");

        return 1;
    } else if( sscanf(arg, "%s -%s", sk, who) == 2 ) {
        if( !wizardp(me) ) 
            return notify_fail("���O�榡�����A�� help proskills �C\n");
        player = find_player(who);
        if( !objectp(player) ) return notify_fail("�S���o�Ӫ��a�C\n");
        listSK(player, sk);
        return 1;
    } else if( sscanf(arg, "%s %s", sk, product) == 2 ) {
        listProduct(me, sk, product);
        return 1;
    } else if( sscanf(arg, "-%s", who) == 1 ) {
        if( !wizardp(me) ) 
            return notify_fail("���O�榡�����A�� help proskills �C\n");
        player = find_player(who);
        if( !objectp(player) ) return notify_fail("�S���o�Ӫ��a�C\n");
        list(player);
        return 1;
    } else if( sscanf(arg, "%s", sk) == 1 ) {
        listSK(me, sk);
        return 1;
    }

    return notify_fail("���O�榡�����A�� help proskills �C\n");
}

int help(object me)
{
    write(@HELP
���O�榡�G
    1. proskills                     �C�X�Ҧ����M�~�ޯ�
    2. proskills �ޯ�id              ��ܸӱM�~�ޯ�ү�s�y���ӫ~
    3. proskills �ޯ�id ���~id       ��ܻs�@�Ӫ��~�һݪ����ƻP������T
    4. proskills �ޯ�id ���~id -m    �Ͳ��Ӳ��~
HELP);

if( wizardp(me) ) {
    write(@HELP

�Ův���O�G
    1. proskills -���aid                  �C�X�Y���a�Ҧ����M�~�ޯ�
    2. proskills �ޯ�id -���aid           �C�X�Y���a�ӱM�~�ޯ�ү�s�y���ӫ~
HELP);
}

    return 1;
}
