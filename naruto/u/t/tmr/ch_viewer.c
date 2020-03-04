#include <ansi.h>
        
#include <armor.h>

inherit F_FACE_EQ;

void create()
{
        set_name("�W�D�O���˵���", ({ "channel viewer","viewer"}));
        set_weight(3);
        if( !clonep() ) {
        set("wear_as", "face_eq");
                set("unit", "�o");
                set("value", 5);
                set("long",
                        "�ϥΫ��O�Gview [�O����]\n");
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
        return notify_fail("�S�� "+file+" �o���ɮסC\n");
    if( !text = read_file(file) )
        return notify_fail("���ɮרS�����󤺮e�C\n");
    
    lines = explode( text, "\n");
    
    text = "";
    
    for(i=0;i<sizeof(lines);i++) {
        if( sscanf( lines[i], "%s use %s: %s", id, chtype, context) == 3 ) {
                        switch(chtype) {
                                case "chat": case "chat*":
                                                context = HIC "" + context + "" NOR;
                                                chtype = HIC "�i����j" NOR;
                                                id = HIC "" + id + ":" NOR;
                                        break;
                                case "music": case "music*":
                                                context = HIK "" + context + "" NOR;
                                                chtype = HIK "�i���֡j" NOR;
                                                id = HIK "" + id + ":" NOR;
                                        break;
                                case "news": case "news*":
                                                context = HIG "" + context + "" NOR;
                                                chtype = HIG "�i�s�D�j" NOR;
                                                id = HIG "" + id + ":" NOR;
                                        break;
                                case "wiz": case "wiz*":
                                                context = HIY"" + context + "" NOR;
                                                chtype = HIY "�i�Ův�j" NOR;
                                                id = HIY"" +  id + ":" NOR;
                                        break;
                                case "rumor": case "rumor*":
                                                context = HIM "" + context + "" NOR;
                                                chtype = HIM "�i�����j" NOR;
                                                id = HIM"" +  id + ":" NOR;
                                        break;
                                case "aucc": case "aucc*":
                                                context = HIG "" + context + "" NOR;
                                                chtype = HIG "�i�ͧJ�ʡj" NOR;
                                                id = HIG"" +  id + ":" NOR;
                                        break;

                        }
                        text += sprintf("%3d%s%s %s\n", (i+1), chtype, id, context );
        } else {
                text += lines[i] + "\n";
        }
    }
    
    write("Channel�G" + file + "\n");
    this_player()->start_more(text);
    return 1;
}

