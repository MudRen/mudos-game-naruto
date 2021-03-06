/* value.c 檢查物品的價格設定是否正確 by -Acme- */

#include <command.h>
#include <ansi.h>

inherit F_CLEAN_UP;

int count_apply(string type, mapping apply)
{
    int value = 0, val;
    int add_attr=0, add_bil=0, add_stat=0, add_sk=0;
    string prop;

    if( !mapp(apply) ) return 0;

    foreach(prop, val in apply) {
        switch( prop ) {
            case "str":        // 力量
            case "con":        // 體格
            case "int":        // 智慧
            case "dex":        // 敏捷
                add_attr += val;            // 屬性要全部累計後再做計算
                break;

            case "exact":      // 命中能力
            case "evade":      // 迴避能力
            case "intimidate": // 攻擊技巧
            case "wittiness":  // 防禦技巧
            case "move":       // 移動能力
            case "carriage":   // 負重能力
            	add_bil += val;            // 能力要全部累計後再做計算
                break;

            case "ap":         // 精神值
            case "hp":         // 體力值
            case "mp":         // 查克拉
            	add_stat += val;          // 狀態要全部累計後再做計算
                break;
            
            case "attack":     // 攻擊力量
                switch( type ) {
                    case "lefthand":
                    case "righthand":
                    case "twohanded":
                        if( val >= 0 && val <= 45 ) value += val*100;          // D級
                        else if( val >= 46 && val <= 90 ) value += val*500;    // C級
                        else if( val >= 91 && val <= 150 ) value += val*1500;  // B級
                        else if( val >= 151 && val <= 200 ) value += val*3000; // A級
                        else if( val >= 201 && val <= 250 ) value += val*6000; // S級
                        else if( !(val<0) ) return -1;
                        break;
                    default:
                        if( val >= 0 && val <= 2 ) value += val*100;          // D級
                        else if( val >= 3 && val <= 4 ) value += val*500;     // C級
                        else if( val >= 5 && val <= 6 ) value += val*1500;    // B級
                        else if( val >= 7 && val <= 8 ) value += val*3000;    // A級
                        else if( val >= 9 && val <= 10 ) value += val*6000;   // S級
                        else if( !(val<0) ) return -1;
                        break;
                }
                break;

            case "armor":      // 防禦力量
                switch( type ) {
                    case "face_eq":
                    case "neck_eq":
                    case "finger_eq":
                        if( val >= 0 && val <= 1 ) value += val*100;          // D級
                        else if( val == 2 ) value += val*500;    // C級
                        else if( val == 3 ) value += val*1500;  // B級
                        else if( val == 4 ) value += val*3000; // A級
                        else if( val == 5 ) value += val*6000; // S級
                        else if( !(val<0) ) return -1;
                        break;

                    case "wrist_eq":
                    case "hand_eq":
                    case "waist_eq":
                    case "feet_eq":
                    case "lefthand":
                    case "righthand":
                    case "twohanded":
                        if( val >= 0 && val <= 2 ) value += val*100;          // D級
                        else if( val >= 3 && val <= 4 ) value += val*500;     // C級
                        else if( val >= 5 && val <= 6 ) value += val*1500;    // B級
                        else if( val >= 7 && val <= 8 ) value += val*3000;    // A級
                        else if( val >= 9 && val <= 10 ) value += val*6000;   // S級
                        else if( !(val<0) ) return -1;
                        break;

                    case "head_eq":
                    case "leg_eq":
                        if( val >= 0 && val <= 4 ) value += val*100;          // D級
                        else if( val >= 5 && val <= 8 ) value += val*500;     // C級
                        else if( val >= 9 && val <= 12 ) value += val*1500;   // B級
                        else if( val >= 13 && val <= 16 ) value += val*3000;  // A級
                        else if( val >= 17 && val <= 20 ) value += val*6000;  // S級
                        else if( !(val<0) ) return -1;
                        break;

                    case "pants":
                        if( val >= 0 && val <= 5 ) value += val*100;          // D級
                        else if( val >= 6 && val <= 10 ) value += val*500;    // C級
                        else if( val >= 11 && val <= 15 ) value += val*1500;  // B級
                        else if( val >= 16 && val <= 20 ) value += val*3000;  // A級
                        else if( val >= 21 && val <= 25 ) value += val*6000;  // S級
                        else if( !(val<0) ) return -1;
                        break;

                    case "cloth":
                        if( val >= 0 && val <= 8 ) value += val*100;          // D級
                        else if( val >= 9 && val <= 16 ) value += val*500;    // C級
                        else if( val >= 17 && val <= 24 ) value += val*1500;  // B級
                        else if( val >= 25 && val <= 32 ) value += val*3000;  // A級
                        else if( val >= 33 && val <= 40 ) value += val*6000;  // S級
                        else if( !(val<0) ) return -1;
                        break;

                    case "armor":
                        if( val >= 0 && val <= 10 ) value += val*100;         // D級
                        else if( val >= 11 && val <= 20 ) value += val*500;   // C級
                        else if( val >= 21 && val <= 30 ) value += val*1500;  // B級
                        else if( val >= 31 && val <= 40 ) value += val*3000;  // A級
                        else if( val >= 41 && val <= 50 ) value += val*6000;  // S級
                        else if( !(val<0) ) return -1;
                        break;
                }
                break;

            default:           // 技能
                add_sk += val;
                break;
        }
    }

    // 屬性加點計算
    if( add_attr ) {
        if( add_attr >= 0 && add_attr <= 2 ) value += add_attr*700;          // D級
        else if( add_attr >= 3 && add_attr <= 4 ) value += add_attr*1300;    // C級
        else if( add_attr >= 5 && add_attr <= 6 ) value += add_attr*2500;    // B級
        else if( add_attr >= 7 && add_attr <= 8 ) value += add_attr*4900;    // A級
        else if( add_attr >= 9 && add_attr <= 10 ) value += add_attr*7700;   // S級
        else if( !(add_attr<0) ) return -1;
    }

    // 能力加點計算
    if( add_bil ) {
        if( add_bil >= 0 && add_bil <= 5 ) value += add_bil*150;          // D級
        else if( add_bil >= 6 && add_bil <= 10 ) value += add_bil*700;    // C級
        else if( add_bil >= 11 && add_bil <= 15 ) value += add_bil*2000;  // B級
        else if( add_bil >= 16 && add_bil <= 20 ) value += add_bil*4000;  // A級
        else if( add_bil >= 21 && add_bil <= 25 ) value += add_bil*7000;  // S級
        else if( !(add_bil<0) ) return -1;
    }

    // 狀態加點計算
    if( add_stat ) {
        if( add_stat >= 0 && add_stat <= 100 ) value += add_stat*50;          // D級
        else if( add_stat >= 101 && add_stat <= 200 ) value += add_stat*100;  // C級
        else if( add_stat >= 201 && add_stat <= 300 ) value += add_stat*200;  // B級
        else if( add_stat >= 301 && add_stat <= 400 ) value += add_stat*300;  // A級
        else if( add_stat >= 401 && add_stat <= 500 ) value += add_stat*400;  // S級
        else if( !(add_stat<0) ) return -1;
    }

    // 技能加點計算
    if( add_sk ) {
        if( add_sk >= 0 && add_sk <= 4 ) value += add_sk*120;          // D級
        else if( add_sk >= 5 && add_sk <= 8 ) value += add_sk*600;     // C級
        else if( add_sk >= 9 && add_sk <= 12 ) value += add_sk*1700;   // B級
        else if( add_sk >= 13 && add_sk <= 16 ) value += add_sk*3500;  // A級
        else if( add_sk >= 17 && add_sk <= 20 ) value += add_sk*6000;  // S級
        else if( !(add_sk<0) ) return -1;
    }

    return value;
}

int check_value(string file, object ob)
{
    int value = 0, temp;
    mapping record, apply;

    // 只有 防具 & 武器 才需要設價格
    if( !ob->is_armor() && !ob->is_weapon() ) return 1;

    write(ob->query("name") + "(" + file + ") ");

    // 計算武器價錢
    if( ob->query("wield_as") ) {
        string s;
        mixed sk = ob->query("wield_as");
        
        if( stringp(sk) ) sk = ({ sk });
        foreach(s in sk) {
            // 攻擊力計算價錢
            if( mapp(record = ob->query("damage/" + s)) ) {
                temp = (record["lower"] + record["upper"]) /2;
                if( temp >= 0 && temp <= 45 ) value += temp*100;          // D級
                else if( temp >= 46 && temp <= 90 ) value += temp*500;    // C級
                else if( temp >= 91 && temp <= 150 ) value += temp*1500;  // B級
                else if( temp >= 151 && temp <= 200 ) value += temp*3000; // A級
                else if( temp >= 201 && temp <= 250 ) value += temp*6000; // S級
                else if( !(temp<0) ) {
                	write("set error..\n");
                    return 1;
                }
            }

            value += temp;

            // 附加能力計算價錢
            apply = ob->query("apply_weapon/" + s);
            if( mapp(apply) ) {
                if( (temp = count_apply(s, apply)) < 0 ) {
                    write("set error..\n");
                    return 1;
                }
                value += temp;
            }
        }
    }

    // 計算防具價錢
    if( ob->query("wear_as") ) {
    	apply = ob->query("apply_armor/" + ob->query("wear_as"));
        if( mapp(apply) ) {
                if( (temp = count_apply(ob->query("wear_as"), apply)) < 0 ) {
                    write("set error..\n");
                    return 1;
                }
                value += temp;
        }
    }

    if( value == ob->query("value") )
        write("必要價" + value + ", 設定價" + ob->query("value") + "\n");
    else write(HIR"必要價" + value + ", 設定價" + ob->query("value") + "\n"NOR);

    return 1;
}

int main(object me, string arg)
{
    object ob;
    string dir;
    mixed *file, *dirent;

    SECURED_COMMAND;
    seteuid(geteuid(this_player(1)));

    dir = resolve_path(me->query("cwd"), arg);
    if( file_size(dir)==-2 && dir[<1] != '/' ) dir += "/";

    file = get_dir(dir, -1);
    if( !sizeof(file) ) {
        if (file_size(dir) == -2) write("目錄是空的。\n");
	    else write("沒有這個目錄。\n");
	    return 1;
    }

    foreach( dirent in file ) {
        ob = new(dir+dirent[0]);
        if( objectp(ob) ) {
            check_value(dir+dirent[0], ob);
            destruct(ob);
        }
    }
    write("Ok.\n");
    return 1;
}

int help(object me)
{
    write(@HELP
指令格式： value [<目錄位置>]

掃瞄目錄位置下的所有裝備、武器的價格設定是否正確，
未指令目錄位置則是以目前的工作目錄為主。
HELP);
    return 1;
}
