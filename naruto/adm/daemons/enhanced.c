#include <ansi.h>
#include <combat.h>

string enhance_weapon(object ob, string weapon_type)
{
    int major = random(1000), minor = random(1000), corr=1;
    string new_name = "";
    string id = ob->query("id");
    mapping apply = ob->query("apply_weapon/" + weapon_type);

    switch( random(1000) ) {
        case 0..5:
            new_name += HIY"(�W�Z)";
            corr = 3;
            break;
        case 6..20:
            new_name += HIW"(���Z)";
            corr = 2;
            break;
    }
    if( major < 70 ) {
        switch( random(8) ) {
            case 0:
                new_name += HIC "�n����";
                apply["intimidate"] += 4 * corr;
                id = "active " + id;
                break;
            case 1:
                new_name += HIC "�I�۪�";
                apply["wittiness"] += 4 * corr;
                id = "sedate " + id;
                break;
            case 2:
                new_name += HIC "���W��";
                apply["exact"] += 4 * corr;
                id = "superb " + id;
                break;
            case 3:
                new_name += HIC "���t��";
                apply["evade"] += 4 * corr;
                id = "holy " + id;
                break;
            case 4:
                new_name += HIC "�F����";
                apply["move"] += 4 * corr;
                id = "nimble " + id;
                break;
            case 5:
                new_name += HIC "��Ԫ�";
                apply["carriage"] += 4 * corr;
                id = "firmness " + id;
                break;
            case 6:
                new_name += HIC "í����";
                apply["armor"] += 4 * corr;
                id = "steady " + id;
                break;
            case 7:
                new_name += HIC "���ɪ�";
                apply["attack"] += 4 * corr;
                id = "tiger " + id;
                break;
        }
    }
    if( minor < 5 ) {
        switch( random(4) ) {
            case 0:
                new_name += HIG "�C�s";
                apply["con"] += 3*corr;
                id = "qinglong " + id;
                break;
            case 1:
                new_name += HIR "����";
                apply["int"] += 3*corr;
                id = "zhuque " + id;
                break;
            case 2:
                new_name += HIW "�ժ�";
                apply["str"] += 3*corr;
                id = "baihu " + id;
                break;
            case 3:
                new_name += HIB "�ȪZ";
                apply["dex"] += 3*corr;
                id = " xuanwu " + id;
                break;
        }
    } else if( minor < 20 ) {
        switch( random(2) ) {
            case 0:
                new_name += HIY "�ĳ�";
                apply["con"] += 1*corr;
                apply["int"] += 1*corr;
                id = "gouchen " + id;
                break;
            case 1:
                new_name += HIM "�f�D";
                apply["str"] += 1*corr;
                apply["dex"] += 1*corr;
                id = "yishe " + id;
                break;
        }
    } else if( minor < 80 ) {
        switch( random(4) ) {
            case 0:
                new_name +=  "����";
                apply["con"] += 1*corr;
                break;
            case 1:
                new_name +=  "�ҩ�";
                apply["int"] += 1*corr;
                break;
            case 2:
                new_name +=  "�a�a";
                apply["str"] += 1*corr;
                break;
            case 3:
                new_name +=  "�{�x";
                apply["dex"] += 1*corr;
                break;
        }
    }
    if( new_name == "" ) return ob->name();
    if( new_name != "" ) {
        new_name += ob->query("name") + NOR;
        ob->set("name", new_name);
        ob->set("id", id);
        ob->set("apply_weapon/" + weapon_type, apply);
        return new_name;
    }
    return ob->name();
}

// �t���r���B�r�����˳�
string enhance_armor(object ob, string armor_type)
{
    int major = random(1000), minor = random(1000), corr=1;
    string new_name = "";
    string id = ob->query("id");
    mapping apply = ob->query("apply_armor/" + armor_type);

    switch( random(1000) ) {
        case 0..5:
            new_name += HIY"(�W�Z)";
            corr = 3;
            break;
        case 6..20:
            new_name += HIW"(���Z)";
            corr = 2;
            break;
    }
    if( major < 70 ) {
        switch( random(8) ) {
            case 0:
                new_name += HIC "�n����";
                apply["intimidate"] += 4 * corr;
                id = "active " + id;
                break;
            case 1:
                new_name += HIC "�I�۪�";
                apply["wittiness"] += 4 * corr;
                id = "sedate " + id;
                break;
            case 2:
                new_name += HIC "���W��";
                apply["exact"] += 4 * corr;
                id = "superb " + id;
                break;
            case 3:
                new_name += HIC "���t��";
                apply["evade"] += 4 * corr;
                id = "holy " + id;
                break;
            case 4:
                new_name += HIC "�F����";
                apply["move"] += 4 * corr;
                id = "nimble " + id;
                break;
            case 5:
                new_name += HIC "��Ԫ�";
                apply["carriage"] += 4 * corr;
                id = "firmness " + id;
                break;
            case 6:
                new_name += HIC "í����";
                apply["armor"] += 4 * corr;
                id = "steady " + id;
                break;
            case 7:
                new_name += HIC "���ɪ�";
                apply["attack"] += 4 * corr;
                id = "tiger " + id;
                break;
        }
    }
    if( minor < 5 ) {
        switch( random(4) ) {
            case 0:
                new_name += HIG "�C�s";
                apply["con"] += 3*corr;
                id = "qinglong " + id;
                break;
            case 1:
                new_name += HIR "����";
                apply["int"] += 3*corr;
                id = "zhuque " + id;
                break;
            case 2:
                new_name += HIW "�ժ�";
                apply["str"] += 3*corr;
                id = "baihu " + id;
                break;
            case 3:
                new_name += HIB "�ȪZ";
                apply["dex"] += 3*corr;
                id = " xuanwu " + id;
                break;
        }
    } else if( minor < 20 ) {
        switch( random(2) ) {
            case 0:
                new_name += HIY "�ĳ�";
                apply["con"] += 1*corr;
                apply["int"] += 1*corr;
                id = "gouchen " + id;
                break;
            case 1:
                new_name += HIM "�f�D";
                apply["str"] += 1*corr;
                apply["dex"] += 1*corr;
                id = "yishe " + id;
                break;
        }
    } else if( minor < 80 ) {
        switch( random(4) ) {
            case 0:
                new_name +=  "����";
                apply["con"] += 1*corr;
                break;
            case 1:
                new_name +=  "�ҩ�";
                apply["int"] += 1*corr;
                break;
            case 2:
                new_name +=  "�a�a";
                apply["str"] += 1*corr;
                break;
            case 3:
                new_name +=  "�{�x";
                apply["dex"] += 1*corr;
                break;
        }
    }
    if( new_name == "" ) return ob->name();
    if( new_name != "" ) {
        new_name += ob->query("name") + NOR;
        ob->set("name", new_name);
        ob->set("id", id);
        ob->set("apply_armor/" + armor_type, apply);
        return new_name;
    }
    return ob->name();
}
