#define SK_DIR "/daemon/pro_skill/"
#include <ansi.h>

void create() { seteuid(getuid()); }

string getProSkillFile(string skill)
{
    string sk_dir;
    sk_dir = SK_DIR + skill + ".c";
    if( file_size(sk_dir) == -1 || file_size(sk_dir) == -2 ) return 0;
    if( !sk_dir->isProSkill() ) return 0;
    return sk_dir;
}

string getProItemFile(string skill, string item)
{
    string item_dir;
    item_dir = SK_DIR + skill + "/" + item + ".c";
    if( file_size(item_dir) == -1 || file_size(item_dir) == -2 ) return 0;
    // ���O�o�ӧޯ�U�����~
    if( item_dir->getProSkill() != skill ) return 0;
    return item_dir;
}

string getProSkillName(string skill)
{
    string sk_dir;
    sk_dir = getProSkillFile(skill);
    if( !stringp(sk_dir) ) return "";
    return sk_dir->getName();
}

int getLearnLevel(string skill, string item)
{
    string item_dir;
    item_dir = getProItemFile(skill, item);
    if( !stringp(item_dir) ) return -1;
    return item_dir->getLearnLevel();
}

string getItemName(string skill, string item)
{
    string item_dir;
    item_dir = getProItemFile(skill, item);
    if( !stringp(item_dir) ) return "";
    return item_dir->getName();
}

string getBrief(string skill, string item)
{
    string item_dir;
    item_dir = getProItemFile(skill, item);
    if( !stringp(item_dir) ) return "";
    return item_dir->getBrief();
}

string getDetaile(string skill, string item)
{
    string item_dir;
    item_dir = getProItemFile(skill, item);
    if( !stringp(item_dir) ) return "";
    return item_dir->getDetail();
}

mapping getStuff(string skill, string item)
{
    string item_dir;
    item_dir = getProItemFile(skill, item);
    if( !stringp(item_dir) ) return ([]);
    return item_dir->getStuff();
}

string getProduct(string skill, string item)
{
    string item_dir;
    item_dir = getProItemFile(skill, item);
    if( !stringp(item_dir) ) return 0;
    return item_dir->getProduct();
}

object createProduct(string skill, string item)
{
    string item_dir;
    object product;
    item_dir = getProItemFile(skill, item);
    if( !stringp(item_dir) ) return 0;
    item_dir = item_dir->getProduct();
    if( !item_dir ) return 0;
    product = new(item_dir);
    if( !objectp(product) ) return 0;
    return product;
}

string getMakeMsg(string skill, string item)
{
    string item_dir;
    item_dir = getProItemFile(skill, item);
    if( !stringp(item_dir) ) return "";
    return item_dir->makeMsg();
}

int isBinding(string skill, string item)
{
    string item_dir;
    item_dir = getProItemFile(skill, item);
    if( !stringp(item_dir) ) return 0;
    return item_dir->isBinding();
}

int preCondition(string skill, string item, object player)
{
    string item_dir;
    item_dir = getProItemFile(skill, item);
    if( !stringp(item_dir) ) return 0;
    return item_dir->preCondition(player);
}

int postCondition(string skill, string item, object player)
{
    string item_dir;
    item_dir = getProItemFile(skill, item);
    if( !stringp(item_dir) ) return 0;
    return item_dir->postCondition(player);
}
