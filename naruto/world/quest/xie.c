#include <ansi.h>

void create() { seteuid(getuid()); }

int isQuest() { return 1; }
int isNewly() { return 0; }
string getName() { return "�H���q���L���p�v"; }

string getDetail() {
    string msg;
        
    msg  = "��~�ӯu�O�V�ӶV���F�A�q�汵��������...\n";
    msg += "�ɦץήƶV�ζV���A�����D���S���H�������j���O...\n";
    msg += "�����O�d�ɷj���Q���ɦסC\n";
    return msg;
}

int getLevel() { return 5; }
int preCondition(object player) { return 1; }
int postCondition(object player, object npc) { return 1; }

string getAssigner() { return "/world/area/whale_island/npc/tu-qian-xie.c"; }
string getRewarder() { return "/world/area/whale_island/npc/tu-qian-xie.c"; }

string *getAssignMessage() {
    string *msg = ({
        "$N���$n���D�G"HIG"��~�ӯu�O�V�ӶV���F�A�q�汵��������...\n"NOR,
        "$N���$n���D�G"HIG"�ɦץήƶV�ζV���A�����D���S���H�������j���O...\n"NOR,
    });        
    return msg;
}

mapping getKill() { return ([]); }

mapping getItem() {
    mapping item = ([
        "/world/area/whale_island/npc/food/crab_meat.c": 10,
    ]);
    return item;
}


// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G"HIG"�ګ����D�`���§A�������F�A�o�O�ڪ��@�I���S�A���¤F�C\n"NOR,
    });
        
    return msg;
}

string getReward()
{
    return "�@�d��Ȥl�C\n�G���I�ǲ��I�ơC\n";
}

void reward(object player, object npc) {
    player->add_point("learn", 200);
    tell_object(player, HIY"(�A��o�F 200 �I�ǲ��I�ơC)\n"NOR);
    player->add("bank", 1000);
    tell_object(player, HIY"(�A��o�F 1000 ��Ȥl�C)\n"NOR);
}
