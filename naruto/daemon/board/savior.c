inherit BULLETIN_BOARD;

void create()
{
        set_name("��ϼu�^", ({ "music board","board" }) );
        set("location", "/u/s/savior/workroom");
        set("board_id", "savior");
        set("board_owner","savior");
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}
