#include <room.h>

// �]��INN�̡A�|�۰ʦ����D�԰ϡA�åB�O�����I
inherit INN;

void create()
{
    set("short", "�y�v����");

    set("long", @long
�o�̬O�y�v�����A�_�S�����������j���۾�ӪŶ��A���X���C����`��
�������μˤl�ܹ���ȡA���W�h����]���`�X�n�C����a���I��ù��
������A���H������ı�����P�F����
long);

    set("exits", ([
        "acme" : "/u/a/acme/workroom.c",
        "kkeenn" : "/u/k/kkeenn/workroom.c",
        "ayumi" : "/u/a/ayumi/workroom.c", 
        "east" : ([ "filename" : "/u/f/flying/area/mei.c",
                                         "x_axis" : 8,
                                          "y_axis" : 9,  
                                  ]),
        "down" : ([ "filename" : "/u/f/flying/area/rod.c",
                                         "x_axis" : 5,
                                         "y_axis" : 5,
                                  ]),
    ]));



    setup();
    replace_program(ROOM);
}


