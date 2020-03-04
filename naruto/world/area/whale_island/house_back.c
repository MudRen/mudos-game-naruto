/* write by -Acme- */
inherit ROOM;

void create()
{
    set("short", "�ѱC�C�a-��|");

    set("long", @long
�o�̬O�H���q�W�@�ӦѱC�C�a����|�A�����O�ͬ۷��~�H�C
long);

    set("detail", ([
        "����" : "�o�̪�����ܦh�A�n����(weed)�����@��...",
    ]));

    set("exits", ([
        "south" : __DIR__"house.c",
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

    if( this_player()->query_temp("woman_herb") ) {
        this_player()->add_temp("woman_herb", 1);
    } else {
        this_player()->set_temp("woman_herb", 1);
    }
    this_player()->start_busy(2);
    return 1;
}
