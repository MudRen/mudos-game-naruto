#define CAMP_DIR "/world/camp/"
#include <ansi.h>

void create()
{
    seteuid(getuid());
}

string getCampFile(string camp)
{
    string camp_dir;
    camp_dir = CAMP_DIR + camp + ".c";
    if( file_size(camp_dir) == -1 || file_size(camp_dir) == -2 ) return 0;
    if( camp_dir->isCamp() == 0 ) return 0;
    return camp_dir;
}

string getCampName(string camp)
{
    string camp_dir;
    camp_dir = getCampFile(camp);
    if( !stringp(camp_dir) ) return "";
    return camp_dir->getName();
}

string *getFriendly(string camp)
{
    string camp_dir;
    camp_dir = getCampFile(camp);
    if( !stringp(camp_dir) ) return ({});

    return camp_dir->getFriendly();
}

string *getAdversely(string camp)
{
    string camp_dir;
    camp_dir = getCampFile(camp);
    if( !stringp(camp_dir) ) return ({});

    return camp_dir->getAdversely();
}

int getHate(string camp)
{
    string camp_dir;
    camp_dir = getCampFile(camp);
    if( !stringp(camp_dir) ) return 0;
    return camp_dir->getHat();
}

string getHateMsg(string camp)
{
    string camp_dir;
    camp_dir = getCampFile(camp);
    if( !stringp(camp_dir) ) return "";
    
    return camp_dir->getHateMsg();
}

int getAdvHate(string camp)
{
    string camp_dir;
    camp_dir = getCampFile(camp);
    if( !stringp(camp_dir) ) return 0;
    
    return camp_dir->getAdvHate();
}

string getAdvHateMsg(string camp)
{
    string camp_dir;
    camp_dir = getCampFile(camp);
    if( !stringp(camp_dir) ) return "";

    return camp_dir->getAdvHateMsg();
}
