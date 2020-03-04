/* trainer.c
   �ΨӰV�m���a�ޯ઺npc
*/

#include <skill.h>
#include <ansi.h>

mapping train = ([]);

/* guild: muye   �츭�Ԫ̧�
      yinyin �����Ԫ̧�
      wuyin  �����Ԫ̧�
      shayin �����Ԫ̧�
      yuyin  �B���Ԫ̧�
      yunyin �����Ԫ̧�
      caoyin �����Ԫ̧�
      puyin  �r���Ԫ̧�
*/

int is_trainer() { return 1; }

mapping query_train() { return train; }

string skill_class(string skill)
{
    switch( SKILL_D(skill)->query_class() ) {
        // naruto
        case "force": return BRED"��N"NOR; break;
        case "ninja": return BBLU"�ԳN"NOR; break;

        // hunter
        case "psychical": return BWHT+BLK"����"NOR; break;
        case "concrete":  return BRED"��{"NOR; break;
        case "emit":      return BGRN"��X"NOR; break;
        case "operation": return BYEL"�ާ@"NOR; break;
        case "special":   return BBLU"�S��"NOR; break;
        case "strength":  return BMAG"�j��"NOR; break;
        case "variation": return BCYN"�ܤ�"NOR; break;

        // piece
        case "fruit":    return HIY"�G��"NOR; break;
        case "blade":    return BGRN"�M�N"NOR; break;
        case "spurn":    return BYEL"���"NOR; break;
        case "martial":  return BRED"�Z�N"NOR; break;
        case "activity": return REV"�S��"NOR; break;

        case "basic": return HIW"��"NOR; break;
        default: return HIK"�䥦"NOR; break;
    }
}

// �]�w��V�m���ޯ�
void set_train(string skill, int learn, int require, int upperbound)
{
    train[skill] = ([]);
    train[skill]["learn"] = learn;                // ���a�S���ӧޯ�ɡA�O�_�i�����߱o���ި�lv1
                                                  // ��lv���ޯ�~�i�H���I�~����m�C
                                                  // �i�Ω�S��ޡA�n�����o��lv���i�V�m�C
    train[skill]["require"] = require;            // �ǲߦ��ޯ�ݭn������
    train[skill]["upperbound"] = upperbound;      // ���ޯ�i�ǲߨ쪺�W��
}

// �]�w��V�m���ޯ�
void set_train_with_camp(string skill, int learn, int require, int upperbound, string camp, int camp_score)
{
    train[skill] = ([]);
    train[skill]["learn"] = learn;                // ���a�S���ӧޯ�ɡA�O�_�i�����߱o���ި�lv1
                                                  // ��lv���ޯ�~�i�H���I�~����m�C
                                                  // �i�Ω�S��ޡA�n�����o��lv���i�V�m�C
    train[skill]["require"] = require;            // �ǲߦ��ޯ�ݭn������
    train[skill]["upperbound"] = upperbound;      // ���ޯ�i�ǲߨ쪺�W��
    train[skill]["camp"] = camp;                  // �ݭn�Y�}�窺�n��~���
    train[skill]["camp_score"] = camp_score;      // �n��F��h�֤~���
}

int isTrain(object player, string sk, int tell)
{
    if( this_object()->query("guild") != "all" ) {
        if( this_object()->query("guild") != this_player()->query("guild") ) return 0;
    }

    // �ǲ߭���
    if( !undefinedp(train[sk]["learn"]) && !train[sk]["learn"] ) {
        if( !player->query_skill(sk) ) {
            if( tell ) tell_object(player, "�A�S���ǹL�o�ӧޯ�A�O�S��k�V�m���C\n");
            return 0;
        }
    }
    
    // ���ŭ���
    if( !undefinedp(train[sk]["require"]) ) {
        if( player->query_level() < train[sk]["require"] ) {
            if( tell ) tell_object(player, "�A�����ⵥ�Ť����A����V�m�o�ӧޯ�C\n");
            return 0;
        }
    }
    
    // �W������
    if( !undefinedp(train[sk]["upperbound"]) ) {
        if( player->query_skill(sk, 1) > train[sk]["upperbound"]) {
            if( tell ) tell_object(player, "�A���ޯ൥�w�g��F��V�m���W���A" + this_object()->query("name") + "�w�g�L�k�A�V�m�A�F�C\n");
            return 0;
        }
    }
    
    // �n�歭��
    if( !undefinedp(train[sk]["camp"]) ) {
        if( !player->hasCamp(train[sk]["camp"]) ) {
            if( tell ) tell_object(player, "�A�����n���}��u" + train[sk]["camp"] + "�v���n��~��i��V�m�C\n");
            return 0;
        }
        
        if( player->getCampScore(train[sk]["camp"]) < train[sk]["camp_score"]) {
            if( tell ) tell_object(player, "�A���}��u" + train[sk]["camp"] + "�v���n�椣���A�L�k�i��V�m�C\n");
        return 0;
        }
    }
    
    return 1;
}

string do_list()
{
    string msg, sk, *sks;

    if( this_object()->query("guild") != "all" ) {
        if( this_object()->query("guild") != this_player()->query("guild") )
            return "�A�����[��" + this_object()->query("name") + "���V�m�ޯ�C��C\n";
    }

    msg = "  " + this_object()->query("name") + "���ѰV�m���ޯ�C��\n";
    msg += "�~�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
    msg += "�x���O  �i�_�V�m  �ݨD����  �W��                                  �V�m�W���x\n";
    msg += "�u�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�t\n";

    sks = sort_array( keys(train) , (: train[$1]["require"] - train[$2]["require"] :));

    foreach( sk in sks ) {
    msg += sprintf("�x%s  %|8s  %|8d  %-37s %|8d�x\n",
               skill_class(sk),
               isTrain(this_player(), sk, 0) ? HIW"   �i   "NOR : HIR"   �_   "NOR,
//               train[sk]["learn"] ? HIW"   �i   "NOR : HIR"   �_   "NOR,
               train[sk]["require"],
               to_chinese(sk) + "(" + sk + ")",
               train[sk]["upperbound"] );
    }

    msg += "���w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";

    return msg;
}

int train_skill(object who, string sk, int time)
{
    int point, sklv, require, learn;

    if( !objectp(who) ) return 0;

    if( undefinedp(train[sk]) ) {
        tell_object(who, this_object()->query("name")+"�S���b���H�V�m " + sk + " �o�ӧޯ�C\n");
        return 1;
    }
    
    if( !isTrain(who, sk, 1) ) return 1;
    
    if( !who->skill_mapped(sk) ) {
        tell_object(who, "�A�o�ӧޯ�w�g disable �L�k�V�m�C\n");
        return 1;
    }
    if( !who->query_skill(sk) ) {
        tell_object(who, "�A�ثe�q�ӨS�ǹL�o�ӧޯ�A�b"+ this_object()->query("name") +"���оɫ�A�A�O��F�o�ӧޯ�F�C\n");
        tell_object(who, "(�Ĥ@���Ǩ�ޯ�O�S��k�V�m���A�аO�o�ϥ� advance ���O��ޯ��I�ơA�~�i�i��V�m�C)\n");
        who->set_skill(sk, 1);
        return 1;
    }
    
    point = who->query_point("learn");
    if( point < time ) {
        tell_object(who, "�A���ǲ��I�Ƥ����C\n");
        return 1;
    }

    sklv = who->query_skill(sk, 1);
    learn = who->query_learn(sk);
    require = who->query_skill_require(sk);

    if( require < learn + time*(who->query_level()) ) {
        time = (require-learn) / who->query_level();
        who->add_point("learn", -time );
        time ++;
    } else who->add_point("learn", -time);

    who->improve_skill(sk, time);
    sklv = who->query_skill(sk, 1);

    if( sklv >= (who->query_skill_ability(sk)*20) ) {
        message_vision("$N�V$n�ǲߦ���"+to_chinese(sk)+"�A�����G�J��F�~�V�C\n", who, this_object() );    
        tell_object(who, "(�A���ޯ���I�����H�A�ǲ߳o�ӧޯ�C)\n");
    } else if( who->query_skill_abandon(sk) ) {
        message_vision("$N�V$n�ǲߦ���"+to_chinese(sk)+"�A�����G�S��k�F�ѡC\n", who, this_object() );
        tell_object(who, "(�A�w�g����ǲ߳o���ޯ�A�ҥH�L�k��o����g��C)\n");
    } else message_vision("$N�V$n�ǲߦ���"+to_chinese(sk)+"�A���G�ᦳ�߱o���C\n", who, this_object() );
    return 1;
}
