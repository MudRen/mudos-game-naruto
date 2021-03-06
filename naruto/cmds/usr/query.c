
/* query.c wirte by -Acme-
*/

#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

//inherit "/adm/daemons/itemd.c";

int sort_comp(string ob1, string ob2)
{
        string name,temp;
        int value1, value2;
        int id1, id2;

        if( sscanf(ob1, "%s %d %d %s", temp, id1, value1, name ) != 4 ) return 0;
        if( sscanf(ob2, "%s %d %d %s", temp, id2, value2, name ) != 4 ) return 0;

        if( value1 == value2 ) return id1 - id2;
        return value1 - value2;
}

int sort_eq_comp(string ob1, string ob2)
{
        string name,temp, type1, type2;
        int value1, value2;
        int id1, id2;

        if( sscanf(ob1, "%s %d %d %s", temp, id1, value1, name ) != 4 ) return 0;
	if( sscanf(name, "%s [%s] %s", temp, type1, temp) != 3) return 0;
        if( sscanf(ob2, "%s %d %d %s", temp, id2, value2, name ) != 4 ) return 0;
	if( sscanf(name, "%s [%s] %s", temp, type2, temp) != 3) return 0;
	
	if( type1 == type2 ) {
	        if( value1 == value2 ) return id1 - id2;
	        return value1 - value2;
	}
	return strcmp(type1, type2);
}

string sort(string context)
{
        return implode( sort_array( explode(context, "\n"), "sort_comp", this_object() ), "\n");        // 回傳合併後的字串陣列
}

string sort_eq(string context)
{
        return implode( sort_array( explode(context, "\n"), "sort_eq_comp", this_object() ), "\n");        // 回傳合併後的字串陣列
}


string getHeader(string show, string type) 
{
        string msg  = "╭─────────────────────────────────────╮\n";
        msg += sprintf("│%-74s│\n", "目前火影忍者所有的" + show + "列表" );
        msg += "├─────────────────────────────────────╯\n";

        if( type == "npc" ) msg += sprintf("│"BRED"%|4s"NOR" "BYEL"%|4s"NOR" "BBLU"%|60s"NOR"\n", "編號", "  等 級  ", "名稱");
        else msg += sprintf("│"BRED"%|4s"NOR" "BYEL"%|4s"NOR" "BBLU"%|60s"NOR"\n", "編號", "單價/銀兩", "名稱");
        return msg;
}

string getFooter() {
        return "╰─────────────────────────────────────╯";
}

string formatting_npc(mapping record)
{
	int index;
	mapping data;
	string name, tmp;
        string msg = "";

    if( wizardp(this_player()) ) {
                foreach(index, data in record) {
                        name = uncolor(data["name"]);
                        tmp  = sprintf("│%|4d %9d %s\n",
                                index,
                                data["level"],
				name + " " + BLU+data["file_name"]+NOR );
                        tmp = replace_string(tmp, name, data["name"]);
                        msg += tmp;
                }
    } else {
                foreach(index, data in record) {
                        name = uncolor(data["name"]);
                        tmp  = sprintf("│%|4d %9d %s\n",
                                index,
                                data["level"],
				name );
                tmp = replace_string(tmp, name, data["name"]);
                msg += tmp;
                }
    }
	return sort(msg);
}

string formatting_eq(mapping record)
{
	int index;
	mapping data;
	string name, tmp;
        string msg = "";

    if( wizardp(this_player()) ) {
                foreach(index, data in record) {
                        name = uncolor(data["name"]);
                        tmp  = sprintf("│%|4d %9d %s\n",
                                index,
                                data["value"],
				name + HIK " [" + data["file_name"]->query("wear_as")  + "] " + HIB + data["file_name"]+NOR );
                        tmp = replace_string(tmp, name, data["name"]);
                        msg += tmp;
                }
    } else {
                foreach(index, data in record) {
                        name = uncolor(data["name"]);
                        tmp  = sprintf("│%|4d %9d %s\n",
                                index,
                                data["value"],
				name + HIK " [" + data["file_name"]->query("wear_as")  + "] " + NOR );
                tmp = replace_string(tmp, name, data["name"]);
                msg += tmp;
                }
    }


	//加入分隔用線
	msg += sprintf( "│"CYN"%|4d %9d %s\n",
			-1, -1, "--------------------鎧甲類-------------------- [armor] "NOR);
	msg += sprintf( "│"CYN"%|4d %9d %s\n",
			-1, -1, "--------------------上身類-------------------- [cloth] " NOR);
	msg += sprintf( "│"CYN"%|4d %9d %s\n",
			-1, -1, "--------------------頭部類-------------------- [head_eq] " NOR);
	msg += sprintf( "│"CYN"%|4d %9d %s\n",
			-1, -1, "--------------------臉部類-------------------- [face_eq] " NOR);
	msg += sprintf( "│"CYN"%|4d %9d %s\n",
			-1, -1, "--------------------頸部類-------------------- [neck_eq] " NOR);
	msg += sprintf( "│"CYN"%|4d %9d %s\n",
			-1, -1, "--------------------小腿類-------------------- [leg_eq] " NOR);
	msg += sprintf( "│"CYN"%|4d %9d %s\n",
			-1, -1, "--------------------下身類-------------------- [pants] " NOR);
	msg += sprintf( "│"CYN"%|4d %9d %s\n",
			-1, -1, "--------------------腳掌類-------------------- [feet_eq] " NOR);
	msg += sprintf( "│"CYN"%|4d %9d %s\n",
			-1, -1, "--------------------手指類-------------------- [finger_eq] " NOR);
	msg += sprintf( "│"CYN"%|4d %9d %s\n",
			-1, -1, "--------------------手部類-------------------- [hand_eq] " NOR);
	msg += sprintf( "│"CYN"%|4d %9d %s\n",
			-1, -1, "--------------------腰部類-------------------- [waist_eq] " NOR);
	msg += sprintf( "│"CYN"%|4d %9d %s\n",
			-1, -1, "--------------------手腕類-------------------- [wrist_eq] " NOR);
	return sort_eq(msg);
}

string formatting_general(mapping record)
{
	int index;
	mapping data;
	string name, tmp;
        string msg = "";

    if( wizardp(this_player()) ) {
                foreach(index, data in record) {
                        name = uncolor(data["name"]);
                        tmp  = sprintf("│%|4d %9d %s\n",
                                index,
				data["value"],
                                name + " " + HIB+data["file_name"]+NOR );
                        tmp = replace_string(tmp, name, data["name"]);
                        msg += tmp;
                }
    } else {
                foreach(index, data in record) {
                        name = uncolor(data["name"]);
                        tmp  = sprintf("│%|4d %9d %s\n",
                                index,
				data["value"],
				name );
                tmp = replace_string(tmp, name, data["name"]);
                msg += tmp;
                }
    }
	return sort(msg);
}

string formatting(mapping record, string show,string type)
{
        string msg = "";

	switch(type) {
		case "eq":
			msg = formatting_eq(record);
		break;
		case "npc":
			msg = formatting_npc(record);
		break;
		default:
			msg = formatting_general(record);
	}

        /* 最後加上列表頭、尾*/
   return getHeader(show, type) + msg +  getFooter();
}

int do_list(string show, string type)
{
    mapping record = ITEM_D->do_query_all(type);

    if( !sizeof(record) ) return notify_fail("目前所查詢的列表沒有任何資料。\n");

    this_player()->start_more( formatting(record, show, type) );

    return 1;
}

int do_scan(string dir)
{
    int i;
    object ob;
    mixed *file, *dirent;
    file = get_dir(dir, -1);

    if( !sizeof(file) ) {
        if( file_size(dir) == -2 ) write("目錄是空的。\n");
        else write("沒有這個目錄。\n");
        return 1;
    }

    foreach( dirent in file ) {
        write(dirent[0] + "\n");
        ob = new(dir + dirent[0]);
        if( !objectp(ob) ) continue;
        if( !ob->query("name") ) continue;
        ITEM_D->add_item(ob, 0);
        destruct(ob);
    }

    ITEM_D->save();

    write("Ok.\n");

    return 1;
}

int do_show_detail(string select, int id)
{
    string msg = "", sub_type;
    object obj;
    mapping record, apply;

    switch( select ) {
        case "eq": record = ITEM_D->do_query("eq", id); break;
        case "wp": record = ITEM_D->do_query("wp", id); break;
        case "npc": record = ITEM_D->do_query("npc", id); break;
        case "food": record = ITEM_D->do_query("food", id); break;
        case "obj": record = ITEM_D->do_query("obj", id); break;
    }

    if( !mapp(record) ) return notify_fail("沒有這個編號。\n");

    if( !objectp(obj = new(record["file_name"])) ) {
        if( file_size(record["file_name"]) == -1 ) {
            switch( select ) {
                case "eq": record = ITEM_D->do_del("eq", id); break;
                case "wp": record = ITEM_D->do_del("wp", id); break;
                case "npc": record = ITEM_D->do_del("npc", id); break;
                case "food": record = ITEM_D->do_del("food", id); break;
                case "obj": record = ITEM_D->do_del("obj", id); break;
            }
        }
        return notify_fail("你目前無法查詢這項物品的資訊。\n");
    }

    if( select == "npc" ) msg += "等級：" + obj->query("level") + "\n";
    msg += "名稱：" + obj->query("name") + "\n";
    msg += "\n" + obj->query("long") + "\n";

    if( select == "eq" ) {
        sub_type = obj->query("wear_as");
        msg += sprintf("護具部位：%s\n", to_chinese(sub_type) );
        apply = obj->query("apply_armor/" + sub_type);
        if( mapp(apply) ) {
            string prop;
            mixed value;
            
            msg += "護具特性：\n";
            foreach(prop, value in apply) {
                msg += sprintf("  %-30s %O\n", to_chinese(prop), value);
            }
        }
    }
    
    if( select == "wp" ) {
        string s;
        mapping dp;
        mixed sk = obj->query("wield_as");
        
        msg += "可使用方式：\n";

        if( stringp(sk) ) sk = ({ sk });
        foreach(s in sk) {
            msg += sprintf("\n☉ %s (%s)\n", to_chinese(s), s);
            dp = obj->query("damage/" + s);
            msg += sprintf("   傷害力： %d - %d (傷害力修正 %d%%，武器等級 %d)\n", 
                dp["lower"], dp["upper"], dp["bonus"], dp["level"] );

            apply = obj->query("apply_weapon/" + s);
            if( mapp(apply) ) {
                string prop;
                mixed value;
            
                msg += "\n   武器特性：\n";
                foreach(prop, value in apply) {
                    prop = to_chinese(prop);
                    msg += sprintf("     %-30s %O\n", prop, value);
                }
            }
        }
    }

    this_player()->start_more(msg);

    destruct(obj);
    
    if( objectp(obj = find_object(record["file_name"]) ) ) destruct(obj);

    return 1;
}

int main(object me, string arg)
{
    int id;
    string select;

    if( !arg ) return notify_fail("指令格式: query <選項> [ <編號> ]，或請參照help query說明文件。\n");

    if( wizardp(me) ) {
        if( !sscanf(arg, "scan %s", select) == 1 )
            if( arg == "scan" ) select = me->query("cwd");
        if( stringp(select) ) {
            if( select[0..6] == "/world/" ) return do_scan(select);
        }
    }

    if( sscanf(arg, "-%s %d", select, id) == 2 )
        return do_show_detail(select , id);

    if( sscanf(arg, "-%s", select) == 1 ) {
        switch( select ) {
            case "eq": return do_list("裝備", "eq"); break;
            case "wp": return do_list("武器", "wp"); break;
            case "npc": return do_list("人物", "npc"); break;
            case "food": return do_list("食物", "food"); break;
            case "obj": return do_list("其它", "obj"); break;
            default: return notify_fail("指令格式錯誤。\n");
        }
    }

    return 1;
}

int help(object me)
{
    write(@HELP
指令格式：
  query <選項>           列出某類型的所有物品
                         如： query -eq   會列出所有裝備
  query <選項> <編號>    會顯示該編號的物品的詳細資料

選項：
  -eq    裝備               -wp    武器
  -npc   非玩家角色         -food  食品
  -obj   其它
HELP);

    if( wizardp(me) ) {
    write(@HELP

巫師指令： query scan [<目錄>]    將某目錄下的物件加入系統列表中
                                  不加目錄位置，則是依目前工作目錄下
HELP);
    }
    return 1;
}

