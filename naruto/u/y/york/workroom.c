inherit ROOM;

void create()
{
        set("short", "�p���");
        set("long", @LONG
�@�����q���p��ΩM�@�Ӷ��쥴���H�Ӯɶ����Ův�C
LONG);
    set("exits", ([
        "jump": __DIR__"jump.c",
        "acme": "/u/a/acme/workroom.c",
        "up"   : ([ "filename" : "/u/y/york/area/york.c",
                                 "x_axis" : 0,
                                 "y_axis" : 5
                 ])
    ]));
   set("objects",([
       _DIR_NPC_"stake.c":1
   ]));

        setup();
    load_object("/daemon/board/york");
}

