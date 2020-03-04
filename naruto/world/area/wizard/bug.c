inherit ROOM;

void create()
{
	set("short", "黑魔法陣");
	set("long", @LONG
這個房間四週佈滿了強大的黑魔法攻擊術，似乎是為了斬殺到處
亂竄的臭蟑螂，在你眼前有著堆積如山的蟑螂殘骸，可見這黑魔法攻
擊術相當有用。
LONG
	);
	set("exits", ([
		"east" : __DIR__"guildhall",
	]));

	setup();
	load_object("/daemon/board/bug");
	replace_program(ROOM);
}
