/* write by -Acme- */
#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "�o�k�a");

    set("long", @long
�o�̬O�츭�����o�k�a�C
long);

    set("exits", ([
        "south" : ([ "filename": __DIR__"muye.c",
                     "x_axis": 17,
                     "y_axis": 18,
                  ]),
    ]));

    set("objects", ([
        __DIR__"npc/nai.c": 1
    ]) );

    setup();
}

int valid_leave(object me, string dir)
{
    object bug;
    int x, y, j;

    if( !me ) return 0;

    j = 10 + random(16);

    if( me->query_temp("bug_exit") && dir == "south" ) {
        if( userp(me) ) tell_object(this_player(), HIK"�A�Q�n�k���o���W�F���f���i"HIM"�Τ���"NOR"�j"HIK"�I�٦������Ϊ��i�F�A���W�I\n"NOR);
        if( bug = present("_GI_BUG_", me) ) {
            bug->add_amount(j);
        } else {
            if( file_size(__DIR__"npc/item/gi_bug.c") < 0 ) return ::valid_leave(me, dir);
            if( catch(bug = new(__DIR__"npc/item/gi_bug.c")) ) return ::valid_leave(me, dir);
            if( !bug->move(me) ) {
                destruct(bug);
            } else {
                bug->set_amount(j);
                bug->set_owner(me);
                bug->set("changed", 1);
            }
        }
        return notify_fail("�o�Ӥ�V�S���X���C\n");
    }
    return ::valid_leave(me, dir);
}
