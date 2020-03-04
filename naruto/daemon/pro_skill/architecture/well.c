/* ���� well.c
*/

#include <ansi.h>

// �ݩ�ؿv�ǧޯ�U�����~
string getProSkill() { return "architecture"; }

// �߱o�����~���n���ޯ൥��
int getLearnLevel() { return 0; }

// ���~�W��
string getName() { return "����"; }

// ²�z
string getBrief() {
    return "�b�a�W���@�f����...";
}

// �ԭz
string getDetail() {
    string msg = "";
    msg += "�A�i�H���N���b���X�k�ئa���a����@�f���A�ðV�m�A���ؿv�ǧޥ�\n";
    msg += "�̰���G�Q�šA�ڻ����X�Ӫ������S���ĥ�...\n";
    msg += "\n";
    msg += "�����������O�G\n";
    msg += "    1. short,  �]�w�������u�ԭz�C(�̪��Q�Ӧr��)\n";
    msg += "    2. long,  �]�w���������ԭz�C(�̪����Q�Ӧr��, �ϥ�to long�ĪG�̦n)\n";
    msg += "    3. drink, ����ӳܡA�ڻ������_���ĪG�C(�@�p�ɤ@��)\n";
    msg += "\n";
    msg += "�سy�ݨD�G\n";
    msg += "    �ǲ��I�� 10000 �I�C\n";
    msg += "\n";
    return msg;
}

// �s�y�����~�һݪ�����
mapping getStuff() {
    mapping stuff = ([
        "/world/area/wizard/npc/obj/shovel.c": 3,  // ��l
    ]);
    return stuff;
}

// �s�y�����~��
string getProduct() {
    return 0;
}

// �s�y���~�ɪ��T��
string makeMsg()
{
    return "$N���_���W����l�A����@��A�k��@��A�L���٫r�ۤ@��A�ۥH���O���������a�W�g���C\n";
}

// ���~�O�_�j�w(�]�N�O�s�y���H�~���), (1:�O, 0:�_)
// ���G�j�w�����~�̦n�O����X�֪����~�A�_�h�j�w�|�V��
//     �j�w�����~�W�|�]�w set("binding", ����id)
//     �ҥH�n�P�_�Ӳ��~�O�_��Q�ϥδN�O�ˬd binding �O�_�ŦX���a��id�N��F
int isBinding() { return 0; }

// �i�H�ۭq�s�@����
int preCondition(object player)
{
int x, y;
    if( !environment(player) ) return 0;
    
    if( player->query_point("learn") < 10000 ) {
        tell_object(player, "�A���ǲ��I�Ƥ��� 10000 �L�k�ϥΫ����ޥ��C\n");
        return 0;
    }

    if( !environment(player)->is_area() ) {
    tell_object(player, "�A����b�o�̫���...\n");
        return 0;
    }
    x = player->query("area_info/x_axis");
    y = player->query("area_info/y_axis");
    
    if( !environment(player)->createBuilding("well_11_eswn", player->query_id(), x, y) ) {
        tell_object(player, "�A�S����k�b�o�̫���...\n");
        return 0;
    }
    
    player->add_point("learn", -10000);
    player->save();
    
    return 1;
}

// �i�H�ۭq�s�@��ĪG
int postCondition(object player)
{
    message_vision(HIW"$N�u�ΤF�T����l�N���X�F�@�f���A��b�O�ӯ��_�F�I�I\n"NOR, player);

    // �j��20�Ť��ണ��
    if( player->getProSkillLevel("architecture") < 20 ) 
        player->addProLevel("architecture");

    return 1;
}
