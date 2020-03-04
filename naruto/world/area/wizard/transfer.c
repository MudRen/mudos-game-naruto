/* transfer.c write by -Acme- */
#include <ansi.h>

inherit ROOM;

mapping record = ([
    1: ([ "name": HIR"������"NOR+BGRN"�츭��"NOR,
          "file": _DIR_AREA_"muye/inn.c",
         "price": 100 ]),
      2: ([ "name": BBLU+HIW"�H���q"NOR,
            "file": _DIR_AREA_"whale_island/mite_hotel.c",
           "price": 100 ]),
    3: ([ "name": BRED+HIW"�q�k�q"NOR,
          "file": _DIR_AREA_"sifa_isle/sea.c",
         "price": 100 ]),


/*
    2: ([ "name": "���������ԧ�",
          "file": _DIR_AREA_"muye/inn.c",
         "price": 100 ]),
*/
]);

string do_list()
{
    int index, size;
    string msg;

    msg  = "�~�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
    msg += "�x����ǰe�S�O�A��                                �x\n";
    msg += "�u�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�t\n";
    msg += "�x�s��  ���/�Ȩ�  �a��                           �x\n";
    msg += "�u�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";

    if( (size=sizeof(record)) )
        for(index=1;index<=size;index++)
            msg += sprintf("�x%4d  %9d  %s\n", index, record[index]["price"], record[index]["name"]);

    msg += "�u�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
    msg += "�x��J transfer <�s��> �i��ǰe�C���Ť@�K�O�I     �x\n";
    msg += "���w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��";

    return msg;
}

void create()
{
    set("short", "����ǰe");
    set("long", "�o�̥R���ۤ@�ѱj�P���d�J�ԡA�i��O�Y��Ԫ̦b���G�U�S�O��\n"
                "�ԳN�A�A�i�H�o�{�|�g�����F�ԳN���b�A�Ӧb�A�����e��ߵۤ@�i�j\n"
                "�P�l�A�W�Y�äC�K�V�a�g�F�@���r�C\n" );

    set("detail", ([
        "�P�l" : (: do_list :),
    ]));

    set("exits", ([
        "east" : ([ "filename" : __DIR__"wizard.c",
                       "x_axis" : 21,
                       "y_axis" : 20,
                  ]),
        "south" : ([ "filename" : __DIR__"wizard.c",
                       "x_axis" : 18,
                       "y_axis" : 23,
                  ]),
        "west" : ([ "filename" : __DIR__"wizard.c",
                       "x_axis" : 15,
                       "y_axis" : 20,
                  ]),
        "north" : ([ "filename" : __DIR__"wizard.c",
                       "x_axis" : 18,
                       "y_axis" : 17,
                  ]),
    ]));

    setup();
}

void init()
{
    add_action("do_transfer", "transfer");
}

int do_transfer(string arg)
{
    int number;
    object me = this_player(), room;

    if( me->is_busy() || me->is_fighting() ) 
        return notify_fail("�A�{�b�S���šC\n");

    if( !arg )
        return notify_fail("�A�Q�n�ǰe����̡H\n");

    if( sscanf(arg, "%d", number) != 1 )
        return notify_fail("�A�Q�n�ǰe����̡H\n");

    if( undefinedp(record[number]) )
        return notify_fail("�A�Q�n�ǰe����̡H\n");

    if( me->query("level") != 1 && me->query("bank") < record[number]["price"] )
        return notify_fail("�A�Ȧ�̪��������A�L�k�ǰe�C\n");

    if( !objectp(room = load_object(record[number]["file"])) )
        return notify_fail("�A�{�b�L�k�ǰe�쨺�Ӧa��C\n");

    message_vision("�|�g��M�h�_�F�@�}�j���A$N�@�����N�Q�j���F...\n", me);

    // ���ʦ��\�~�ݥI��
    if( me->move(room) && me->query("level") != 1 ) me->add("bank", -record[number]["price"]);

    message_vision("�|�g��M�h�_�F�@�}�j���A$N�Q�j���a�L�ӳo��...\n", me);

    me->start_busy(3);

    return 1;
}
