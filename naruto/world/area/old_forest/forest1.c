#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",GRN"�O�L�~��"NOR);
    set("long", @long
����񺡤F�s�}���~���۾��A���F�@���D�`�U�k���H�����񤧥~
���G�����Pı���X�o�̴��g���H�ӹL�A���ΰ��n��s�A�����P�@�j��
���O�L�C�q���񪺤j��ӬݡA�@�ʾ�X�G�n�ƤQ�H�~�����A�i��
�o���ӬO�D�`�j�Ѫ��a��F�C
long);
    set("exits", ([
        "north" : __DIR__"hole03.c",
        "south" : __DIR__"forest1.c",
        "west" : __DIR__"forest1.c",
        "east" : __DIR__"forest1.c",
    ]));
    set("no_recall", 1);
    setup();
}
int valid_leave(object me, string dir)
{
    string area = __DIR__"forest"+random(20)+".c";
    object mob;
    if( !me ) return 0;
    if( userp(me) && (dir == "west" || dir == "east" || dir == "south" ) ) {
        me->move(area);
        switch( random(500) ) {
            case 50..105: message_vision(HIR"$N���ۨ��ۡA�|�P���M�ǥX�@�}���~���ɫ��n�I\n"NOR, me);
                          mob = new(__DIR__"npc/sacrier.c");
                          mob->move(environment(me));
                          break;
            case 260..315: message_vision(HIW"�I�G�������n���A�ե��q�Z�K���K���W�}�ŦӤU�I\n"NOR, me);
                          mob = new(__DIR__"npc/sworder.c");
                          mob->move(environment(me));
                          break;
            case 420..475: message_vision(HIG"���b�����ܪ���[�Z���I���o���H�۸޲������n...\n"NOR, me);
                          mob = new(__DIR__"npc/doctor.c");
                          mob->move(environment(me));
                          break;
        }
        return notify_fail("");
    }
    return ::valid_leave(me, dir);
}
