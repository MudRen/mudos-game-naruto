#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "�A��x����");
    set("long", @LONG
�e�������ӡA�]�����l�����Y�D�`�z��A�D����@�I�`���C���l�e��
�\�F�@�y���j���滷��A���G����ݨ�ܻ����a��C
LONG);

    set("exits", ([
        "down" : __DIR__"look2.c",
    ]));
    set("detail", ([
        "�滷��": "�i�H��ܬݥ|�Ӥ�V(�F��B���B�n��B�_��)�C",
        "�F��": "���G��ݨ��C������������C",
        "���": "���Ӥj�F�A�u��j�j�ݨ�@�y�p�q...",
        "�n��": "�u���@���L�v�j���M�X���p��C",
        "�_��": "��ݨ��q�����x�`�����j���u���q�����v",
    ]));
    setup();
}
