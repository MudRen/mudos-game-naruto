
inherit BULLETIN_BOARD;

void create()
{
	set_name("����d���O", ({ "chat board", "board" }) );
	set("location", "/world/area/wizard/power");
	set("board_id", "chat");
	setup();
	set("capacity", 200);
	replace_program(BULLETIN_BOARD);
}
