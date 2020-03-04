/* �M�~�ޯ�A�����G���G
     1. �M�~�ޯ�G
     2. ���n�ޯ�G�����B�i���B���
*/

#define SK_DIR "/daemon/pro_skill/"
#define PRO_MAX 3

#include <ansi.h>
#include <dbase.h>

int *level_scope = ({ 75, 150, 225, 300, 375 });

mapping pro_sk = ([]);

mapping getProSkills() { return pro_sk; }

mapping getProSkill(string skill)
{
    if( undefinedp(pro_sk[skill]) ) return 0;
    return pro_sk[skill];
}

int getLevelScope(int level)
{
    int i;
    for(i=0; i<sizeof(level_scope); i++)
       if( level_scope[i] == level ) return i;
    return -1;
}

int getScopeLevel(int scope)
{
    if( scope < 0 || scope >= sizeof(level_scope) ) return -1;
    return level_scope[scope];
}

int getProSkillLevel(string skill)
{
    if( undefinedp(pro_sk[skill]) ) return 0;
    return pro_sk[skill]["level"];
}

// �[�J�@�ӷs���M�~�ޯ�
int addProSkill(string skill)
{
    if( sizeof(pro_sk) >= PRO_MAX ) return 0;
    if( !undefinedp(pro_sk[skill]) ) return 0;
    if( !PROSKILL_D->getProSkillFile(skill) ) return 0;

    pro_sk[skill] = ([]);
    pro_sk[skill]["level"] = 0;
    pro_sk[skill]["max_level"] = level_scope[0];
    pro_sk[skill]["item"] = ({});
    return 1;
}

// �����@�ӱM�~�ޯ�
int removeProSkill(string skill)
{
    if( undefinedp(pro_sk[skill]) ) return 0;
    map_delete(pro_sk, skill);
    tell_object(this_object(), "�A���M�~�ޯ� " + skill + " �w�g��ѤF�C\n");
    return 1;
}

// ���@�ӱM�~�ޯണ�ɤ@�Ӽh��
int upProSkill(string skill)
{
    int level;

    if( undefinedp(pro_sk[skill]) ) return 0;
    level = getLevelScope(pro_sk[skill]["max_level"]);
    if( level >= sizeof(level_scope)-1 ) return 0;
    if( !PROSKILL_D->getProSkillFile(skill) ) return 0;

    pro_sk[skill]["max_level"] = level_scope[level+1];
    tell_object(this_object(), HIY"�A���M�~�ޯ� " + PROSKILL_D->getProSkillName(skill) + "(" + skill + ") �����ŤW�����ɦ� " + level_scope[level+1] + " �šC\n"NOR);
    
    return 1;
}

// ���@�ӱM�~�ޯണ�ɤ@�ӵ���
int addProLevel(string skill)
{
    if( undefinedp(pro_sk[skill]) ) return 0;
    if( undefinedp(pro_sk[skill]["level"]) || undefinedp(pro_sk[skill]["max_level"]) ) return 0;
    if( pro_sk[skill]["level"] >= pro_sk[skill]["max_level"] ) return 0;
    if( !PROSKILL_D->getProSkillFile(skill) ) return 0;

    pro_sk[skill]["level"]++;
    tell_object(this_object(), HIY"�A���M�~�ޯ� " + PROSKILL_D->getProSkillName(skill) + "(" + skill + ") �����Ŵ��ɦ� " + pro_sk[skill]["level"] + " �šC\n"NOR);

    return 1;
}

// ���@�ӱM�~�ޯ�s�W�@�Ӳ��~
int addProItem(string skill, string item)
{
    if( undefinedp(pro_sk[skill]) ) return 0;

    // �ɮפ��s�b�A�άO���O�o�ӧޯ�U�����~
    if( !PROSKILL_D->getProItemFile(skill, item) ) return 0;

    // ���Ť����H�ǲ�
    if( PROSKILL_D->getLearnLevel(skill, item) > pro_sk[skill]["level"] ) return 0;

    // �w�g�ǹL
    if( member_array(item, pro_sk[skill]["item"]) != -1 ) return 0;

    // �ǲ�
    pro_sk[skill]["item"] += ({ item });

    return 1;
}

int removeProItem(string skill, string item)
{
    if( undefinedp(pro_sk[skill]) ) return 0;
    if( member_array(item, pro_sk[skill]["item"]) == -1 ) return 0;
    
    pro_sk[skill]["item"] -= ({ item });
    
    tell_object(this_object(), "�A��ѤF�s�@ " + item + " ���~����O�F�C\n");
    
    return 1;
}

private string getItemFile(object item)
{
    string file;
    if( !objectp(item) ) return "";
    file = file_name(item);
    if( sscanf(file, "%s#%*d", file) != 2 ) return "";
    return file + ".c";
}

private void destStuff(string skill, string item)
{
    object obj, *inv;
    mapping stuff;

    stuff = PROSKILL_D->getStuff(skill, item);
    inv = all_inventory(this_object());
    
    foreach(obj in inv) {
        string file = getItemFile(obj);
        
        // ���O����
        if( undefinedp(stuff[file]) ) continue;
        
        // �o�ӧ��Ƥw�g�T�w
        if( stuff[file] <= 0 ) continue;
        
        // �D�ƦX���~
        if( !function_exists("query_amount", obj) ) {
            destruct(obj);
            stuff[file] -= 1;
        // �ƦX���~
        } else {
            obj->set_amount(obj->query_amount()-stuff[file]);
            if( obj->query_amount() <= 0 )
            destruct(obj);
            stuff[file] = 0;
        }
    }
}

private void createProduct(string skill, string item)
{
    object product;
    
    product = PROSKILL_D->createProduct(skill, item);

    if( !objectp(product) ) return;

    if( PROSKILL_D->isBinding(skill, item) ) {
        product->set("change", 1);
        product->set("binding", this_object()->query("id"));
    }

    product->move(this_object());
}

private int isMake(string skill, string item)
{
    mapping stuff;
    string key, *kkey;
    object obj, *inv;

    if( !PROSKILL_D->getProSkillFile(skill) ) return 0;
    if( !PROSKILL_D->getProItemFile(skill, item) ) return 0;

    stuff = PROSKILL_D->getStuff(skill, item);
    
    inv = all_inventory(this_object());
    foreach(obj in inv) {
        string file = getItemFile(obj);
        
        // ���O����
        if( undefinedp(stuff[file]) ) continue;
        
        // �D�ƦX���~
        if( !function_exists("query_amount", obj) ) stuff[file] -= 1;
        // �ƦX���~
        else stuff[file] -= obj->query_amount();
    }
    
    kkey = keys(stuff);
    foreach(key in kkey) {
        if( stuff[key] > 0 ) return 0;
    }

    if( !PROSKILL_D->preCondition(skill, item, this_object()) ) return 0;

    destStuff(skill, item);
    createProduct(skill, item);

    message_vision(PROSKILL_D->getMakeMsg(skill, item), this_object());

    PROSKILL_D->postCondition(skill, item, this_object());

    return 1;
}

int make(string skill, string item)
{
    if( undefinedp(pro_sk[skill]) ) return 0;
    if( member_array(item, pro_sk[skill]["item"]) == -1 ) return 0;

    if( !isMake(skill, item) ) return 0;

    return 1;
}
