inherit ROOM;

void create()
{
        set("short", "���¤���");
        set("long", @LONG
�@�ʪ����n�C��K���j��A�𪺪K���Z�K�A�ڳ��X�G�Q���F��y
�����¡A��W�ٵ��F�@�ǩ|���������G��C�J�Ӫ��ݬݨ��ǪG��A��
�M�o�{�G��~�M�S������@�Ӫ����@�˪��A�����C�⤣�P�A�N�s�~�[
�Ϊ������ۦP�A�u�O�n�_������\�H�n���o�ةǾ�]���¡C
LONG);
    set("exits", ([
        "south" : __DIR__"altar04.c",
        "north" : __DIR__"altar01.c",
        "east" : __DIR__"altar03.c",
        "west" : __DIR__"altar02.c",
    ]));
        setup();
}
