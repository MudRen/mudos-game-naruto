/* write by -Acme- */

inherit ROOM;

void create()
{
    set("short", "��");

    set("long", @long
�o�̬O�츭���S�����Ŭu�t�a�A�|�g�Ů�x�M�M���A�A�i�H�ݨ�
���񪺷Ŭu�����ɪ��_�X���ϡA���A���ѽİʷQ�������i�h�w�C�b���f
�ߵۤG�ڪ��X�A�W�Y���O�g�ۡu�Ŭu���̵N���J�A�Ŭu���̪w���J�v�A
�A�ݬݲ��e�@�s�k�H�w�b���l����Y�ۤ��N���J�A�ٯu�O�ήe���۷�K
�����C
long);

    set("exits", ([
        "north" : ([ "filename": __DIR__"muye.c",
                      "x_axis": 14,
                      "y_axis": 41,
                 ]),
    ]));

    set("objects", ([
        __DIR__"npc/pooler.c": 1,
        __DIR__"npc/poolman.c": 3,
    ]));

    setup();
}
