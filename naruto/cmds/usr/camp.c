/* camp.c
*/

#define CAMP_DIR "/world/camp/"
#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

private int getRankMax(int rank)
{
    if( rank == 4 ) return 75000;
    else if( rank == 3 ) return 35000;
    else if( rank == 2 ) return 15000;
    else if( rank == 1 ) return 6000;
    else if( rank == 0 ) return 100;
    else if( rank == -1 ) return -101;
    else if( rank == -2 ) return -6001;
    else if( rank == -3 ) return -15001;
    else if( rank == -4 ) return -35001;
}

private int getRankMin(int rank)
{
    if( rank == 4 ) return 35001;
    else if( rank == 3 ) return 15001;
    else if( rank == 2 ) return 6001;
    else if( rank == 1 ) return 101;
    else if( rank == 0 ) return -100;
    else if( rank == -1 ) return -6000;
    else if( rank == -2 ) return -15000;
    else if( rank == -3 ) return -35000;
    else if( rank == -4 ) return -75000;
}

private string getRankName(int rank)
{
    if( rank == 4 ) return HIW"[崇拜]"NOR;
    else if( rank == 3 ) return HIY"[崇敬]"NOR;
    else if( rank == 2 ) return HIG"[尊敬]"NOR;
    else if( rank == 1 ) return GRN"[友好]"NOR;
    else if( rank == 0 ) return "[中立]";
    else if( rank == -1 ) return HIK"[冷淡]"NOR;
    else if( rank == -2 ) return CYN"[敵視]"NOR;
    else if( rank == -3 ) return MAG"[敵對]"NOR;
    else if( rank == -4 ) return RED"[恨仇]"NOR;
    return "";
}

private string getCampName(string camp)
{
    string dir, name;

    dir = CAMP_DIR + camp + ".c";
    if( file_size(dir) == -1 || file_size(dir) == -2 ) name = "未知";
    else name = dir->getName();
    
    name += "(" + camp + ")";
    
    return name;
}

private string getHead(string name)
{
    string str = "";
    str += "╭───────────────╮\n";
    str += sprintf("│%|30s│\n", name);
    str += "├───────────────┴──────────────────────────╮\n";
    return str;
}

private string getBar(int rank, int value)
{
int min, max, rank_min, rank_max;
    string bar;
    
    bar = sprintf("%|40s", ""+value);

    rank_min = getRankMin(rank);
    rank_max = getRankMax(rank);
    
    min = value - rank_min;
    max = rank_max - rank_min;
    
    if( rank == 0 )
        bar = sprintf("%s%s", LINE + BYEL + bar[0..(min*40/max)] + NOR, LINE + BBLU + bar[(min*40/max)+1..39] + NOR);
    else if( rank >= 1 )
        bar = sprintf("%s%s", LINE + BGRN + bar[0..(min*40/max)] + NOR, LINE + BBLU + bar[(min*40/max)+1..39] + NOR);
    else bar = sprintf("%s%s", LINE + BBLU + bar[0..(min*40/max)] + NOR, LINE + BRED + bar[(min*40/max)+1..39] + NOR);
    
    bar = sprintf("%+6s%s%-6s"NOR, ""+rank_min, bar, ""+rank_max);
    
    return bar;
}

private string getBody(mapping camps, object player)
{
int i, rank, *value;
    string *key, line, msg = "";

    key = keys(camps);
    value = values(camps);

    for(i=0; i<sizeof(key); i++) {
    rank = player->getCampScore(key[i]);
    msg += sprintf("│%s %-24s %s│\n", getRankName(rank), getCampName(key[i]), getBar(rank, value[i]));
    }
    
    return msg;
}

private string getTail()
{
    return "╰──────────────────────────────────────────╯\n";
}

private void list(object player)
{
    string msg;
    mapping camps;
    
    camps = player->getCamps();
    if( !mapp(camps) ) return;
    
    msg = getHead("陣營聲望");
    msg += getBody(camps, player);
    msg += getTail();
    
    write(msg);
}

int main(object me, string arg)
{
    object player;
    string who, sk;

    if( !arg || !wizardp(me) ) {
        list(me);
        return 1;
    }
    
    player = find_player(arg);
    if( !objectp(player) ) return notify_fail("沒有這個玩家。\n");
    list(player);
    
    return 1;
}

int help(object me)
{
    write(@HELP
指令格式： camp           列出所有陣營的聲望

   崇拜      35001 ~ 75000
   崇敬      15001 ~ 35000
   尊敬       6001 ~ 15000
   友好        101 ~ 6000
   中立       -100 ~ 100
   冷淡       -101 ~ -6000
   敵視      -6001 ~ -15000
   敵對     -15000 ~ -35000
   仇恨     -35000 ~ -75000
HELP);

if( wizardp(me) ) {
    write(@HELP

巫師指令： camp <id>      列出某玩家所有陣營的聲望
HELP);
}

    return 1;
}
