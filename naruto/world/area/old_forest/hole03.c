#include <ansi.h>
inherit ROOM;

string *wheres = ({
  MAG"�|�P�Q�X�@�}�����A���A�d���M���F�n��_...\n"NOR,
  HIB"�@�D�Ŧ⪺�{�����L�A�������A���A���U�@���V��...\n"NOR,
  HIW"�զ⪺���������ۡA�ڥ��N�S��k���M����m...\n"NOR,
  HIK"�S���O�������¬}�]���A���⤣������...\n"NOR,
  BLK"���ߪ����D���Q�A�j�q���l�J�󤤡A���M�@�}�w�t...\n"NOR,
});

void create()
{
    set("short","�}�]���O");
    set("long", @long
���O�W���|�Ӥ�V�����}�ޥi�H�i�J�A���O�s���}�ު����u�O�@
���ΥۻO�ҷf�ت��p�D�n�O�򪺤Ӥj�O�άO���n�F�A�i�O�|����}��
�L�ӯ����H���O�I�]�\�]���|�P�Ӷ¤F�A�~�M���A�@�ɶ��ॢ��V�P
�A�p�G�Q���}�N���򪺧�÷�l�a...�����٦b����~��...
long);
    set("exits", ([
        "north" : __DIR__"hole03.c",
        "south" : __DIR__"hole03.c",
        "east" : __DIR__"hole03.c",
        "west" : __DIR__"hole03.c",
    ]));
    set("detail", ([
        "÷�l": HIK"�A�������n���ݨ�W����÷�l...�n��(climb)�ݬݶܡH"NOR,
    ]));
    set("no_recall", 1);
    setup();
}
void init()
{
    add_action("do_climb", "climb");
}
int do_climb(string arg)
{
    if( arg == "÷�l") {
        if( this_player()->is_busy() ) {
            tell_object(this_player(), "�A�ثe�L�k�ʼu�A���દ÷�l�C\n"NOR);
            return 1;
        }
        if( this_player()->query_stat_current("ap") < 100 ) {
            tell_object(this_player(), "�A���믫�L��h�ΡA�{�b��÷�l�ӦM�I�F�C\n"NOR);
            return 1;
        }
        if( this_player()->query_temp("oldtree") ) {
            message_vision(CYN"$N���Ť��@�����G�Q�줰��F��A���O�o��F�ӪŮt�I����L���`�W���C\n"NOR, this_player());
            tell_object(this_player(), HIR"(�A�~�����Y�N���A�����믫���j�����O�I)\n"NOR);
            this_player()->damage_stat("ap", 100);
            this_player()->start_busy(5);
            return 1;
        }
        message_vision("$N���e�@���A��n���÷�Y���F�W�h�C\n", this_player());
        this_player()->move(__DIR__"hole02.c");
        message_vision("$N���F���B�Y�������A�q�U�����F�W�ӡC\n", this_player());
        return 1;
    }
    return notify_fail("�A�Q������F��H\n");
}
int valid_leave(object me, string dir)
{
    if( !me ) return 0;
    if( userp(me) && (dir == "west" || dir == "east" || dir == "north" || dir == "south") ) {
        if( me->query_temp("oldtree/west") == 3 && me->query_temp("oldtree/east") == 7 &&
            me->query_temp("oldtree/south") == 1 && me->query_temp("oldtree/north") == 2 ) {

            tell_object(this_player(), HIY"(�A�����e�ŵM�}�ԡA�ש��L�}�ި�F�@���O�L�I)\n"NOR);
            me->delete_temp("oldtree");
            me->start_busy(1);
            call_out("oldtree", 2, me);
            return notify_fail("");
        } else if( random(20) < 2 ) {
            tell_object(this_player(), HIW"(�A���ۨ��ۦ��G�S���^��F�_�I)\n"NOR);
            me->delete_temp("oldtree");
        } else {
            tell_object(me, wheres[random(sizeof(wheres))]);
            me->add_temp("oldtree/"+dir, 1);
        }
    }
    return ::valid_leave(me, dir);
}
void oldtree(object me)
{
    string area = "/world/area/old_forest/forest1.c";
    me->move(area);
}
