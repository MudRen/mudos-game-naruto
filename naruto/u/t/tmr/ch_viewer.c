#include <ansi.h>
        
#include <armor.h>

inherit F_FACE_EQ;

void create()
{
        set_name("頻道記錄檢視器", ({ "channel viewer","viewer"}));
        set_weight(3);
        if( !clonep() ) {
        set("wear_as", "face_eq");
                set("unit", "發");
                set("value", 5);
                set("long",
                        "使用指令：view [記錄檔]\n");
        }
        setup();
}

void init()
{
        if( wizardp(this_player() ) )
         add_action("do_view", "view");
}

int do_view(string arg)
{
    string file, text;
    string id, chtype, context;
    string *lines;
        int i;

    seteuid(geteuid(this_player(1)));
    if (!arg)
        arg = "CHANNELS";       // default channel log

    file = resolve_path("/log/channel/", arg);
    if( file_size(file) < 0 ) 
        return notify_fail("沒有 "+file+" 這個檔案。\n");
    if( !text = read_file(file) )
        return notify_fail("該檔案沒有任何內容。\n");
    
    lines = explode( text, "\n");
    
    text = "";
    
    for(i=0;i<sizeof(lines);i++) {
        if( sscanf( lines[i], "%s use %s: %s", id, chtype, context) == 3 ) {
                        switch(chtype) {
                                case "chat": case "chat*":
                                                context = HIC "" + context + "" NOR;
                                                chtype = HIC "【閒聊】" NOR;
                                                id = HIC "" + id + ":" NOR;
                                        break;
                                case "music": case "music*":
                                                context = HIK "" + context + "" NOR;
                                                chtype = HIK "【音樂】" NOR;
                                                id = HIK "" + id + ":" NOR;
                                        break;
                                case "news": case "news*":
                                                context = HIG "" + context + "" NOR;
                                                chtype = HIG "【新聞】" NOR;
                                                id = HIG "" + id + ":" NOR;
                                        break;
                                case "wiz": case "wiz*":
                                                context = HIY"" + context + "" NOR;
                                                chtype = HIY "【巫師】" NOR;
                                                id = HIY"" +  id + ":" NOR;
                                        break;
                                case "rumor": case "rumor*":
                                                context = HIM "" + context + "" NOR;
                                                chtype = HIM "【謠言】" NOR;
                                                id = HIM"" +  id + ":" NOR;
                                        break;
                                case "aucc": case "aucc*":
                                                context = HIG "" + context + "" NOR;
                                                chtype = HIG "【友克鑫】" NOR;
                                                id = HIG"" +  id + ":" NOR;
                                        break;

                        }
                        text += sprintf("%3d%s%s %s\n", (i+1), chtype, id, context );
        } else {
                text += lines[i] + "\n";
        }
    }
    
    write("Channel：" + file + "\n");
    this_player()->start_more(text);
    return 1;
}

