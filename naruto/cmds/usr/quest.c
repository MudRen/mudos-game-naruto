/* quest.c wirte by -Acme-
 */

#include <ansi.h>
inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

string getKill(object me, string quest_file)
{
    string *key, msg;
    int i, *value, size;
    mapping require;
    object ob;

    require = quest_file->getKill();

    if( !mapp(require) ) return "";

    key = keys(require);
    value = values(require);
    size = sizeof(key);

    if( !size ) return "";

    msg = "\n�w�����G\n";
    for(i=0;i<size;i++) {
        if( !objectp(ob = load_object(key[i])) ) continue;
        if( me->getKilled(quest_file, key[i]) >= value[i] )
            msg += sprintf("  %s(%s)�G %s\n"NOR, HIK+ob->name(), HIK+ob->query("id"), HIK+me->getKilled(quest_file, key[i])+"/"+value[i] );
        else 
            msg += sprintf("  %s(%s)�G %d/%d\n", ob->name(), ob->query("id"), me->getKilled(quest_file, key[i]), value[i] );

       destruct(ob);
    }

    return msg;
}

string getItem(object me, string quest_file)
{
    string *key, msg;
    int i, *value, size;
    mapping require;
    object ob;

    require = quest_file->getItem();
    if( !mapp(require) ) return "";

    key = keys(require);
    value = values(require);
    size = sizeof(key);

    if( !size ) return "";

    msg = "\n�w���o�G\n";
    for(i=0;i<size;i++) {
        if( !objectp(ob = load_object(key[i])) ) continue;
        if( me->getItem(quest_file, key[i]) >= value[i] )
            msg += sprintf("  %s(%s)�G %s\n"NOR, HIK+ob->name(), HIK+ob->query("id"), HIK+me->getItem(quest_file, key[i])+"/"+value[i] );
        else
            msg += sprintf("  %s(%s)�G %d/%d\n", ob->name(), ob->query("id"), me->getItem(quest_file, key[i]), value[i] );

        destruct(ob);
    }

    return msg;
}

void detail(object me, int index)
{
    int i, size;
    string *key, msg;
    mapping toDoList;

    toDoList = me->getToDoList();

    if( !mapp(toDoList) ) return;

    key = keys(toDoList);
    size = sizeof(key);
    
    if( !size ) return;
    if( index < 1 || index >= size+1 ) return;
    
    msg  = HIY"�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n"NOR;
   msg += sprintf("%-60s\n", key[index-1]->getName() + (wizardp(this_player()) ? " " + key[index-1] : ""));
    msg += HIY"�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n\n"NOR;
    msg += key[index-1]->getDetail();
    msg += getKill(me, key[index-1]);
    msg += getItem(me, key[index-1]);
    msg += "\n���ȼ��y�G\n";
    msg += key[index-1]->getReward() + "\n";
    msg += HIY"�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n"NOR;
    
    write(msg);
}

void list(object me)
{
    int i, size;
    string *key, msg;
    mapping toDoList;

    toDoList = me->getToDoList();

   if( !mapp(toDoList) ) return;

    key = keys(toDoList);
    size = sizeof(key);
    
    msg  = HIB"�~��������������������������������������������������������������\n"NOR;
    msg += HIB"��                                                            ��\n"NOR;
     msg += sprintf(HIB"��"NOR"%-54s %2d/40"HIB"��\n"NOR, "���Ȥ�x", size);
    msg += HIB"��                                                            ��\n"NOR;
    msg += HIB"����������������������������������������������������������������\n"NOR;
    msg += HIB"��                                                            ��\n"NOR;
    msg += HIB"��"NOR"�s��  ����  ����                                            "HIB"��\n"NOR;
    msg += HIB"��"HIY"�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w"HIB"��\n"NOR;
    for(i=0;i<size;i++) {
    msg += sprintf(HIB"��"NOR" %2d    %2d   %-48s"HIB"��\n"NOR, i+1, key[i]->getLevel(), key[i]->getName());
    }
    msg += HIB"��"HIY"�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w"HIB"��\n"NOR;
    msg += sprintf(HIB"��"NOR"%60s"HIB"��\n"NOR, me->name()+" �I  ");
    msg += HIB"����������������������������������������������������������������\n"NOR;
    
    write(msg);
}

void giveup(object me, int index)
{
    int i, size;
    string *key;
    mapping toDoList;

    toDoList = me->getToDoList();

    if( !mapp(toDoList) ) return;

    key = keys(toDoList);
    size = sizeof(key);
    
    if( !size ) return;
    if( index < 1 || index >= size+1 ) return;
    
    write("�A���F " + key[index-1]->getName() + " ���ȡC\n");
    me->delToDo(key[index-1]);
}

void listSolved(object me)
{
    int i, size;
    string *solved, msg;
        
    solved = me->getSolved();
    size = sizeof(solved);
    
    msg  = HIB"�~��������������������������������������������������������������\n"NOR;
    msg += HIB"��                                                            ��\n"NOR;
    msg += sprintf(HIB"��"NOR"%-60s"HIB"��\n"NOR, "�w���������ȦC��");
    msg += HIB"��                                                            ��\n"NOR;
    msg += HIB"����������������������������������������������������������������\n"NOR;
    msg += HIB"��                                                            ��\n"NOR;
    msg += HIB"��"NOR"�s��  ����  ����                                            "HIB"��\n"NOR;
    msg += HIB"��"HIY"�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w"HIB"��\n"NOR;
    for(i=0;i<size;i++) {
    msg += sprintf(HIB"��"NOR"%s%3d   %2d   %-48s"HIB"��\n"NOR, solved[i]->isNewly() ? "*" : " ", i+1, solved[i]->getLevel(), solved[i]->getName());
    }
    msg += HIB"��"HIY"�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w"HIB"��\n"NOR;
    msg += sprintf(HIB"��"NOR"%60s"HIB"��\n"NOR, me->name()+" �I  ");
    msg += HIB"����������������������������������������������������������������\n"NOR;
    
    write(msg);
}

void solvedDetail(object me, int index)
{
    int i, size;
    string *solved, msg;

    solved = me->getSolved();
    size = sizeof(solved);
    
    if( !size ) return;
    if( index < 1 || index >= size+1 ) return;
    
    msg  = HIY"�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n"NOR;
    msg += sprintf("%-60s\n", solved[index-1]->getName());
    msg += HIY"�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n\n"NOR;
    msg += solved[index-1]->getDetail();
    msg += getKill(me, solved[index-1]);
    msg += getItem(me, solved[index-1]);
    msg += "\n���ȼ��y�G\n";
    msg += solved[index-1]->getReward() + "\n";
    msg += HIY"�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n"NOR;
    
    write(msg);
}

int main(object me, string arg)
{
    int index;
    string id, control;
    object player;

    if( !arg ) list(me);
    else {
        if( sscanf(arg, "%s %d -%s", id, index, control) == 3 ) {
            player = find_player(id);
            if( !objectp(player) ) return notify_fail("�S���o�Ӫ��a�C\n");
            if( control != "s" ) return notify_fail("�S���o�ӱ���@�C\n");
            solvedDetail(player, index);
        } else if( sscanf(arg, "%d -%s", index, control) == 2 ) {
            if( control == "d" ) giveup(me, index);
            else if( control == "s" ) solvedDetail(me, index);
            else return notify_fail("�S���o�ӱ���@�C\n");
        
        } else if( sscanf(arg, "%s -%s", id, control) == 2 && wizardp(me) ) {
            player = find_player(id);
            if( !objectp(player) )
                return notify_fail("�S���o�Ӫ��a�C\n");
            if( control != "s" ) return notify_fail("�S���o�ӱ���@�C\n");
            listSolved(player);
        } else if( sscanf(arg, "%s %d", id, index) == 2 && wizardp(me) ) {
            player = find_player(id);
            if( objectp(player) ) detail(player, index);
            else return notify_fail("�S���o�Ӫ��a�C\n");
        } else if( sscanf(arg, "%d", index) == 1 ) {
            detail(me, index);
        } else if( sscanf(arg, "-%s", control) == 1 ) {
            if( control != "s" ) return notify_fail("�S���o�ӱ���@�C\n");
            listSolved(me);
        } else if( sscanf(arg, "%s", id) == 1 && wizardp(me) ) {
            player = find_player(id);
            if( objectp(player) ) list(player);
            else return notify_fail("�S���o�Ӫ��a�C\n");
        } else return notify_fail("�A�n�d���@�ӽs�������ȡH\n");
    }

    return 1;
}

int help(object me)
{
    write(@HELP
���O�榡�G
    1. quest              �C�X���������ȦC��
    2. quest <�s��>       ��ܥ��Ȼ���
    3. quest <�s��> -d    ���Y�ӽs��������
    4. quest -s           �C�X�w�ѨM������ (�Y���Ȧ����O*��ܥi���Ƹ�)
    5. quest <�s��> -s    �˥ܤw�ѨM�����Ȼ���
HELP);

if( wizardp(me) ) {
    write(@HELP

�Ův���O�G
    1. quest <id>             �C�X�Y���a���������ȦC��
    2. quest <id> <�s��>      �C�X�Y���a���Ȼ���
    3. quest <id> -s          �C�X�Y���a�w�ѨM������ (�Y���Ȧ����O*��ܥi���Ƹ�)
    4. quest <id> <�s��> -s   �˥ܬY���a�w�ѨM�����Ȼ���
HELP);
}

    return 1;
}
