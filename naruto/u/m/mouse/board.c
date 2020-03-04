#include <ansi.h>

#define BOARD_CAPACITY  query("capacity")
#define NO_PLAYER_POST  query("NO_PLAYER_POST")

inherit ITEM;
inherit F_SAVE;

void create()
{
    set_name(HIY"�u�@"HIW"�p���O"NOR,({"work board","board"}));
    set("long",@LONG
�@�����j���ժO�A�O���@�Ǥu�@�ƶ��M�p���C�ϥΫ��O�G

post <���D>                ���X�@���u�@�p��
read <�s��>                �\Ū�@���u�@�p��
discard <�s��>             �R���@���u�@�p��
mark <�s��>                �аO�@���u�@�p��
followup <�s��>[<�s���D>]  �^�Ф@���u�@�p��[���[�h�ϥέ���D]

LONG);
    set("no_get", 1);
    set("location","/u/m/mouse/workroom.c");
    set("capacity",500);
    set("board_id", "board");
    set("board_owner","board");
    setup();
}

void setup()
{
    string loc;

    seteuid(getuid());
    ::setup();
    if( stringp(loc = query("location")) )
        move(loc);
    restore();
}

void init()
{
    add_action("do_post", "post");
    add_action("do_read", "read");
    add_action("do_discard", "discard");
    add_action("do_followup", "followup");
    add_action("do_mark","mark");
}

string query_save_file()
{
    string id;

    if( !stringp(id = query("board_id")) ) return 0;
    return "/u/m/mouse/board/" + id;
}

string short()
{
    mapping *notes;
    int i, unread, last_read_time;

    notes = query("notes");
    if( !pointerp(notes) || !sizeof(notes) )
        return ::short() + " [ �S������u�@�p�� ]";

    if( this_player() && this_player()->link() ) {
        last_read_time = (int)this_player()->link()->query("board_last_read/" + (string)query("board_id"));
        for(unread = 0, i=sizeof(notes)-1; i>=0; i--, unread ++)
            if( notes[i]["time"] <= last_read_time ) break;
    }
    if( unread )
        return sprintf("%s [ %d ���u�@�p���M%d �����\Ū ]", ::short(), sizeof(notes), unread);
    else
        return sprintf("%s [ %d ���u�@�p�� ]", ::short(), sizeof(notes));
}

string long()
{
    mapping *notes;
    
    int i, last_time_read;
    string msg, tmp;

    notes = query("notes");
    msg = query("long");
    if( !msg ) msg = "";

    last_time_read = this_player()->link()->query("board_last_read/" + (string)query("board_id"));

    msg += "�~�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
    msg += sprintf("�x%-67s  �e�q%|5d���x\n", query("name"), BOARD_CAPACITY);
    msg += "�u�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�t\n";
    msg += sprintf("�x"BGRN+HIW"%s"NOR" "BRED+HIW"%|33s"NOR" "BBLU+HIW"%|24s"NOR" "BMAG+HIW"%|16s"NOR"�x\n", "�s��", "�D�D", "�p���H", "�ɶ�");
    if( pointerp(notes) && sizeof(notes) ) {
         for(i=0; i<sizeof(notes); i++) {
             msg += sprintf("�x%|4s%s%-33s %|24s %16s�x\n",
                            notes[i]["time"] > last_time_read ? sprintf(HIC"%|4d"NOR, i+1) : ""+(i+1),
                            notes[i]["mark"] ? HIY"M"NOR : " ",
                            strlen(notes[i]["
title"]) > 32 ? notes[i]["title"][0..29] + ".." : notes[i]["title"],
                            notes[i]["author"],
                            CHINESE_D->chinese_date_brief(notes[i]["time"]));
         }
    }
    msg += "���w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
    return msg;
}

// This is the callback function to process the string returned from the
// editor defined in F_EDIT of player object.
void done_post(object me, mapping note, string text)
{
    mapping *notes;
    string sig;
    int i=0,j=0;
    if( stringp(sig = me->link()->query("signature")) )
        text += "--\n" + sig;   // �[ -- �n�b followup �i�H���D

    note["msg"] = text+NOR;
    notes = query("notes");
    if( !pointerp(notes) || !sizeof(notes) )
        notes = ({ note });
    else
        notes += ({ note });

    // Truncate the notes if maximum capacity exceeded.
    if( sizeof(notes) > BOARD_CAPACITY ) {
        while( i < BOARD_CAPACITY && !j ) {
                if( notes[i]["mark"] ) i++;
                else {
                        notes -= ({ notes[i] });
                        j++;
                }
        }

    }
    set("notes", notes);
    tell_object(me, "�s�u�@�p���s�w�����C\n");

    save();
    return;
}

int do_post(string arg)
{
    mapping note;
    if(!arg) return notify_fail("�u�@�p�������n�����D�C\n");

    // ���a����s�@
    if( NO_PLAYER_POST && (!wizardp(this_player())))
        return notify_fail("���a����s�q�u�@�p���C\n");

    if( sizeof(query("notes")) > BOARD_CAPACITY )
        return notify_fail("�ժ��g���F�A�S�Ŧ�s�w�u�@�p���C\n");

    if( strlen(arg) > 40 )
        return notify_fail("�z���p���W�٤Ӫ��F�M���@�� 40 �Ӧr���H�����a�C\n");
        
    note = allocate_mapping(4);
    note["title"] = arg;
    note["author"] = this_player()->name() + "(" +this_player()->query("id") + ")";
    note["time"] = time();
    this_player()->edit( (: done_post, this_player(), note :) );
    return 1;
}

int do_read(string arg)
{
    int num, tmp;
    mapping *notes, last_read_time;
    string myid, msg;

    // ���a����ݤu�@�p�e
    if( !wizardp(this_player()) )
        return notify_fail("�A�n�ۭp���O�r�ݡA�o�u�ݨ�@�ζ¼v�C\n");

    last_read_time = this_player()->link()->query("board_last_read");
    myid = query("board_id");
    notes = query("notes");

    if( !pointerp(notes) || !sizeof(notes) )
        return notify_fail("�p���O�W�ثe�S������u�@�p���C\n");

    if( !arg ) return notify_fail("���O�榡�Rread <�s��>|new|next\n");
    if( arg=="new" || arg=="next" ) {
        if( !mapp(last_read_time) || undefinedp(last_read_time[myid]) )
           num = 1;
        else
            for(num = 1; num<=sizeof(notes); num++)
                if( notes[num-1]["time"] > last_read_time[myid] ) break;
                        
    } else if( !sscanf(arg, "%d", num) )
        return notify_fail("�A�nŪ�ĴX���u�@�p���S\n");

    if( num < 1 || num > sizeof(notes) ) return notify_fail("�S���o���u�@�p���C\n");
    num--;

    msg = sprintf(BGRN+HIW"%|4d"NOR" "BRED+HIW"%-33s"NOR" "BBLU+HIW"%|24s"NOR" "BMAG+HIW"%|16s"NOR"\n",
                   num+1,
                   strlen(notes[num]["title"]) > 32 ? notes[num]["title"][0..29] + ".." : notes[num]["title"],
                   notes[num]["author"],
                   CHINESE_D->chinese_date_brief(notes[num]["time"]) );
//                 ctime(notes[num]["time"])[0..9] + ctime(notes[num]["time"])[19..23] );
    msg += "�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n";
    msg += notes[num]["msg"];
    msg += "�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w";

    this_player()->start_more(msg);

    if( !mapp(last_read_time) ) {
            this_player()->link()->set("board_last_read", ([ myid: notes[num]["time"] ]) );
    } else if( undefinedp(last_read_time[myid]) || notes[num]["time"] > last_read_time[myid] )
            last_read_time[myid] = notes[num]["time"];

    return 1;
}

int do_discard(string arg)
{
    mapping *notes;
    int num;

    // ���a����R���p��
    if( !wizardp(this_player()) )
        return notify_fail("�ݳ��ݤ���F�ٷQ�R����H\n");

    if( !arg || sscanf(arg, "%d", num)!=1 )
        return notify_fail("���O�榡�Rdiscard <�s��>\n");
    notes = query("notes");
    if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
        return notify_fail("�S���o���u�@�p���C\n");
    num--;
    if( notes[num]["author"] != (string) this_player(1)->query("name")+ "(" + this_player(1)->query("id") + ")"
    &&  wiz_level(this_player(1)) < 4 && query("board_owner") != this_player()->query_id() )
        return notify_fail("�o�Ӥu�@�p�����O�A�g���C\n");

    if( notes[num]["mark"] ) 
        return notify_fail("�o�u�@�p���w�]�w�аO�A�Х��M���аO�C\n");

    notes = notes[0..num-1] + notes[num+1..sizeof(notes)-1];
    set("notes", notes);
    save();
    write("�R���� " + (num+1) + " ���u�@�p��....Ok�C\n");
    return 1;
}

int do_followup(string str)
{
    mapping *notes, note;
    string *text, title;
    int i, num;
        
    // ���a����^���u�@
    if ( !wizardp(this_player()) )
        return notify_fail("�n�^��ԣ�̪F�F���H\n");

    if( !str )
        return notify_fail("���O�榡�Rfollowup <�s��> [�s�����D]\n");

    if( sscanf(str, "%d %s", num, title) != 2 )
        if( sscanf(str, "%d", num) != 1 )
            return notify_fail("�A�n�^���ĴX���u�@�p���S\n");
        
    notes = query("notes");
        
    if( num < 1 || num > sizeof(notes) )
        return notify_fail("�S���o���u�@�p���C\n");

    num--;
    if( !title ) title = "Re�R" + notes[num]["title"];
    note = allocate_mapping(4);
    note["title"]  = title;
    note["author"] = this_player()->query("name") + "(" + this_player()->query("id") + ")";
    note["time"]   = time();

    text = explode( notes[num]["msg"], "\n" );
    // title, num �o����ܼƮ��ӦA�Q��
    title = sprintf(GRN"> %s �b %s �d�U�o���u�@�p���R\n"NOR,
        notes[num]["author"],
        "(" + ctime(notes[num]["time"])[0..9] + ")" );
    num = sizeof(text);
    for( i=0; i<num; i++ ) 
    {
        // �Ŧ���L, �W�W�@�g���L
        if( text[i] == "" || strsrch(text[i], "> ") != -1)
            continue;
        // ñ�W��, ����
        if( text[i][0..1] == "--" )
            i=num;
        else title = title + GRN + "> " + text[i] + NOR + "\n";
    }
    note["msg"] = title;
    this_player()->edit( (: done_post, this_player(), note :), title );
    return 1;
}

int do_mark(string arg)
{
    mapping *notes;
    int num;

    // ���a����аO�u�@
    if ( !wizardp(this_player()) )
        return notify_fail("�аO�@�ζ¼v�ܡH\n");

    if( !arg || sscanf(arg, "%d", num)!=1 )
        return notify_fail("���O�榡�Rmark <�s��>\n");
    notes = query("notes");
    if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
        return notify_fail("�S���o���u�@�p���C\n");
    num--;

    if( wiz_level(this_player(1)) < 4 && query("board_owner") != this_player()->query_id() )
        return notify_fail("�A�S���v�Q�аO�u�@�p���C\n");

    if( !notes[num]["mark"] ) {
        write("�N��"+(num+1)+"���u�@�p���]�w�аO�C\n");
        notes[num]["mark"]=1;
    } else {
        write("�N��"+(num+1)+"���u�@�p�������аO�C\n");
        notes[num]["mark"]=0;
    }
    save();
    return 1;
}
