/* trainer.c
   用來訓練玩家技能的npc
*/

#include <skill.h>
#include <ansi.h>

mapping train = ([]);

/* guild: muye   木葉忍者村
      yinyin 音隱忍者村
      wuyin  霧隱忍者村
      shayin 砂隱忍者村
      yuyin  雨隱忍者村
      yunyin 雲隱忍者村
      caoyin 草隱忍者村
      puyin  瀑隱忍者村
*/

int is_trainer() { return 1; }

mapping query_train() { return train; }

string skill_class(string skill)
{
    switch( SKILL_D(skill)->query_class() ) {
        // naruto
        case "force": return BRED"體術"NOR; break;
        case "ninja": return BBLU"忍術"NOR; break;

        // hunter
        case "psychical": return BWHT+BLK"念技"NOR; break;
        case "concrete":  return BRED"具現"NOR; break;
        case "emit":      return BGRN"放出"NOR; break;
        case "operation": return BYEL"操作"NOR; break;
        case "special":   return BBLU"特質"NOR; break;
        case "strength":  return BMAG"強化"NOR; break;
        case "variation": return BCYN"變化"NOR; break;

        // piece
        case "fruit":    return HIY"果實"NOR; break;
        case "blade":    return BGRN"刀術"NOR; break;
        case "spurn":    return BYEL"踢技"NOR; break;
        case "martial":  return BRED"武術"NOR; break;
        case "activity": return REV"特殊"NOR; break;

        case "basic": return HIW"基本"NOR; break;
        default: return HIK"其它"NOR; break;
    }
}

// 設定能訓練的技能
void set_train(string skill, int learn, int require, int upperbound)
{
    train[skill] = ([]);
    train[skill]["learn"] = learn;                // 當玩家沒有該技能時，是否可直接習得此技到lv1
                                                  // 有lv的技能才可以投點繼續鍛練。
                                                  // 可用於特殊技，要解謎得到lv後方可訓練。
    train[skill]["require"] = require;            // 學習此技能需要的等級
    train[skill]["upperbound"] = upperbound;      // 此技能可學習到的上限
}

// 設定能訓練的技能
void set_train_with_camp(string skill, int learn, int require, int upperbound, string camp, int camp_score)
{
    train[skill] = ([]);
    train[skill]["learn"] = learn;                // 當玩家沒有該技能時，是否可直接習得此技到lv1
                                                  // 有lv的技能才可以投點繼續鍛練。
                                                  // 可用於特殊技，要解謎得到lv後方可訓練。
    train[skill]["require"] = require;            // 學習此技能需要的等級
    train[skill]["upperbound"] = upperbound;      // 此技能可學習到的上限
    train[skill]["camp"] = camp;                  // 需要某陣營的聲望才能學
    train[skill]["camp_score"] = camp_score;      // 聲望達到多少才能學
}

int isTrain(object player, string sk, int tell)
{
    if( this_object()->query("guild") != "all" ) {
        if( this_object()->query("guild") != this_player()->query("guild") ) return 0;
    }

    // 學習限制
    if( !undefinedp(train[sk]["learn"]) && !train[sk]["learn"] ) {
        if( !player->query_skill(sk) ) {
            if( tell ) tell_object(player, "你沒有學過這個技能，是沒辦法訓練的。\n");
            return 0;
        }
    }
    
    // 等級限制
    if( !undefinedp(train[sk]["require"]) ) {
        if( player->query_level() < train[sk]["require"] ) {
            if( tell ) tell_object(player, "你的角色等級不夠，不能訓練這個技能。\n");
            return 0;
        }
    }
    
    // 上限限制
    if( !undefinedp(train[sk]["upperbound"]) ) {
        if( player->query_skill(sk, 1) > train[sk]["upperbound"]) {
            if( tell ) tell_object(player, "你的技能等已經到達到訓練的上限，" + this_object()->query("name") + "已經無法再訓練你了。\n");
            return 0;
        }
    }
    
    // 聲望限制
    if( !undefinedp(train[sk]["camp"]) ) {
        if( !player->hasCamp(train[sk]["camp"]) ) {
            if( tell ) tell_object(player, "你必須要有陣營「" + train[sk]["camp"] + "」的聲望才能進行訓練。\n");
            return 0;
        }
        
        if( player->getCampScore(train[sk]["camp"]) < train[sk]["camp_score"]) {
            if( tell ) tell_object(player, "你的陣營「" + train[sk]["camp"] + "」的聲望不足，無法進行訓練。\n");
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
            return "你不能觀看" + this_object()->query("name") + "的訓練技能列表。\n";
    }

    msg = "  " + this_object()->query("name") + "提供訓練的技能列表\n";
    msg += "╭────────────────────────────────────╮\n";
    msg += "│類別  可否訓練  需求等級  名稱                                  訓練上限│\n";
    msg += "├────────────────────────────────────┤\n";

    sks = sort_array( keys(train) , (: train[$1]["require"] - train[$2]["require"] :));

    foreach( sk in sks ) {
    msg += sprintf("│%s  %|8s  %|8d  %-37s %|8d│\n",
               skill_class(sk),
               isTrain(this_player(), sk, 0) ? HIW"   可   "NOR : HIR"   否   "NOR,
//               train[sk]["learn"] ? HIW"   可   "NOR : HIR"   否   "NOR,
               train[sk]["require"],
               to_chinese(sk) + "(" + sk + ")",
               train[sk]["upperbound"] );
    }

    msg += "╰────────────────────────────────────╯\n";

    return msg;
}

int train_skill(object who, string sk, int time)
{
    int point, sklv, require, learn;

    if( !objectp(who) ) return 0;

    if( undefinedp(train[sk]) ) {
        tell_object(who, this_object()->query("name")+"沒有在幫人訓練 " + sk + " 這個技能。\n");
        return 1;
    }
    
    if( !isTrain(who, sk, 1) ) return 1;
    
    if( !who->skill_mapped(sk) ) {
        tell_object(who, "你這個技能已經 disable 無法訓練。\n");
        return 1;
    }
    if( !who->query_skill(sk) ) {
        tell_object(who, "你目前從來沒學過這個技能，在"+ this_object()->query("name") +"的教導後，你記住了這個技能了。\n");
        tell_object(who, "(第一次學到技能是沒辦法訓練的，請記得使用 advance 指令投技能點數，才可進行訓練。)\n");
        who->set_skill(sk, 1);
        return 1;
    }
    
    point = who->query_point("learn");
    if( point < time ) {
        tell_object(who, "你的學習點數不足。\n");
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
        message_vision("$N向$n學習有關"+to_chinese(sk)+"，但似乎遇到了瓶頸。\n", who, this_object() );    
        tell_object(who, "(你的技能投點不足以再學習這個技能。)\n");
    } else if( who->query_skill_abandon(sk) ) {
        message_vision("$N向$n學習有關"+to_chinese(sk)+"，但似乎沒辦法了解。\n", who, this_object() );
        tell_object(who, "(你已經停止學習這項技能，所以無法獲得任何經驗。)\n");
    } else message_vision("$N向$n學習有關"+to_chinese(sk)+"，似乎頗有心得的。\n", who, this_object() );
    return 1;
}
