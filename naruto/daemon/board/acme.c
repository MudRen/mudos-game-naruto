inherit BULLETIN_BOARD;

void create()
{
        set_name("�y�ûR��", ({ "acme's board","board" }) );
        set("location", "/u/a/acme/workroom");
        set("board_id", "acme");
        set("board_owner","acme");
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}
