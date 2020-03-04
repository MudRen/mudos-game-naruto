
inherit ROOM;

void create()
{
	set("short", "巫師學院");
	set("long", @LONG
這裡是巫師們研究討論這個世界未來的場所，你可以看到許多巫
師比手劃腳地高談闊論著自已的想法，你也可以一同參與他們的討論
，讓這個世界更美好。
LONG
	);
	set("exits", ([
		"south" : __DIR__"guildhall",
	]));

	setup();
	load_object("/daemon/board/design");
	replace_program(ROOM);
}