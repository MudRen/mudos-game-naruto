inherit BULLETIN_BOARD;

void create()
{
	set_name("�K�ԥv", ({ "alickyuen's board", "board" }));
	set("location", "/u/a/alickyuen/work2");
	set("board_id", "alickyuen");
	set("board_owner", "alickyuen");
	setup();
	set("capacity", 999);
	replace_program(BULLETIN_BOARD);
}
