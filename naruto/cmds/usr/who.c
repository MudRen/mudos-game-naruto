/*  who.c write by -Acme-
*/

#include <ansi.h>

inherit F_CLEAN_UP;

object *all, *target;
string msg;
int i, j;

void msg_format(string arg);

void create() { seteuid(getuid()); }

mixed main(object me, string arg, int remote)
{
    int center_lv;
    string tmp;
    target = ({});
    msg = "";

    /* 先過濾尚未登入完成的使用者，與隱形的上級巫師。
     * 注意在被 rwho_q 呼叫的狀況下，this_player() 為 0。
     */
    if( this_player(1) )
        all = filter(users(), (: objectp(environment($1)) &&
                                 (!wizardp($1) || wiz_level($2)>wiz_level($1) || $1->visible($2)) :), this_player(1));
    else all = filter(users(), (: objectp(environment($1)) && !wizardp($1) :));

    i = sizeof(all);
    
    if( !arg || arg=="" ) {
	    center_lv = me->query_level();
        while( i-- ) {
            if( all[i]->query_level() - center_lv < 6 && center_lv - all[i]->query_level() < 6 && !wizardp(all[i]) )
                target += ({ all[i] });
        }
        msg_format("1");
    } else {
        switch(arg){
            case "-mu":
        		target = filter(all, (: $1->query("guild")=="muye" :));     // 木葉村
                msg_format("5");
                break;
            case "-yi":
        		target = filter(all, (: $1->query("guild")=="yinyin" :));   // 音隱村
                msg_format("5");
                break;
            case "-wn":
        		target = filter(all, (: $1->query("guild")=="wuyin" :));    // 霧隱村
                msg_format("5");
                break;
            case "-sn":
        		target = filter(all, (: $1->query("guild")=="shayin" :));   // 砂隱村
                msg_format("5");
                break;
            case "-yn":
        		target = filter(all, (: $1->query("guild")=="yuyin" :));    // 雨隱村
                msg_format("5");
                break;
            case "-yy":
        		target = filter(all, (: $1->query("guild")=="yunyin" :));   // 雲隱村
                msg_format("5");
                break;
            case "-cn":
        		target = filter(all, (: $1->query("guild")=="caoyin" :));   // 草隱村
                msg_format("5");
                break;
            case "-pn":
        		target = filter(all, (: $1->query("guild")=="puyin" :));    // 瀑隱村
                msg_format("5");
                break;
        	case "-cr":
        		target = filter(all, (: $1->query_class()=="commoner" :));  // 平民
                msg_format("5");
        		break;
            case "-ir":
                target = filter(all, (: $1->query_class()=="inferior" :));  // 下忍
                msg_format("5");
                break;
            case "-me":
                target = filter(all, (: $1->query_class()=="middle" :));    // 中忍
                msg_format("5");
                break;
            case "-sr":
                target = filter(all, (: $1->query_class()=="superior" :));  // 上忍
                msg_format("5");
                break;
            case "-an":
                target = filter(all, (: $1->query_class()=="assassin" :));  // 暗忍
                msg_format("5");
                break;
            case "-pe":
                target = filter(all, (: $1->query_class()=="police" :));    // 警部
                msg_format("5");
                break;
            case "-mh":
                target = filter(all, (: $1->query_class()=="monarch" :));   // 影忍
                msg_format("5");
                break;
            case "-h":
                target = filter(all, (: $1->query("guild")=="hunter" :));   // 獵人
                msg_format("5");
                break;
            case "-l":
                target = all;
                msg_format("5");
                break;
            case "-w":
	            target = filter(all, (: wizardp :));
                msg_format("5");
                break;
            case "-i":
                msg_format("41");
                break;
            case "-n":
                msg_format("42");
                break;
	        default :
	            return notify_fail("請輸入 help who 了解指令格式。\n");
        }
    }

    tmp = msg;
//    tmp += sprintf("│共列出 %3d/%3d 位使用者  系統負荷：%-37s│\n",  sizeof(target), sizeof(all), query_load_average());
    tmp += sprintf("│%-72s│\n", "共列出 " + sizeof(target) + "/" + sizeof(all) + " 位使用者  系統負荷：" + query_load_average());
    tmp += "╰────────────────────────────────────╯";
    
    if( remote ) return tmp;

    me->start_more(tmp);
    return 1;
}

int sort_user(object ob1, object ob2)
{
    int ord;

    ord = wiz_level(ob1) - wiz_level(ob2);
    if( ord==0 )
        ord = (int)ob1->query_level() - (int)ob2->query_level();
    if( ord == 0 )
        ord = ob1->query_score("combat exp") - ob2->query_score("combat exp");
    return ord;
}

void msg_format(string arg)
{
	string tmp, ntmp;
    if( !arg || arg=="" )    return;

    j = sizeof(target);
    target = sort_array(target, "sort_user", this_object());

    switch(arg){
    case "1":
    case "5":
    case "50":
        msg  = "╭────────────────────────────────────╮\n";
        msg += sprintf("│%-72s│\n", MUD_NAME+"線上玩家列表" );
        msg += "├────────────────────────────────────┤\n";
        msg += "│"BYEL"等級"NOR" "BRED"  職    業  "NOR" "BGRN"  頭      銜  "NOR" "BMAG"  匿      稱  "NOR" "BBLU"        名稱(ID)        "NOR"│\n";

        while( j-- ) {
        	if( target[j]->query("nickname") ) ntmp = uncolor(target[j]->query("nickname"));
        	else ntmp = "";
            tmp = sprintf("│%|4d %s%|12s"NOR" %|14s %|14s %12s%-12s│\n"NOR,
                  target[j]->query_level(),
                  wizardp(target[j]) ? BOLD : NOR,
                  target[j]->rank(),
                  target[j]->query("title") ? target[j]->query("title") : "",
                  ntmp,
                  target[j]->query("name", 1),
                  "(" + capitalize(target[j]->query("id")) + ")" );
            if( ntmp != "" ) tmp = replace_string(tmp, ntmp, target[j]->query("nickname"));
            msg += tmp;
/*
            msg = sprintf("%s│%|4d %s%|12s"NOR" %|14s %|14s %12s%-12s│\n"NOR,
                  msg,
                  target[j]->query_level(),
                  wizardp(target[j]) ? BOLD : NOR,
                  target[j]->rank(),
                  target[j]->query("title") ? target[j]->query("title") : "",
                  target[j]->query("nickname") ? target[j]->query("nickname") : "",
                  target[j]->query("name", 1),
                  "(" + capitalize(target[j]->query("id")) + ")" );
*/
        }
        msg += "├────────────────────────────────────┤\n";

        break;
    case "41":
        target = sort_array(all, "sort_user", this_object());
        j = sizeof(target);
        msg  = "╭────────────────────────────────────╮\n";
        msg += sprintf("│%-72s│\n", MUD_NAME+"線上玩家列表" );
        msg += "╰────────────────────────────────────╯\n";

        while( j-- ) {
            msg = sprintf("%s  %-10s%s", msg, capitalize(target[j]->query("id")), (( i - j ) % 6 ) ? "" : "\n" );
        }
        if( i % 6 ) msg += "\n";
        msg += "╭────────────────────────────────────╮\n";
        break;
    case "42":
        target = sort_array(all, "sort_user", this_object());
        j = sizeof(target);
        msg  = "╭────────────────────────────────────╮\n";
        msg += sprintf("│%-72s│\n", MUD_NAME+"線上玩家列表" );
        msg += "╰────────────────────────────────────╯\n";
        while( j-- ) {
            msg = sprintf("%s  %-12s%s", msg, target[j]->query("name", 1), (( i - j ) % 6 ) ? "" : "\n" );
        }
        if( i % 6 ) msg += "\n";
        msg += "╭────────────────────────────────────╮\n";
        break;
    default:
        msg = "請輸入 help who 了解指令格式。\n";
    }
}

int help(object me)
{
    write(@HELP
指令格式 : who [選項]

這個指令可以列出在線上的使用者及其等它相關資訊。
選項有下列幾種, 一次只可使用一種選項, 即 who -i -w 視同 who -i。
無選項時, 列出與你等級相差 5 級以內之使用者。

一般選項：
  -w  只列出巫師                     -l  列出所有使用者
  -n  只列出中文名稱                 -i  只列出英文ID

職業選項：
  -cr 列出所有平民(commoner)         -ir 列出所有下忍(inferior)
  -me 列出所有中忍(middle)           -sr 列出所有上忍(superior)
  -an 列出所有暗部(assassin)         -pe 列出所有警部(police)
  -mh 列出所有影忍(monarch)

  -h 列出所有獵人

忍者村選項：
  -mu 列出所有木葉村忍者(muye)       -yi 列出所有音隱村忍者(yinyin)
  -wn 列出所有霧隱村忍者(wuyin)      -sn 列出所有砂隱村忍者(shayin)
  -yn 列出所有雨隱村忍者(yuyin)      -yy 列出所有雲隱村忍者(yunyin)
  -cn 列出所有草隱村忍者(caoyin)     -pn 列出所有瀑隱村忍者(puyin)

相關指令： finger
HELP);
    return 1;
}
