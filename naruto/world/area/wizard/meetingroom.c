#include <ansi.h>
#include <command.h>

inherit ROOM;

string filename;

void create()
{
	set("short", "異言堂");
	set("long", @LONG
這裡是眾神們討論重大事情的場所。圓形的房間，白色的牆，鋪
著紅色的地毯，房間的頂端鑲崁著一顆神秘的晶石，光線就從晶石散
發出來，照亮了整個房間，明亮卻不刺眼。靠門的牆邊浮著一塊紫色
的玉板，板子上刻了些字。
LONG
	);

	set("exits", ([
		"down" : __DIR__"guildhall"
	]));

	set("detail", ([
		"玉板" : "一塊飄浮在半空中的紫翠玉板, 上面刻了些字:

會議記錄的方法:
start <filename> :	開始記錄會議過程, filename 是會議記錄的檔名。
over :			停止記錄會議過程。

",
	]));
    set("no_fight", 1);
	setup();
	load_object("/daemon/board/wizard_talk");
}

void init()
{
	add_action("say", ({"say", "'"}) );
	add_action("start", "start");
	add_action("over", "over");
}

int start(string str)
{
	if( !wizardp(this_player()) )
	return notify_fail("你沒有權力開會議。\n");

	if( !str )
	return notify_fail("你要將會議記錄寫在那個檔??\n");

	if ( (int)query("meeting_trigger") != 0 )
	return notify_fail("目前正在開會中。\n");

	set("meeting_trigger", 1);
	message_vision(HIW"\n$N宣布現在會議正式開始。\n\n"NOR, this_player());
	filename = str;
	log_file(filename, sprintf("[%s] %s (%s) 開啟會議。\n",
		ctime(time()), this_player()->name(1), geteuid(this_player())));
	return 1;
}

int say(string msg)
{
	if( !msg ) return 0;
	else
	SAY_CMD->main(this_player(), msg);
	if ((int)query("meeting_trigger") == 1)
	log_file(filename,
	sprintf("%s說道﹕" + msg + "\n",this_player()->name(1)) );
	return 1;
}

int over()
{
	if( !wizardp(this_player()) )
        return notify_fail("你沒有權力結束會議。\n");

	delete("meeting_trigger");
	log_file(filename, sprintf("[%s] %s (%s) 結束會議。\n",
		ctime(time()), this_player()->name(1), geteuid(this_player())));
	message_vision(HIW"\n$N宣布會議結束。\n\n"NOR, this_player());
	return 1;
}
