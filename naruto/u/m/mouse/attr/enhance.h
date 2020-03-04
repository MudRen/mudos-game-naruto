void die()
{
    object item = new(query("item_drop"));
    int i, j, corr=1;
    string new_name = "";
    string id = item->query("id");

    // �P�_ mob ���`�����ӼQ�X���F�謰��
    if( !query("item_drop") ) {
        ::die();
        return;
    }
    if( !objectp(item) ) {
        destruct(item);
        ::die();
        return;
    }
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
    if( item->query("wield_as") ) {
        mapping apply = item->query("apply_weapon/" + item->query("wield_as"));
        if( random(1000) < 5 ) {
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
                    id = "xuanwu " + id;
                    break;
            }
        }
        if( random(100) < 8 ) {
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
        if( new_name == "" ) {
            item->delete("apply_weapon");
        }
        if( new_name != "" ) {
            new_name += item->query("name") + NOR;
            item->set("name", new_name);
            item->set("id", id);
            item->set("apply_weapon/" + item->query("wield_as"), apply);
        }
    } else if( item->query("wear_as") ) {
        mapping apply = item->query("apply_armor/" + item->query("wear_as"));
        if( random(100) < 7 ) {
            switch( random(6) ) {
                case 0:
                    new_name += HIC "�n����";
                    apply["intimidate"] += 3*corr;
                    break;
                case 1:
                    new_name += HIC "�I�۪�";
                    apply["wittiness"] += 3*corr;
                    break;
                case 2:
                    new_name += HIC "���W��";
                    apply["exact"] += 3*corr;
                    break;
                case 3:
                    new_name += HIC "�F����";
                    apply["evade"] += 3*corr;
                    break;
                case 4:
                    new_name += HIC "í����";
                    apply["armor"] += 3*corr;
                    break;
                case 5:
                    new_name += HIC "���ɪ�";
                    apply["attack"] += 3*corr;
                    break;
            }
        }
        if( random(100) < 1 ) {
            switch( random(4) ) {
                case 0:
                    new_name += HIC "����";
                    apply["intimidate"] += 5*corr;
                    id = "Vulcan " + id;
                    break;
                case 1:
                    new_name += HIC "����";
                    apply["wittiness"] += 5*corr;
                    id = "Narcissus " + id;
                    break;
                case 2:
                    new_name += HIC "����";
                    apply["exact"] += 5*corr;
                    id = "Poseidon " + id;
                    break;
                case 3:
                    new_name += HIC "�s��";
                    apply["evade"] += 5*corr;
                    id = "Dionysus " + id;
                    break;
                case 4:
                    new_name += HIC "�ԯ�";
                    apply["attack"] += 5*corr;
                    id = "Mars " + id;
                    break;
                case 5:
                    new_name += HIC "�s��";
                    apply["armor"] += 5*corr;
                    id = "Nymphs " + id;
                    break;
            }
        }
        if( new_name == "" ) {
            item->delete("apply_armor");
        }
        if( new_name != "" ) {
            new_name += item->query("name") + NOR;
            item->set("name", new_name);
            item->set("id", id);
            item->set("apply_armor/" + item->query("wear_as"), apply);
        }
    }
    // �����~�Q�O�Э��n���ק��O
    item->set("changed", 1);

    // ���~�̫�A��b�a�W�A�����v�P�_
    if( query("molecule") ) i = query("molecule");
    else i = 1;

    if( query("denominator") ) j = random(query("denominator"))+1;
    else j = random(100)+1;

    // ���������b�a�W�A�^�����W���P�_�Ӧh
    if( i >= j ) {
        message_vision("$N�t�b���W��$n�]���渨�ӱ�����a���C\n"NOR, this_object(), item);
        if( environment(this_object())->is_area() ) move_side(item, this_object());
        else item->move(environment(this_object()));
    }
    ::die();
    return;
}
