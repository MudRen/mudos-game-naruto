#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",GRN"���j�O�L"NOR);
    set("long", @long
�Z�K���O�L�A�C�ʾ�ֻ������Ʀʤ��ءA�K���Z���N�ѤW���Ӷ�
�\�ӵL���A���U�K�߽L�ڿ��`�A�ݨӳo�Ǥj��ֻ��]���X�d�~���ͩR
�F�A������K��O�����ͩR�몺���ʵۡA���G�ٷ|���}�����K������
���]��Ө�ֳ\�������A�]�]���o�˾���˪L�������ٺ�M���C
long);
    set("exits", ([
        "north" : __DIR__"forest15.c",
        "south" : __DIR__"forest15.c",
        "west" : __DIR__"forest15.c",
        "east" : __DIR__"forest15.c",
    ]));
    set("no_recall", 1);
    setup();
}
int valid_leave(object me, string dir)
{
    string area = __DIR__"forest"+random(20)+".c";
    object mob;
    if( !me ) return 0;
    if( userp(me) && (dir == "west" || dir == "east" || dir == "south" || dir == "north" ) ) {
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
    }
    return notify_fail("");
}
