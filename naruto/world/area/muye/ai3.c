/* write by -Acme- */
inherit ROOM;

void create()
{
    set("short", "�R�l�a-��|");

    set("long", @long
�o�̬O�츭�����R�l�a����|�A�����O�ͬ۷��~�H�C
long);

    set("detail", ([
        "����" : "�o�̪�����ܦh�A�n����(weed)�����@��...",
    ]));

    set("exits", ([
        "east" : __DIR__"ai2.c",
    ]));

    setup();
}

void init()
{
    add_action("do_weed", "weed");
}

int do_weed(string arg)
{
    if( this_player()->is_busy() ) return notify_fail("�A�W�@�Ӱʧ@�٨S�����C\n");
    message_vision("$N���۸y�}�l�ް_�a�W������...\n", this_player());

    if( this_player()->query_temp("ai_herb") ) {
        this_player()->add_temp("ai_herb", 1);
    } else {
        this_player()->set_temp("ai_herb", 1);
    }
    this_player()->start_busy(2);
    return 1;
}
