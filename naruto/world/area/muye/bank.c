/* write by -Acme- */

#include <room.h>

inherit BANK;

void create()
{
    set("short", "�츭�Ȧ�");

    set("long", @long
�@�����j���Ȧ�A�|�P�ٳƬ۷���Y�A��A�@���i�ӡA�|�g�H��
�����������b�A���W�A�n���n�N�A�ͧ]����@��C�Ȧ���f���ۤ@��
���p�O�o�ˤl�g���u�U�U�ӭɿ��B�N�N�h�ٿ��v�A�ݨӧA�̦n�O���
��ɿ��A�n���M�Q���l�]�٤����C
�������O�G[�s��] deposit <�ƶq> <�f������>
          [���] withdraw <�ƶq> <�f������>
          [�׿�] outward <�H��> <�ƶq>
long);

    set("exits", ([
        "north" : ([ "filename": __DIR__"muye.c",
                      "x_axis": 25,
                      "y_axis": 38,
                 ]),
    ]));

    setup();
}
