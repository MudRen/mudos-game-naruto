#include <ansi.h>
inherit ROOM;

mapping record = ([
    1: ([ "name": BGRN"�j�Ѵ˪L"NOR,
          "file": _DIR_AREA_"old_forest/monkey.c",
          "x": 1,
          "y": 10,
       ]),
    2: ([ "name": BBLU+HIW"���Z��"NOR,
          "file": _DIR_AREA_"lake/lake.c",
          "x": 13,
          "y": 18,
       ]),
    3: ([ "name": BGRN+HIG"��Q�L"NOR,
          "file": _DIR_AREA_"thorn_pine/pine.c",
          "x": 15,
          "y": 1,
       ]),
    4: ([ "name": HIK"���v�p�|"NOR,
          "file": _DIR_AREA_"sneakhole/path.c",
          "x": 8,
          "y": 38,
       ]),
    5: ([ "name": HIM"�^���s�}"NOR,
          "file": _DIR_AREA_"echo/echo.c",
          "x": 15,
          "y": 19,
       ]),
    6: ([ "name": BRED+HIW"�e��"BRED+HIR"�Գ�"NOR,
          "file": _DIR_AREA_"bone/bone.c",
          "x": 6,
          "y": 39,
       ]),
    7: ([ "name": BRED+HIW"�q�k�q"NOR,
          "file": _DIR_AREA_"sifa_isle/sifa.c",
          "x": 45,
          "y": 38,
       ]),
    8: ([ "name": HIY"������"NOR,
          "file": _DIR_AREA_"ship/lufi.c",
          "x": 29,
          "y": 29,
       ]),
    9: ([ "name": BGRN+HIY"�p��q"NOR,
          "file": _DIR_AREA_"barren_isle/barren.c",
          "x": 24,
          "y": 3,
       ]),
   10: ([ "name": BMAG+HIW"�]�N������"NOR,
          "file": _DIR_AREA_"magic_house/house.c",
          "x": 15,
          "y": 19,
       ]),
   11: ([ "name": YEL"�a�U�F��"NOR,
          "file": _DIR_AREA_"sand_hole/sand.c",
          "x": 15,
          "y": 15,
       ]),
   12: ([ "name": HIY"�m��"HIG"�A��"NOR,
          "file": _DIR_AREA_"rural_area/area.c",
          "x": 18,
          "y": 18,
       ]),
   13: ([ "name": YEL"���~"GRN"�˪L"NOR,
          "file": _DIR_AREA_"god_forest/god_1.c",
          "x": 22,
          "y": 12,
       ]),
   14: ([ "name": BRED+HIW"���s"NOR"�C�q",
          "file": _DIR_AREA_"lv60_area/fire_isle.c",
          "x": 10,
          "y": 6,
       ]),
]);

string do_list()
{
    int index, size;
    string msg;

    if( !wizardp(this_player()) ) {
        msg  = "\n\n�@��äC�K�V�����e�šA�ڥ��ݤ����C\n";
        return msg;
    }
    msg  = "�~�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
    msg += "�x���~�P�ǰe�}                                    �x\n";
    msg += "�u�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�t\n";
    msg += "�x�s��   �a��            (X,Y)�_�I��m            �x\n";
    msg += "�u�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";

    if( (size=sizeof(record)) )
        for(index=1;index<=size;index++)
        msg += sprintf("�x%4d  %12s     (%d,%d)\n", index, record[index]["name"], record[index]["x"], record[index]["y"]);

    msg += "�u�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
    msg += "�x��J ffly <�s��> <X�y��> <Y�y��>  �i��ǰe�C    �x\n";
    msg += "���w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��";

    return msg;
}
void create()
{
    set("short", HIW"��"HIG"��"NOR"�a");
    set("long", @LONG
�b���H���Τ߾�z�U�A�󼯮a�ש���ܤF�즳�������A�����@��
���b���a�C���F�D�H�ϥΪ���K�A�o�٦b�ж�����m�F�@�y�u�@�p��
�O�A���D�H���n�ѪF�Ѧ誺�A�ӰO�����F��N�g�b�O�W�C�y�L�ݹL��
���\�]��A�A�o�{�ж��k�W�����Ӥ��~�P�A�����O�����򪺡C���䨤
���h���@������A�����i�H�D��@�֩��ѩ������ѭ��C
LONG);
    set("exits", ([
        "down" : ([ "filename": _DIR_AREA_"wizard/wizard.c",
                      "x_axis": 14,
                      "y_axis": 5,
                 ]),
        "east" : __DIR__"bathing.c",
        "north" : __DIR__"tomb.c",
        "test" : __DIR__"workroom2.c",
    ]));
    set("detail", ([
        "���": "���G�i�H���}(open)�X�h���ˤl�C",
        "���~�P": (: do_list :),
    ]));
    set("objects", ([
        __DIR__"npc/vaga.c" : 1,
    ]));
    setup();
    load_object("/u/m/mouse/board.c");
}
void init()
{
    if( wizardp(this_player()) ) {
        add_action("do_ffly", "ffly");
        add_action("do_gojail", "gojail");
    }
    add_action("do_open", "open");
}
int do_open(string arg)
{
    if( arg == "���" || arg == "��" ) {
        message_vision("$N�N������}�A�w�w�����F�X�h�C\n", this_player());
        this_player()->move(_DIR_AREA_"muye/inn");
        message_vision("$N�q���ѩ����䪺������F�X�ӡC\n", this_player());
        this_player()->start_busy(1);
        return 1;
    }
    return notify_fail("�A�Q���}����H\n");
}
int do_gojail(string arg)
{
    message_vision("$N"HIR"���}�t�����F�i�h�C\n"NOR, this_player());
    this_player()->move(_DIR_AREA_"jail.c");
    message_vision("$N"HIR"���M�X�{�b�o�[��S���H�Q���C\n"NOR, this_player());
    return 1;
}
int do_ffly(string arg)
{
    int number, x, y;
    object me = this_player(), room;

    if( me->is_busy() || me->is_fighting() ) 
        return notify_fail("�A�{�b�S���šC\n");

    if( !arg )
        return notify_fail("�A�Q�n������Ӱϰ�H\n");

    if( sscanf(arg, "%d %d %d", number, x, y) != 3 )
        return notify_fail("�A�Q�n����ϰ줤�ݭn�[�W�y�СC\n");

    if( undefinedp(record[number]) )
        return notify_fail("�A�Q�n������Ӱϰ�H\n");

    if( x < 0 || y < 0 )
        return notify_fail("�S���o�Ӯy�Хi�H���C\n");

    if( !objectp(room = load_object(record[number]["file"])) )
        return notify_fail("�A�o�Ӧa��ثe�L�k�ǰe\n");

    message_vision("$N���M���F�_�ӡA�C�C�����b�o�̡C\n", me);

    if( !area_move(room, me, x, y) ) {
        message_vision("���G$N��M���h���ߡA�S�q�Ť��^�F�U�ӡC\n", me);
        return 1;
    }
    message_vision("$N�q�Ѧӭ��A�wí�������b�o�̡C\n", me);
    return 1;
}
int valid_leave(object me, string dir)
{
    int x, y;
    if( !me ) return 0;
    if( !userp(me) && dir == "down" ) return 0;
    if( userp(me) && dir == "test" ) {
        if( !wizardp(me) ) return notify_fail("�o�̥u���Ův�~��i�h�C\n");
    }
    return ::valid_leave(me, dir);
}
