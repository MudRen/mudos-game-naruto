/* write by -Acme- */

inherit ROOM;

void create()
{
    set("short", "�츭�ѩ�");

    set("long", @long
�o�O�@���ﺡ�ϮѪ��p���ѩ��A��A�٨S�i��ѩ��̮ɴN�Q���f
���@���p�l�l�ޡA�W���g�ۡu�Ѩ�ήɤ��֡A�@���d���֪��D�v��
�ӳo���ѩ��S�O�ɽ�@�Ǥ��}�����ǡA��A�b�ѩ����U�k�߮ɡA����
���ɪ��Ǩӫy���n�A���G��A���լݮѷP��۷����C
long);

    set("exits", ([
        "west" : ([ "filename": __DIR__"muye.c",
                      "x_axis": 15,
                      "y_axis": 10,
                 ]),
    ]));

    set("objects", ([
        __DIR__"npc/booker.c": 1,
    ]));

    setup();
}
