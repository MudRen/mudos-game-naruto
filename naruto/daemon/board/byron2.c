inherit BULLETIN_BOARD;

void create()
{
        set_name("�L�Ѵѧ�", ({ "byron's chess","chess" }) );
        set("location", "/u/b/byron/workroom2.c");
        set("board_id", "byron2");
        set("board_owner","byron2");
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}
